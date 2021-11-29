
#include "CombatAnimNotify_EndAttack.h"
#include "CombatGame/Characters/CombatCharacter.h"

// Set default values
UCombatAnimNotify_EndAttack::UCombatAnimNotify_EndAttack()
{
	NotifyColor = FColor::Red;
}

// Apply effect to animation
void UCombatAnimNotify_EndAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (Player)
		Player->EndAttack();
}
