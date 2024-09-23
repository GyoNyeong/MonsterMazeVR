// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterBaseCharacter.h"

// Sets default values
AMonsterBaseCharacter::AMonsterBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	AController* MonsterController = GetWorld()->SpawnActor<AController>(AIControllerClass, GetActorLocation(), GetActorRotation());
	if (MonsterController == nullptr)
	{
		return;
	}

	PossessedBy(MonsterController);
}

// Called every frame
void AMonsterBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMonsterBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

