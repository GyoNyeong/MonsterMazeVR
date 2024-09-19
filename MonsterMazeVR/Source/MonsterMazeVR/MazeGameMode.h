// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MazeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERMAZEVR_API AMazeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMazeGameMode();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = Levels)
	TArray<TSubclassOf<AActor>> Levels;

protected:
	virtual void BeginPlay() override;

private:
	AActor* CurrentLevel;

	FTimerHandle MazeCompletionTimerHandle;

	int32 TotalSecondsMazeCompletion;

	int32 CurrentLevelIndex;

	void IncrementMazeCompletionTime();

	UFUNCTION()
	void LevelComplete();

	void StartNextLevel();
	
};
