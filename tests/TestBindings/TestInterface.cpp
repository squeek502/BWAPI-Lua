#include <catch.hpp>
#include <sol.hpp>
#include <BWAPI_Lua.h>
#include "BindingTestHelpers.h"
#include "MockGame.h"
#include "MockUnit.h"

using namespace BWAPI;
using namespace BWAPI_Lua;

TEST_CASE("interface bindings", "[interface]")
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	auto BWAPI = lua.create_named_table("BWAPI");
	bindGame(BWAPI);
	bindUnit(BWAPI);
	TestBindings::bindMockGameImpl(BWAPI);
	TestBindings::bindMockUnitImpl(BWAPI);
	lua.script_file(TestBindings::getLuaTestPath(__FILE__));

	SECTION("client info")
	{
		sol::function test = lua["clientInfo"];
		REQUIRE_NOTHROW(test());
	}
}