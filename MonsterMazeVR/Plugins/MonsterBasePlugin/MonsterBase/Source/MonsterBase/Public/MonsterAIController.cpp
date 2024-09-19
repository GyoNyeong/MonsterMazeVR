// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MonsterState.h"

AMonsterAIController::AMonsterAIController()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AMonsterAIController::OnTargetDetected);
}s

void AMonsterAIController::BeginPlay()
{
	RunBehaviorTree(BTMonster);
}

void AMonsterAIController::OnTargetDetected(AActor* actor, FAIStimulus const Stimuls)
{
	if (Stimuls.IsActive())
	{
		
		// 감지된 Actor가 플레이어인지 확인
		if (APawn* PlayerPawn = Cast<APawn>(actor))
		{
			// BlackBoard에 TargetActor 키로 플레이어 설정
			GetBlackboardComponent()->SetValueAsObject("TargetActor", PlayerPawn);
			GetBlackboardComponent()->SetValueAsEnum("MonsterState", (uint8)(EMonsterState::Chase));
		}
	}
	else
	{
		// 플레이어가 시야에서 벗어나면 TargetActor 값을 지움
		GetBlackboardComponent()->ClearValue("TargetActor");
		GetBlackboardComponent()->SetValueAsEnum("MonsterState", (uint8)(EMonsterState::Stand));
	}
}

