
#include "CombatAnimNotify_ForwardThrust.h"
#include "CombatGame/Characters/CombatCharacter.h"

// Set default values
UCombatAnimNotify_ForwardThrust::UCombatAnimNotify_ForwardThrust()
{
	NotifyColor = FColor::Cyan;
}

// Apply effect to animation
void UCombatAnimNotify_ForwardThrust::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (Player)
		Player->ForwardThrust();
}
