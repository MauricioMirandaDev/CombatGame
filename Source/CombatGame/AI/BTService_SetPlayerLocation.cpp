
#include "BTService_SetPlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CombatGame/Controllers/EnemyAIController.h"
#include "CombatGame/Characters/CombatCharacter.h"
#include "CombatGame/Characters/CombatEnemy.h"
#include "Kismet/GameplayStatics.h"

// Set default values
UBTService_SetPlayerLocation::UBTService_SetPlayerLocation()
{
	NodeName = ("Set Player Location");
}

// Update next tick
void UBTService_SetPlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ACombatCharacter* Player = Cast<ACombatCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Player == nullptr)
		return;

	ACombatEnemy* Self = Cast<ACombatEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (Self == nullptr)
		return;

	// Find dot product between player's location and enemy's forward vector
	FVector Difference = Player->GetActorLocation() - Self->GetActorLocation(), Forward = Self->GetActorForwardVector();
	Difference.Normalize();
	Forward.Normalize();

	float DotProd = FVector::DotProduct(Difference, Forward);

	// Update player location if player is in front of enemy
	if (DotProd > 0 && FVector::Dist(Self->GetActorLocation(), Player->GetActorLocation()) < Self->DetectionRadius && OwnerComp.GetAIOwner()->LineOfSightTo(Player))
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
	else
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
}
