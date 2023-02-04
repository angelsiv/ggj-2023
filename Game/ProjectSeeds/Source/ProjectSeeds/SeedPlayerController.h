// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SeedPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API ASeedPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASeedPlayerController();
	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupInputComponent() override;
	
	void RotateTowardsMouse();
	
	void SetFiringPressed();
	void SetFiringReleased();
	bool IsFireInputPressed() const;

protected:
	virtual void OnPossess(APawn* aPawn) override;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> CursorActor;
	
	bool bIsFiringPressed = false;
	
private:
	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
	static const FName FireForwardBinding;
	static const FName FireRightBinding;
	static const FName FireBinding;

	UPROPERTY()
	AActor* _spawnedCursor;
};
