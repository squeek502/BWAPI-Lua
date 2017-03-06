#include <sol.hpp>
#include <BWAPI.h>
#include "Interface.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindForce(sol::table module)
	{
		sol::simple_usertype<ForceInterface> force = module.create_simple_usertype<ForceInterface>(
			sol::meta_function::construct, sol::nil,
			"getID", &ForceInterface::getID,
			"getName", &ForceInterface::getName,
			"getPlayers", &ForceInterface::getPlayers,
			sol::meta_function::to_string, &ForceInterface::getName
		);
		bindInterface(force);
		bindIsInstance(force);
		module.set_usertype("Force", force);
	}
}