// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "HealthWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API UHealthWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* HealthBar;

	FLinearColor FriendlyColour = FLinearColor(0.06, 0.39, 0.07); // Some green
	FLinearColor EnemyColour = FLinearColor::Red;
};
