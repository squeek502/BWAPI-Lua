#include <catch.hpp>
#include <sol.hpp>
#include <BWAPI_Lua.h>
#include "BindingTestHelpers.h"
#include "MockGame.h"

using namespace BWAPI;
using namespace BWAPI_Lua;

TEST_CASE("game bindings", "[game]")
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	auto BWAPI = lua.create_named_table("BWAPI");
	bindGame(BWAPI);
	TestBindings::bindMockGameImpl(BWAPI);
	lua.script_file(TestBindings::getLuaTestPath(__FILE__));

	SECTION("mouse/key states")
	{
		bindInput(BWAPI);
		sol::function test = lua["mouseKeyStates"];
		REQUIRE_NOTHROW(test());
	}
}