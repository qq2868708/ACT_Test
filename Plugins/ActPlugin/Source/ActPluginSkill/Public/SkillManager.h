// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillComponent.h"
#include "Components/ActorComponent.h"
#include "SkillManager.generated.h"

class SkillComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class ACTPLUGINSKILL_API USkillManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	TArray<USkillComponent*> skillArray;
	UFUNCTION(BlueprintCallable)
	virtual USkillComponent* AddSkill(TSubclassOf<USkillComponent> skillClass);

	UFUNCTION(BlueprintCallable)
	void SetCurrentSkillComponent(int index);

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	USkillComponent* currentSkillComponent;
};
