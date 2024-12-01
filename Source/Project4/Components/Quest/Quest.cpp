// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"

#include "../../FP_FirstPerson/MyPlayerController.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/WidgetComponent.h"	

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
	
	quest_icon = CreateDefaultSubobject<UWidgetComponent>(TEXT("QuestIcon"));

	completed = false;
	activated = false;
}

void AQuest::ActivateQuest()
{
	activated = true;
	quest_icon->SetVisibility(true);
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

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();

	quest_icon->SetVisibility(false);
}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}