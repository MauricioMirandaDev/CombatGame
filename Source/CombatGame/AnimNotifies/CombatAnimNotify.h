
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "CombatAnimNotify.generated.h"

class ACombatCharacter;
class ACombatEnemy;

UCLASS()
class COMBATGAME_API UCombatAnimNotify : public UAnimNotify
{
	GENERATED_BODY()

protected:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	ACombatCharacter* Player;

	ACombatEnemy* Enemy;
};
