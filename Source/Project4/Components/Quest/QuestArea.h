// // Fill out your copyright notice in the Description page of Project Settings.
//
// #pragma once
//
// #include "CoreMinimal.h"
// #include "GameFramework/Actor.h"
// #include "QuestArea.generated.h"
//
// class UUserWidget;
// class UWidgetComponent;
// class UBoxComponent;
//
// UCLASS()
// class PROJECT4_API AQuestArea : public AActor
// {
// 	GENERATED_BODY()
// 	
// public:	
// 	// Sets default values for this actor's properties
// 	AQuestArea();
//
// 	UPROPERTY(EditAnywhere, BlueprintReadOnly)
// 	UBoxComponent* trigger;
//
// 	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
// 	UWidgetComponent* quest_icon;
//
// 	UPROPERTY(EditAnywhere, BlueprintReadOnly)
// 	FText area_name;
//
// 	UFUNCTION(BlueprintCallable)
// 	void ShowMarker(bool show);
//
// 	UFUNCTION(BlueprintCallable)
// 	void ActivateQuestArea();
//
// 	void UpdateQuestMarkerPosition();
// 	
// protected:
// 	// Called when the game starts or when spawned
// 	virtual void BeginPlay() override;
//
// 	UFUNCTION()
// 	void OnPlayerEnter(UPrimitiveComponent* overlapped, AActor* other, UPrimitiveComponent* other_comp, int32 other_index, bool sweep, const FHitResult& sweep_result);
// 	
// public:	
// 	// Called every frame
// 	virtual void Tick(float DeltaTime) override;
//
// };
