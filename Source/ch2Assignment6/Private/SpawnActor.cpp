// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnActor.h"
#include "MovingPlatform.h"
#include "RotatingObject.h"

// Sets default values
ASpawnActor::ASpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();

	if (SpawnActorClasses.Num() > 0)
	{
		// 랜덤 인덱스 선택
		int32 Index = FMath::RandRange(1, 2);

		switch (Index) {
		case 1:
		{
			TSubclassOf<AActor> PickedClass = SpawnActorClasses[0];

			// AMovingPlatform 전용으로 캐스팅
			TSubclassOf<AMovingPlatform> ChosenClass = *PickedClass;

			AMovingPlatform* Spawned = GetWorld()->SpawnActor<AMovingPlatform>(
				PickedClass,
				FVector(6830.f, 2115.f, 1590.f),  // 위치
				FRotator(0.f, 0.f, 0.f)           // 회전
			);
			Spawned->SetStartPointLocation(FVector(0.f, 0.f, 0.f));
			Spawned->SetEndPointLocation(FVector(0.f, 0.f, -500.f));

			Spawned = GetWorld()->SpawnActor<AMovingPlatform>(
				PickedClass,
				FVector(6400.f, 2245.f, 1590.f),  // 위치
				FRotator(0.f, -30.f, 0.f)           // 회전
			);
			Spawned->SetStartPointLocation(FVector(0.f, 0.f, -500.f));
			Spawned->SetEndPointLocation(FVector(0.f, 0.f, 0.f));

			Spawned = GetWorld()->SpawnActor<AMovingPlatform>(
				PickedClass,
				FVector(6070.f, 2540.f, 1590.f),  // 위치
				FRotator(0.f, -50.f, 0.f)           // 회전
			);
				Spawned->SetStartPointLocation(FVector(0.f, 0.f, 0.f));
				Spawned->SetEndPointLocation(FVector(0.f, 0.f, -500.f));

			break;
		}
		case 2:
		{
			TSubclassOf<AActor> PickedClass = SpawnActorClasses[1];
			TSubclassOf<ARotatingObject> ChosenClass = *PickedClass;

			ARotatingObject* Spawned1 = GetWorld()->SpawnActor<ARotatingObject>(
				PickedClass,
				FVector(6380.f, 2160.f, 1310.f),  // 위치
				FRotator(0.f, 0.f, 0.f)           // 회전
			);
			Spawned1->SetActorScale3D(FVector(0.78989f, 0.78989f, 1.f));
			Spawned1->SetRotationRate(FRotator(0.f, 20.f, 0.f));
			break;
		}
		}
	}
}

// Called every frame
void ASpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

