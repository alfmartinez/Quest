// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestChainActor.h"
#include "QuestManagerSubsystem.h"

// Sets default values
AQuestChainActor::AQuestChainActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AQuestChainActor::Start_Implementation()
{
	OnQuestChainStarted.Broadcast();
}

void AQuestChainActor::Abort_Implementation()
{
	OnQuestChainAborted.Broadcast();
}

void AQuestChainActor::Complete_Implementation()
{
	OnQuestChainCompleted.Broadcast();

	UGameInstance* GameInstance = GetGameInstance();
	UQuestManagerSubsystem* QuestManager = GameInstance->GetSubsystem<UQuestManagerSubsystem>();
	QuestManager->FlushQuestChain(QuestChainTitle);
}

