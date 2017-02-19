#include <sol.hpp>
#include <BWAPI.h>
#include "CommonBindings.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPlayerset(sol::table module)
	{
		auto userTypePlayerset = module.create_simple_usertype<Playerset>();
		bindSetContainer<Playerset, Player>(userTypePlayerset);
		module.set_usertype("Playerset", userTypePlayerset);
	}
}