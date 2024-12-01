// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IconWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT4_API UIconWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateIconPosition(FVector2D position);
};
