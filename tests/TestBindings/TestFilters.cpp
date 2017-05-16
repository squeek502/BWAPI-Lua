#include <catch.hpp>
#include <sol.hpp>
#include <BWAPI_Lua.h>
#include "BindingTestHelpers.h"
#include "MockUnit.h"

using namespace BWAPI_Lua;

TEST_CASE("Filters", "[filter]")
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	auto BWAPI = lua.create_named_table("BWAPI");
	bindUnit(BWAPI);
	TestBindings::bindMockUnitImpl(BWAPI);
	bindFilters(BWAPI);
	lua.script_file(TestBindings::getLuaTestPath(__FILE__));

	SECTION("Lowest")
	{
		sol::function test = lua["lowest"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("Highest")
	{
		sol::function test = lua["highest"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("Unary unit filters")
	{
		sol::function test = lua["unaryUnitFilter"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("Comparison unit filters")
	{
		sol::function test = lua["comparisonUnitFilter"];
		REQUIRE_NOTHROW(test());
	}
}