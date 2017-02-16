#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindFlag(sol::table module)
	{
		module.create_named("Flag",
			"CompleteMapInformation", Flag::CompleteMapInformation,
			"UserInput", Flag::UserInput,
			"Max", Flag::Max
		);
	}
}