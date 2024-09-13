// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "MonsterState.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERBASE_API UMonsterState : public UUserDefinedEnum
{
	GENERATED_BODY()
	
};

UENUM()
enum class EMonsterState
{
	Stand UMETA(DisplayName = "Stand"),
	Chase UMETA(DisplayName = "Chase"),
	Attack UMETA(DisplayName = "Attack"),
	Die UMETA(DisplayName = "Die")
};