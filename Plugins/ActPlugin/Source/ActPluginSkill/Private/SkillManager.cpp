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
	
}


// Called every frame
void USkillManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

USkillComponent* USkillManager::AddSkill(TSubclassOf<USkillComponent> skillClass)
{
	USkillComponent* newSkill=NewObject<USkillComponent>(GetOwner(),skillClass);
	newSkill->RegisterComponent();
	skillArray.Add(newSkill);
	newSkill->OnInit(this);
	return newSkill;
}


void USkillManager::SetCurrentSkillComponent(int index)
{
	currentSkillComponent=skillArray[index];
}
