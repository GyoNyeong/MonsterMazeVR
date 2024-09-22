// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGenerator.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"

const int MazeSizeMax = 101;
const float distance = 350.0f;

// Sets default values
AMazeGenerator::AMazeGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SizeX = 5;
	SizeY = 5;
}


// Called when the game starts or when spawned
void AMazeGenerator::BeginPlay()
{
	Super::BeginPlay();
	GenerateMaze();
}

void AMazeGenerator::InitializeMazeArray()
{
	MazeArray.SetNum(SizeX);
	for (int32 x = 0; x < SizeX; x++)
	{
		MazeArray[x].SetNum(SizeY);
		for (int32 y = 0; y < SizeY; y++)
		{
			MazeArray[x][y] = true; // �⺻ ���� ����
		}
	}
}

void AMazeGenerator::ClearMaze()
{
	for (int32 x = 0; x < SizeX; x++)
	{
		for (int32 y = 0; y < SizeY; y++)
		{
			if (MazeArray[x][y])
			{
				FVector Location = FVector(x * distance, y * distance, 170.0f);
				SpawnManager(Wall, Location);
			}
		}
	}
}

// �̷� ���� �ٽ� �Լ�
void AMazeGenerator::GenerateMaze()
{
	InitializeMazeArray(); // 2���� �迭 �ʱ�ȭ

	// DFS �˰���, �̷� ���� ������ 1,1
	CarveMazeDFS(1, 1);

	ClearMaze(); // �̷��� �� ����

	// PlayerStart ����
	FVector PlayerStartLocation = FVector(distance * 1.5, distance * 1.5, 92.0f);
	SpawnedPlayerStart = SpawnManager(PlayerStart, PlayerStartLocation);
	UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->SetActorLocation(FVector(distance * 1.5, distance * 1.5, 92.0f));

	// ExitPortal ����
	SpawnedExitPortal = SpawnManager(ExitPortal, FVector((SizeX - 2) * distance + 175.0f, (SizeY - 2) * distance + 175.0f, 92.0f));

	// PlayerWeapon �� PlayerStart �� �ٷ� �� ĭ�� ����
	// PlayerStart ��ó�� ��θ� Ȯ���� ��, PlayerGunWeapon ����
	FVector PlayerForwardDirection = FVector(distance, 0.0f, 0.0f);
	FVector GunSpawnLocation = PlayerStartLocation + PlayerForwardDirection;

	// GunSpawnLocation �� ���� �ƴ� ������� Ȯ��
	int32 GridX = FMath::FloorToInt(GunSpawnLocation.X / distance);
	int32 GridY = FMath::FloorToInt(GunSpawnLocation.Y / distance);

	if (GridX > 0 && GridX < SizeX && GridY > 0 && GridY < SizeY && !MazeArray[GridX][GridY])
	{
		SpawnedPlayerGunWeapon = SpawnManager(PlayerGunWeapon, GunSpawnLocation);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Gun cannot be spawned at the location because it is a wall"));
	}

	// �̷��� ����� false �ΰ��� ã�� ����
	TArray<FVector> EmptyLocation;

	for (int32 x = 1; x < SizeX - 1; x++)
	{
		for (int32 y = 1; y < SizeY - 1; y++)
		{
			if (!MazeArray[x][y])
			{
				EmptyLocation.Add(FVector(x * distance + 175.0f, y * distance + 175.0f, 92.0f));
			}
		}
	}

	for (int MonsterSpawnCnt = 0; MonsterSpawnCnt < 5; MonsterSpawnCnt++)
	{
		if (EmptyLocation.Num() > 0)
		{
			int32 RandomIndex = FMath::RandRange(0, EmptyLocation.Num() - 1);
			FVector SpawnLoction = EmptyLocation[RandomIndex];

			// ���� ����
			SpawnedMonster = SpawnManager(Monster, SpawnLoction);

			// ���õ� ��ġ�� �ٽ� ������� �ʵ��� ��Ͽ��� ����
			EmptyLocation.RemoveAt(RandomIndex);

		}
	}

	for (int BulletSpawnCnt = 0; BulletSpawnCnt < 5; BulletSpawnCnt++)
	{
		if (EmptyLocation.Num() > 0)
		{
			int32 RandomIndex = FMath::RandRange(0, EmptyLocation.Num() - 1);
			FVector BulletSpawnLocation = EmptyLocation[RandomIndex];

			// �Ѿ� ����
			SpawnedBullet = SpawnManager(Bullet, BulletSpawnLocation);

			// ���õ� ��ġ�� �ٽ� ������� �ʵ��� ��Ͽ��� ����
			EmptyLocation.RemoveAt(RandomIndex);
		}
	}
}

void AMazeGenerator::CarveMazeDFS(int X, int Y)
{
	// �湮�� �� �ִ� ���� (��, ��, ��, ��)
	TArray<int32> Directions = { 0, 1, 2, 3 };

	// ���� ��ġ�� ��η� ����
	MazeArray[X][Y] = false;

	for (int32 i = 0; i < 4; i++)
	{
		int RandomDirectionIndex = FMath::RandRange(0, Directions.Num() - 1);  // 0 ~ 3 ������ ������ �ε��� ����
		int Direction = Directions[RandomDirectionIndex];  // ������ ���� ����

		int DX = 0;
		int DY = 0;
		if (i == 0)
		{
			if (Direction == 0)
			{
				Direction = 1;
			}
			if (Direction == 3)
			{
				Direction = 2;
			}
		}
		switch (Direction)
		{
		case 0: DX = -2;
			break;
		case 1: DX = 2;
			break;
		case 2: DY = 2;
			break;
		case 3: DY = -2;
			break;
		default:
			break;
		}

		int NX = X + DX;
		int NY = Y + DY;
		// ���ο� ��ǥ�� �̷� ���� �ȿ� �ְ� ���� �湮���� ���� ���� ���
		if (NX > 0 && NX < SizeX - 1 && NY > 0 && NY < SizeY - 1 && MazeArray[NX][NY])
		{
			// �� ĭ �̵��Ͽ� ��θ� ����� �߰��� ���� ����
			MazeArray[NX][NY] = false;
			MazeArray[X + DX / 2][Y + DY / 2] = false;

			// ��� ȣ��� ���� ��θ� Ž��
			CarveMazeDFS(NX, NY);
		}
	}
}


AActor* AMazeGenerator::SpawnManager(UClass* BlockType, const FVector Location, const FRotator Rotation)
{
	if (BlockType == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Blocktype is nullptr in SpawnManager!"));
		return nullptr;
	}

	// ���忡 ���ο� ������Ʈ ����
	AActor* NewBlock = GetWorld()->SpawnActor<AActor>(BlockType, Location, Rotation);
	if (NewBlock == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to spawn actor at location: %s"), *Location.ToString());
		return nullptr;
	}

	// ���Ͱ� �ƴ� ��쿡�� ���� ��� ����
	if (BlockType != Monster)
	{
		#if WITH_EDITOR
		NewBlock->SetFolderPath("/Maze");
		#endif
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Skipping folder path for Monster"));
	}


	return NewBlock;
}

