// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

#include "Quest/Quest.h"

UQuestManager::UQuestManager()
{
	PrimaryComponentTick.bCanEverTick = false;

}

UQuestManager::~UQuestManager() {

}

void UQuestManager::SubmitQuest(AQuest* quest) {
	if (quest) {
		active_quests.Add(quest);
		quest->StartQuest();
	}
}

void UQuestManager::CompleteQuest(AQuest* quest) {
	if (quest && active_quests.Contains(quest)) {
		quest->CompleteQuest();
		active_quests.Remove(quest);
	}
}

bool UQuestManager::CheckQuestStatus(AQuest* quest) const {
	return quest ? quest->CheckQuestStatus() : false;
}