#include "LuaAIModule.h"
#include <iostream>
#include <BWAPI_Lua.h>

using namespace BWAPI;

void LuaAIModule::onStart()
{
	// Start Lua VM and load BWAPI module as global 'BWAPI'
	lua = sol::state();
	lua.set_function("__protectederrorhandler", [](std::string msg) { Broodwar << msg << std::endl;  return msg; });
	sol::protected_function::set_default_handler(lua["__protectederrorhandler"]);
	lua.open_libraries();
	BWAPI_Lua::requireBWAPI(lua);

	// Redirect print to BWAPI.print
	lua.script(R"(
function _G.print(...)
	local n = select('#', ...)
	local arguments = {...}
	for i = 1, n do
		arguments[i] = tostring(arguments[i])
	end
	BWAPI.print(table.concat(arguments, "\t") .. "\n")
end
	)");

	// Set package paths relative to loaded dll
	size_t found = dllPath.find_last_of("/\\");
	std::string dllDirectory = dllPath.substr(0, found);
	lua["package"]["path"] = dllDirectory + "\\?.lua;" + dllDirectory + "\\?\\init.lua;" + lua["package"]["path"].get_or(std::string(""));
	lua["package"]["cpath"] = dllDirectory + "\\?.dll;" + lua["package"]["cpath"].get_or(std::string(""));

	// Load init script
	try
	{
		lua.script_file(dllDirectory + "\\init.lua");
		lua["BWAPI"]["onStart"]();
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onEnd(bool isWinner)
{
	try
	{
		lua["BWAPI"]["onEnd"]();
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onFrame()
{
	try
	{
		lua["BWAPI"]["onFrame"]();
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onSendText(std::string text)
{
	try
	{
		lua.script(text);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}

}

void LuaAIModule::onReceiveText(BWAPI::Player player, std::string text)
{
	try
	{
		lua["BWAPI"]["onReceiveText"](player, text);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onPlayerLeft(BWAPI::Player player)
{
	try
	{
		lua["BWAPI"]["onPlayerLeft"](player);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onNukeDetect(BWAPI::Position target)
{
	try
	{
		lua["BWAPI"]["onNukeDetect"](target);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onUnitDiscover(BWAPI::Unit unit)
{
	try
	{
		lua["BWAPI"]["onUnitDiscover"](unit);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onUnitEvade(BWAPI::Unit unit)
{
	try
	{
		lua["BWAPI"]["onUnitEvade"](unit);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onUnitShow(BWAPI::Unit unit)
{
	try
	{
		lua["BWAPI"]["onUnitShow"](unit);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onUnitHide(BWAPI::Unit unit)
{
	try
	{
		lua["BWAPI"]["onUnitHide"](unit);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onUnitCreate(BWAPI::Unit unit)
{
	try
	{
		lua["BWAPI"]["onUnitCreate"](unit);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onUnitDestroy(BWAPI::Unit unit)
{
	try
	{
		lua["BWAPI"]["onUnitDestroy"](unit);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onUnitMorph(BWAPI::Unit unit)
{
	try
	{
		lua["BWAPI"]["onUnitMorph"](unit);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onUnitRenegade(BWAPI::Unit unit)
{
	try
	{
		lua["BWAPI"]["onUnitRenegade"](unit);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onSaveGame(std::string gameName)
{
	try
	{
		lua["BWAPI"]["onSaveGame"](gameName);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}

void LuaAIModule::onUnitComplete(BWAPI::Unit unit)
{
	try
	{
		lua["BWAPI"]["onUnitComplete"](unit);
	}
	catch (const sol::error& e)
	{
		Broodwar << e.what() << std::endl;
	}
}
