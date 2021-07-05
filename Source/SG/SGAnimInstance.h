// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SGAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SG_API USGAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	/** custom tick function for our animation */
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);
	
	/** initialize animation override */
	virtual void NativeInitializeAnimation() override;


private:

	/** getting the character */
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Movement,meta=(AllowPrivateAccess= "true"))
	class ASGCharacter* SGCharacter;

	/** The Speed of the character */
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Movement,meta=(AllowPrivateAccess= "true"));
	float Speed;

	/** Is Character in air ? */
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Movement,meta=(AllowPrivateAccess= "true"));
	bool bIsInAir;

	/** Is Character Moving ? */
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Movement,meta=(AllowPrivateAccess= "true"));
	bool bIsAccelerating;
	
};
