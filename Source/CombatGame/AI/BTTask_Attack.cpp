
#include "BTTask_Attack.h"
#include "Animation/AnimMontage.h"
#include "CombatGame/Controllers/EnemyAIController.h"
#include "CombatGame/Characters/CombatEnemy.h"

// Set default values
UBTTask_Attack::UBTTask_Attack()
{
	NodeName = TEXT("Attack");
}

// Starts task, returns succeeded or failed
EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ACombatEnemy* Self = Cast<ACombatEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (Self == nullptr)
		return EBTNodeResult::Failed;

	// Perform desired attack animation
	Self->PlayAnimMontage(Attack, 1.0f, TEXT("None"));

	return EBTNodeResult::Succeeded;
}
