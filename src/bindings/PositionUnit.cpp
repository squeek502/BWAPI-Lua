#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPositionOrUnit(sol::table module)
	{
		auto constructors = sol::factories(
			[]() { return PositionOrUnit(); },
			[](Unit unit) { return PositionOrUnit(unit); },
			[](Position pos) { return PositionOrUnit(pos); }
		);
		module.new_simple_usertype<PositionOrUnit>("PositionOrUnit",
			sol::meta_function::construct, constructors,
			sol::call_constructor, constructors,
			"isUnit", &PositionOrUnit::isUnit,
			"getUnit", &PositionOrUnit::getUnit,
			"isPosition", &PositionOrUnit::isPosition,
			"getPosition", &PositionOrUnit::getPosition
		);
	}
}