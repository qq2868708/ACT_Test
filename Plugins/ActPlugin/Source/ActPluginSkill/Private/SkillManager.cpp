// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillManager.h"
#include "SkillComponent.h"

// Sets default values for this component's properties
USkillManager::USkillManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkillManager::BeginPlay()
{
	Super::BeginPlay();

	if(GetOwner()&&GetOwner()->InputComponent)
	{
		GetOwner()->InputComponent->BindAction("Q",EInputEvent::IE_Pressed,this,&USkillManager::CastSKill1);
	}
	
}


// Called every frame
void USkillManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

USkillComponent* USkillManager::AddSkill(TSubclassOf<USkillComponent> skillClass)
{
	UE_LOG(LogTemp,Warning,TEXT("1234"));
	USkillComponent* newSkill=NewObject<USkillComponent>(GetOwner(),skillClass);
	newSkill->RegisterComponent();
	skillArray.Add(newSkill);
	newSkill->OnInit(this);
	return newSkill;
}

void USkillManager::BindSkill(USkillComponent* inBindSkill, USkillComponent*& targetSkill)
{
	if(!inBindSkill)
	{
		return;
	}
	targetSkill=inBindSkill;
}

void USkillManager::CastSkill(USkillComponent* skill)
{
	if(skill)
	{
		skill->OnCast();
	}
}

void USkillManager::BindSkill1(USkillComponent* skill)
{
	BindSkill(skill,skill1);
}

void USkillManager::CastSKill1()
{
	CastSkill(skill1);
}

