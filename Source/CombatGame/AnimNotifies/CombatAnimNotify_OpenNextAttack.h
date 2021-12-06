
#pragma once

#include "CoreMinimal.h"
#include "CombatGame/AnimNotifies/CombatAnimNotify.h"
#include "CombatAnimNotify_OpenNextAttack.generated.h"

UCLASS()
class COMBATGAME_API UCombatAnimNotify_OpenNextAttack : public UCombatAnimNotify
{
	GENERATED_BODY()
	
public:
	UCombatAnimNotify_OpenNextAttack();

protected:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
