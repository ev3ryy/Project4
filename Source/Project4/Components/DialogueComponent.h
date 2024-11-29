// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "../Data/DialogueBase.h"
#include "../UI/Widgets/DialogueWidget.h"
#include "../UI/Widgets/DialogueAnswer.h"
#include "Delegates/Delegate.h"
#include "DialogueComponent.generated.h"

class UUserWidget;
class UVerticalBox;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT4_API UDialogueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDialogueComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Dialogue)
	UDataTable* data;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Dialogue)
	TSubclassOf<UDialogueWidget> widget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Dialogue)
	TSubclassOf<UDialogueAnswer> answer_widget;

	UDialogueWidget* current_widget;

	UFUNCTION(BlueprintCallable)
	void StartDialogue(FName dialogue_row);

	void ClearDialogue();

	void EndDialogue();

	UFUNCTION(BlueprintCallable)
	FDialogueBase GetDialogue(FName dialogue_row);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	FName current_dialogue; // row name

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
