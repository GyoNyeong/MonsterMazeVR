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
	TSubclassOf<AActor> Monster;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Maze Properites")
	TSubclassOf<AActor> PlayerGunWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Maze Properites")
	TSubclassOf<AActor> Bullet;

	UFUNCTION(BlueprintCallable, Category = "MazeGen")
	void GenerateMaze();

	// Sets default values for this actor's properties
	AMazeGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 2���� �迭�� �̷� ������ ���
	TArray<TArray<bool>> MazeArray; // true : ��, false : ���

	// Player start and exit portal references
	AActor* SpawnedPlayerStart;
	AActor* SpawnedExitPortal;
	AActor* SpawnedMonster;
	AActor* SpawnedPlayerGunWeapon;
	AActor* SpawnedBullet;
	
	// DFS �˰����� ����Ͽ� �̷θ� �����ϴ� �Լ�
	void CarveMazeDFS(int X, int Y);

	// Helper functions
	void InitializeMazeArray();
	void ClearMaze();
	AActor* SpawnManager (UClass* BlockType, FVector Location, FRotator Rotation = FRotator(0, 0, 0));
};
