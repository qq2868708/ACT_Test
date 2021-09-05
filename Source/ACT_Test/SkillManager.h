// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillManager.generated.h"

class USkillComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class ACT_TEST_API USkillManager : public UActorComponent
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

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	TArray<USkillComponent*> SkillArray;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	USkillComponent* NowAnimSkill;

	UFUNCTION(BlueprintCallable)
	virtual USkillComponent* AddSkill(TSubclassOf<USkillComponent> SkillClass);

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill(USkillComponent*InBindSkill,USkillComponent* &TargetSkill);

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill(USkillComponent* Skill);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkillComponent* Skill1;

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill1(USkillComponent* Skill) ;

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill1() ;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkillComponent* Skill2;

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill2(USkillComponent* Skill) ;

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill2() ;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkillComponent* Skill3;

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill3(USkillComponent* Skill) ;

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill3() ;
};
