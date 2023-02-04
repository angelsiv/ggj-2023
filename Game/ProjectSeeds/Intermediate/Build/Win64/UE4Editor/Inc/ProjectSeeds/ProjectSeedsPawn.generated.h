// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTSEEDS_ProjectSeedsPawn_generated_h
#error "ProjectSeedsPawn.generated.h already included, missing '#pragma once' in ProjectSeedsPawn.h"
#endif
#define PROJECTSEEDS_ProjectSeedsPawn_generated_h

#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_SPARSE_DATA
#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_RPC_WRAPPERS
#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectSeedsPawn(); \
	friend struct Z_Construct_UClass_AProjectSeedsPawn_Statics; \
public: \
	DECLARE_CLASS(AProjectSeedsPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectSeeds"), NO_API) \
	DECLARE_SERIALIZER(AProjectSeedsPawn)


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAProjectSeedsPawn(); \
	friend struct Z_Construct_UClass_AProjectSeedsPawn_Statics; \
public: \
	DECLARE_CLASS(AProjectSeedsPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectSeeds"), NO_API) \
	DECLARE_SERIALIZER(AProjectSeedsPawn)


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProjectSeedsPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProjectSeedsPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectSeedsPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectSeedsPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectSeedsPawn(AProjectSeedsPawn&&); \
	NO_API AProjectSeedsPawn(const AProjectSeedsPawn&); \
public:


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectSeedsPawn(AProjectSeedsPawn&&); \
	NO_API AProjectSeedsPawn(const AProjectSeedsPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectSeedsPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectSeedsPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectSeedsPawn)


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ShipMeshComponent() { return STRUCT_OFFSET(AProjectSeedsPawn, ShipMeshComponent); } \
	FORCEINLINE static uint32 __PPO__CameraComponent() { return STRUCT_OFFSET(AProjectSeedsPawn, CameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AProjectSeedsPawn, CameraBoom); }


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_9_PROLOG
#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_SPARSE_DATA \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_RPC_WRAPPERS \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_INCLASS \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_SPARSE_DATA \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_INCLASS_NO_PURE_DECLS \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTSEEDS_API UClass* StaticClass<class AProjectSeedsPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectSeeds_Source_ProjectSeeds_ProjectSeedsPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
