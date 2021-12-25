
#include "CombatEnemy.h"

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

