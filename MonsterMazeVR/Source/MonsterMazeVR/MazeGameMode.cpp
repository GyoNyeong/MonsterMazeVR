// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGameMode.h"
#include "ExitPortal.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"

AMazeGameMode::AMazeGameMode() : Super()
{
	PrimaryActorTick.bCanEverTick = true;
	TotalSecondsMazeCompletion = 0;
	CurrentLevelIndex = 0;
}

void AMazeGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMazeGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto LevelName = GetWorld()->GetMapName();
	LevelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);
	
	if (LevelName.Contains("TestLoadLevels"))
	{
		StartNextLevel();
		GetWorldTimerManager().SetTimer(MazeCompletionTimerHandle, this, &AMazeGameMode::IncrementMazeCompletionTime, 1.0f, true);
	}
}

void AMazeGameMode::IncrementMazeCompletionTime()
{
	Total
}

void AMazeGameMode::LevelComplete()
{
}

void AMazeGameMode::StartNextLevel()
{
}


