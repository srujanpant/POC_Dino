// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AudioActorComponent.generated.h"

UENUM(BlueprintType)
enum class EAudioType : uint8
{
	WWise			UMETA(DisplayName = "WWise"),
	MetaSound		UMETA(DisplayName = "Meta Sound")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class POC_DINO_API UAudioActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAudioActorComponent();

	UFUNCTION(BlueprintCallable, Category = "Audio|Wwise")
	void PlaySpatialAudioEvent();

	UFUNCTION(BlueprintCallable, Category = "Audio|MetaSound")
	void PlayMetaSound();

	UFUNCTION(BlueprintCallable, Category = "Audio|Wwise", meta = (Latent, LatentInfo = "LatentInfo"))
	void PlaySpatialAudioToEnd(FLatentActionInfo LatentInfo);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Audio")
	bool bShouldCallFromBeginPlay = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	EAudioType AudioType = EAudioType::WWise;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Audio|Wwise", meta = (EditCondition = "AudioType == EAudioType::WWise", EditConditionHides))
	TObjectPtr<class UAkAudioEvent> WiseAudioEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio|MetaSound", meta = (EditCondition = "AudioType == EAudioType::MetaSound", EditConditionHides))
	TObjectPtr<class USoundBase> MetaSoundSource;

private:
	UPROPERTY()
	TObjectPtr<class UAudioComponent> AudioComponent;
};
