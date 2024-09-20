// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAIController.h"
#include "MonsterState.h"
#include "BehaviorTree/BlackboardComponent.h"


AMonsterAIController::AMonsterAIController()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	BBMonster = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BBMonster"));
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AMonsterAIController::OnTargetDetected);
}

void AMonsterAIController::BeginPlay()
{
	RunBehaviorTree(BTMonster);
}

void AMonsterAIController::OnTargetDetected(AActor* actor, FAIStimulus const Stimuls)
{
	if (Stimuls.IsActive())
	{
		// ������ Actor�� �÷��̾����� Ȯ��
		if (APawn* PlayerPawn = Cast<APawn>(actor))
		{

			// BlackBoard�� TargetActor Ű�� �÷��̾� ����
			GetBlackboardComponent()->SetValueAsObject("TargetActor", PlayerPawn);
			UE_LOG(LogTemp, Display, TEXT("%s"), *PlayerPawn->GetName());

			GetBlackboardComponent()->SetValueAsEnum("MonsterState", (uint8)(EMonsterState::Chase));
		}
	}
	else
	{
		// �÷��̾ �þ߿��� ����� TargetActor ���� ����
		GetBlackboardComponent()->ClearValue("TargetActor");
		GetBlackboardComponent()->SetValueAsEnum("MonsterState", (uint8)(EMonsterState::Stand));
	}
}
