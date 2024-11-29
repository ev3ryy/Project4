// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameState.h"

AMyGameState::AMyGameState() {
	quest_manager = CreateDefaultSubobject<UQuestManager>(TEXT("QuestManager"));
}