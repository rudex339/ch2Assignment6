// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingObject.h"

// Sets default values
ARotatingObject::ARotatingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// 기본 회전 속도 설정 (X,Y,Z)
	RotationRate = FRotator(0.f, 90.f, 0.f); // Yaw 90도/초

}

// Called when the game starts or when spawned
void ARotatingObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const float Direction = bRotateForward ? 1.f : -1.f;
	AddActorLocalRotation(RotationRate * Direction * DeltaTime);
}

