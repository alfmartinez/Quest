// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManagerSubsystem.h"

void UQuestManagerSubsystem::RegisterQuestGoal(UQuestGoal* Goal)
{
	Goals.Add(Goal);
	OnQuestGoalRegistered.Broadcast(Goal);
}

void UQuestManagerSubsystem::UnregisterQuestGoal(UQuestGoal* Goal)
{
	Goals.Remove(Goal);
}

void UQuestManagerSubsystem::FlushQuestChain(const FText QuestChainTitle)
{
	Goals.RemoveAll([&](UQuestGoal* Goal) {
		return QuestChainTitle.IdenticalTo(Goal->GetChainTitle());
	});
	OnQuestChainFlushed.Broadcast(QuestChainTitle);
}

TArray<UQuestGoal*> UQuestManagerSubsystem::GetActiveQuests() const
{
	return Goals;
}
