// Fill out your copyright notice in the Description page of Project Settings.

#include "UraniumSkies.h"
#include "CharacterBaseClass.h"


// Sets default values
ACharacterBaseClass::ACharacterBaseClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterBaseClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterBaseClass::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ACharacterBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterBaseClass::JumpPressed);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacterBaseClass::JumpReleased);
	InputComponent->BindAxis("MoveXAxis", this, &ACharacterBaseClass::MoveX);
	InputComponent->BindAxis("MoveYAxis", this, &ACharacterBaseClass::MoveY);
	InputComponent->BindAxis("Turn", this, &ACharacterBaseClass::AddControllerYawInput);
	InputComponent->BindAxis("Lookup", this, &ACharacterBaseClass::AddControllerPitchInput);
}

void ACharacterBaseClass::JumpPressed()
{
	ACharacter::Jump();
}
void ACharacterBaseClass::JumpReleased()
{
	ACharacter::StopJumping();
}
void ACharacterBaseClass::MoveX(float xScale)
{
	if ((Controller != NULL) && (xScale != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, xScale);
	}
}
void ACharacterBaseClass::MoveY(float yScale)
{
	if ((Controller != NULL) && (yScale != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, yScale);
	}
}