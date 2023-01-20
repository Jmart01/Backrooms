// Fill out your copyright notice in the Description page of Project Settings.


#include "M_Player.h"
#include "InputMappingContext.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AM_Player::AM_Player()
{
	PlayerEye = CreateDefaultSubobject<UCameraComponent>("PlayerEye");
	TP_Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("TP_Mesh");
}

void AM_Player::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (Subsystem)
		{
			Subsystem->AddMappingContext(PlayerMappingContext, 0);
		}
	}
}

void AM_Player::Move(const FInputActionValue& Value)
{
	
}

void AM_Player::Look(const FInputActionValue& Value)
{
}

void AM_Player::InitializeAttributes()
{
	if (GAS && DefaultAttributeEffect)
	{
		FGameplayEffectContextHandle EffectContext = GAS->MakeEffectContext();
		EffectContext.AddSourceObject(this);
		FGameplayEffectSpecHandle SpecHandle = GAS->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);
		if (SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle GEHandle = GAS->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}

void AM_Player::GiveAbilities()
{
	if (GAS)
	{
		for (TSubclassOf<UBaseAbility>& StartupAbility : DefaultAbilities)
		{
			GAS->GiveAbility(FGameplayAbilitySpec(StartupAbility, 1, static_cast<int32>(StartupAbility.GetDefaultObject()->AbilityInputID), this));
		}
	}
}

void AM_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AM_Player::Move);
	}
}


