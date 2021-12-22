
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_SetPlayerLocation.generated.h"

UCLASS()
class COMBATGAME_API UBTService_SetPlayerLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	// Set default values
	UBTService_SetPlayerLocation();

protected:
	// Update next tick
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
