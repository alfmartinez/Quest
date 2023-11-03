// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/CancellableAsyncAction.h"
#include "Goal.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGoalDelegate);

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
	UPROPERTY(BlueprintAssignable)
	FOnGoalDelegate OnGoalStarted;

	UPROPERTY(BlueprintAssignable)
	FOnGoalDelegate OnGoalCompleted;

	UPROPERTY(BlueprintAssignable)
	FOnGoalDelegate OnGoalFailed;

	UPROPERTY(BlueprintAssignable)
	FOnGoalDelegate OnGoalAborted;

	UPROPERTY(BlueprintAssignable)
	FOnGoalDelegate OnGoalUpdated;

	/** The context world of this action. */
    TWeakObjectPtr<UWorld> ContextWorld = nullptr;

	UFUNCTION(BlueprintCallable)
    virtual UWorld* GetWorld() const override
    {
    	return ContextWorld.IsValid() ? ContextWorld.Get() : nullptr;
    }
};
