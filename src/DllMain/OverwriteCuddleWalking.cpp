#include "OverwriteCuddleWalking.h"


void Load()
{
	Log::Get().Init("Hello World");

	Log::GetLog()->info("a test log");

}

void Unload()
{


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
