cmake_minimum_required (VERSION 2.6)
project (BWAPI_Lua)

# Dependencies
set(SOL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/dependencies/sol)
set(BWAPI_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/dependencies/bwapi/include)
set(BWAPI_LIB_DIR ${PROJECT_SOURCE_DIR}/dependencies/bwapi/lib)
set(LUA_5_1_SRC_DIR ${PROJECT_SOURCE_DIR}/dependencies/lua/5.1)
set(CATCH_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/dependencies/catch)
add_subdirectory(dependencies/bwapi)

# Lua 5.1
file(GLOB LUA_5_1_SOURCE_FILES ${LUA_5_1_SRC_DIR}/*.h ${LUA_5_1_SRC_DIR}/*.c)
add_library ( Lua51 SHARED ${LUA_5_1_SOURCE_FILES} )
set_source_files_properties(${LUA_5_1_SOURCE_FILES} PROPERTIES LANGUAGE CXX) # Compile as C++
target_compile_definitions ( Lua51 PRIVATE _CRT_SECURE_NO_WARNINGS LUA_BUILD_AS_DLL )
target_compile_definitions ( Lua51 INTERFACE SOL_USING_CXX_LUA SOL_CHECK_ARGUMENTS )
target_include_directories( Lua51 INTERFACE ${LUA_5_1_SRC_DIR} )
set_target_properties( Lua51 PROPERTIES OUTPUT_NAME lua51 )

# Bindings for Lua 5.1
set(LUA_BINDINGS_DIR ${PROJECT_SOURCE_DIR}/src/bindings)
file(GLOB LUA_BINDINGS_SOURCE_FILES ${LUA_BINDINGS_DIR}/*.h ${LUA_BINDINGS_DIR}/*.cpp)
add_library ( Lua51Bindings ${LUA_BINDINGS_SOURCE_FILES} )
target_include_directories( Lua51Bindings INTERFACE ${LUA_BINDINGS_DIR} )
target_include_directories( Lua51Bindings PUBLIC ${SOL_INCLUDE_DIR} ${BWAPI_INCLUDE_DIR} )
target_link_libraries ( Lua51Bindings Lua51 )

# LuaAIModule for Lua 5.1
set(LUA_AI_MODULE_DIR ${PROJECT_SOURCE_DIR}/src/module)
file(GLOB LUA_AI_MODULE_SOURCE_FILES  ${LUA_AI_MODULE_DIR}/*.h ${LUA_AI_MODULE_DIR}/*.cpp)
add_library ( Lua51AIModule SHARED ${LUA_AI_MODULE_SOURCE_FILES} )
target_link_libraries ( Lua51AIModule Lua51Bindings BWAPI )
set_target_properties( Lua51AIModule PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS" )

# Tests for Lua 5.1 Bindings
set(TEST_LUA_BINDINGS_DIR ${PROJECT_SOURCE_DIR}/tests/TestBindings)
file(GLOB TEST_LUA_BINDINGS_SOURCE_FILES ${TEST_LUA_BINDINGS_DIR}/*.h ${TEST_LUA_BINDINGS_DIR}/*.cpp)
add_executable ( TestLua51Bindings ${TEST_LUA_BINDINGS_SOURCE_FILES} )
target_include_directories( TestLua51Bindings PUBLIC ${CATCH_INCLUDE_DIR} )
target_link_libraries ( TestLua51Bindings Lua51Bindings Lua51 BWAPI )