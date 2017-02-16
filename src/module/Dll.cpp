#include <BWAPI.h>
#include <Windows.h>

#include "LuaAIModule.h"

namespace LuaAIModuleDll
{
	std::string dllPath;
}

extern "C" __declspec(dllexport) void gameInit(BWAPI::Game* game) { BWAPI::BroodwarPtr = game; }
BOOL APIENTRY DllMain( HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			char dllPath[MAX_PATH + 1];
			GetModuleFileNameA((HMODULE)hModule, dllPath, _countof(dllPath));
			LuaAIModuleDll::dllPath = dllPath;
			break;
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) BWAPI::AIModule* newAIModule()
{
	LuaAIModule* module = new LuaAIModule();
	module->setDllPath(LuaAIModuleDll::dllPath);
	return module;
}
