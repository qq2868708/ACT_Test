// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_Skill.h"
#include "SkillManager.h"
#include  "SkillComponent.h"

void UAnimNotify_Skill::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	if(!MeshComp)
	{
		return;
	}
	TInlineComponentArray<USkillManager*> components(MeshComp->GetOwner());
	for(auto* a :components)
	{
		USkillComponent* skillComponent=a->currentSkillComponent;
		if(!skillComponent)
		{
			return;
		}
		UFunction* func=skillComponent->FindFunction(functionName);
		if(func)
		{
			skillComponent->ProcessEvent(func,nullptr);
		}
	}
}
