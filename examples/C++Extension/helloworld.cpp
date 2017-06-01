#define LUA_LIB
#include "lauxlib.h"
#include "BWAPI.h"

static int helloworld_print(lua_State *L)
{
	const char* msg = luaL_checkstring(L, 1);
	BWAPI::Broodwar << msg << std::endl;
	return 0;
}

LUALIB_API int luaopen_helloworld(lua_State *L)
{
	// If BWAPI::Broodwar is used, we need to set it to the same pointer that BWAPI-Lua uses,
	// so we need to grab that from BWAPI.Broodwar
	lua_getglobal(L, "BWAPI");
	lua_getfield(L, -1, "Broodwar");
	void* data = lua_touserdata(L, -1);
	BWAPI::Game* bw = *static_cast<BWAPI::Game**>(data);
	BWAPI::BroodwarPtr = bw;
	lua_settop(L, 0); // clear the stack

	// Create a table with a 'print' function that prints to the BW chat
	lua_newtable(L);
	int tableIndex = lua_gettop(L);
	lua_pushcfunction(L, &helloworld_print);
	lua_setfield(L, tableIndex, "print");

	// Return the table since it's still on the stack
	return 1;
}