// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "../Components/Quest/Quest.h"
#include "DialogueBase.generated.h"

USTRUCT(BlueprintType)
struct PROJECT4_API FResponses {
	GENERATED_BODY()

	FResponses() :
		answer(TEXT("none")),
		next_row(TEXT("")),
		is_end(false),
		quest(nullptr)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Response)
	FString answer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Response)
	FName next_row;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Response)
	bool is_end;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Response)
	TSubclassOf<AQuest> quest;
};

USTRUCT(BlueprintType)
struct PROJECT4_API FDialogueBase : public FTableRowBase
{
	GENERATED_BODY()

	FDialogueBase() :
		name(TEXT("none")),
		text(TEXT("none")),
		row_name(TEXT(""))
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Dialogue)
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Dialogue)
	FString text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Dialogue)
	TArray<FResponses> responses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Dialogue)
	FName row_name;
};
