// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedPlayerController.h"

#include "ProjectSeedsPawn.h"
#include "Components/DecalComponent.h"
#include "Kismet/KismetMathLibrary.h"

const FName ASeedPlayerController::MoveForwardBinding("MoveForward");
const FName ASeedPlayerController::MoveRightBinding("MoveRight");
const FName ASeedPlayerController::FireForwardBinding("FireForward");
const FName ASeedPlayerController::FireRightBinding("FireRight");
const FName ASeedPlayerController::FireBinding("Fire");

ASeedPlayerController::ASeedPlayerController()
{
	SetShowMouseCursor(true);
	DefaultMouseCursor = EMouseCursor::Default;
}

void ASeedPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!IsValid(GetPawn()))
	{
		return;
	}
	
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * Cast<AProjectSeedsPawn>(GetPawn())->MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		GetPawn()->GetRootComponent()->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			GetPawn()->GetRootComponent()->MoveComponent(Deflection, NewRotation, true);
		}
	}

	RotateTowardsMouse();

	if (IsFireInputPressed())
	{
		Cast<AProjectSeedsPawn>(GetPawn())->FireShot();
	}
}

void ASeedPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// set up gameplay key bindings
	InputComponent->BindAxis(MoveForwardBinding);
	InputComponent->BindAxis(MoveRightBinding);

	InputComponent->BindAction(FireBinding, IE_Pressed, this, &ASeedPlayerController::SetFiringPressed);
	InputComponent->BindAction(FireBinding, IE_Released, this, &ASeedPlayerController::SetFiringReleased);
}

void ASeedPlayerController::RotateTowardsMouse()
{
		FHitResult TraceHitResult;
	if (GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult))
	{
		FVector CursorFV = TraceHitResult.ImpactNormal;
		FRotator CursorR = CursorFV.Rotation();
		FRotator NewLookAtRotation = UKismetMathLibrary::FindLookAtRotation(GetPawn()->GetActorLocation(), TraceHitResult.Location);
		GetPawn()->SetActorRotation(FRotator(0, NewLookAtRotation.Yaw, 0));

		if (IsValid(_spawnedCursor))
		{
			// _spawnedCursor->SetHidden(false);
			_spawnedCursor->SetActorLocation(TraceHitResult.Location);
			_spawnedCursor->SetActorRotation(CursorR);
		}
	}
	else
	{
		if (IsValid(_spawnedCursor))
		{
			// _spawnedCursor->SetHidden(true);
		}
	}
}
	
void ASeedPlayerController::SetFiringPressed()
{
	bIsFiringPressed = true;
}

void ASeedPlayerController::SetFiringReleased()
{
	bIsFiringPressed = false;
}

bool ASeedPlayerController::IsFireInputPressed() const
{
	if (!bIsFiringPressed)
	{
		return false;
	}

	return true;
}

void ASeedPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	
	if (CursorActor)
	{
		_spawnedCursor = GetWorld()->SpawnActor<AActor>(CursorActor);
	}
}
