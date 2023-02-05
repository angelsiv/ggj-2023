// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SeedHUD.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API ASeedHUD : public AHUD
{
	GENERATED_BODY()

	ASeedHUD();

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class USeedHUDWidget> WidgetClass;
};
