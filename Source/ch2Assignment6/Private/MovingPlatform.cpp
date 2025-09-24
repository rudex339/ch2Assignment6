// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "Components/ArrowComponent.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	StartPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("StartPoint"));
	StartPoint->SetupAttachment(SceneRoot);
	StartPoint->ArrowColor = FColor::Green; // 색상 구분
	StartPoint->bHiddenInGame = true;

	EndPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("EndPoint"));
	EndPoint->SetupAttachment(SceneRoot);
	EndPoint->ArrowColor = FColor::Red;
	EndPoint->bHiddenInGame = true;

	GoalTime = 1.0f;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	Start = StartPoint->GetComponentLocation();
	End = EndPoint->GetComponentLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!StaticMeshComp || !StartPoint || !EndPoint) return;
	if (!bIsMoving) return;
	
	MoveAlpha += DeltaTime / GoalTime;
	if (MoveAlpha >= 1.f)
	{
		MoveAlpha = 0.f;
		bGoingToEnd = !bGoingToEnd;
	}
	else {

	}
	

	// 방향에 따라 보간
	FVector TargetLocation = bGoingToEnd ?
		FMath::Lerp(Start, End, MoveAlpha) :
		FMath::Lerp(End, Start, MoveAlpha);

	SetActorLocation(TargetLocation);
}

