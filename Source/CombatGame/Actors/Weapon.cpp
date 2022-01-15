
#include "Weapon.h"
#include "CombatGame/Characters/CombatEnemy.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set default values
	EnemyClass = nullptr;

	// Create a scene root
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	// Create a SkeletalMesh and set default values
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Create a BoxComponent and set default values
	Hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	Hitbox->SetupAttachment(Mesh);
	Hitbox->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::OnOverlapBegin);
	Hitbox->OnComponentEndOverlap.AddDynamic(this, &AWeapon::OnOverlapEnd);
	Hitbox->SetGenerateOverlapEvents(false);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Set weapon hitbox active or deactive
void AWeapon::SetHitBoxActive(bool bHitboxActive)
{
	Hitbox->SetGenerateOverlapEvents(bHitboxActive);
}

// Declare overlap begin
void AWeapon::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if (IsEnemy(OtherActor))
		{
			Hitbox->SetGenerateOverlapEvents(false);
			UE_LOG(LogTemp, Warning, TEXT("You got a hit in!"));
		}
			
	}
}

// Declare overlap end
void AWeapon::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		
	}
}

// Check if the weapon hits an enemy character
bool AWeapon::IsEnemy(AActor* HitActor)
{
	if (!EnemyClass)
		return false;

	return HitActor->IsA(EnemyClass);
}

