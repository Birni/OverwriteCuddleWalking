#include "Hooks.h"

#define CUDDLE_TYPE_CUDDLE		0
#define CUDDLE_TYPE_FOOD		1
#define CUDDLE_TYPE_WALKING		2


void InitHooks()
{
	ArkApi::GetHooks().SetHook("APrimalDinoCharacter.UpdateBabyCuddling", &Hook_APrimalDinoCharacter_UpdateBabyCuddling, &APrimalDinoCharacter_UpdateBabyCuddling_original);
}

void RemoveHooks()
{
	ArkApi::GetHooks().DisableHook("APrimalDinoCharacter.UpdateBabyCuddling", &Hook_APrimalDinoCharacter_UpdateBabyCuddling);
}



void  Hook_APrimalDinoCharacter_UpdateBabyCuddling(APrimalDinoCharacter* _this, long double NewBabyNextCuddleTime, char NewBabyCuddleType, TSubclassOf<UPrimalItem> NewBabyCuddleFood)
{
	long double currentServerTime = ArkApi::GetApiUtils().GetWorld()->TimeSecondsField();
	long double overwirrtenServerTime = currentServerTime + 3600;

	if (CUDDLE_TYPE_WALKING == NewBabyCuddleType)
	{
		int RandNumber = rand() % 5;

		const wchar_t* blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_Base_XSmall.PrimalItemConsumable_Kibble_Base_XSmall_C" };

		switch (RandNumber)
		{
			case 0:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_Base_XSmall.PrimalItemConsumable_Kibble_Base_XSmall_C" }; break; 
			case 1:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_Base_Special.PrimalItemConsumable_Kibble_Base_Special_C" }; break;
			case 2:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_Base_XLarge.PrimalItemConsumable_Kibble_Base_XLarge_C" }; break;
			case 3:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_Base_Medium.PrimalItemConsumable_Kibble_Base_Medium_C" }; break;
			case 4:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_Base_Large.PrimalItemConsumable_Kibble_Base_Large_C" }; break;
			default: break;

		}
			
		UObject* object = Globals::StaticLoadObject(UObject::StaticClass(), nullptr, blueprint, nullptr, 0, 0, true);
		
		if (nullptr != object)
		{
			TSubclassOf<UPrimalItem> item;
			item.uClass = reinterpret_cast<UClass*>(object);
		
			APrimalDinoCharacter_UpdateBabyCuddling_original(_this, overwirrtenServerTime, CUDDLE_TYPE_FOOD, item);
		}
		else
		{
			APrimalDinoCharacter_UpdateBabyCuddling_original(_this, overwirrtenServerTime, NewBabyCuddleType, NewBabyCuddleFood);
			FString errormsg = blueprint;
			Log::GetLog()->error("OverwriteCuddleWalking: nulltptr object blueprint {}" , errormsg.ToString());
		}
	}
	else
	{
		APrimalDinoCharacter_UpdateBabyCuddling_original(_this, overwirrtenServerTime, NewBabyCuddleType, NewBabyCuddleFood);
	}

}

