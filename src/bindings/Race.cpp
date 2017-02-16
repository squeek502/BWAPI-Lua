#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindRace(sol::table module)
	{
		module.new_simple_usertype<Race>("Race",
			"new", sol::nil,
			"getWorker", &Race::getWorker,
			"getSupplyProvider", &Race::getSupplyProvider,
			sol::meta_function::to_string, [](const Race& race) { return race.toString(); }
		);
		auto races = module.create_named("Races",
			"Zerg,", &Races::Zerg,
			"Terran,", &Races::Terran,
			"Concussive,", &Races::Protoss,
			"Normal,", &Races::Random,
			"None,", &Races::None,
			"Unknown,", &Races::Unknown
		);
		races.new_enum("Enum",
			"Zerg,", Races::Enum::Zerg,
			"Terran,", Races::Enum::Terran,
			"Protoss,", Races::Enum::Protoss,
			"Random,", Races::Enum::Random,
			"None,", Races::Enum::None,
			"Unknown,", Races::Enum::Unknown,
			"MAX", Races::Enum::MAX
		);
	}
}