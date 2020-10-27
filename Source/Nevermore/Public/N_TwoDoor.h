// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "N_TwoDoor.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class NEVERMORE_API AN_TwoDoor : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* CustomRootComponent;

	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* DoorWayComponent;

	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* DoorRightComponent;

	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* DoorLeftComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* KeysZoneColliderComponent;



protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DoorAngle")
	float OpenAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Door")
	bool bIsOpen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Door")
	FName DoorTag;
	
public:	
	// Sets default values for this actor's properties
	AN_TwoDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void CheckKeyFromPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "My Door")
	void BP_OpenDoor();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void OpenDoor();

};
