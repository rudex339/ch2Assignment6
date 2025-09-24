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

	UFUNCTION(BlueprintCallable, Category = "Location")
	void SetStartWaitTime(float NewTime) { StartWaitTime = NewTime; }

	UFUNCTION(BlueprintCallable, Category = "Location")
	void SetEndWaitTime(float NewTime) { EndWaitTime = NewTime; }

	UFUNCTION(BlueprintCallable, Category = "Location")
	void SetStartPointLocation(const FVector& NewLocation);

	/** EndPoint Arrow 위치만 변경 */
	UFUNCTION(BlueprintCallable, Category = "Location")
	void SetEndPointLocation(const FVector& NewLocation);

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

	FVector Start = FVector(0.f, 0.f, 0.f);
	FVector End = FVector(0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location", meta = (AllowPrivateAccess = "true"))
	float StartWaitTime = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location", meta = (AllowPrivateAccess = "true"))
	float EndWaitTime = 0.5f;

	FTimerHandle WaitHandle;

	bool bIsMoving = true;
	void ResumeMove();
};
