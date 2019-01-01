#include "Hooks.h"

void InitHooks()
{
	ArkApi::GetHooks().SetHook("APrimalDinoCharacter.UpdateBabyCuddling", &Hook_APrimalDinoCharacter_UpdateBabyCuddling, &APrimalDinoCharacter_UpdateBabyCuddling_original);
	ArkApi::GetHooks().SetHook("APrimalDinoCharacter.UpdateImprintingQuality_Implementation", &Hook_APrimalDinoCharacter_UpdateImprintingQuality_Implementation, &APrimalDinoCharacter_UpdateImprintingQuality_Implementation_original);
}

void RemoveHooks()
{
	ArkApi::GetHooks().DisableHook("APrimalDinoCharacter.UpdateBabyCuddling", &Hook_APrimalDinoCharacter_UpdateBabyCuddling);
	ArkApi::GetHooks().DisableHook("APrimalDinoCharacter.UpdateImprintingQuality_Implementation", &Hook_APrimalDinoCharacter_UpdateImprintingQuality_Implementation);
}





void  Hook_APrimalDinoCharacter_UpdateBabyCuddling(APrimalDinoCharacter* _this, long double NewBabyNextCuddleTime, char NewBabyCuddleType, TSubclassOf<UPrimalItem> NewBabyCuddleFood)
{

	const wchar_t* blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_StaminaSoup.PrimalItemConsumable_StaminaSoup_C" };

	UObject* object = Globals::StaticLoadObject(UObject::StaticClass(), nullptr, blueprint, nullptr, 0, 0, true);
	TSubclassOf<UPrimalItem> item;
	item.uClass = reinterpret_cast<UClass*>(object);

	long double currentServerTime = ArkApi::GetApiUtils().GetWorld()->TimeSecondsField();
	long double overwirrtenServerTime = currentServerTime + 300;

														    
	APrimalDinoCharacter_UpdateBabyCuddling_original(_this, overwirrtenServerTime, 1, item);
}




void  Hook_APrimalDinoCharacter_UpdateImprintingQuality_Implementation(APrimalDinoCharacter* _this, float NewImprintingQuality)
{
	if (nullptr != _this)
	{
		float CurrentDinoImprint = _this->GetCharacterStatusComponent()->DinoImprintingQualityField();

		if (1.0f > (CurrentDinoImprint + 0.2f))
		{
			APrimalDinoCharacter_UpdateImprintingQuality_Implementation_original(_this, CurrentDinoImprint + 0.2f);
		
		}
		else
		{
			APrimalDinoCharacter_UpdateImprintingQuality_Implementation_original(_this, 1);
		}
	}
}

