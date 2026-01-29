// Fill out your copyright notice in the Description page of Project Settings.

#include "Audio/AudioActorComponent.h"
#include "AkGameplayStatics.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UAudioActorComponent::UAudioActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UAudioActorComponent::PlaySpatialAudioEvent()
{
	if (WiseAudioEvent)
	{
		FOnAkPostEventCallback PostEventCallback;
		UAkGameplayStatics::PostEvent(WiseAudioEvent, GetOwner(), 0, PostEventCallback);
		UAkGameplayStatics::SetOcclusionRefreshInterval(0, GetOwner());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Please assign a WWise Audio Event"));
		return;
	}
}

void UAudioActorComponent::PlayMetaSound()
{
	if (!MetaSoundSource)
	{
		UE_LOG(LogTemp, Error, TEXT("MetaSoundSource is not assigned!"));
		return;
	}

	AActor* Owner = GetOwner();
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("AudioActorComponent has no owner!"));
		return;
	}

	AudioComponent = UGameplayStatics::SpawnSoundAttached(MetaSoundSource, Owner->GetRootComponent());
	if(AudioComponent)
		AudioComponent->Play();
}

// Called when the game starts
void UAudioActorComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if(bShouldCallFromBeginPlay && AudioType == EAudioType::WWise)
		PlaySpatialAudioEvent();
	else if(bShouldCallFromBeginPlay && AudioType == EAudioType::MetaSound)
		PlayMetaSound();
}

void UAudioActorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UAkGameplayStatics::StopActor(GetOwner());	
}