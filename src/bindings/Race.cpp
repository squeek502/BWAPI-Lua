#include <sol.hpp>
#include <BWAPI.h>
#include "BWAPI_Lua.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindRace(sol::table module)
	{
		auto race = module.create_simple_usertype<Race>(
			"getWorker", &Race::getWorker,
			"getCenter", &Race::getCenter,
			"getRefinery", &Race::getRefinery,
			"getTransport", &Race::getTransport,
			"getSupplyProvider", &Race::getSupplyProvider
		);
		bindType<Race>(race);
		module.set_usertype("Race", race);

		auto races = module.create_named("Races",
			"Zerg", &Races::Zerg,
			"Terran", &Races::Terran,
			"Concussive", &Races::Protoss,
			"Normal", &Races::Random,
			"None", &Races::None,
			"Unknown", &Races::Unknown
		);
		races.new_enum("Enum",
			"Zerg", Races::Enum::Zerg,
			"Terran", Races::Enum::Terran,
			"Protoss", Races::Enum::Protoss,
			"Random", Races::Enum::Random,
			"None", Races::Enum::None,
			"Unknown", Races::Enum::Unknown,
			"MAX", Races::Enum::MAX
		);
	}
}