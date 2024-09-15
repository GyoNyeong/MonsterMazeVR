// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGenerator.h"

const int MazeSizeMax = 101;

// Sets default values
AMazeGenerator::AMazeGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SizeX = 5;
	SizeY = 5;
	RegenerateMaze = false;
}

// 에디터에서 RegenerateMaze 속성이 변경될 때 호출.
void AMazeGenerator::PostEditChangeProperty(struct FPropertyChangedEvent& e)
{
	Super::PostEditChangeProperty(e);

	// 변경된 Property 이름을 얻음. 
	FName PropertyName = (e.Property != NULL) ? e.Property->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(AMazeGenerator, RegenerateMaze))
	{
		RegenerateMaze = false;
		GenerateMaze(SizeX, SizeY);
	}
}

// Called when the game starts or when spawned
void AMazeGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMazeGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMazeGenerator::GenerateMaze(const int TileX, const int TileY)
{
	// 미로 크기 처리 : 미로 크기가 짝수이면 오류, 미로 크기가 홀수 크기에서만 생성.
	if (TileX % 2 == 0 || TileY % 2 == 0)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Only odd number allowed for Maze size X and Y"));
		}
		return;
	}

	// 
	if (Ground == nullptr || Wall == nullptr)
	{
		return;
	}
}

AActor* AMazeGenerator::SpawnBlock(UClass* BlockType, FVector Locatiom, FRotator Rotation)
{
	return nullptr;
}

void AMazeGenerator::ReplaceBlock(UClass* NewBlock, int MazeX, int MAzeY)
{
}

