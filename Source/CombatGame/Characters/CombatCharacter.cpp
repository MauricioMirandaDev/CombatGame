
#include "CombatCharacter.h"
#include "Camera/CameraComponent.h"
#include "CombatGame/Actors/Weapon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

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



