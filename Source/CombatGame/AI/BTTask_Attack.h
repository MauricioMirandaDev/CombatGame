
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Attack.generated.h"

class UAnimMontage;

UCLASS()
class COMBATGAME_API UBTTask_Attack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	// Set default values for this task

	// NOTE: Re-parent to not inherit from blackboard base
	UBTTask_Attack();

protected:
	// Starts task, returns succeeded or failed
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	// The attack to perform
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* Attack;
};
