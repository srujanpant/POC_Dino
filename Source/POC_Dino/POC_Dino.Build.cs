// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class POC_Dino : ModuleRules
{
	public POC_Dino(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
            "AkAudio",
			"WwiseSoundEngine",
            "MetasoundEngine"
        });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"POC_Dino",
			"POC_Dino/Variant_Platforming",
			"POC_Dino/Variant_Platforming/Animation",
			"POC_Dino/Variant_Combat",
			"POC_Dino/Variant_Combat/AI",
			"POC_Dino/Variant_Combat/Animation",
			"POC_Dino/Variant_Combat/Gameplay",
			"POC_Dino/Variant_Combat/Interfaces",
			"POC_Dino/Variant_Combat/UI",
			"POC_Dino/Variant_SideScrolling",
			"POC_Dino/Variant_SideScrolling/AI",
			"POC_Dino/Variant_SideScrolling/Gameplay",
			"POC_Dino/Variant_SideScrolling/Interfaces",
			"POC_Dino/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
