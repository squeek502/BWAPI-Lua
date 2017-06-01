Writing Modules
===============

Writing a C/C++ Binary Module
-----------------------------

The most simple binary module would be one that is wholly independent of BWAPI-Lua and BWAPI, as it would only need to link to the Lua library. If using the CMake script below, your Lua link library should be named ``lua51.lib`` and placed in ``dependecies/lua/5.1/lib`` within the module's project folder; the necessary Lua header files should be placed in ``dependecies/lua/5.1/include``.

.. code-block:: cmake
   :caption: CMakeLists.txt

   cmake_minimum_required (VERSION 2.6)
   project (HelloWorldModule)

   # Lua
   set(LUA_5_1_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/dependencies/lua/5.1/include)
   set(LUA_5_1_LIB_DIR ${PROJECT_SOURCE_DIR}/dependencies/lua/5.1/lib)
   find_library(LUA_LIB lua51 ${LUA_5_1_LIB_DIR} NO_DEFAULT_PATH)

   # Our Module
   add_library( helloworld SHARED helloworld.cpp helloworld.def )
   set_target_properties( helloworld PROPERTIES LINK_FLAGS "${CMAKE_LINK_DEF_FILE_FLAG}${PROJECT_SOURCE_DIR}/helloworld.def /SUBSYSTEM:WINDOWS" )
   target_link_libraries ( helloworld ${LUA_LIB} )

.. code-block:: c++
   :caption: helloworld.cpp

   #define LUA_LIB
   #include "lauxlib.h"

   LUALIB_API int luaopen_helloworld(lua_State *L)
   {
      // Loading this module will return the string "Hello World!"
      lua_pushstring(L, "Hello World!");
      return 1;
   }

.. code-block:: none
   :caption: helloworld.def

   EXPORTS
   luaopen_helloworld

Once built and placed next to the BWAPI-Lua dll (in the same directory), the following Lua code would work:

.. code-block:: lua
   :caption: init.lua

   local helloWorld = require('helloworld')

   assert(helloWorld == "Hello World!")
   print(helloWorld)

Interacting with BWAPI
^^^^^^^^^^^^^^^^^^^^^^

To write a binary module that interacts with BWAPI, we will need to link against BWAPILIB and make sure its headers are in our include path. If using the CMake script below:

- Your BWAPILIB release library should be named ``BWAPILIB.lib`` and placed in ``dependencies/bwapi/lib`` within the module's project folder
- Your BWAPILIB debug library should be named ``BWAPILIBd.lib`` and placed in ``dependencies/bwapi/lib``
- Your BWAPI header files should be placed in ``dependencies/bwapi/include``
- Lua library/headers should be in the same places as in the previous module

.. important::
   When linking BWAPILIB, your module will contain a separate instance of ``BWAPI::Broodwar`` and a NULL ``BWAPI::BroodwarPtr``. To use ``BWAPI::Broodwar`` in your extension, ``BWAPI::BroodwarPtr`` will need to be set to the value of ``BWAPI.Broodwar`` from the Lua VM, which is a ``BWAPI::Game*`` pushed to Lua as userdata by the Sol2 binding library. The code below shows how to retrieve that value using the Lua C API (see also `the Sol2 docs on this subject <http://sol2.readthedocs.io/en/latest/api/usertype_memory.html#to-retrieve-a-t>`__).

.. code-block:: cmake
   :caption: CMakeLists.txt

   cmake_minimum_required (VERSION 2.6)
   project (HelloWorldModule)

   # BWAPILIB
   set(BWAPI_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/dependencies/bwapi/include)
   set(BWAPI_LIB_DIR ${PROJECT_SOURCE_DIR}/dependencies/bwapi/lib)
   find_library(BWAPILIB_RELEASE_LIB BWAPILIB ${BWAPI_LIB_DIR} NO_DEFAULT_PATH)
   find_library(BWAPILIB_DEBUG_LIB BWAPILIBd ${BWAPI_LIB_DIR} NO_DEFAULT_PATH)

   # Lua
   set(LUA_5_1_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/dependencies/lua/5.1/include)
   set(LUA_5_1_LIB_DIR ${PROJECT_SOURCE_DIR}/dependencies/lua/5.1/lib)
   find_library(LUA_LIB lua51 ${LUA_5_1_LIB_DIR} NO_DEFAULT_PATH)

   # Our Module
   add_library( helloworld SHARED helloworld.cpp helloworld.def )
   set_target_properties( helloworld PROPERTIES LINK_FLAGS "${CMAKE_LINK_DEF_FILE_FLAG}${PROJECT_SOURCE_DIR}/helloworld.def /SUBSYSTEM:WINDOWS" )
   target_link_libraries ( helloworld ${LUA_LIB} optimized ${BWAPILIB_RELEASE_LIB} debug ${BWAPILIB_DEBUG_LIB} )

.. literalinclude:: ../../../examples/C++Extension/helloworld.cpp
   :language: c++
   :caption: `helloworld.cpp <https://github.com/squeek502/BWAPI-Lua/blob/master/examples/C++Extension/helloworld.cpp>`_

.. literalinclude:: ../../../examples/C++Extension/helloworld.def
   :language: c++
   :caption: `helloworld.def <https://github.com/squeek502/BWAPI-Lua/blob/master/examples/C++Extension/helloworld.def>`_

Once built and placed next to the BWAPI-Lua dll (in the same directory), the following Lua code would work:

.. code-block:: lua
   :caption: init.lua

   local helloWorld = require('helloworld')

   assert(type(helloWorld) == "table")
   assert(type(helloWorld.print) == "function")
   helloWorld.print("Hello World!")
