
#include "CombatAnimNotify.h"
#include "CombatGame/Characters/CombatCharacter.h"

// Obtain a pointer to the player
void UCombatAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp != nullptr && Animation != nullptr)
	{
		if (MeshComp->GetOwner()->IsA(ACombatCharacter::StaticClass()))
		{
			Player = Cast<ACombatCharacter>(MeshComp->GetOwner());
		}
	}
}

