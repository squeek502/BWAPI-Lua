#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnit_canAttackGrouped(sol::simple_usertype<UnitInterface>& unit)
	{
		unit.set("canAttackGrouped", sol::overload(
			[](UnitInterface* unit) { return unit->canAttackGrouped(); },
			[](UnitInterface* unit, bool flag1) { return unit->canAttackGrouped(flag1); },
			static_cast<bool (UnitInterface::*)(bool, bool) const>(&UnitInterface::canAttackGrouped),

			[](UnitInterface* unit, const Position& pos) { return unit->canAttackGrouped(PositionOrUnit(pos)); },
			[](UnitInterface* unit, const Position& pos, bool flag1) { return unit->canAttackGrouped(PositionOrUnit(pos), flag1); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2) { return unit->canAttackGrouped(PositionOrUnit(pos), flag1, flag2); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2, bool flag3) { return unit->canAttackGrouped(PositionOrUnit(pos), flag1, flag2, flag3); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2, bool flag3, bool flag4) { return unit->canAttackGrouped(PositionOrUnit(pos), flag1, flag2, flag3, flag4); },
			[](UnitInterface* unit, Unit pos) { return unit->canAttackGrouped(PositionOrUnit(pos)); },
			[](UnitInterface* unit, Unit pos, bool flag1) { return unit->canAttackGrouped(PositionOrUnit(pos), flag1); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2) { return unit->canAttackGrouped(PositionOrUnit(pos), flag1, flag2); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2, bool flag3) { return unit->canAttackGrouped(PositionOrUnit(pos), flag1, flag2, flag3); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2, bool flag3, bool flag4) { return unit->canAttackGrouped(PositionOrUnit(pos), flag1, flag2, flag3, flag4); }
		));
	}
}