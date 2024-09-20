// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeGenerator.generated.h"


UCLASS()
class MONSTERMAZEVR_API AMazeGenerator : public AActor
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Maze Properites")
	int SizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Maze Properites")
	int SizeY;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Maze Properites")
	TSubclassOf<AActor> Wall;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Maze Properites")
	TSubclassOf<AActor> ExitPortal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Maze Properites")
	TSubclassOf<AActor> PlayerStart;

	UFUNCTION(BlueprintCallable, Category = "MazeGen")
	void GenerateMaze();

	// Sets default values for this actor's properties
	AMazeGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 2차원 배열을 미로 구조로 사용
	TArray<TArray<bool>> MazeArray; // true : 벽, false : 통로

	// Player start and exit portal references
	AActor* SpawnedPlayerStart;
	AActor* SpawnedExitPortal;
	
	// DFS 알고리즘을 사용하여 미로를 생성하는 함수
	void CarveMazeDFS(int X, int Y);

	// Helper functions
	void InitializeMazeArray();
	void ClearMaze();
	AActor* SpawnBlock(UClass* BlockType, FVector Location, FRotator Rotation = FRotator(0, 0, 0));
};
