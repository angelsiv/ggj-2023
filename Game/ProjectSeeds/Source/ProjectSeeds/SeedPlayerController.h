// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "SeedPlayerController.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSeedPlayerController, All, All);

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

	void IncreaseCurrency(int Value);
	bool CanSpendCurrency(int Value);

	UFUNCTION(BlueprintCallable)
	AProjectSeedsPawn* GetSeedPawn() const;

protected:
	virtual void OnPossess(APawn* aPawn) override;

	void OnZoom(float AxisValue);
	void OnZoomResetPressed();

	UFUNCTION()
	void OnBeginActorPawnOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> CursorActor;
	UPROPERTY(EditAnywhere)
	float ZoomSpeed = 100.0f;
	UPROPERTY(EditAnywhere)
	float ZoomDefault = 2000.0f;
	UPROPERTY(EditAnywhere)
	float ZoomMin = 500.0f;
	UPROPERTY(EditAnywhere)
	float ZoomMax = 3500.0f;

	bool bIsFiringPressed = false;

	UPROPERTY(VisibleAnywhere)
	int CurrencyAmmount = 0;

private:
	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
	static const FName FireForwardBinding;
	static const FName FireRightBinding;
	static const FName FireBinding;
	static const FName Zoom;
	static const FName ZoomReset;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* _cameraBoom;

	UPROPERTY()
	AActor* _spawnedCursor;
};
