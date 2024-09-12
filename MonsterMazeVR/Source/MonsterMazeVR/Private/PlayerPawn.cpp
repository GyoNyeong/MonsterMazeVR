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

    // HMD�� Ȱ��ȭ�Ǿ����� Ȯ��
    if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
    {
        UE_LOG(LogTemp, Warning, TEXT("Head Mounted Display is enabled!"));

        // Ʈ��ŷ ������ Floor Level�� ����
        UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Floor);

        // �ٸ� Ʈ��ŷ ������ ����ϰ� ���� ���
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

