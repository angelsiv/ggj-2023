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

protected:
	virtual void NativeConstruct() override;

	void UpdateHPBarSize(float NewMaxHealthValue);
	void UpdateActionPointCount(int Count);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* HealthPointBar;

	UPROPERTY(BlueprintReadWrite)
	float HPBarVerticalScale = 1.0f;

	UPROPERTY(BlueprintReadWrite)
	int ActionPointCount = 1;
};
