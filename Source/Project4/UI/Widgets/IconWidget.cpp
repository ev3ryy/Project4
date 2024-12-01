// Fill out your copyright notice in the Description page of Project Settings.


#include "IconWidget.h"

#include "Components/CanvasPanelSlot.h"

void UIconWidget::UpdateIconPosition(FVector2D position)
{
	UCanvasPanelSlot* canvas = Cast<UCanvasPanelSlot>(GetRootWidget()->Slot);
	if(canvas)
	{
		canvas->SetPosition(position);
	}
}
