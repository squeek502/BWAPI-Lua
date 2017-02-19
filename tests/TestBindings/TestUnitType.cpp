#include <catch.hpp>
#include <BWAPI/UnitType.h>
#include <sol.hpp>
#include <BWAPI_Lua.h>
#include "BindingTestHelpers.h"

using namespace BWAPI;
using namespace BWAPI_Lua;

TEST_CASE("unit type bindings", "[unittype]")
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	bindUnitType(lua.create_named_table("BWAPI"));
	lua.script_file(TestBindings::getLuaTestPath(__FILE__));

	SECTION("constructors")
	{
		sol::function test = lua["constructors"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("equality")
	{
		sol::function test = lua["equality"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("tostring")
	{
		sol::function test = lua["toStringTest"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("unit type values")
	{
		bindRace(lua["BWAPI"]);
		bindTechType(lua["BWAPI"]);
		bindUpgradeType(lua["BWAPI"]);
		bindUnitSizeType(lua["BWAPI"]);
		bindPosition(lua["BWAPI"]);
		bindWeaponType(lua["BWAPI"]);

		SECTION("scv")
		{
			sol::function test = lua["valuesOfTheSCVUnitType"];
			REQUIRE_NOTHROW(test());
		}

		SECTION("unknown")
		{
			sol::function test = lua["valuesOfTheUnknownUnitType"];
			REQUIRE_NOTHROW(test());
		}
	}
}