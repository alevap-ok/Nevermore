// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "N_Item.generated.h"

class USphereComponent;
class AN_Character;

UCLASS()
class NEVERMORE_API AN_Item : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* MainColliderComponent;

	
public:	
	// Sets default values for this actor's properties
	AN_Item();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PickUp(AN_Character* PickupCharacter);

	UFUNCTION(BluePrintImplementableEvent, BlueprintCallable, Category = "Item")
	void BP_Pickup(AN_Character* PickupCharacter);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
