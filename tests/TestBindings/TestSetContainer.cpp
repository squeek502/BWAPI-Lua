#include <catch.hpp>
#include <BWAPI/Position.h>
#include <sol.hpp>
#include <BWAPI_Lua.h>
#include "BindingTestHelpers.h"

using namespace BWAPI;
using namespace BWAPI_Lua;

TEST_CASE("setcontainer bindings", "[setcontainer]")
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	bindUnitType(lua.create_named_table("BWAPI"));
	lua.script_file(TestBindings::getLuaTestPath(__FILE__));

	SECTION("default constructor")
	{
		sol::function test = lua["defaultConstructor"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("table constructor")
	{
		sol::function test = lua["tableConstructor"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("copy constructor")
	{
		sol::function test = lua["copyConstructor"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("iterator")
	{
		sol::function test = lua["iterator"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("asTable")
	{
		sol::function test = lua["asTable"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("count")
	{
		sol::function test = lua["count"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("size")
	{
		sol::function test = lua["size"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("contains")
	{
		sol::function test = lua["contains"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("empty")
	{
		sol::function test = lua["empty"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("insert")
	{
		sol::function test = lua["insert"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("erase")
	{
		sol::function test = lua["erase"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("clear")
	{
		sol::function test = lua["clear"];
		REQUIRE_NOTHROW(test());
	}

	SECTION("equality")
	{
		bindDamageType(lua["BWAPI"]);
		sol::function test = lua["equality"];
		REQUIRE_NOTHROW(test());
	}

}