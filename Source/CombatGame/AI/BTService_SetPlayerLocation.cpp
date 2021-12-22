
#include "BTService_SetPlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CombatGame/Controllers/EnemyAIController.h"
#include "CombatGame/Characters/CombatCharacter.h"
#include "CombatGame/Characters/CombatEnemy.h"
#include "Kismet/GameplayStatics.h"

UBTService_SetPlayerLocation::UBTService_SetPlayerLocation()
{

}

void UBTService_SetPlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ACombatCharacter* Player = Cast<ACombatCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Player == nullptr)
		return;

	ACombatEnemy* Self = Cast<ACombatEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (Self == nullptr)
		return;

	if (FVector::Dist(Player->GetActorLocation(), Self->GetActorLocation()) <= 500.0f)
	{
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
	}
	else
	{
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}
