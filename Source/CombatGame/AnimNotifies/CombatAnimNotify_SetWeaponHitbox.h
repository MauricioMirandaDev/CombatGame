// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatGame/AnimNotifies/CombatAnimNotify.h"
#include "CombatAnimNotify_SetWeaponHitbox.generated.h"


UCLASS()
class COMBATGAME_API UCombatAnimNotify_SetWeaponHitbox : public UCombatAnimNotify
{
	GENERATED_BODY()
	
public:
	UCombatAnimNotify_SetWeaponHitbox();

protected:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	bool bActivateWeaponHitbox;
};
