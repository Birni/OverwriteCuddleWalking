#include "Tools.h"
#include "Requests.h"
#include "ICommands.h"
#include "IHooks.h"
#include "API/ARK/Ark.h"


#pragma comment(lib, "ArkApi.lib")

DECLARE_HOOK(APrimalDinoCharacter_UpdateBabyCuddling, void, APrimalDinoCharacter*, long double, char, TSubclassOf<UPrimalItem>);


void InitHooks();
void RemoveHooks();