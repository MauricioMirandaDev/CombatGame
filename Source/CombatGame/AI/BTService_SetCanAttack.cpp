
#include "BTService_SetCanAttack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CombatGame/Controllers/EnemyAIController.h"
#include "CombatGame/Characters/CombatCharacter.h"
#include "CombatGame/Characters/CombatEnemy.h"
#include "Kismet/GameplayStatics.h"

// Set default values
UBTService_SetCanAttack::UBTService_SetCanAttack()
{
	NodeName = ("Set Can Attack");
}

// Update next tick
void UBTService_SetCanAttack::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ACombatCharacter* Player = Cast<ACombatCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Player == nullptr)
		return;

	ACombatEnemy* Self = Cast<ACombatEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (Self == nullptr)
		return;

	// Allow the enemy to attack if the player is in attack range
	if (FVector::Dist(Player->GetActorLocation(), Self->GetActorLocation()) < 100.0f)
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true);
	else
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
}
