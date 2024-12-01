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

	UPROPERTY(BlueprintReadOnly)
	TArray<AQuest*> active_quests;

	UFUNCTION(BlueprintCallable)
	void AddQuest(TSubclassOf<AQuest> quest);

	UFUNCTION(BlueprintCallable)
	void ActivateQuest(FString quest_name);

	UFUNCTION(BlueprintCallable)
	AQuest* FindQuestByName(FString quest_name);
	
private:
		
};
