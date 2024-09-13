// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterBaseCharacter.generated.h"

UCLASS()
class MONSTERBASE_API AMonsterBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonsterBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	int MonsterLife = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	float RespawnTime = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	UAnimMontage* AttackMontage;



};
