
#include "BTService_SensePlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CombatGame/Controllers/EnemyAIController.h"
#include "CombatGame/Characters/CombatCharacter.h"
#include "CombatGame/Characters/CombatEnemy.h"
#include "Kismet/GameplayStatics.h"

// Set default values
UBTService_SensePlayer::UBTService_SensePlayer()
{
	NodeName = TEXT("Sense Player");
}

// Update next tick
void UBTService_SensePlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ACombatCharacter* Player = Cast<ACombatCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Player == nullptr)
		return;

	ACombatEnemy* Self = Cast<ACombatEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (Self == nullptr)
		return;

	// Update player location if player is wihtin detection radius
	if (FVector::Dist(Player->GetActorLocation(), Self->GetActorLocation()) < Self->DetectionRadius)
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
	else
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
}
