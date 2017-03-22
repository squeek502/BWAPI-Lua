#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnit_canUseTech(sol::simple_usertype<UnitInterface>& unit)
	{
		unit.set("canUseTech", sol::overload(
			[](UnitInterface* unit, TechType target) { return unit->canUseTech(target); },
			[](UnitInterface* unit, TechType target, const Position& pos) { return unit->canUseTech(target, PositionOrUnit(pos)); },
			[](UnitInterface* unit, TechType target, const Position& pos, bool flag1) { return unit->canUseTech(target, PositionOrUnit(pos), flag1); },
			[](UnitInterface* unit, TechType target, const Position& pos, bool flag1, bool flag2) { return unit->canUseTech(target, PositionOrUnit(pos), flag1, flag2); },
			[](UnitInterface* unit, TechType target, const Position& pos, bool flag1, bool flag2, bool flag3) { return unit->canUseTech(target, PositionOrUnit(pos), flag1, flag2, flag3); },
			[](UnitInterface* unit, TechType target, const Position& pos, bool flag1, bool flag2, bool flag3, bool flag4) { return unit->canUseTech(target, PositionOrUnit(pos), flag1, flag2, flag3, flag4); },
			[](UnitInterface* unit, TechType target, Unit pos) { return unit->canUseTech(target, PositionOrUnit(pos)); },
			[](UnitInterface* unit, TechType target, Unit pos, bool flag1) { return unit->canUseTech(target, PositionOrUnit(pos), flag1); },
			[](UnitInterface* unit, TechType target, Unit pos, bool flag1, bool flag2) { return unit->canUseTech(target, PositionOrUnit(pos), flag1, flag2); },
			[](UnitInterface* unit, TechType target, Unit pos, bool flag1, bool flag2, bool flag3) { return unit->canUseTech(target, PositionOrUnit(pos), flag1, flag2, flag3); },
			[](UnitInterface* unit, TechType target, Unit pos, bool flag1, bool flag2, bool flag3, bool flag4) { return unit->canUseTech(target, PositionOrUnit(pos), flag1, flag2, flag3, flag4); }
		));
	}
}