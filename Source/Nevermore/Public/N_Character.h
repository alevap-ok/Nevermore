// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "N_Character.generated.h"

class UCameraComponent;

UCLASS()
class NEVERMORE_API AN_Character : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* FPSCameraComponent;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aiming")
	bool bIsLookInversion;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aiming")
	FName FPSCameraSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float MaxWalkSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float MaxRunSpeed;

public:
	// Sets default values for this character's properties
	AN_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);

	void MoveRight(float value);

	virtual void Running();

	virtual void StopRunning();

	virtual void Jump() override;

	virtual void StopJumping() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void AddControllerPitchInput(float value) override;

};
