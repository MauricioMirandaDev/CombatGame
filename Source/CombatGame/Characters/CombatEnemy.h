
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CombatEnemy.generated.h"

UCLASS()
class COMBATGAME_API ACombatEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACombatEnemy();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Max distance the enemy can detect the player
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Behavior")
	float DetectionRadius;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

};
