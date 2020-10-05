// Fill out your copyright notice in the Description page of Project Settings.


#include "N_TwoDoor.h"
#include "Components/StaticMeshComponent.h"

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

	OpenAngle = 90.0f;
}

// Called when the game starts or when spawned
void AN_TwoDoor::BeginPlay()
{
	Super::BeginPlay();
	OpenDoor();
}

// Called every frame
void AN_TwoDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AN_TwoDoor::OpenDoor()
{
	FRotator NewRotationR = FRotator(0, OpenAngle, 0);
	FRotator NewRotationL = FRotator(0, OpenAngle * -1, 0);
	DoorRightComponent->SetRelativeRotation(NewRotationR);
	DoorLeftComponent->SetRelativeRotation(NewRotationL);
}