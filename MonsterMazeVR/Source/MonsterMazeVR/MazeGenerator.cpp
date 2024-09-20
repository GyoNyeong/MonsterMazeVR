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
			MazeArray[x][y] = true; // 기본 벽을 설정
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
				SpawnBlock(Wall, Location);
			}
		}
	}
}

// 미로 생성 핵심 함수
void AMazeGenerator::GenerateMaze()
{
	InitializeMazeArray(); // 2차원 배열 초기화

	// DFS 알고리즘, 미로 생성 시작점 1,1
	CarveMazeDFS(1, 1);

	ClearMaze(); // 미로의 벽 생성

	SpawnedPlayerStart = SpawnBlock(PlayerStart, FVector(distance*1.5, distance*1.5, 92.0f));
	UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->SetActorLocation(FVector(distance * 1.5, distance * 1.5, 92.0f));
	SpawnedExitPortal = SpawnBlock(ExitPortal, FVector((SizeX - 2) * distance, (SizeY - 2) * distance, 0.0f));
}

void AMazeGenerator::CarveMazeDFS(int X, int Y)
{
	// 방문할 수 있는 방향 (북, 동, 남, 서)
	TArray<int32> Directions = { 0, 1, 2, 3 };

	// 현재 위치는 통로로 설정
	MazeArray[X][Y] = false;

	for (int32 i = 0; i < 4; i++)
	{
		int RandomDirectionIndex = FMath::RandRange(0, Directions.Num() - 1);  // 0 ~ 3 사이의 무작위 인덱스 선택
		int Direction = Directions[RandomDirectionIndex];  // 무작위 방향 선택

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
		// 새로운 좌표가 미로 범위 안에 있고 아직 방문하지 않은 곳일 경우
		if (NX > 0 && NX < SizeX - 1 && NY > 0 && NY < SizeY - 1 && MazeArray[NX][NY])
		{
			// 두 칸 이동하여 통로를 만들고 중간에 벽을 제거
			MazeArray[NX][NY] = false;
			MazeArray[X + DX / 2][Y + DY / 2] = false;

			// 재귀 호출로 다음 경로를 탐색
			CarveMazeDFS(NX, NY);
		}
	}
}


AActor* AMazeGenerator::SpawnBlock(UClass* BlockType, const FVector Location, const FRotator Rotation)
{
	if (BlockType == nullptr)
	{
		return nullptr;
	}

	// 월드에 새로운 오브젝트 생성
	AActor* NewBlock = GetWorld()->SpawnActor<AActor>(BlockType, Location, Rotation);
	#if WITH_EDITOR
		NewBlock->SetFolderPath("/Maze");
	#endif

	return NewBlock;
}

