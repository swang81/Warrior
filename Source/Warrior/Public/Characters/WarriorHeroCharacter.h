

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

class UDataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;
struct  FInputActionValue;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()
public:
	AWarriorHeroCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	// EditAnyWhere: �����ڱ༭�����޸ı���
	// BlueprintReadWrite: ������ͼ��ȡ��д�����
	// AllowPrivateAccess = "true",��ʹ������Private�ģ�Ҳ��������ͼ�н��б༭�Ͷ�ȡ��
	
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
#pragma endregion


#pragma region Inputs
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "CharacterData", meta = (AllowPrivateAccess = "true"));
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);
	
#pragma endregion 
	
};
