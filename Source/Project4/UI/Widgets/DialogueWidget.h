// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueWidget.generated.h"

class UVerticalBox;
class URichTextBlock;

UCLASS()
class PROJECT4_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta=(BindWidget))
	UVerticalBox* answers;

	UPROPERTY(meta = (BindWidget))
	URichTextBlock* name;

	UPROPERTY(meta = (BindWidget))
	URichTextBlock* text;
};
