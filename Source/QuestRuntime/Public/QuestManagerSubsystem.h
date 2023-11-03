// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Goal.h"
#include "QuestManagerSubsystem.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestGoalRegistered, UQuestGoal*, QuestGoal);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestChainFlushed, FText, QuestChainTitle);


/**
 * 
 */
UCLASS()
class QUESTRUNTIME_API UQuestManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quest Manager Subsystem")
	void RegisterQuestGoal(UQuestGoal* Goal);

	UFUNCTION(BlueprintCallable, Category = "Quest Manager Subsystem")
	void UnregisterQuestGoal(UQuestGoal* Goal);

	UFUNCTION(BlueprintCallable, Category = "Quest Manager Subsystem")
	void FlushQuestChain(const FText QuestChainTitle);

	UFUNCTION(BlueprintCallable, Category = "Quest Manager Subsystem")
	TArray<UQuestGoal*> GetActiveQuests() const;

private:
	TArray<UQuestGoal*> Goals;

public:
	UPROPERTY(BlueprintAssignable)
	FOnQuestGoalRegistered OnQuestGoalRegistered;

	UPROPERTY(BlueprintAssignable)
	FOnQuestChainFlushed OnQuestChainFlushed;
};
