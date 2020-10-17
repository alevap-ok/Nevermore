// Fill out your copyright notice in the Description page of Project Settings.


#include "N_Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AN_Character::AN_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FPSCameraSocketName = "SCK_Camera";
	MaxWalkSpeed = 250.f;
	MaxRunSpeed = 500.f;

	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPS_CameraComponent"));
	FPSCameraComponent->bUsePawnControlRotation = true;
	FPSCameraComponent->SetupAttachment(GetMesh(), FPSCameraSocketName);

	GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
}

// Called when the game starts or when spawned
void AN_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AN_Character::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void AN_Character::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}

void AN_Character::Running()
{
	GetCharacterMovement()->MaxWalkSpeed = MaxRunSpeed;
}

void AN_Character::StopRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
}

void AN_Character::Jump()
{
	Super::Jump();
}

void AN_Character::StopJumping()
{
	Super::StopJumping();
}

void AN_Character::AddControllerPitchInput(float value)
{
	Super::AddControllerPitchInput(bIsLookInversion ? -value : value);
}


// Called every frame
void AN_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AN_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AN_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AN_Character::MoveRight);


	PlayerInputComponent->BindAxis("LookUp", this, &AN_Character::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &ACharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AN_Character::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AN_Character::StopJumping);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AN_Character::Running);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AN_Character::StopRunning);
}

