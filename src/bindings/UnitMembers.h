#pragma once
#include <sol.hpp>

namespace BWAPI { class UnitInterface; }

namespace BWAPI_Lua
{
	void bindUnit_canAttack(sol::simple_usertype<BWAPI::UnitInterface>& unit);
	void bindUnit_canAttackGrouped(sol::simple_usertype<BWAPI::UnitInterface>& unit);
	void bindUnit_canSetRallyPoint(sol::simple_usertype<BWAPI::UnitInterface>& unit);
	void bindUnit_canRightClick(sol::simple_usertype<BWAPI::UnitInterface>& unit);
	void bindUnit_canRightClickGrouped(sol::simple_usertype<BWAPI::UnitInterface>& unit);
	void bindUnit_canUseTech(sol::simple_usertype<BWAPI::UnitInterface>& unit);
}