#include <sol.hpp>
#include <BWAPI.h>
#include "BWAPI_Lua.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPlayerset(sol::table module)
	{
		auto userTypePlayerset = module.create_simple_usertype<Playerset>(
			"getUnits", &Playerset::getUnits,
			"getRaces", &Playerset::getRaces,
			"setAlliance", sol::overload(
				[](Playerset& set) { return set.setAlliance(); },
				[](Playerset& set, bool allies) { return set.setAlliance(allies); },
				&Playerset::setAlliance
			)
		);
		bindSetContainer<Playerset, Player>(userTypePlayerset);
		module.set_usertype("Playerset", userTypePlayerset);
	}
}