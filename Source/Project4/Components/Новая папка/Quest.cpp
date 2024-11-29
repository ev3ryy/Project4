// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

// Sets default values
AQuest::AQuest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	completed = false;
}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuest::StartQuest() {
	UE_LOG(LogTemp, Log, TEXT("started quest: %s"), *name);
}

void AQuest::CompleteQuest() {
	UE_LOG(LogTemp, Log, TEXT("completed quest: %s"), *name);
}

bool AQuest::CheckQuestStatus() const {
	UE_LOG(LogTemp, Log, TEXT("status %s is &s"), *name, completed ? TEXT("completed") : TEXT("non completed!"));
	return completed;
}