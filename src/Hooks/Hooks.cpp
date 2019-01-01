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
		int RandNumber = rand() % 15;

		const wchar_t* blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_AnkyloEgg.PrimalItemConsumable_Kibble_AnkyloEgg_C" };

		switch (RandNumber)
		{
			case 0:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_AnkyloEgg.PrimalItemConsumable_Kibble_AnkyloEgg_C" }; break; 
			case 1:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_TurtleEgg.PrimalItemConsumable_Kibble_TurtleEgg_C" }; break;
			case 2:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_DiloEgg.PrimalItemConsumable_Kibble_DiloEgg_C" }; break;
			case 3:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_DimetroEgg.PrimalItemConsumable_Kibble_DimetroEgg_C" }; break;
			case 4:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_DodoEgg.PrimalItemConsumable_Kibble_DodoEgg_C" }; break;
			case 5:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_GalliEgg.PrimalItemConsumable_Kibble_GalliEgg_C" }; break;
			case 6:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_LystroEgg.PrimalItemConsumable_Kibble_LystroEgg_C" }; break;
			case 7:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_PachyEgg.PrimalItemConsumable_Kibble_PachyEgg_C" }; break;
			case 8:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_ParaEgg.PrimalItemConsumable_Kibble_ParaEgg_C" }; break;
			case 9:   blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_ParaEgg.PrimalItemConsumable_Kibble_ParaEgg_C" }; break;
			case 10:  blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_PteroEgg.PrimalItemConsumable_Kibble_PteroEgg_C" }; break;
			case 11:  blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_RaptorEgg.PrimalItemConsumable_Kibble_RaptorEgg_C" }; break;
			case 12:  blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_StegoEgg.PrimalItemConsumable_Kibble_StegoEgg_C" }; break;
			case 13:  blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_TerrorBirdEgg.PrimalItemConsumable_Kibble_TerrorBirdEgg_C" }; break;
			case 14:  blueprint = { L"/Game/PrimalEarth/CoreBlueprints/Items/Consumables/PrimalItemConsumable_Kibble_TrikeEgg.PrimalItemConsumable_Kibble_TrikeEgg_C" }; break;
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

