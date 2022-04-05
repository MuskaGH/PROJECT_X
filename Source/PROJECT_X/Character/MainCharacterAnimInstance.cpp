// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacterAnimInstance.h"

#include "MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMainCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	MainCharacter = Cast<AMainCharacter>(TryGetPawnOwner());
}

void UMainCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (MainCharacter == nullptr)
	{
		MainCharacter = Cast<AMainCharacter>(TryGetPawnOwner());
	}

	if (MainCharacter == nullptr)
		return;

	FVector Velocity = MainCharacter->GetVelocity();
	Velocity.Z = 0.0;
	Speed = Velocity.Size();

	bIsInAir = MainCharacter->GetCharacterMovement()->IsFalling();

	bIsAccelerating = MainCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.0f ? true : false;
}
