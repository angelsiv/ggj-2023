// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSeedAI.h"

// Sets default values
ABaseSeedAI::ABaseSeedAI()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SeedFaction = ESeedFaction::FactionEnemy;
}

// Called when the game starts or when spawned
void ABaseSeedAI::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseSeedAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
