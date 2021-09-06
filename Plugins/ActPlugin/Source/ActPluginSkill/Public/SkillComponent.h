// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillComponent.generated.h"

class USkillManager;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class ACTPLUGINSKILL_API USkillComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void OnInit(USkillManager * manager);
	UFUNCTION(BlueprintCallable)
	virtual void OnCast();
	UFUNCTION(BlueprintImplementableEvent)
	void OnCastImp();
	UFUNCTION(BlueprintCallable)
	void PlayAnimation();

public:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	USkillManager * manager;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UAnimMontage* skillMontage;
};
