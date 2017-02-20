#include <catch.hpp>
#include <sol.hpp>
#include <BWAPI_Lua.h>
#include "MockUnit.h"
#include "BindingTestHelpers.h"

using namespace BWAPI_Lua;

TEST_CASE("UnitOrPosition bindings", "[unitorposition]")
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	auto module = lua.create_named_table("BWAPI");
	bindPosition(module);
	bindUnit(module);
	TestBindings::bindMockUnitImpl(module);
	bindPositionOrUnit(module);
	lua.script_file(TestBindings::getLuaTestPath(__FILE__));

	SECTION("constructors")
	{
		sol::function test = lua["constructors"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("null unit")
	{
		sol::function test = lua["nullUnit"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("unit")
	{
		sol::function test = lua["unit"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("position")
	{
		sol::function test = lua["position"];
		REQUIRE_NOTHROW(test());
	}
}