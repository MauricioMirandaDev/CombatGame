
#pragma once

#include "CoreMinimal.h"
#include "CombatGame/AnimNotifies/CombatAnimNotify.h"
#include "CombatAnimNotify_CloseNextAttack.generated.h"

UCLASS()
class COMBATGAME_API UCombatAnimNotify_CloseNextAttack : public UCombatAnimNotify
{
	GENERATED_BODY()

public:
	UCombatAnimNotify_CloseNextAttack();

protected:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
