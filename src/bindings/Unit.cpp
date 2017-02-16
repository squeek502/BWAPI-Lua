#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnit(sol::table module)
	{
		module.new_simple_usertype<UnitInterface>("Unit",
			"new", sol::nil,
			"getID", &UnitInterface::getID,
			"exists", &UnitInterface::exists,
			"isLockedDown", &UnitInterface::isLockedDown,
			"isStasised", &UnitInterface::isStasised,
			"isMaelstrommed", &UnitInterface::isMaelstrommed,
			"isLoaded", &UnitInterface::isLoaded,
			"isPowered", &UnitInterface::isPowered,
			"isStuck", &UnitInterface::isStuck,
			"isCompleted", &UnitInterface::isCompleted,
			"isConstructing", &UnitInterface::isConstructing,
			"getType", &UnitInterface::getType,
			"isIdle", &UnitInterface::isIdle,
			"isCarryingGas", &UnitInterface::isCarryingGas,
			"isCarryingMinerals", &UnitInterface::isCarryingMinerals,
			"returnCargo", &UnitInterface::returnCargo,
			"getPowerUp", &UnitInterface::getPowerUp,
			"gather", &UnitInterface::gather,
			"train", &UnitInterface::train,
			"build", sol::overload(
				[](UnitInterface* unit, UnitType type)
		{
			return unit->build(type);
		},
				[](UnitInterface* unit, UnitType type, TilePosition target)
		{
			return unit->build(type, target);
		}
			),
			"getPosition", &UnitInterface::getPosition,
			"getTilePosition", &UnitInterface::getTilePosition,
			"getClosestUnit", sol::overload(
				[](const UnitInterface* unit)
		{
			return unit->getClosestUnit();
		},
				[](const UnitInterface* unit, const sol::function& pred)
		{
			UnitFilter filter(nullptr);
			if (pred.valid())
				filter = UnitFilter(sol::protected_function(pred));
			return unit->getClosestUnit(filter);
		},
			[](const UnitInterface* unit, const sol::function& pred, int radius)
		{
			UnitFilter filter(nullptr);
			if (pred.valid())
				filter = UnitFilter(sol::protected_function(pred));
			return unit->getClosestUnit(filter, radius);
		}
			)
			);
	}
}