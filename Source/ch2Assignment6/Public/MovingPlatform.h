// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class CH2ASSIGNMENT6_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Root", meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMeshComp;


	UPROPERTY(VisibleAnywhere, Category = "Location", meta = (AllowPrivateAccess = "true"))
	class UArrowComponent* StartPoint;

	UPROPERTY(VisibleAnywhere, Category = "Location", meta = (AllowPrivateAccess = "true"))
	class UArrowComponent* EndPoint;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location", meta = (AllowPrivateAccess = "true"))
	float GoalTime;

	bool bGoingToEnd = true;
	float MoveAlpha = 0.f;

	FVector Start;
	FVector End;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location", meta = (AllowPrivateAccess = "true"))
	float StartWaitTime = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location", meta = (AllowPrivateAccess = "true"))
	float EndWaitTime = 0.0f;

	FTimerHandle WaitHandle;

	bool bIsMoving = true;
	void ResumeMove();
};
