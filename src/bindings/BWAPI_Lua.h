#pragma once
#include <sol.hpp>

namespace BWAPI_Lua
{
	void bindGame(sol::table module);
	void bindUnit(sol::table module);
	void bindFlag(sol::table module);
	void bindDamageType(sol::table module);
	void bindUnitType(sol::table module);
	void bindColor(sol::table module);
	void bindError(sol::table module);
	void bindRace(sol::table module);
	void bindPlayer(sol::table module);
	void bindPlayerset(sol::table module);
	void bindUnitset(sol::table module);
	void bindFilters(sol::table module);
	void bindPosition(sol::table module);

	sol::table openBWAPI(sol::this_state s);
}