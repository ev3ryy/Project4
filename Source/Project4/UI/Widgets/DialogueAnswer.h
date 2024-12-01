// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../../Data/DialogueBase.h"
#include "DialogueAnswer.generated.h"

class UButton;
class URichTextBlock;
class UDialogueComponent;

UCLASS()
class PROJECT4_API UDialogueAnswer : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta=(BindWidget))
	UButton* answer_button;

	UPROPERTY(meta = (BindWidget))
	URichTextBlock* text;

	void InitializeAnswer(FResponses& response, UDialogueComponent* dialogue);

private:
	FResponses cached_response;
	UDialogueComponent* dialogue_owner = nullptr;

	UFUNCTION()
	void OnClicked();
};
