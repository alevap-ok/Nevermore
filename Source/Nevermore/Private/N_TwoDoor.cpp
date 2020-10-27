// Fill out your copyright notice in the Description page of Project Settings.


#include "N_TwoDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "N_Character.h"

// Sets default values
AN_TwoDoor::AN_TwoDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));
	RootComponent = CustomRootComponent;

	DoorWayComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorWay"));
	DoorWayComponent->SetupAttachment(CustomRootComponent);

	DoorRightComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorWayRight"));
	DoorRightComponent->SetupAttachment(DoorWayComponent);

	DoorLeftComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorWayLeft"));
	DoorLeftComponent->SetupAttachment(DoorWayComponent);

	KeysZoneColliderComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("KeyZoneCollider"));
	KeysZoneColliderComponent->SetupAttachment(CustomRootComponent);
	KeysZoneColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	KeysZoneColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	KeysZoneColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	OpenAngle = 90.0f;
	DoorTag = "KeyA";
}

// Called when the game starts or when spawned
void AN_TwoDoor::BeginPlay()
{
	Super::BeginPlay();
	KeysZoneColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &AN_TwoDoor::CheckKeyFromPlayer);
}

void AN_TwoDoor::CheckKeyFromPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (bIsOpen)
	{
		return;
	}

	if (IsValid(OtherActor))
	{
		AN_Character* OberlappedCharacter = Cast<AN_Character>(OtherActor);
		if (IsValid(OberlappedCharacter))
		{
			if (OberlappedCharacter->HasKey(DoorTag))
			{
				OpenDoor();
			}
		}
	}
}

// Called every frame
void AN_TwoDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AN_TwoDoor::OpenDoor()
{
	bIsOpen = true;
	BP_OpenDoor();
}