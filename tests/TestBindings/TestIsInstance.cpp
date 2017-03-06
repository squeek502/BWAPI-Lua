#include <catch.hpp>
#include <sol.hpp>
#include <BWAPI_Lua.h>
#include "BindingTestHelpers.h"
#include "MockUnit.h"

using namespace BWAPI_Lua;

TEST_CASE("isInstance bindings", "[isInstance]")
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	auto BWAPI = lua.create_named_table("BWAPI");
	bindUnit(BWAPI);
	TestBindings::bindMockUnitImpl(BWAPI);
	bindPosition(BWAPI);
	lua.script_file(TestBindings::getLuaTestPath(__FILE__));

	sol::function test = lua["isInstance"];
	REQUIRE_NOTHROW(test());
}