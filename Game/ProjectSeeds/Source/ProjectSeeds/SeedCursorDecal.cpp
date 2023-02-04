// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedCursorDecal.h"
#include "Components/DecalComponent.h"

ASeedCursorDecal::ASeedCursorDecal()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/Material/M_Cursor_Decal.M_Cursor_Decal'"));

	if (DecalMaterialAsset.Succeeded())
	{
		CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}

	CursorToWorld->DecalSize = DecalSize;
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());
}

// Called when the game starts or when spawned
void ASeedCursorDecal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASeedCursorDecal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

