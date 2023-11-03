// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"

UQuestGoal* UQuestGoal::CreateGoal(const UObject* WorldContext, UQuestGoal* InGoal)
{

    UWorld* ContextWorld = GEngine->GetWorldFromContextObject(WorldContext, EGetWorldErrorMode::ReturnNull);
    if(!ensureAlwaysMsgf(IsValid(WorldContext), TEXT("World Context was not valid.")))
    {
    	return nullptr;
    }

    InGoal->ContextWorld = ContextWorld;
    InGoal->RegisterWithGameInstance(ContextWorld->GetGameInstance());
    return InGoal;
}

void UQuestGoal::Start_Implementation()
{
    OnGoalStarted.Broadcast();
}

void UQuestGoal::Abort_Implementation()
{
    OnGoalAborted.Broadcast();
    Cancel();
}

void UQuestGoal::Fail_Implementation()
{
    OnGoalFailed.Broadcast();
    Cancel();
}

void UQuestGoal::Complete_Implementation()
{
    OnGoalCompleted.Broadcast();
    Cancel();
}

FText UQuestGoal::GetDescription_Implementation() const
{
    return FText();
}

void UQuestGoal::Update()
{
    OnGoalUpdated.Broadcast();
}

void UQuestGoal::Activate()
{
    Start();
}

void UQuestGoal::Cancel()
{
    Super::Cancel();
}