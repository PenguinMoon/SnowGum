// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ThirdPersonController.generated.h"

UCLASS()
class SNOWGUM_API AThirdPersonController : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThirdPersonController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(EditAnywhere)
	float RotationRate = 10;

	UPROPERTY(VisibleAnywhere)
	bool IsAiming = false;

	/**
	 * Binds to the "MoveForward" input axis to receive the axis value and multiplies it by
	 * the character's forward vector.
	 * This value is then given to the function AddCharacterInput();
	 * @param value 
	 */
	void MoveForward(float value);

	/**
	 * Binds to the "MoveRight" input axis to receive the axis value and multiplies it by
	 * the character's right vector.
	 * This value is then given to the function AddCharacterInput();
	 * @param value 
	 */
	void MoveRight(float value);

	/**
	 * Binds to the "LookUpRate" input axis to receive the axis value.
	 * @param rate 
	 */
	void LookUpRate(float rate);

	/**
	 * Binds to the "LookRightRate" input axis to receive the axis value.
	 * @param rate 
	 */
	void LookRightRate(float rate);

	void Attack();

	void AimBow();

	void ReleaseAim();
	
};
