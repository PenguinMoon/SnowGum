// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Arrow.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class SNOWGUM_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief Aims the bow.
	 */
	void StartAiming();

	/**
	 * @brief Stops aiming the bow.
	 */
	void StopAiming();

	/**
	 * @brief Draws the bow back.
	 * This will start the bow draw timer.
	 */
	void Draw();

	/**
	 * @brief Fires the bow.
	 */
	void Fire();

private:

	UPROPERTY(EditAnywhere, Category = "Bow")
	/**
	 * @brief The accuracy of the bow over draw time between 0 and 1.
	 */
	FRuntimeFloatCurve accuracyOverTime;

	UPROPERTY(EditAnywhere, Category = "Bow")
	/**
	 * @brief The force of the bow over draw time between 0 and 1
	 */
	FRuntimeFloatCurve forceOverTime;

	UPROPERTY(EditAnywhere, Category = "Bow")
	/**
	 * @brief The maximun level of accuracy of the bow.
	 * How much the shot will vary in millimeters per meter.
	 * This will be sued to calculate a random direction the arrow will fire in.
	 */
	float maxAccuracy;

	UPROPERTY(EditAnywhere, Category = "Bow")
	/**
	 * @brief The maximum level of force of the bow.
	 * This will determine how far an arrow goes and how hard it hits.
	 */
	float maxPower;

	/**
	 * @brief The amount of time the bow has been drawn for in seconds.
	 */
	float drawTime;

	/**
	 * @brief The current arrow kind the bow is firing.
	 * 
	 */
	AArrow currentAmmo;

	bool isAiming;

	/**
	 * @brief 
	 * 
	 * @return float 
	 */
	float CalculateAccuracy();

	/**
	 * @brief 
	 * 
	 * @return float 
	 */
	float CalculateForce();
};
