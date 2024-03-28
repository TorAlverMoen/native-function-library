// © 2024 jawadato

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "HAL/PlatformApplicationMisc.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NativeFunctionLibraryBPLibrary.generated.h"

UCLASS()
class UNativeFunctionLibraryBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

		//SortActorsByDistance
		/** 
		* Sorts an array of actors relative to distance to the provided actor from closest to furthest.
		* @param	RelativeTo Array to sort against
		* @param	Array Array to sort
		* @return Sorted Array from closest to furthest
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByDistance"))
		static void SortActorsByDistance(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue);


		//SortActorsByDistance2D
		/** 
		* Sorts an array of actors relative to horizontal distance to the provided actor from closest to furthest.
		* @param	RelativeTo Array to sort against
		* @param	Array Array to sort
		* @return Sorted Array from closest to furthest		
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByDistance2D"))
		static void SortActorsByDistance2D(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue);


		//SortActorsByLocation
		/** 
		* Sorts an array of actors relative to distance to the provided location vector from closest to furthest.
		* @param	RelativeTo Array to sort against
		* @param	Array Array to sort
		* @return Sorted Array from closest to furthest				
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Actor", Meta = (Keywords = "SortActorsByLocation"))
		static void SortActorsByLocation(FVector RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue);


		//SortVectorsByDistance
		/** 
		* Sorts an array of vectors relative to distance to the provided location vector from closest to furthest.
		* @param	RelativeTo Array to sort against
		* @param	Array Array to sort
		* @return Sorted Array from closest to furthest
		*/
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "SortVectorsByDistance"))
		static void SortVectorsByDistance(FVector RelativeTo, TArray<FVector> Array, TArray<FVector>& ReturnValue);


		//RandomVectorsInExtent
		/** 
		* Returns an array of random vectors distributed within a certain box extent from the origin, counting up to the provided amount.
		* @param	Amount Count of vectors
		* @param	InBoxExtent Extent of the rectangular volume
		* @param	Origin Origin of the volume
		* @return Created vectors
		*/
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "RandomVectorsInExtent"))
		static void RandomVectorsInBoxExtent(int32 Amount, FVector InBoxExtent, FVector Origin, TArray<FVector>& ReturnValue);


		//RandomVectorsInExtentFromStream
		/** 
		* Returns an array of random vectors distributed within a certain box extent from the origin, counting up to the provided amount.
		* @param	Amount Count of vectors
		* @param	InBoxExtent Extent of the rectangular volume
		* @param	Origin Origin of the volume
		* @param	Stream Random stream to use
		* @return Created vectors
		*/
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "RandomVectorsInExtentFromStream"))
		static void RandomVectorsInBoxExtentFromStream(int32 Amount, FVector InBoxExtent, FVector Origin, FRandomStream Stream, TArray<FVector>& ReturnValue);


		//AverageSeparationBetweenVectors
		/** 
		* Returns an arbitrary average separation value between an array of vectors, can be used to define arbitrary density of supplied vectors.
		* @param	Array Array which contains the vectors
		* @return Calculated average separation value
		*/
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "AverageSeparationBetweenVectors"))
		static void AverageSeparationBetweenVectors(TArray<FVector> Array, float& ReturnValue);		


		//NotNearLocations
		/** 
		* Compares an array of vectors against a provided location vector and returns true if none in the array is within a certain radius of the provided location vector.
		* @param	RelativeTo Location vector to compare against
		* @param	Array Array containing the vectors
		* @param	Radius Radius within which to check
		* @return True or false based on check result
		*/		
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|Vector", Meta = (Keywords = "NotNearLocations"))
		static bool NotNearLocations(FVector RelativeTo, TArray<FVector> Array, float Radius);


		//PutAllRigidBodiesToSleep
		/** 
		* Force all bodies of associated skeletal mesh back to sleep.
		* @param	Mesh Skeletal Mesh which contains the simulating bones
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|SkeletalMesh", Meta = (Keywords = "PutAllRigidBodiesToSleep"))
		static void PutAllRigidBodiesToSleep(USkeletalMeshComponent* Mesh);


		//ClearOnScreenDebugMessages
		/** 
		* Clears all on screen debug messages.
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Debug", Meta = (Keywords = "ClearOnScreenDebugMessages"))
		static void ClearOnScreenDebugMessages();


		//LaunchedWithCommandLineArgument
		/** 
		* Returns true if a specific command line flag was used during launch.
		* @param	Argument Command line argument to check against
		* @return True or false based on check result
		*/		
		UFUNCTION(BlueprintPure, Category = "Jawadato|NativeFunctionLibrary|CommandLine", Meta = (Keywords = "LaunchedWithCommandLineArgument"))
		static bool LaunchedWithCommandLineArgument(FString Argument = "");


		//StringToClipboard
		/** 
		* Copies the provided string into clipboard.
		* @param	String String which to copy
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Misc", Meta = (Keywords = "StringToClipboard"))
		static void StringToClipboard(const FString& String);


		//ClipboardToString
		/** 
		* Retrieves the contents of the clipboard into a string.
		* @return String containing clipboard contents
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Misc", Meta = (Keywords = "ClipboardToString"))
		static FString ClipboardToString();


		//HexToColor
		/** 
		* Converts provided Hex color code to a Color Structure.
		* @param	Hex Hex code which to convert
		* @return Converted Color Structure
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "HexToColor"))
		static FColor HexToColor(FString Hex);


		//ColorToHex
		/** 
		* Converts provided Color Structure into Hex color code.
		* @param	Color Color Structure which to convert
		* @return Converted Hex String
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|String", Meta = (Keywords = "ColorToHex"))
		static FString ColorToHex(FColor Color);


		//FlushInputs
		/** 
		* Flushes all accumulated inputs.
		* @param	PlayerController Player Controller which needs to be flushed
		*/		
		UFUNCTION(BlueprintCallable, Category = "Jawadato|NativeFunctionLibrary|Input", Meta = (Keywords = "FlushInputs"))
		static void FlushInputs(APlayerController* PlayerController);		
};