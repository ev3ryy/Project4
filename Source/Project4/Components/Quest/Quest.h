// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Quest.generated.h"

class UBoxComponent;
class UIconWidget;
class UIconComponent;

USTRUCT(BlueprintType)
struct FObjectiveType
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector world_pos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool completed = false;
};

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
	TArray<FObjectiveType> objectives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	bool completed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	bool activated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	UBoxComponent* quest_zone;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	UIconWidget* quest_icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	UIconComponent* icon_component;

	UFUNCTION(BlueprintCallable)
	void ActivateQuest();

	UFUNCTION(BlueprintCallable)
	void CompleteQuest();

	UFUNCTION(BlueprintCallable)
	FVector2D GetQuestIconPosition();

	UFUNCTION(BlueprintCallable)
	void UpdateQuestIconPosition();

	UFUNCTION(BlueprintCallable)
	bool IsQuestVisible();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnPlayerEnter(UPrimitiveComponent* overlapped, AActor* other, UPrimitiveComponent* other_comp, int32 other_index, bool sweep, const FHitResult& sweep_result);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
