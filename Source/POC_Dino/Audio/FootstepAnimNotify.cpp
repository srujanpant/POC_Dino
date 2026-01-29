// Fill out your copyright notice in the Description page of Project Settings.

#include "Audio/FootstepAnimNotify.h"
#include "Audio/AudioActorComponent.h"

void UFootstepAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	AActor* Owner = MeshComp->GetOwner();
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("FootstepAnimNotify: Owner not found"));
		return;
	}

	UAudioActorComponent* AudioComp = Owner->FindComponentByClass<UAudioActorComponent>();
	if (!AudioComp)
	{
		UE_LOG(LogTemp, Error, TEXT("FootstepAnimNotify: AudioActorComponent not found on %s"), *Owner->GetName());
		return;
	}

	AudioComp->PlaySpatialAudioEvent();
}