
#pragma once

#include "CoreMinimal.h"
#include "CombatGame/AnimNotifies/CombatAnimNotify.h"
#include "CombatAnimNotify_EndAttack.generated.h"

UCLASS()
class COMBATGAME_API UCombatAnimNotify_EndAttack : public UCombatAnimNotify
{
	GENERATED_BODY()

public:
	UCombatAnimNotify_EndAttack();

protected:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
