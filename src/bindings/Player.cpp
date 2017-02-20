#include <sol.hpp>
#include <BWAPI.h>
#include "Interface.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPlayer(sol::table module)
	{
		sol::simple_usertype<PlayerInterface> player = module.create_simple_usertype<PlayerInterface>(
			"new", sol::nil,
			"getID", &PlayerInterface::getID,
			"getName", &PlayerInterface::getName,
			"isObserver", &PlayerInterface::isObserver,
			"getRace", &PlayerInterface::getRace,
			"getUnits", &PlayerInterface::getUnits,
			"isNeutral", &PlayerInterface::isNeutral,
			"incompleteUnitCount", &PlayerInterface::incompleteUnitCount,
			sol::meta_function::to_string, &PlayerInterface::getName
		);
		bindInterface(player);
		module.set_usertype("Player", player);
	}
}