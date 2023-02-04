// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectSeedsGameMode.h"
#include "ProjectSeedsPawn.h"

AProjectSeedsGameMode::AProjectSeedsGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AProjectSeedsPawn::StaticClass();
}

