#include "SwordAbilityTypes.h"
#include "AbilitySystemGlobals.h"
#include "ProjectSword/Abilities/SwordAbilitySystemComponent.h"

bool FSwordGameplayEffectContainerSpec::HasValidEffects() const
{
	return TargetGameplayEffectSpecs.Num() > 0;
}

bool FSwordGameplayEffectContainerSpec::HasValidTargets() const
{
	return TargetData.Num() > 0;
}

void FSwordGameplayEffectContainerSpec::AddTargets(const TArray<FGameplayAbilityTargetDataHandle>& InTargetData, const TArray<FHitResult>& HitResults, const TArray<AActor*> TargetActors)
{
	for (const FGameplayAbilityTargetDataHandle& TD : InTargetData)
	{
		TargetData.Append(TD);
	}

	for (const FHitResult& HitResult : HitResults)
	{
		FGameplayAbilityTargetData_SingleTargetHit* NewData = new FGameplayAbilityTargetData_SingleTargetHit(HitResult);
		TargetData.Add(NewData);
	}

	if (TargetActors.Num() > 0)
	{
		FGameplayAbilityTargetData_ActorArray* NewData = new FGameplayAbilityTargetData_ActorArray();
		NewData->TargetActorArray.Append(TargetActors);
		TargetData.Add(NewData);
	}
}

void FSwordGameplayEffectContainerSpec::ClearTargets()
{
	TargetData.Clear();
}