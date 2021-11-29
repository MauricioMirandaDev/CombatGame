
#pragma once

#include "CoreMinimal.h"
#include "CombatGame/AnimNotifies/CombatAnimNotify.h"
#include "CombatAnimNotify_StartAttack.generated.h"

UCLASS()
class COMBATGAME_API UCombatAnimNotify_StartAttack : public UCombatAnimNotify
{
	GENERATED_BODY()
	
public:
	UCombatAnimNotify_StartAttack();

protected:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
