
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_ClearBlackboardKey.generated.h"

UCLASS()
class COMBATGAME_API UBTTask_ClearBlackboardKey : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	// Set default values for this task
	UBTTask_ClearBlackboardKey();

protected:
	// Starts task, returns succeeded or failed
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
