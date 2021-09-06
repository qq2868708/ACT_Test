// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Timer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) ,Blueprintable)
class ACTPLUGINSKILL_API UTimer : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTimer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(VisibleAnywhere)
	float lastTime;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	float time;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	bool reset;
	UFUNCTION(BlueprintCallable)
	void SetLastTime();
};
