// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "GameFramework/Actor.h"
#include "BehaviorTree/BehaviorTree.h"
#include "MonsterAIController.generated.h"



/**
 * 
 */
UCLASS()
class MONSTERBASE_API AMonsterAIController : public AAIController
{
	GENERATED_BODY()
	
	AMonsterAIController();


public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UAIPerceptionComponent> AIPerception;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Default")
	UBehaviorTree* BTMonster;

	virtual void BeginPlay() override;
};
