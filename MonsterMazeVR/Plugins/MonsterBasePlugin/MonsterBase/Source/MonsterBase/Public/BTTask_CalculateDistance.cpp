// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CalculateDistance.h"
#include "AIController.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "MonsterState.h"



EBTNodeResult::Type UBTTask_CalculateDistance::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{


	APawn* ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();

	MonsterLocation = ControlledPawn->GetActorLocation();

	if (nullptr == ControlledPawn) return EBTNodeResult::Failed;

	AActor* TargetActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TEXT("TargetActor")));

	if (TargetActor == nullptr) return EBTNodeResult::Failed;

	AttackRange = OwnerComp.GetBlackboardComponent()->GetValueAsInt(TEXT("AttackRange"));
	if (AttackRange == 0) return EBTNodeResult::Failed;

	EMonsterState State = (EMonsterState)OwnerComp.GetBlackboardComponent()->GetValueAsEnum((TEXT("MonsterState")));
	if (State == EMonsterState::Chase)
	{
		if (TargetActor)
		{
			if (MonsterLocation.Distance(MonsterLocation, TargetActor->GetActorLocation()) <= AttackRange)
			{
				return EBTNodeResult::Succeeded;
			}
		}
	}

	else if (State == EMonsterState::Attack)
	{
		if (MonsterLocation.Distance(MonsterLocation, TargetActor->GetActorLocation()) >= AttackRange)
		{
			return EBTNodeResult::Failed;
		}
		else
		{
			EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;

}
