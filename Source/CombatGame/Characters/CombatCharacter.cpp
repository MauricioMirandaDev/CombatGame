
#include "CombatCharacter.h"
#include "Animation/AnimMontage.h"
#include "Camera/CameraComponent.h"
#include "CombatGame/Actors/Weapon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACombatCharacter::ACombatCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set default values
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	bCanJump = true;
	AttackCount = 0;
	bCanAttack = true;
	ForwardThrustMultiplier = 1.0f;

	// Set default values for CharacterMovement
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// Create a SpringArm and set default values
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bVisualizeComponent = false;
	SpringArm->bHiddenInGame = true;

	// Create a Camera and set default values
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->ProjectionMode = ECameraProjectionMode::Perspective;
}

// Called when the game starts or when spawned
void ACombatCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Spawn a weapon in the world and set the player as its owner
	if (WeaponClass)
	{
		Weapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass);
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
		Weapon->SetOwner(this);
	}
}

// Called every frame
void ACombatCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACombatCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Movement
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACombatCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACombatCharacter::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACombatCharacter::Jump);

	// Combat
	PlayerInputComponent->BindAction(TEXT("LightAttack"), EInputEvent::IE_Pressed, this, &ACombatCharacter::LightAttackPressed);
}

// Modify variables at the start of the attack
void ACombatCharacter::StartAttack()
{
	bCanJump = false;
	bCanAttack = false;
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
}

// Modify variables at the end of the attack
void ACombatCharacter::EndAttack()
{
	AttackCount = 0;
	bCanJump = true;
	bCanAttack = true;
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
}

// Open time window for the next attack
void ACombatCharacter::OpenNextAttack()
{
	bCanAttack = true;
}

// Close time window for the next attack
void ACombatCharacter::CloseNextAttack()
{
	bCanAttack = false;
}

// Thrust the character forward when attacking
void ACombatCharacter::ForwardThrust()
{
	FLatentActionInfo LatentActionInfo;
	LatentActionInfo.CallbackTarget = this;

	FVector ForwardLocation = GetActorLocation() + (GetActorForwardVector() * ForwardThrustMultiplier);

	// Before applying the forward thrust, check if the player would be forced into a wall or over an edge
	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);

	if (UKismetSystemLibrary::SphereTraceSingle(GetWorld(), ForwardLocation, ForwardLocation, 50.0f, UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_Visibility),
		false, ActorsToIgnore, EDrawDebugTrace::None, HitResult, true) 
		|| 
		!GetWorld()->LineTraceSingleByChannel(HitResult, ForwardLocation, FVector(ForwardLocation.X, ForwardLocation.Y, ForwardLocation.Z - 100.0F),
			ECollisionChannel::ECC_Visibility, QueryParams))
	{
		ForwardLocation = GetActorLocation();
	}

	// Apply the forward thrust
	UKismetSystemLibrary::MoveComponentTo(GetRootComponent(), ForwardLocation, GetActorRotation(), false, false, 0.1f, false, EMoveComponentAction::Move, LatentActionInfo);
}

// Move the player forward and backward
void ACombatCharacter::MoveForward(float Scale)
{
	AddMovementInput(FVector(1.0f, 1.0f, 0.0f), Scale);
}

// Move the player right and left
void ACombatCharacter::MoveRight(float Scale)
{
	AddMovementInput(FVector(-1.0f, 1.0f, 0.0f), Scale);
}

// Launch the player and play sound effect
void ACombatCharacter::Jump()
{
	Super::Jump();

	if (!GetCharacterMovement()->IsFalling() && bCanJump && JumpSoundEffect)
		UGameplayStatics::PlaySound2D(GetWorld(), JumpSoundEffect);
}

// Perform a phase in the Light Attack combo whenver the light attack button is pressed
void ACombatCharacter::LightAttackPressed()
{
	if (bCanAttack)
	{
		AttackCount++;

		if (LightAttack01 && LightAttack02 && LightAttack03)
		{
			switch (AttackCount)
			{
			case 1:
				PlayAnimMontage(LightAttack01, 1.0f, TEXT("None"));
				break;
			case 2:
				PlayAnimMontage(LightAttack02, 1.0f, TEXT("None"));
				break;
			case 3:
				PlayAnimMontage(LightAttack03, 1.0f, TEXT("None"));
				break;
			default:
				break;
			}
		}
	}
}



