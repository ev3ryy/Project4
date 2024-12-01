// // Fill out your copyright notice in the Description page of Project Settings.
//
//
// #include "QuestArea.h"
// #include "Components/BillboardComponent.h"
// #include "Components/BoxComponent.h"
// #include "../../FP_FirstPerson/MyPlayerController.h"
// #include "../../Game/MyGameState.h"
// #include "Blueprint/UserWidget.h"
// #include "Components/WidgetComponent.h"
//
// // Sets default values
// AQuestArea::AQuestArea()
// {
//  	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
// 	PrimaryActorTick.bCanEverTick = true;
//
// 	trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
// 	trigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
// 	trigger->SetCollisionObjectType(ECC_WorldDynamic);
// 	trigger->SetCollisionResponseToChannels(ECollisionResponse::ECR_Ignore);
// 	trigger->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
//
// 	quest_icon = CreateDefaultSubobject<UWidgetComponent>(TEXT("QuestIcon"));
// }
//
// void AQuestArea::ShowMarker(bool show)
// {
// 	UUserWidget* widget = quest_icon->GetWidget();
//
// 	widget->CallFunctionByNameWithArguments(TEXT("SetMandatoryIcon"), *GLog, nullptr, true);
//
// 	quest_icon->SetVisibility(show);
// }
//
// void AQuestArea::ActivateQuestArea()
// {
// 	ShowMarker(true);
// 	UpdateQuestMarkerPosition();
// }
//
// void AQuestArea::UpdateQuestMarkerPosition()
// {
// 	// if(quest_icon)
// 	// {
// 	// 	FVector pos = GetActorLocation() + FVector(0.0f, 0.0f, 300.0f);
// 	// 	quest_icon->SetupAttachment(RootComponent);
// 	// 	quest_icon->SetRelativeLocation(pos);
// 	// }
// }
//
// // Called when the game starts or when spawned
// void AQuestArea::BeginPlay()
// {
// 	Super::BeginPlay();
//
// 	trigger->OnComponentBeginOverlap.AddDynamic(this, &AQuestArea::OnPlayerEnter);
// 	quest_icon->SetVisibility(false);
// }
//
// void AQuestArea::OnPlayerEnter(UPrimitiveComponent* overlapped, AActor* other, UPrimitiveComponent* other_comp,
// 	int32 other_index, bool sweep, const FHitResult& sweep_result)
// {
// 	AMyPlayerController* controller = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
// 	if(controller)
// 	{
// 		if(other == controller->GetPawn())
// 		{
// 			AMyGameState* gamestate = Cast<AMyGameState>(GetWorld()->GetGameState());
// 			if(gamestate)
// 			{
// 				gamestate->quest_manager->CompleteQuest(this);
// 			}
//
// 			ShowMarker(false);
// 			Destroy();
// 		}
// 	}
// }
//
// // Called every frame
// void AQuestArea::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
//
// }
//
