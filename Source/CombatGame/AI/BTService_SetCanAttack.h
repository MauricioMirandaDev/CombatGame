
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_SetCanAttack.generated.h"

UCLASS()
class COMBATGAME_API UBTService_SetCanAttack : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	// Set default values for this service
	UBTService_SetCanAttack();

protected:
	// Update next tick
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
