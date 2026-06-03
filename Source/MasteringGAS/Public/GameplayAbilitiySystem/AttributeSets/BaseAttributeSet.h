// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "BaseAttributeSet.generated.h"

UCLASS()
class MASTERINGGAS_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UBaseAttributeSet();

	// Health Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeSet, MaxHealth);
	
	// Stamina Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing=OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeSet, Stamina);
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing=OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeSet, MaxStamina);

public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	UFUNCTION()
	void OnRep_Health(FGameplayAttributeData& OldValue) const
	{ GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeSet, Health, OldValue); }

	UFUNCTION()
	void OnRep_MaxHealth(FGameplayAttributeData& OldValue) const
	{ GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeSet, MaxHealth, OldValue); }

	UFUNCTION()
	void OnRep_Stamina(FGameplayAttributeData& OldValue) const
	{ GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeSet, Stamina, OldValue); }

	UFUNCTION()
	void OnRep_MaxStamina(FGameplayAttributeData& OldValue) const
	{ GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeSet, MaxStamina, OldValue); }
};
