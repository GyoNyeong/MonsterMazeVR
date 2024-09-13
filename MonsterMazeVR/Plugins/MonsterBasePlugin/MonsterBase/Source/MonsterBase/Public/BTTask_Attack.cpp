// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "AIController.h"
#include "GameFramework/Character.h"




EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APawn* ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();

	ACharacter* Monster = Cast<ACharacter>(ControlledPawn);

	if (Monster)
	{
		//Monster->PlayAnimMontage();    //attack motion anim montage Ãß°¡
	}


	return EBTNodeResult:: Succeeded;
}
