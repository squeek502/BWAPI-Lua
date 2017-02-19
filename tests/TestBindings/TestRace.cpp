#include <catch.hpp>
#include <sol.hpp>
#include <BWAPI_Lua.h>
#include "BindingTestHelpers.h"

using namespace BWAPI_Lua;

TEST_CASE("race bindings", "[race]")
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	bindRace(lua.create_named_table("BWAPI"));
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

	SECTION("race values")
	{
		bindUnitType(lua["BWAPI"]);

		SECTION("Zerg")
		{
			sol::function test = lua["valuesZerg"];
			REQUIRE_NOTHROW(test());
		}

		SECTION("Unknown")
		{
			sol::function test = lua["valuesUnknown"];
			REQUIRE_NOTHROW(test());
		}
	}
}