// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilitiySystem/AttributeSets/BaseAttributeSet.h"

#include "Net/UnrealNetwork.h"

UBaseAttributeSet::UBaseAttributeSet()
{
	Health = 100;
	MaxHealth = 100;
	Stamina = 100;
	MaxStamina = 100;
}

void UBaseAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
}
