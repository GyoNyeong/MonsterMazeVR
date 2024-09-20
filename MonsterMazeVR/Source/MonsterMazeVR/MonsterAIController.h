// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "MonsterAIController.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERMAZEVR_API AMonsterAIController : public AAIController
{
	GENERATED_BODY()
	AMonsterAIController();
	
public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UAIPerceptionComponent> AIPerception;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Default")
	UBehaviorTree* BTMonster;


	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<UBlackboardComponent> BBMonster;


	virtual void BeginPlay() override;

	UFUNCTION()
	void OnTargetDetected(AActor* actor, FAIStimulus const Stimuls);

};
