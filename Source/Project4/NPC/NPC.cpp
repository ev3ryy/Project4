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
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
}

void ANPC::Interact_Implementation(AActor* instigator) {
	dialogue->StartDialogue(TEXT("first"));
}