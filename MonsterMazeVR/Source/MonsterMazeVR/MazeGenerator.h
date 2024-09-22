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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Maze Properites")
	TSubclassOf<AActor> PlayerGunWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Maze Properites")
	TSubclassOf<AActor> WarriorMonster;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Maze Properites")
	TSubclassOf<AActor> MageMonster;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Maze Properites")
	TSubclassOf<AActor> Bullet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Maze Properites")
	TSubclassOf<AActor> HealthPotion;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Maze Properites")
	TSubclassOf<AActor> Trap;

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
	// 해당 스폰한 위치를 수정해야할 때 사용하는 변수
	AActor* SpawnedPlayerStart;
	AActor* SpawnedExitPortal;
	AActor* SpawnedPlayerGunWeapon;

	
	// DFS 알고리즘을 사용하여 미로를 생성하는 함수
	void CarveMazeDFS(int X, int Y);

	// Helper functions
	void InitializeMazeArray();
	void ClearMaze();
	AActor* SpawnManager (UClass* BlockType, FVector Location, FRotator Rotation = FRotator(0, 0, 0));
	
	void SpawnActors(UClass* ActorType, int32 SpawnCount, TArray<FVector>& EmptyLocation);
};
