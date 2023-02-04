// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectSeedsPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

static TAutoConsoleVariable<bool> CVarGodMode(
	TEXT("c.PlayerGodMode"),
	false,
	TEXT("Enable or disable player GodMode"),
	ECVF_Cheat);

AProjectSeedsPawn::AProjectSeedsPawn()
{
	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm
	// Movement
	MoveSpeed = 1000.0f;
	SeedFaction = ESeedFaction::FactionPlayer;
}
bool AProjectSeedsPawn::ShouldTakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) const
{
	return !CVarGodMode.GetValueOnAnyThread();
}
