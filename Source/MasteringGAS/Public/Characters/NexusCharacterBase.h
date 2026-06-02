// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "NexusCharacterBase.generated.h"

UCLASS()
class MASTERINGGAS_API ANexusCharacterBase : public ACharacter, public IAbilitySystemInterface  
{
	GENERATED_BODY()

public:
	ANexusCharacterBase();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NexusASC")
	UAbilitySystemComponent* NexusASC;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NexusASC")
	EGameplayEffectReplicationMode ASCReplicationMode = EGameplayEffectReplicationMode::Mixed;

protected:
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
};
