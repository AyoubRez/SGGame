// Fill out your copyright notice in the Description page of Project Settings.


#include "SGAnimInstance.h"
#include "SGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void USGAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	/** each frame we check if the character is a null pointer */
	if(SGCharacter==nullptr)
	{
		/** we cast to the SGCharacter when it's a null pointer */
		SGCharacter=Cast<ASGCharacter>( TryGetPawnOwner());
	}

	/** we double check if SGCharacter is set */
	if(SGCharacter)
	{
		//Get the "Lateral" speed of the character from velocity
		FVector Velocity{ SGCharacter->GetVelocity() };
		
		/** we Zero out the Z component to get the lateral velocity */
		Velocity.Z=0;
		
		/** the Speed is The size of the Latreral Velocity */
		Speed=Velocity.Size();

		//Is the character in the air ?
		bIsInAir = SGCharacter->GetCharacterMovement()->IsFalling();

		//Is The Character accelerating ? (true if character current acceleration is 0 ) 
		if(SGCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size()>0.f)
		{
			bIsAccelerating=true;
		}
		else
		{
			bIsAccelerating=false;
		}
	}
}

void USGAnimInstance::NativeInitializeAnimation()
{
	//initialize the SGCharacter when anim instance is run  
	SGCharacter=Cast<ASGCharacter>( TryGetPawnOwner());
}
