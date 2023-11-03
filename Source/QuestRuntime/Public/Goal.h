// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/CancellableAsyncAction.h"
#include "Goal.generated.h"



UENUM(BlueprintType)
enum class EQuestStatus : uint8
{
	PENDING			UMETA(DisplayName = "Pending"),
	STARTED			UMETA(DisplayName = "Started"),
	COMPLETED		UMETA(DisplayName = "Completed"),
	ABORTED			UMETA(DisplayName = "Aborted"),
	FAILED			UMETA(DisplayName = "Failed")
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGoalDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGoalUpdated, EQuestStatus, Status);

/**
 * 
 */
UCLASS(Blueprintable)
class QUESTRUNTIME_API UQuestGoal : public UCancellableAsyncAction
{

public:
    
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, DisplayName="Start Goal", meta=(WorldContext="WorldContext", BlueprintInternalUseOnly="true"))
	static UQuestGoal* CreateGoal(const UObject* WorldContext, UQuestGoal* InGoal);


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Start();
	virtual void Start_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Complete();
	virtual void Complete_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Abort();
	virtual void Abort_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Fail();
	virtual void Fail_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FText GetDescription() const;
	virtual FText GetDescription_Implementation() const;

	UFUNCTION(BlueprintCallable)
	void Update();

	virtual void Activate() override;
	virtual void Cancel() override;


public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Quest Chain", meta = (ExposeOnSpawn = "true"))
	FText QuestChainTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Goal")
	EQuestStatus Status = EQuestStatus::PENDING;

public:
	UPROPERTY(BlueprintAssignable)
	FOnGoalDelegate OnGoalStarted;

	UPROPERTY(BlueprintAssignable)
	FOnGoalDelegate OnGoalCompleted;

	UPROPERTY(BlueprintAssignable)
	FOnGoalDelegate OnGoalFailed;

	UPROPERTY(BlueprintAssignable)
	FOnGoalDelegate OnGoalAborted;

	UPROPERTY(BlueprintAssignable)
	FOnGoalUpdated OnGoalUpdated;

	/** The context world of this action. */
    TWeakObjectPtr<UWorld> ContextWorld = nullptr;

	UFUNCTION(BlueprintCallable)
    virtual UWorld* GetWorld() const override
    {
    	return ContextWorld.IsValid() ? ContextWorld.Get() : nullptr;
    }
};
