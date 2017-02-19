#include <catch.hpp>
#include <BWAPI/UnitType.h>
#include <sol.hpp>
#include <BWAPI_Lua.h>
#include "BindingTestHelpers.h"

using namespace BWAPI;
using namespace BWAPI_Lua;

TEST_CASE("weapon type bindings", "[weapontype]")
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	bindWeaponType(lua.create_named_table("BWAPI"));
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

	SECTION("weapon type values")
	{
		bindRace(lua["BWAPI"]);
		bindTechType(lua["BWAPI"]);
		bindUpgradeType(lua["BWAPI"]);
		bindUnitSizeType(lua["BWAPI"]);
		bindPosition(lua["BWAPI"]);
		bindUnitType(lua["BWAPI"]);
		bindDamageType(lua["BWAPI"]);
		bindExplosionType(lua["BWAPI"]);

		SECTION("Gauss_Rifle")
		{
			sol::function test = lua["valuesOfTheGaussRifleType"];
			REQUIRE_NOTHROW(test());
		}

		SECTION("Unknown")
		{
			sol::function test = lua["valuesOfTheUnknownType"];
			REQUIRE_NOTHROW(test());
		}
	}
}