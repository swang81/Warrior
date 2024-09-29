// 


#include "AnimInstance/WarriorCharacterAnimInstance.h"
#include "Characters/WarriorBaseCharacter.h"

void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());
	
	if(OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement(); // Initialize the owning character
	}

	
}

void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if(!OwningCharacter || !OwningMovementComponent)
	{
		return; 
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D()>0.f;
}
