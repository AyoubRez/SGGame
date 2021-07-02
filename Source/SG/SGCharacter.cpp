// Fill out your copyright notice in the Description page of Project Settings.


#include "SGCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASGCharacter::ASGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//My Code is here .........
	//Create a cameraBoom (pulls in towards the character if there is a collision ) 
	CameraBoom=CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength =300.f;//the camera follows at this distance from the character
	CameraBoom->bUsePawnControlRotation=true;//Rotate the camera based on the controller
	//
	//create a FollowCamera
	FollowCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));//Creating the camera 
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);//attaching the camera to the springArm from the socket called socketName
	FollowCamera->bUsePawnControlRotation=false;//The camera doesnt rotate relative to the springArm
	//To Here............. 

}

// Called when the game starts or when spawned
void ASGCharacter::BeginPlay()
{
	Super::BeginPlay();



	
}
//MoveForward Implementation *************************
void ASGCharacter::MoveForward(float Value)
{
	if(( Controller != nullptr ) && ( Value != 0.f ))
	{
		// find out which way is forward
		const FRotator Rotation { Controller->GetControlRotation() };
		const FRotator YawRotation {0, Rotation.Yaw ,0};


		const FVector Direction { FRotationMatrix{YawRotation}.GetUnitAxis(EAxis::X) };
		AddMovementInput(Direction,Value);
	}
}
//MoveRight Implementation *************************
void ASGCharacter::MoveRight(float Value)
{
	if(( Controller != nullptr ) && ( Value != 0.f ))
	{
		// find out which way is right
		const FRotator Rotation { Controller->GetControlRotation() };
		const FRotator YawRotation {0, Rotation.Yaw ,0};


		const FVector Direction { FRotationMatrix{YawRotation}.GetUnitAxis(EAxis::Y) };
		AddMovementInput(Direction,Value);
	}
}

// Called every frame
void ASGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Check PlayerImputComponent
	check(PlayerInputComponent);
	//Bind Moving Action to functions

	PlayerInputComponent->BindAxis("MoveForward",this,&ASGCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ASGCharacter::MoveRight);
}

