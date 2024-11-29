// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"

#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"
#include "../Components/DialogueComponent.h"
#include "Blueprint/UserWidget.h"
#include "../UI/MyHUD.h"
#include "../FP_FirstPerson/FP_FirstPersonCharacter.h"
#include "../UI/Widgets/DialogueWidget.h"

// Sets default values
ANPC::ANPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = GetCapsuleComponent();

	dialogue = CreateDefaultSubobject<UDialogueComponent>(TEXT("DialogueComponent"));

	quest_icon = CreateDefaultSubobject<UWidgetComponent>(TEXT("QuestIcon"));
	quest_icon->SetupAttachment(RootComponent);
	quest_icon->SetWidgetSpace(EWidgetSpace::Screen);
	quest_icon->SetDrawSize(FVector2D(32.0f, 32.0f));
	quest_icon->SetRelativeLocation(FVector(0.0f, 0.0f, 150.0f));

	current_widget = nullptr;
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
	if(quest_icon) quest_icon->SetVisibility(false);
}

void ANPC::Interact_Implementation(AActor* instigator) {
	dialogue->StartDialogue(TEXT("first"));
}

void ANPC::SetQuestIconState(bool state) {
	UUserWidget* widget = quest_icon->GetWidget();

	widget->CallFunctionByNameWithArguments(state ? TEXT("SetMandatoryIcon") : TEXT("SetOptionalIcon"), *GLog, nullptr, true);

	quest_icon->SetVisibility(true);
}
