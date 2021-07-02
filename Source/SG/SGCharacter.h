// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SGCharacter.generated.h"

UCLASS()
class SG_API ASGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASGCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Move Forward/Backward function
	void MoveForward(float Value);

	//Move Right/Left function
	void MoveRight(float Value);

	/**Turn rate function
	*Called via input to turn at a given rate
	*@param Rate this is a normalized rate , i.e. 1.0 means 100% of desired rate
	**/
	void TurnAtRate(float Rate);

	/**Turn rate function
	*Called via input to look up / down  at a given rate
	*@param Rate this is a normalized rate , i.e. 1.0 means 100% of desired rate
	**/
	void LookUpAtRate(float Rate);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//My section in code 
private:
	/** CameraBoom positioning the camera behind the character  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= Camera , meta=(AllowPrivateAccess="true"))
	class  USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* FollowCamera;

	//Base turn rate , in deg/sec . Other scaling may affect final turn rate . 
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Camera, meta=(AllowPrivateAccess="true"))
	float BaseTurnRate;

	//Base lookUp/down rate , in deg/sec . Other scaling may affect final lookUp rate . 
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Camera, meta=(AllowPrivateAccess="true"))
	float BaseLookUpRate;

public:
	/** Return cameraBoom subobject */
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Return FollowCamera subobject */
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
