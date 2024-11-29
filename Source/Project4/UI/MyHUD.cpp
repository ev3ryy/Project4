// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Blueprint/UserWidget.h"

void AMyHUD::CreateCustomWidget(TSubclassOf<UUserWidget> widget) {
	current_widget = CreateWidget<UUserWidget>(GetWorld(), widget);
	current_widget->AddToViewport();
	UE_LOG(LogTemp, Log, TEXT("Created widget"));
}