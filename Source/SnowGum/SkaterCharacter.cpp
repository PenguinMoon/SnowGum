// Fill out your copyright notice in the Description page of Project Settings.

#include "SkaterCharacter.h"

// Sets default values
ASkaterCharacter::ASkaterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASkaterCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASkaterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASkaterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ASkaterCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASkaterCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookRight", this, &APawn::AddControllerYawInput);
}

#pragma region InputBindings

// Binds to the forward axis
void ASkaterCharacter::MoveForward(float value){
	AddMovementInput(GetActorForwardVector() * value);
}

/* Binds to the "MoveRight" axis.
*/
void ASkaterCharacter::MoveRight(float value){
	AddMovementInput(GetActorRightVector() * value);
}

/* Zooms camera in and out based on the value given.
	Binds to the Zoom axis.*/
void ASkaterCharacter::ZoomCamera(float value){
	/* TODO: Implement camrea zooming in and out.
		For this we will need to first setup the camera varaible.
	*/
}

#pragma endregion InputBindings