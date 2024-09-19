// Fill out your copyright notice in the Description page of Project Settings.


#include "ExitPortal.h"
#include "Components/BoxComponent.h"

// Sets default values
AExitPortal::AExitPortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto OverlapComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	OverlapComponent->SetBoxExtent(FVector(75, 75, 50));
	RootComponent = OverlapComponent;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetupAttachment(RootComponent);

	OverlapComponent->OnComponentBeginOverlap.AddDynamic(this, &AExitPortal::OnPortalBeginOverlap);
}

// Called when the game starts or when spawned
void AExitPortal::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExitPortal::OnPortalBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Detected with %s"), *OtherActor->GetName());
	LevelComplete.Broadcast();
}

// Called every frame
void AExitPortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

