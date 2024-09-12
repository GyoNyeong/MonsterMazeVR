// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/ObjectPtr.h"
#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"


UCLASS()
class MONSTERMAZEVR_API APlayerPawn : public APawn
{
	GENERATED_BODY()

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<USceneComponent> VROrigin;


	///** Please add a variable description */
	//UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	//TObjectPtr<UB_MannequinsXR_C> HandRight;

	///** Please add a variable description */
	//UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	//TObjectPtr<UB_MannequinsXR_C> HandLeft;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UMotionControllerComponent> MotionControllerRightGrip;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UMotionControllerComponent> MotionControllerLeftGrip;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UCameraComponent> Camera;

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
