
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CombatEnemy.generated.h"

class AWeapon; 

UCLASS()
class COMBATGAME_API ACombatEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACombatEnemy();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Functions for attack effects
	void StartAttack();

	void EndAttack();

	void SetWeaponActive(bool bWeaponActive);

	// Max distance the enemy can detect the player
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Behavior")
	float DetectionRadius;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Functions, variables, and components for combat
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AWeapon> WeaponClass;

	UPROPERTY(BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	AWeapon* Weapon;
};
