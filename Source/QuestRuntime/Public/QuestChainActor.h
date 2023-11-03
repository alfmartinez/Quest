// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestChainActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQuestChainDelegate);

UCLASS(BlueprintType, Blueprintable)
class QUESTRUNTIME_API AQuestChainActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestChainActor();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Chain Actor")
	void Start();
	virtual void Start_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Chain Actor")
	void Abort();
	virtual void Abort_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Chain Actor")
	void Complete();
	virtual void Complete_Implementation();


public:
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category = "Quest Chain Actor")
	FOnQuestChainDelegate OnQuestChainStarted;

	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category = "Quest Chain Actor")
	FOnQuestChainDelegate OnQuestChainCompleted;

	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category = "Quest Chain Actor")
	FOnQuestChainDelegate OnQuestChainAborted;
};
