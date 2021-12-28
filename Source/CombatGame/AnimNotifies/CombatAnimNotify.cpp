
#include "CombatAnimNotify.h"
#include "CombatGame/Characters/CombatCharacter.h"
#include "CombatGame/Characters/CombatEnemy.h"

// Obtain a pointer to the player
void UCombatAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp != nullptr && Animation != nullptr)
	{
		if (MeshComp->GetOwner()->IsA(ACombatCharacter::StaticClass()))
			Player = Cast<ACombatCharacter>(MeshComp->GetOwner());
		else if (MeshComp->GetOwner()->IsA(ACombatEnemy::StaticClass()))
			Enemy = Cast<ACombatEnemy>(MeshComp->GetOwner());
	}
}

