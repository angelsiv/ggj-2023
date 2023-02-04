// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectSeeds/ProjectSeedsGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectSeedsGameMode() {}
// Cross Module References
	PROJECTSEEDS_API UClass* Z_Construct_UClass_AProjectSeedsGameMode_NoRegister();
	PROJECTSEEDS_API UClass* Z_Construct_UClass_AProjectSeedsGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ProjectSeeds();
// End Cross Module References
	void AProjectSeedsGameMode::StaticRegisterNativesAProjectSeedsGameMode()
	{
	}
	UClass* Z_Construct_UClass_AProjectSeedsGameMode_NoRegister()
	{
		return AProjectSeedsGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AProjectSeedsGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProjectSeedsGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectSeeds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectSeedsGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ProjectSeedsGameMode.h" },
		{ "ModuleRelativePath", "ProjectSeedsGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProjectSeedsGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProjectSeedsGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProjectSeedsGameMode_Statics::ClassParams = {
		&AProjectSeedsGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AProjectSeedsGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectSeedsGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProjectSeedsGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProjectSeedsGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProjectSeedsGameMode, 1930109517);
	template<> PROJECTSEEDS_API UClass* StaticClass<AProjectSeedsGameMode>()
	{
		return AProjectSeedsGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProjectSeedsGameMode(Z_Construct_UClass_AProjectSeedsGameMode, &AProjectSeedsGameMode::StaticClass, TEXT("/Script/ProjectSeeds"), TEXT("AProjectSeedsGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProjectSeedsGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
