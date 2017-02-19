#include <sol.hpp>
#include <BWAPI.h>
#include "CommonBindings.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnitset(sol::table module)
	{
		auto unitset = module.create_simple_usertype<Unitset>();
		bindSetContainer<Unitset, Unit>(unitset);
		module.set_usertype("Unitset", unitset);
	}
}