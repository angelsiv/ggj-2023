// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAbility.h"

// Sets default values
ABaseAbility::ABaseAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilityCooldown = 5.0f;
	AbilityCost = 1;

}


