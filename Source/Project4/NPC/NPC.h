// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Interfaces/Interactable.h"
#include "NPC.generated.h"

class UWidgetComponent;
class UDialogueComponent;
class UUserWidget;

UCLASS()
class PROJECT4_API ANPC : public ACharacter, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC();

	void Interact_Implementation(AActor* instigator) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	UDialogueComponent* dialogue;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

};
