// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Quest.generated.h"

class UBoxComponent;
class UWidgetComponent;
class UQuestIcon;

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
	bool completed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	bool activated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	UBoxComponent* quest_zone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	UWidgetComponent* quest3d_icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	TSubclassOf<UQuestIcon> quest_icon;

	UQuestIcon* current_widget = nullptr;

	UFUNCTION(BlueprintCallable)
	void ActivateQuest();

	UFUNCTION(BlueprintCallable)
	void CompleteQuest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
