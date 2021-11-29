
#pragma once

#include "CoreMinimal.h"
#include "CombatGame/AnimNotifies/CombatAnimNotify.h"
#include "CombatAnimNotify_ForwardThrust.generated.h"

UCLASS()
class COMBATGAME_API UCombatAnimNotify_ForwardThrust : public UCombatAnimNotify
{
	GENERATED_BODY()
	
public:
	UCombatAnimNotify_ForwardThrust();

protected:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
