

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

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

};
