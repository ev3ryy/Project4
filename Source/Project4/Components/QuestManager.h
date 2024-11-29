// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestManager.generated.h"

class AQuest;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT4_API UQuestManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestManager();
	~UQuestManager();

	UFUNCTION(BlueprintCallable)
	void SubmitQuest(AQuest* quest);

	UFUNCTION(BlueprintCallable)
	void CompleteQuest(AQuest* quest);

	UFUNCTION(BlueprintCallable)
	bool CheckQuestStatus(AQuest* quest) const;

private:
	TArray<AQuest*> active_quests;
		
};
