

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InputTag,ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};


template <class UserObject, typename CallbackFunc>
inline void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	//check ֻ���һ���򵥵Ĵ�����Ϣ��ָ������ʧ�ܵ�λ�á�
	//checkf �������ṩһ����ʽ���Ĵ�����Ϣ�������������������Ϣ��
	check(InInputConfig);
	checkf(InInputConfig,TEXT("Input config data asset is null, can not proceed with binding input action"));

	if(UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}
