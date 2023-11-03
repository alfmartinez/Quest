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
	for (UQuestGoal* Goal : Goals)
	{
		if (QuestChainTitle.IdenticalTo(Goal->GetChainTitle()))
		{
			UnregisterQuestGoal(Goal);
		}
	}
	OnQuestChainFlushed.Broadcast(QuestChainTitle);
}

TArray<UQuestGoal*> UQuestManagerSubsystem::GetActiveQuests() const
{
	return Goals;
}
