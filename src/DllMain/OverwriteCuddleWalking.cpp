#include "OverwriteCuddleWalking.h"
#include "Hooks.h"


void Load()
{
	Log::Get().Init("OverwriteCuddleWalking");

	InitHooks();

}

void Unload()
{

	RemoveHooks();

}



BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Load();
		break;
	case DLL_PROCESS_DETACH:
		Unload();
		break;
	}
	return TRUE;
}
