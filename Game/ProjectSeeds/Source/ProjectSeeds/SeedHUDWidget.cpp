// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedHUDWidget.h"

void USeedHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void USeedHUDWidget::UpdateHPBarSize(float NewMaxHealthValue)
{
	//auto newIncrease = new / starting value
	//HPBarVerticalScale += newIncrease;
}

void USeedHUDWidget::UpdateActionPointCount(int Count)
{
	ActionPointCount = Count;
}
