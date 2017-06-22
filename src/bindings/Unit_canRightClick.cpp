#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnit_canRightClick(sol::simple_usertype<UnitInterface>& unit)
	{
		unit.set("canRightClick", sol::overload(
			[](UnitInterface* unit) { return unit->canRightClick(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canRightClick),

			[](UnitInterface* unit, const Position& pos) { return unit->canRightClick(pos); },
			[](UnitInterface* unit, const Position& pos, bool flag1) { return unit->canRightClick(pos, flag1); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2) { return unit->canRightClick(pos, flag1, flag2); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2, bool flag3) { return unit->canRightClick(pos, flag1, flag2, flag3); },
			[](UnitInterface* unit, Unit pos) { return unit->canRightClick(pos); },
			[](UnitInterface* unit, Unit pos, bool flag1) { return unit->canRightClick(pos, flag1); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2) { return unit->canRightClick(pos, flag1, flag2); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2, bool flag3) { return unit->canRightClick(pos, flag1, flag2, flag3); }
		));
	}
}