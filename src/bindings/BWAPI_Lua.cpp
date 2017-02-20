#include "BWAPI_Lua.h"
#include <BWAPI.h>

using namespace BWAPI;
using namespace BWAPI_Lua;

namespace BWAPI_Lua
{
	sol::table requireBWAPI(sol::state_view& lua) {
		return lua.require("BWAPI", sol::c_call<decltype(&BWAPI_Lua::openBWAPI), &BWAPI_Lua::openBWAPI>);
	}

	sol::table openBWAPI(sol::this_state s) {
		sol::state_view lua(s);
		sol::table module = lua.create_table();

		// Redirect BWAPI.print to the GameWrapper ostream
		module["print"] = [](const char *msg) {
			Broodwar << msg;
			Broodwar.flush();
		};

		// Initialize all callbacks to no-op functions
		auto noop = [] {};
		for (const char * callback : {
			"onStart",
			"onEnd",
			"onFrame",
			"onSendText",
			"onReceiveText",
			"onPlayerLeft",
			"onNukeDetect",
			"onUnitDiscover",
			"onUnitEvade",
			"onUnitShow",
			"onUnitHide",
			"onUnitCreate",
			"onUnitDestroy",
			"onUnitMorph",
			"onUnitRenegade",
			"onSaveGame",
			"onUnitComplete"
		})
		{
			module.set_function(callback, noop);
		}

		bindGame(module);
		bindUnit(module);
		bindFlag(module);
		bindDamageType(module);
		bindUnitType(module);
		bindColor(module);
		bindError(module);
		bindRace(module);
		bindPlayer(module);
		bindPlayerset(module);
		bindUnitset(module);
		bindFilters(module);
		bindPosition(module);
		bindTechType(module);
		bindUpgradeType(module);
		bindUnitSizeType(module);
		bindWeaponType(module);
		bindExplosionType(module);
		bindForceset(module);
		bindForce(module);
		bindBulletType(module);
		bindGameType(module);
		bindOrder(module);

		module["Broodwar"] = BroodwarPtr;

		return module;
	}
}