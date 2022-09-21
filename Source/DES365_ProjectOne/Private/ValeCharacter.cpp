// Fill out your copyright notice in the Description page of Project Settings.


#include "ValeCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "InteractComponent.h"

// Sets default values
AValeCharacter::AValeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AValeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AValeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AValeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AValeCharacter::InteractWithNearestObject()
{
	FCollisionObjectQueryParams Query;

	if (const UWorld* World = GetWorld())
	{

		FVector Location = GetActorLocation();
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		TArray<AActor*> ActorsToIgnore;
		ActorsToIgnore.Add(this);
		TArray<AActor*> OutActors;
		UKismetSystemLibrary::SphereOverlapActors(World, Location, InteractRadius, ObjectTypes, nullptr, ActorsToIgnore, OutActors);

		for (auto Hit : OutActors)
		{
			if (Hit != this)
			{
				FVector HitLocation = Hit->GetActorLocation();
				float distance = FVector::Dist(Location, HitLocation);
				if (distance < InteractRadius)
				{
					if (UInteractComponent* Interactor = Hit->FindComponentByClass<UInteractComponent>())
					{
						Interactor->OnInteract.Broadcast(this);
						break;
					}
				}

			}
		}
	}
}

