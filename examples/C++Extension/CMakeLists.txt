cmake_minimum_required (VERSION 2.6)
project (HelloWorldModule)

# Grab the Lua/BWAPI projects from the BWAPI-Lua project
add_subdirectory(../.. . EXCLUDE_FROM_ALL)

# Our Module
add_library( helloworld SHARED helloworld.cpp helloworld.def )
set_target_properties( helloworld PROPERTIES LINK_FLAGS "${CMAKE_LINK_DEF_FILE_FLAG}${PROJECT_SOURCE_DIR}/helloworld.def /SUBSYSTEM:WINDOWS" )
target_link_libraries ( helloworld Lua51 BWAPILIB )