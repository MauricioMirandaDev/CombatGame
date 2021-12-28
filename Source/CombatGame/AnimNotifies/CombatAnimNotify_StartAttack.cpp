
#include "CombatAnimNotify_StartAttack.h"
#include "CombatGame/Characters/CombatCharacter.h"
#include "CombatGame/Characters/CombatEnemy.h"

// Set default values
UCombatAnimNotify_StartAttack::UCombatAnimNotify_StartAttack()
{
	NotifyColor = FColor::Green;
}

// Apply effect to animation
void UCombatAnimNotify_StartAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (Player)
		Player->StartAttack();

	if (Enemy)
		Enemy->StartAttack();
}
