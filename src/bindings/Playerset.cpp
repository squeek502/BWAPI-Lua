#include <sol.hpp>
#include <BWAPI.h>
#include "SetContainer.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPlayerset(sol::table module)
	{
		sol::simple_usertype<Playerset> userTypePlayerset = module.create_simple_usertype<Playerset>(
			"getUnits", &Playerset::getUnits,
			"getRaces", &Playerset::getRaces,
			"setAlliance", sol::overload(
				[](Playerset& set) { return set.setAlliance(); },
				[](Playerset& set, bool allies) { return set.setAlliance(allies); },
				&Playerset::setAlliance
			)
		);
		bindSetContainer<Playerset, Player>(userTypePlayerset);
		bindIsInstance(userTypePlayerset);
		module.set_usertype("Playerset", userTypePlayerset);
	}
}