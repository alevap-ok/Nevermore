// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "N_TwoDoor.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class NEVERMORE_API AN_TwoDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AN_TwoDoor();

	UPROPERTY(visibleAnywhere, Category = "Components")
	USceneComponent* CustomRootComponent;

	UPROPERTY(visibleAnywhere, Category = "Components")
	UStaticMeshComponent* DoorWayComponent;

	UPROPERTY(visibleAnywhere, Category = "Components")
	UStaticMeshComponent* DoorRightComponent;

	UPROPERTY(visibleAnywhere, Category = "Components")
	UStaticMeshComponent* DoorLeftComponent;

	UPROPERTY(EditAnywhere, Category = "DoorAngle")
	float OpenAngle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void OpenDoor();
};
