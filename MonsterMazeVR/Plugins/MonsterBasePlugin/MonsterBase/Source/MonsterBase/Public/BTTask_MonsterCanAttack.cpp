// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_MonsterCanAttack.h"
#include "AIController.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "MonsterState.h"


EBTNodeResult::Type UBTTask_MonsterCanAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	OwnerComp.GetBlackboardComponent()->SetValueAsEnum((TEXT("MonsterState")), (uint8)EMonsterState::Attack);

	return EBTNodeResult::Succeeded;
}
