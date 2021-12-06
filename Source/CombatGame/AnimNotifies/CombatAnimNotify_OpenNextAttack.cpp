
#include "CombatAnimNotify_OpenNextAttack.h"
#include "CombatGame/Characters/CombatCharacter.h"

// Set default values
UCombatAnimNotify_OpenNextAttack::UCombatAnimNotify_OpenNextAttack()
{
	NotifyColor = FColor::Blue;
}

// Open opportunity for next attack
void UCombatAnimNotify_OpenNextAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (Player)
		Player->OpenNextAttack();
}
