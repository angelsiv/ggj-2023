// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseSeed.h"
#include "ProjectSeedsPawn.generated.h"

UCLASS(Blueprintable)
class AProjectSeedsPawn : public ABaseSeed
{
	GENERATED_BODY()



	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

public:
	AProjectSeedsPawn();

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
	
	void RotateTowardsMouse();
	void SetFiringPressed();
	void SetFiringReleased();
	bool IsFireInputPressed();

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End Actor Interface

	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
	static const FName FireForwardBinding;
	static const FName FireRightBinding;
	static const FName FireBinding;

private:
	virtual void BeginPlay() override;

	ESeedFaction Faction;
	bool bIsFiringPressed = false;

	UPROPERTY()
	APlayerController* PlayerController;
	
};

