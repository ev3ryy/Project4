// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueAnswer.h"

#include "Components/Button.h"
#include "Components/RichTextBlock.h"

#include "Delegates/Delegate.h"

#include "../../Components/DialogueComponent.h"
#include "../../Game/MyGameState.h"

void UDialogueAnswer::InitializeAnswer(FResponses& response, UDialogueComponent* dialogue) {
	cached_response = response;
	dialogue_owner = dialogue;

	UE_LOG(LogTemp, Log, TEXT("next row: %s, class: %s"), *response.next_row.ToString(), *GetName());

	answer_button->OnClicked.AddDynamic(this, &UDialogueAnswer::OnClicked);
}

void UDialogueAnswer::OnClicked() {
	if (cached_response.quest) {
		AMyGameState* gamestate = Cast<AMyGameState>(GetWorld()->GetGameState());
		if (gamestate) {
			AQuest* quest = GetWorld()->SpawnActor<AQuest>(cached_response.quest);
			if (quest) {
				gamestate->quest_manager->SubmitQuest(quest);
			}
		}
	}

	if (cached_response.is_end) {
		dialogue_owner->EndDialogue();
	}
	else {
		dialogue_owner->StartDialogue(cached_response.next_row);
	}
}