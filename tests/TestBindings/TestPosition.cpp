#include <catch.hpp>
#include <BWAPI/Position.h>
#include <sol.hpp>
#include <BWAPI_Lua.h>
#include "BindingTestHelpers.h"

using namespace BWAPI;
using namespace BWAPI_Lua;

TEST_CASE("position bindings", "[position]")
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	bindPosition(lua.create_named_table("BWAPI"));
	lua.script_file(TestBindings::getLuaTestPath(__FILE__));

	SECTION("default constructors") 
	{
		sol::function test = lua["defaultConstructors"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("constructors with values")
	{
		sol::function test = lua["constructorsWithValues"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("conversion constructors")
	{
		sol::function test = lua["conversionConstructors"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("equality")
	{
		sol::function test = lua["equality"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("positions can be valid or invalid")
	{
		sol::function test = lua["positionsCanBeValidOrInvalid"];
		REQUIRE_NOTHROW(test());

		SECTION("positions can be made valid")
		{
			sol::function test = lua["positionsCanBeMadeValid"];
			REQUIRE_NOTHROW(test());

			SECTION("valid position values match expectations")
			{
				sol::function test = lua["validPositionValuesMatchExpectations"];
				REQUIRE_NOTHROW(test());
			}
		}
	}

	SECTION("less than comparison")
	{
		sol::function test = lua["lessThanComparison"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("addition")
	{
		sol::function test = lua["addition"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("subtraction")
	{
		sol::function test = lua["subtraction"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("multiplication")
	{
		sol::function test = lua["multiplication"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("division")
	{
		sol::function test = lua["division"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("modulus")
	{
		sol::function test = lua["modulus"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("setMin")
	{
		sol::function test = lua["setMin"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("setMax")
	{
		sol::function test = lua["setMax"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("tostring")
	{
		sol::function test = lua["testToString"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("getLength")
	{
		sol::function test = lua["getLength"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("getDistance")
	{
		sol::function test = lua["getDistance"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("getApproxDistance")
	{
		sol::function test = lua["getApproxDistance"];
		REQUIRE_NOTHROW(test());
	}
}