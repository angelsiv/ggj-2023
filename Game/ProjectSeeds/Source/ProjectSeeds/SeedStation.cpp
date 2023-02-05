// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedStation.h"

#include "ProjectSeedsPawn.h"
#include "SeedPlayerController.h"
#include "SeedStationText.h"
#include "Components/BoxComponent.h"
#include "Components/TextBlock.h"


// Sets default values
ASeedStation::ASeedStation()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneRootComponent;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetCollisionProfileName("SeedStation");
	StaticMeshComponent->SetupAttachment(RootComponent);

	const ConstructorHelpers::FObjectFinder<UStaticMesh> CubeFinder(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"), LOAD_Quiet | LOAD_NoWarn);
	StaticMeshComponent->SetStaticMesh(CubeFinder.Object);
	StaticMeshComponent->SetWorldScale3D({1.0f, 1.0f, 0.2f});

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("SphereCollider"));
	BoxComponent->SetCollisionProfileName("SeedStation");
	BoxComponent->SetupAttachment(RootComponent);
	BoxComponent->SetWorldScale3D({1.5f, 1.5f, 1.0f});

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(RootComponent);
	WidgetComponent->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
}

void ASeedStation::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (BoxComponent)
	{
		BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ASeedStation::OnBoxBeginOverlap);
		BoxComponent->OnComponentEndOverlap.AddDynamic(this, &ASeedStation::OnBoxEndOverlap);
	}
}

// Called when the game starts or when spawned
void ASeedStation::BeginPlay()
{
	Super::BeginPlay();

	if (const auto* SeedText = Cast<USeedStationText>(WidgetComponent->GetWidget()))
	{
		if (IsValid(SeedText->TheTextBlock))
		{
			SeedText->TheTextBlock->SetText(FText::FromString(FString::Printf(TEXT("%s : C[%i], V[%s]"), *Text, CurrencyCost, *FString::SanitizeFloat(UpgradeAmount))));
		}
	}
}

// Called every frame
void ASeedStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASeedStation::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AProjectSeedsPawn>(OtherActor) && CanStationAction())
	{
		FTimerManager& timerManager = GetWorld()->GetTimerManager();
		timerManager.ClearTimer(TimerHandle);

		FTimerDelegate timerDelegate;
		timerDelegate.BindUObject(this, &ASeedStation::StationAction);

		timerManager.SetTimer(TimerHandle, timerDelegate, DelayUpgradeTime, false);
	}
}

void ASeedStation::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<AProjectSeedsPawn>(OtherActor))
	{
		FTimerManager& timerManager = GetWorld()->GetTimerManager();
		timerManager.ClearTimer(TimerHandle);
	}
}
bool ASeedStation::CanStationAction()
{
	if (const auto* seedPC = ASeedPlayerController::GetInstance(this))
	{
		return seedPC->HasEnoughCurrency(CurrencyCost);
	}

	return false;
}

void ASeedStation::StationAction()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Purple, FString::Printf(TEXT("[%s] STATION ACTION"), *GetName()));
}
