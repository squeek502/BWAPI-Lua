#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindForce(sol::table module)
	{
		module.new_simple_usertype<ForceInterface>("Force",
			sol::meta_function::construct, sol::nil,
			"getID", &ForceInterface::getID,
			"getName", &ForceInterface::getName,
			"getPlayers", &ForceInterface::getPlayers,
			sol::meta_function::to_string, &ForceInterface::getName
		);
	}
}