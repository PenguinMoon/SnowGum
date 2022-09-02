// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonController.h"

// Sets default values
AThirdPersonController::AThirdPersonController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AThirdPersonController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThirdPersonController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AThirdPersonController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Axis Input
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AThirdPersonController::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AThirdPersonController::MoveRight);
	
	//For controller input
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AThirdPersonController::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &AThirdPersonController::LookRightRate);
	
	//For mouse input
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	
	//Action Input
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AThirdPersonController::Attack);
}

#pragma region InputBindings

void AThirdPersonController::MoveForward(float value){
	AddMovementInput(GetActorForwardVector() * value);
	
}

void AThirdPersonController::MoveRight(float value){
	AddMovementInput(GetActorRightVector() * value);
}

void AThirdPersonController::LookUpRate(float rate){
	AddControllerPitchInput(rate * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AThirdPersonController::LookRightRate(float rate){
	AddControllerYawInput(rate * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AThirdPersonController::Attack(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Attack"));
}

#pragma endregion InputBindings

