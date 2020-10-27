// Fill out your copyright notice in the Description page of Project Settings.


#include "N_DoorKey.h"
#include "Components/StaticMeshComponent.h"
#include "N_Character.h"

AN_DoorKey::AN_DoorKey()
{
	KeyMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyMeshComponent"));
	KeyMeshComponent->SetupAttachment(RootComponent);
	KeyMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	KeyTag = "KeyA";
}

void AN_DoorKey::PickUp(AN_Character* PickupCharacter)
{
	Super::PickUp(PickupCharacter);
	PickupCharacter->AddKey(KeyTag);
	Destroy();
}