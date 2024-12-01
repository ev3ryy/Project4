// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "../../UI/Widgets/IconComponent.h"

#include "../../FP_FirstPerson/MyPlayerController.h"
#include "Components/CanvasPanelSlot.h"
#include "Project4/UI/Widgets/IconWidget.h"

// Sets default values
AQuest::AQuest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	quest_zone = CreateDefaultSubobject<UBoxComponent>(TEXT("QuestZone"));
	quest_zone->SetupAttachment(RootComponent);
	quest_zone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	quest_zone->SetCollisionResponseToChannels(ECollisionResponse::ECR_Ignore);
	quest_zone->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
	quest_zone->OnComponentBeginOverlap.AddDynamic(this, &AQuest::OnPlayerEnter);

	icon_component = CreateDefaultSubobject<UIconComponent>(TEXT("QuestIcon"));
	icon_component->SetupAttachment(RootComponent);
	icon_component->SetWidgetSpace(EWidgetSpace::Screen);
	icon_component->SetDrawSize(FVector2D(32.0f, 32.0f));
	icon_component->SetRelativeLocation(FVector(0.0f, 0.0f, 150.0f));
	
	completed = false;
	activated = false;
}

void AQuest::ActivateQuest()
{
	activated = true;
	//quest_icon->SetVisibility(true);
	UE_LOG(LogTemp, Log, TEXT("quest %s activated"), *name);
}

void AQuest::CompleteQuest()
{
	if(activated && !completed)
	{
		completed = true;
		UE_LOG(LogTemp, Log, TEXT("quest %s completed"), *name);
		Destroy();
	}
}

FVector2D AQuest::GetQuestIconPosition()
{
	AMyPlayerController* controller = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
	if(controller)
	{
		FVector player_location = controller->GetPawn()->GetActorLocation();
		FVector quest_location = GetActorLocation();

		FVector direction_to_quest = quest_location - player_location;
		direction_to_quest.Z = 0;
		direction_to_quest.Normalize();

		FVector player_forward = controller->GetPawn()->GetActorForwardVector();

		float dot = FVector::DotProduct(direction_to_quest, player_forward);

		FVector2D icon_position;

		controller->ProjectWorldLocationToScreen(quest_location, icon_position);

		FVector2D screen_size = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
		icon_position /= screen_size;

		if(dot < -0.1f)
		{
			icon_position = FVector2D(0.5f, 0.9f);
		}

		icon_position.X = FMath::Clamp(icon_position.X, 0.1f, 0.9f);
		icon_position.Y = FMath::Clamp(icon_position.Y, 0.1f, 0.9f);

		return icon_position;
	}

	return FVector2D();
}

void AQuest::UpdateQuestIconPosition()
{
	AMyPlayerController* controller = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
	if(controller)
	{
		FVector player_location = controller->GetPawn()->GetActorLocation();
		FVector quest_location = GetActorLocation();

		if(IsQuestVisible())
		{
			FVector icon_world_pos = quest_location;
			if(icon_component)
			{
				icon_component->SetVisibility(true);
				if(quest_icon)
				{
					quest_icon->RemoveFromViewport();
				}

				icon_component->SetWorldLocation(icon_world_pos);
				UE_LOG(LogTemp, Log, TEXT("world"));
			}
		}
		else
		{
			FVector dir_to_quest = quest_location - player_location;
			dir_to_quest.Z = 0;

			dir_to_quest.Normalize();

			FVector2D screen;

			controller->ProjectWorldLocationToScreen(quest_location, screen);

			FVector2D canvas = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
			screen /= canvas;

			if(FVector::DotProduct(dir_to_quest, controller->GetPawn()->GetActorForwardVector()) < -0.1f)
			{
				screen = FVector2D(0.5f, 0.9f);
			}

			screen.X = FMath::Clamp(screen.X, 0.1f, 0.9f);
			screen.Y = FMath::Clamp(screen.Y, 0.1f, 0.9f);

			if(quest_icon)
			{
				quest_icon->UpdateIconPosition(screen * canvas);
			}

			if(icon_component)
			{
				icon_component->SetVisibility(false);
			}

			quest_icon->AddToViewport();

			UE_LOG(LogTemp, Log, TEXT("screen"));
		}
	}
}

bool AQuest::IsQuestVisible()
{
	AMyPlayerController* controller = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
	if(controller)
	{
		FVector player_location = controller->GetPawn()->GetActorLocation();
		FVector player_forward = controller->GetPawn()->GetActorForwardVector();
		FVector quest_location = GetActorLocation();

		FVector dir_to_quest = quest_location - player_location;
		dir_to_quest.Z = 0;

		dir_to_quest.Normalize();

		float dot = FVector::DotProduct(dir_to_quest, player_forward);

		return dot > 0.5f;
	}

	return false;
}

void AQuest::OnPlayerEnter(UPrimitiveComponent* overlapped, AActor* other, UPrimitiveComponent* other_comp,
                           int32 other_index, bool sweep, const FHitResult& sweep_result)
{
	if(activated && !completed)
	{
		CompleteQuest();
	}
}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();

	if(quest_icon)
	{
		quest_icon = CreateWidget<UIconWidget>(GetWorld(), quest_icon->GetClass());
	}
}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateQuestIconPosition();
}