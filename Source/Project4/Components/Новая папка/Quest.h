// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Quest.generated.h"

UCLASS()
class PROJECT4_API AQuest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuest();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	TArray<FText> objectives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	bool completed;

	UFUNCTION(BlueprintCallable)
	virtual void StartQuest();

	UFUNCTION(BlueprintCallable)
	virtual void CompleteQuest();

	UFUNCTION(BlueprintCallable)
	virtual bool CheckQuestStatus() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
