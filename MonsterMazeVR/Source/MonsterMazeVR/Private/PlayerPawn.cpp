// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

    // HMD가 활성화되었는지 확인
    if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
    {
        UE_LOG(LogTemp, Warning, TEXT("Head Mounted Display is enabled!"));

        // 트래킹 원점을 Floor Level로 설정
        UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Floor);

        // 다른 트래킹 원점을 사용하고 싶을 경우
        // UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Eye);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Head Mounted Display is not enabled!"));
    }
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

