
#include "CombatEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACombatEnemy::ACombatEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set default values for this enemy type
	DetectionRadius = 100.0f;
}

// Called when the game starts or when spawned
void ACombatEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACombatEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Modify variables at the start of the attack
void ACombatEnemy::StartAttack()
{
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
}

// Modify variables at the end of the attack
void ACombatEnemy::EndAttack()
{
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
}

