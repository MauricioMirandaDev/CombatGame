
#include "CombatAnimNotify_SetWeaponHitbox.h"
#include "CombatGame/Characters/CombatCharacter.h"
#include "CombatGame/Characters/CombatEnemy.h"

// Set default values
UCombatAnimNotify_SetWeaponHitbox::UCombatAnimNotify_SetWeaponHitbox()
{
	NotifyColor = FColor::Magenta;
	bActivateWeaponHitbox = false;
}

// Apply effect to animation
void UCombatAnimNotify_SetWeaponHitbox::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (Player)
		Player->SetWeaponActive(bActivateWeaponHitbox);

	if (Enemy)
		Enemy->SetWeaponActive(bActivateWeaponHitbox);
}
