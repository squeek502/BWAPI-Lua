#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPlayer(sol::table module)
	{
		module.new_simple_usertype<PlayerInterface>("Player",
			"new", sol::nil,
			"getID", &PlayerInterface::getID,
			"getName", &PlayerInterface::getName,
			"isObserver", &PlayerInterface::isObserver,
			"getRace", &PlayerInterface::getRace,
			"getUnits", &PlayerInterface::getUnits,
			"isNeutral", &PlayerInterface::isNeutral,
			"incompleteUnitCount", &PlayerInterface::incompleteUnitCount,
			sol::meta_function::to_string, [](const PlayerInterface* player)
		{
			return player->getName();
		}
		);
	}
}