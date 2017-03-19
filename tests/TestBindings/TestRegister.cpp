#include <catch.hpp>
#include <sol.hpp>
#include <BWAPI_Lua.h>

using namespace BWAPI_Lua;

TEST_CASE("register lua module", "[register]")
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	REQUIRE_NOTHROW(requireBWAPI(lua));
}