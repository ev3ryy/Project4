// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "Components/RichTextBlock.h"
#include "../FP_FirstPerson/FP_FirstPersonCharacter.h"
#include "../Game/MyGameState.h"

// Sets default values for this component's properties
UDialogueComponent::UDialogueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UDialogueComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDialogueComponent::ClearDialogue() {
	if (current_widget) {
		current_widget->RemoveFromViewport();
		current_widget = nullptr;
	}

	current_dialogue = FName();
}

void UDialogueComponent::EndDialogue() {
	if (current_widget) {
		current_widget->RemoveFromViewport();
		current_widget = nullptr;
	}

	AMyPlayerController* controller = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
	if (controller) {
		controller->bShowMouseCursor = false;
		controller->SetInputMode(FInputModeGameOnly());
	}
}

void UDialogueComponent::StartDialogue(FName dialogue_row) {
	ClearDialogue();

	AMyPlayerController* controller = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());

	AMyGameState* gamestate = Cast<AMyGameState>(GetWorld()->GetGameState());

	current_widget = CreateWidget<UDialogueWidget>(GetWorld(), widget);
	current_widget->AddToViewport();

	current_dialogue = dialogue_row;
	current_widget->answers->ClearChildren();

	FDialogueBase dialogue = GetDialogue(dialogue_row);
	UE_LOG(LogTemp, Log, TEXT("Dialog: %s"), *dialogue.name);

	current_widget->name->SetText(FText::FromString(dialogue.name));
	current_widget->text->SetText(FText::FromString(dialogue.text));

	for (int32 i = 0; i < dialogue.responses.Num(); i++) {
		UDialogueAnswer* answer = CreateWidget<UDialogueAnswer>(GetWorld(), answer_widget);
		answer->AddToViewport();

		answer->text->SetText(FText::FromString(dialogue.responses[i].answer));

		current_widget->answers->AddChild(answer);

		answer->InitializeAnswer(dialogue.responses[i], this);
	}

	controller->bShowMouseCursor = true;
	controller->SetInputMode(FInputModeUIOnly());
}

FDialogueBase UDialogueComponent::GetDialogue(FName dialogue_row) {
	if (data) {
		return *data->FindRow<FDialogueBase>(dialogue_row, TEXT("GetDialogue"));
	}

	return FDialogueBase();
}