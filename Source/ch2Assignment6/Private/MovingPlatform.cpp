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
	if (Start == FVector(0.f, 0.f, 0.f))
		Start = StartPoint->GetComponentLocation();
	if (End == FVector(0.f, 0.f, 0.f))
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
		MoveAlpha = 1.f;
		bGoingToEnd = !bGoingToEnd;

		bIsMoving = false;

		GetWorld()->GetTimerManager().SetTimer(WaitHandle, this, &AMovingPlatform::ResumeMove,
			bGoingToEnd ? StartWaitTime:EndWaitTime, false);
		return;
	}
	

	// 방향에 따라 보간
	FVector TargetLocation = bGoingToEnd ?
		FMath::Lerp(Start, End, MoveAlpha) :
		FMath::Lerp(End, Start, MoveAlpha);

	SetActorLocation(TargetLocation);
}

void AMovingPlatform::SetStartPointLocation(const FVector& NewLocation)
{
	if (StartPoint)
	{
		StartPoint->SetRelativeLocation(NewLocation); // 상대 위치로 설정
		Start = StartPoint->GetComponentLocation(); // 내부 값도 갱신
	}
}

void AMovingPlatform::SetEndPointLocation(const FVector& NewLocation)
{
	if (EndPoint)
	{
		EndPoint->SetRelativeLocation(NewLocation); // 상대 위치로 설정
		End = EndPoint->GetComponentLocation(); // 내부 값도 갱신
	}
}

void AMovingPlatform::ResumeMove()
{
	// 대기 후 이동 재개
	MoveAlpha = 0.f;      // 다음 경로 시작
	bIsMoving = true;
}
