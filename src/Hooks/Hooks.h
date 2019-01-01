#include "Tools.h"
#include "Requests.h"
#include "ICommands.h"
#include "IHooks.h"
#include "API/ARK/Ark.h"


#pragma comment(lib, "ArkApi.lib")

DECLARE_HOOK(APrimalDinoCharacter_UpdateBabyCuddling, void, APrimalDinoCharacter*, long double, char, TSubclassOf<UPrimalItem>);
DECLARE_HOOK(APrimalDinoCharacter_UpdateImprintingQuality_Implementation, void, APrimalDinoCharacter*, float);
DECLARE_HOOK(APrimalDinoCharacter_IncrementImprintingQuality, void, void);

void InitHooks();
void RemoveHooks();