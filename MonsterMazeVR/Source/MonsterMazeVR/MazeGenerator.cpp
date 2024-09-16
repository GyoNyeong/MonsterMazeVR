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

// �����Ϳ��� RegenerateMaze �Ӽ��� ����� �� ȣ��.
void AMazeGenerator::PostEditChangeProperty(struct FPropertyChangedEvent& e)
{
	Super::PostEditChangeProperty(e);

	// ����� Property �̸��� ����. 
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
	// �̷� ũ�� ó�� : �̷� ũ�Ⱑ ¦���̸� ����, �̷� ũ�Ⱑ Ȧ�� ũ�⿡���� ����.
	if (TileX % 2 == 0 || TileY % 2 == 0)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Only odd number allowed for Maze size X and Y"));
		}
		return;
	}

	// �� Wall �� �ٴ� Ground �� �������� �ʾ��� �� �Լ� ����
	if (Ground == nullptr || Wall == nullptr)
	{
		return;
	}

	// ���� �ʱ�ȭ
	float CaptureX = 0.0f;
	float CpatureY = 0.0f;
	const float Offset = 350.0f;

	// ���� PlayerStart �� ExitPortal ����
	if (SpawnedPlayerStart != nullptr)
	{
		SpawnedPlayerStart->Destroy();
	}
	if (SpawnedExitPortal != nullptr)
	{
		SpawnedExitPortal->Destroy();
	}

	// �̷� �ʱ�ȭ
	MazeGrid.Clear();
	MazeGrid.AddUninitialized(TileX, TileY);

	// �̷��� �⺻ ���� ����
	for (int x = 0; x < TileX; x++)
	{
		for (int y = 0; y < TileY; y++)
		{
			const FVector Location(CaptureX, CpatureY, 0.0f);
			if (y == 0 || x == 0 || y == TileY - 1 || x == TileX - 1 || y % 2 == 0 && x % 2 == 0)
			{
				MazeGrid.Rows[x].Columns[y] = SpawnBlock(Wall, Location);
			}
		}
	}
}

AActor* AMazeGenerator::SpawnBlock(UClass* BlockType, FVector Locatiom, FRotator Rotation)
{
	return nullptr;
}

void AMazeGenerator::ReplaceBlock(UClass* NewBlock, int MazeX, int MAzeY)
{
}

