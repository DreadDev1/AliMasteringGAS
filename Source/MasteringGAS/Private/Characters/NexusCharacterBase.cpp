// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NexusCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ANexusCharacterBase::ANexusCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set Collision Capsule Size
	GetCapsuleComponent()->InitCapsuleSize(35.f, 90.0f);
	
#pragma region AbilitySystemComponent & AttributeSet Initialization
	//Add Ability System Component
	NexusASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("NexusASC"));
	NexusASC->SetIsReplicated(true);
	NexusASC->SetReplicationMode(ASCReplicationMode);

	// Add BaseAttributeSet
	BaseAttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("BaseAttributeSet"));
#pragma endregion
	
#pragma region Character Rotation and Movement Settings
	//Disable rotation when the Controller rotates
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	// Configure Character Movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking= 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;
#pragma endregion
}
	
void ANexusCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ANexusCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (NexusASC) { NexusASC->InitAbilityActorInfo(this, this); }
}

void ANexusCharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	if (NexusASC) { NexusASC->InitAbilityActorInfo(this, this); }
}


void ANexusCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANexusCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* ANexusCharacterBase::GetAbilitySystemComponent() const
{
	return NexusASC;
}

