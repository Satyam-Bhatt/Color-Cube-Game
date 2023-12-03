// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Pawn.h"
#include "MovementClass.generated.h"

class UCurveFloat;

UCLASS()
class CUBEMOVEGAME_API AMovementClass : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMovementClass();

	UFUNCTION()
	void TimelineProgress(float Value);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimeline CurveTimeline;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	UCurveFloat* CurveFloat;

	UPROPERTY()
	FVector StartLoc;

	UPROPERTY()
	FVector EndLoc;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	float XOffset = 100.f;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	float YOffset = 100.f;


private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CubeMesh;

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	class URotatingMovementComponent* RotationDoer;

	FVector MoveLocation;

	void LookUp(float AxisValue);

	void TimelineFunction();

	void UpMovement();

	void RightMovement();

	void LeftMovement();

	void DownMovement();

	void RotateUp();

	UPROPERTY(EditAnywhere, Category = "Movement")
	float PitchValue = 0.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float YawValue = 0.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RollValue = 0.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
