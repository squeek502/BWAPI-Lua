#include <sol.hpp>
#include <BWAPI.h>
#include "Interface.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindRegion(sol::table module)
	{
		sol::simple_usertype<RegionInterface> region = module.create_simple_usertype<RegionInterface>(
			sol::meta_function::construct, sol::no_constructor,
			"getID", &RegionInterface::getID,
			"getRegionGroupID", &RegionInterface::getRegionGroupID,
			"getCenter", &RegionInterface::getCenter,
			"isHigherGround", &RegionInterface::isHigherGround,
			"getDefensePriority", &RegionInterface::getDefensePriority,
			"isAccessible", &RegionInterface::isAccessible,
			"getNeighbors", &RegionInterface::getNeighbors,
			"getBoundsLeft", &RegionInterface::getBoundsLeft,
			"getBoundsTop", &RegionInterface::getBoundsTop,
			"getBoundsRight", &RegionInterface::getBoundsRight,
			"getBoundsBottom", &RegionInterface::getBoundsBottom,
			"getClosestAccessibleRegion", &RegionInterface::getClosestAccessibleRegion,
			"getClosestInaccessibleRegion", &RegionInterface::getClosestInaccessibleRegion,
			"getDistance", &RegionInterface::getDistance,
			"getUnits", sol::overload(
				[](const Region region) { return region->getUnits(); },
				[](const Region region, const sol::function& pred)
				{
					UnitFilter filter(nullptr);
					if (pred.valid())
						filter = UnitFilter(sol::protected_function(pred));
					return region->getUnits(filter);
				},
				&RegionInterface::getUnits
			)
		);
		bindInterface(region);
		module.set_usertype("Region", region);
	}
}