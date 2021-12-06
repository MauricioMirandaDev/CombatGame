
#include "CombatAnimNotify_CloseNextAttack.h"
#include "CombatGame/Characters/CombatCharacter.h"

// Set default values
UCombatAnimNotify_CloseNextAttack::UCombatAnimNotify_CloseNextAttack()
{
	NotifyColor = FColor::Orange;
}

// Close opportunity for next attack
void UCombatAnimNotify_CloseNextAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (Player)
		Player->CloseNextAttack();
}
