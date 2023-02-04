// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSeed.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSEEDS_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilityComponent();

protected:
	
	void BindAbilities();
	void ActivateAbility();
	void ResetPoints();

	// Action Points
	virtual bool CanSpendActionPoints(int Value);
	virtual void UpgradeMaxActionPoints(int Value);

	UPROPERTY(EditAnywhere)
	int MaxActionPoints;
	
	UPROPERTY(EditAnywhere)
	int ActionPoints;

	UPROPERTY()
	APlayerController* PlayerController;
	
	UPROPERTY()
	ABaseSeed* Owner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AProjectSeedsProjectile> SelectedAbility;

	//Expose list of abilites in editor, add bIsUnlocked in BaseAbility and check against
	// UPROPERTY()
	// TArray<ABaseAbility*> OwnedAbilities;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	static const FName ActivateBinding;

	
};
