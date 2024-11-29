// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

class UUserWidget;

UCLASS()
class PROJECT4_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	UUserWidget* current_widget;

	UFUNCTION(BlueprintCallable)
	void CreateCustomWidget(TSubclassOf<UUserWidget> widget);
};
