// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_CalculateDistance.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERBASE_API UBTTask_CalculateDistance : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	FVector MonsterLocation;

	int AttackRange = 0;

};
