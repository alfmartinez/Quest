// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"

UGoal* UGoal::CreateGoal(const UObject* WorldContext, UGoal* InGoal)
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

void UGoal::Start_Implementation()
{
    OnGoalStarted.Broadcast();
}

void UGoal::Abort_Implementation()
{
    OnGoalAborted.Broadcast();
    Cancel();
}

void UGoal::Fail_Implementation()
{
    OnGoalFailed.Broadcast();
    Cancel();
}

void UGoal::Complete_Implementation()
{
    OnGoalCompleted.Broadcast();
    Cancel();
}

FText UGoal::GetDescription_Implementation() const
{
    return FText();
}

void UGoal::Update()
{
    OnGoalUpdated.Broadcast();
}

void UGoal::Activate()
{
    Start();
}

void UGoal::Cancel()
{
    Super::Cancel();
}