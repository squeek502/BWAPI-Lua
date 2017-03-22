#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnit_canAttack(sol::simple_usertype<UnitInterface>& unit)
	{
		unit.set("canAttack", sol::overload(
			[](UnitInterface* unit) { return unit->canAttack(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canAttack),

			[](UnitInterface* unit, const Position& pos) { return unit->canAttack(PositionOrUnit(pos)); },
			[](UnitInterface* unit, const Position& pos, bool flag1) { return unit->canAttack(PositionOrUnit(pos), flag1); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2) { return unit->canAttack(PositionOrUnit(pos), flag1, flag2); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2, bool flag3) { return unit->canAttack(PositionOrUnit(pos), flag1, flag2, flag3); },
			[](UnitInterface* unit, Unit pos) { return unit->canAttack(PositionOrUnit(pos)); },
			[](UnitInterface* unit, Unit pos, bool flag1) { return unit->canAttack(PositionOrUnit(pos), flag1); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2) { return unit->canAttack(PositionOrUnit(pos), flag1, flag2); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2, bool flag3) { return unit->canAttack(PositionOrUnit(pos), flag1, flag2, flag3); }
		));
	}
}