// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSeed.h"

// Sets default values
ABaseSeed::ABaseSeed()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}	

// Called when the game starts or when spawned
void ABaseSeed::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseSeed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseSeed::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseSeed::SetHealthToFull()
{
	this->Health = 1;
}

void ABaseSeed::SetHealthToZero()
{
	this->Health = 0;
}

void ABaseSeed::Heal(float Value)
{
}

void ABaseSeed::Damage(ABaseSeed Target, float Value)
{
	
}

void ABaseSeed::SetMoveSpeed(float Value)
{
	this->MoveSpeed = Value;
}



