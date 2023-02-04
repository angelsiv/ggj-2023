// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef PROJECTSEEDS_ProjectSeedsProjectile_generated_h
#error "ProjectSeedsProjectile.generated.h already included, missing '#pragma once' in ProjectSeedsProjectile.h"
#endif
#define PROJECTSEEDS_ProjectSeedsProjectile_generated_h

#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_SPARSE_DATA
#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectSeedsProjectile(); \
	friend struct Z_Construct_UClass_AProjectSeedsProjectile_Statics; \
public: \
	DECLARE_CLASS(AProjectSeedsProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectSeeds"), NO_API) \
	DECLARE_SERIALIZER(AProjectSeedsProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAProjectSeedsProjectile(); \
	friend struct Z_Construct_UClass_AProjectSeedsProjectile_Statics; \
public: \
	DECLARE_CLASS(AProjectSeedsProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectSeeds"), NO_API) \
	DECLARE_SERIALIZER(AProjectSeedsProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProjectSeedsProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProjectSeedsProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectSeedsProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectSeedsProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectSeedsProjectile(AProjectSeedsProjectile&&); \
	NO_API AProjectSeedsProjectile(const AProjectSeedsProjectile&); \
public:


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectSeedsProjectile(AProjectSeedsProjectile&&); \
	NO_API AProjectSeedsProjectile(const AProjectSeedsProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectSeedsProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectSeedsProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectSeedsProjectile)


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ProjectileMesh() { return STRUCT_OFFSET(AProjectSeedsProjectile, ProjectileMesh); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AProjectSeedsProjectile, ProjectileMovement); }


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_12_PROLOG
#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_SPARSE_DATA \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_RPC_WRAPPERS \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_INCLASS \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_SPARSE_DATA \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_INCLASS_NO_PURE_DECLS \
	ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTSEEDS_API UClass* StaticClass<class AProjectSeedsProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectSeeds_Source_ProjectSeeds_ProjectSeedsProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
