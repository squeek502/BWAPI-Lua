#include <sol.hpp>
#include <BWAPI.h>
#include "SetContainer.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindForceset(sol::table module)
	{
		auto forceset = module.create_simple_usertype<Forceset>(
			"getPlayers", &Forceset::getPlayers
		);
		bindSetContainer<Forceset, Force>(forceset);
		bindIsInstance(forceset);
		module.set_usertype("Forceset", forceset);
	}
}