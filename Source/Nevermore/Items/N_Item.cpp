// Fill out your copyright notice in the Description page of Project Settings.


#include "N_Item.h"
#include "N_Character.h"
#include "Components/SphereComponent.h"

// Sets default values
AN_Item::AN_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainColliderComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MainColliderComponent"));
	MainColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MainColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	RootComponent = MainColliderComponent;
}

// Called when the game starts or when spawned
void AN_Item::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AN_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AN_Item::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (IsValid(OtherActor))
	{
		AN_Character* OverlappedCharacter = Cast<AN_Character>(OtherActor);
		if (IsValid(OverlappedCharacter))
		{
			PickUp(OverlappedCharacter);
		}
	}

	
}

void AN_Item::PickUp(AN_Character* PickupCharacter)
{
	BP_Pickup(PickupCharacter);
}