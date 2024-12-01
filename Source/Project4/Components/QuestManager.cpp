// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

#include "Kismet/GameplayStatics.h"
#include "Quest/Quest.h"

UQuestManager::UQuestManager()
{
	PrimaryComponentTick.bCanEverTick = false;

}

UQuestManager::~UQuestManager() {

}

void UQuestManager::AddQuest(TSubclassOf<AQuest> quest)
{
	if(quest)
	{
		// active_quests.Add(quest);
		// ActivateQuest(quest->name);
		// UE_LOG(LogTemp, Log, TEXT("added quest %s"), *quest->name);
		TArray<AActor*> out;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AQuest::StaticClass(), out);
		for(AActor* finded : out)
		{
			AQuest* found_quest = Cast<AQuest>(finded);
			if(found_quest->GetClass() == quest && !active_quests.Contains(found_quest))
			{
				active_quests.Add(found_quest);
				ActivateQuest(found_quest->name);
				UE_LOG(LogTemp, Log, TEXT("added quest %s"), *found_quest->name);
			}
		}
	}
}

void UQuestManager::ActivateQuest(FString quest_name)
{
	AQuest* quest = FindQuestByName(quest_name);
	if(quest && !quest->activated)
	{
		quest->ActivateQuest();
	}
}

AQuest* UQuestManager::FindQuestByName(FString quest_name)
{
	for(AQuest* quest : active_quests)
	{
		if(quest->name == quest_name)
		{
			return quest;
		}
	}

	return nullptr;
}
