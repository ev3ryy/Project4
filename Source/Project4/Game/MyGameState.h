// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Delegates/Delegate.h"
#include "Delegates/DelegateCombinations.h"
#include "../Data/DialogueBase.h"
#include "../Components/QuestManager.h"
#include "MyGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FButton, FResponses&, responses);

UCLASS()
class PROJECT4_API AMyGameState : public AGameStateBase
{
	GENERATED_BODY()
	
	AMyGameState();

public:
	FButton answer_button;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	UQuestManager* quest_manager;

};
