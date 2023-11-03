// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManagerSubsystem.h"

void UQuestManagerSubsystem::RegisterQuestGoal(UQuestGoal* Goal)
{
	Goals.Add(Goal);
}

void UQuestManagerSubsystem::UnregisterQuestGoal(UQuestGoal* Goal)
{
	Goals.Remove(Goal);
}

TArray<UQuestGoal*> UQuestManagerSubsystem::GetActiveQuests() const
{
	return Goals;
}
