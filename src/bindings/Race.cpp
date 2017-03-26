#include <sol.hpp>
#include <BWAPI.h>
#include "Type.h"
#include "SetContainer.h"
#include "IsInstance.h"

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
		bindIsInstance(race);
		module.set_usertype("Race", race);

		auto raceSet = module.create_simple_usertype<Race::set>();
		bindSetContainer<Race::set, Race>(raceSet);
		bindIsInstance(raceSet);
		module.set_usertype("Raceset", raceSet);

		auto races = module.create_named("Races",
			"allRaces", &Races::allRaces,
			"Zerg", &Races::Zerg,
			"Terran", &Races::Terran,
			"Protoss", &Races::Protoss,
			"Random", &Races::Random,
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