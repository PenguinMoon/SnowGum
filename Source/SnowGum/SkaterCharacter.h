// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SkaterCharacter.generated.h"

UCLASS()
class SNOWGUM_API ASkaterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASkaterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Binds to the forward axis
	void MoveForward(float value);

	// Binds to the right axis
	void MoveRight(float value);

	/* Zooms camera in and out based on the value given.
		Binds to the Zoom axis.*/
	void ZoomCamera(float value);

	void RotateCamera(float value);

	float ZoomMultiplier;
};
