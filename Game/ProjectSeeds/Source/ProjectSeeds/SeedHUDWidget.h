// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "SeedHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API USeedHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* HealthPointBar;

	UPROPERTY(BlueprintReadWrite)
	float HPBarVerticalScale = 1.0f;
};
