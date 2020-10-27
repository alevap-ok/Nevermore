// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/N_Item.h"
#include "N_DoorKey.generated.h"

class UStaticMeshComponent;

/**
 * 
 */
UCLASS()
class NEVERMORE_API AN_DoorKey : public AN_Item
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* KeyMeshComponent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Key")
	FName KeyTag;

public:
	AN_DoorKey();

public:
	UFUNCTION(Blueprintcallable, Category = "Getter")
	FName GetKeyTag() const { return KeyTag; };

protected:
	virtual void PickUp(AN_Character* PickupCharacter) override;
};
