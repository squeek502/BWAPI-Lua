#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnit_canSetRallyPoint(sol::simple_usertype<UnitInterface>& unit)
	{
		unit.set("canSetRallyPoint", sol::overload(
			[](UnitInterface* unit) { return unit->canSetRallyPoint(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canSetRallyPoint),

			[](UnitInterface* unit, const Position& pos) { return unit->canSetRallyPoint(pos); },
			[](UnitInterface* unit, const Position& pos, bool flag1) { return unit->canSetRallyPoint(pos, flag1); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2) { return unit->canSetRallyPoint(pos, flag1, flag2); },
			[](UnitInterface* unit, const Position& pos, bool flag1, bool flag2, bool flag3) { return unit->canSetRallyPoint(pos, flag1, flag2, flag3); },
			[](UnitInterface* unit, Unit pos) { return unit->canSetRallyPoint(pos); },
			[](UnitInterface* unit, Unit pos, bool flag1) { return unit->canSetRallyPoint(pos, flag1); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2) { return unit->canSetRallyPoint(pos, flag1, flag2); },
			[](UnitInterface* unit, Unit pos, bool flag1, bool flag2, bool flag3) { return unit->canSetRallyPoint(pos, flag1, flag2, flag3); }
		));
	}
}