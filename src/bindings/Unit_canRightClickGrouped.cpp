#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnit_canRightClickGrouped(sol::simple_usertype<UnitInterface>& unit)
	{
		unit.set("canRightClickGrouped", sol::overload(
			[](UnitInterface* unit) { return unit->canRightClickGrouped(); },
			[](UnitInterface* unit, bool flag1) { return unit->canRightClickGrouped(flag1); },
			static_cast<bool (UnitInterface::*)(bool, bool) const>(&UnitInterface::canRightClickGrouped),

			[](UnitInterface* unit, const Position& pos) { return unit->canRightClickGrouped(pos); },
			[](UnitInterface* unit, const Position& pos, bool flag1) { return unit->canRightClickGrouped(pos, flag1); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2) { return unit->canRightClickGrouped(pos, flag1, flag2); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2, bool flag3) { return unit->canRightClickGrouped(pos, flag1, flag2, flag3); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2, bool flag3, bool flag4) { return unit->canRightClickGrouped(pos, flag1, flag2, flag3, flag4); },
			[](UnitInterface* unit, Unit pos) { return unit->canRightClickGrouped(pos); },
			[](UnitInterface* unit, Unit pos, bool flag1) { return unit->canRightClickGrouped(pos, flag1); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2) { return unit->canRightClickGrouped(pos, flag1, flag2); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2, bool flag3) { return unit->canRightClickGrouped(pos, flag1, flag2, flag3); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2, bool flag3, bool flag4) { return unit->canRightClickGrouped(pos, flag1, flag2, flag3, flag4); }
		));
	}
}