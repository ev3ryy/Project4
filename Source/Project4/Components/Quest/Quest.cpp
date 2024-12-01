// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"

#include "../../FP_FirstPerson/MyPlayerController.h"
#include "../../FP_FirstPerson/FP_FirstPersonCharacter.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/WidgetComponent.h"	

#include "../../UI/Widgets/QuestIcon.h"

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
	
	quest3d_icon = CreateDefaultSubobject<UWidgetComponent>(TEXT("QuestIcon"));

	completed = false;
	activated = false;
}

void AQuest::ActivateQuest()
{
	activated = true;

	quest3d_icon->SetVisibility(true);
	if (current_widget) current_widget->AddToViewport();

	UE_LOG(LogTemp, Log, TEXT("quest %s activated"), *name);
}

void AQuest::CompleteQuest()
{
	if(activated && !completed)
	{
		completed = true;
		UE_LOG(LogTemp, Log, TEXT("quest %s completed"), *name);

		if (current_widget) current_widget->RemoveFromViewport();

		Destroy();
	}
}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();

	quest3d_icon->SetVisibility(false);

	AFP_FirstPersonCharacter* character = Cast<AFP_FirstPersonCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (character) {
		character->quest_location = GetActorLocation();
	}

	current_widget = CreateWidget<UQuestIcon>(GetWorld(), quest_icon);
}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}