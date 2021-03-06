# BWAPI-Lua
[![Build status](https://ci.appveyor.com/api/projects/status/3ak475f4lbdalb58?svg=true)](https://ci.appveyor.com/project/squeek502/bwapi-lua) [![Documentation Status](https://readthedocs.org/projects/bwapi-lua/badge/?version=latest)](http://bwapi-lua.readthedocs.io/en/latest/?badge=latest)

Lua bindings for the [Brood War API](https://github.com/bwapi/bwapi) using the [sol2](https://github.com/ThePhD/sol2) Lua bindings library, for the purposes of writing StarCraft AI using the [Lua](https://www.lua.org) scripting language.

Currently supports BWAPI version 4.2.0 and Lua 5.1.5 (with planned support for Lua 5.3 and LuaJIT)

## Quick Start

- Install Starcraft, BWAPI, and BWAPI-Lua according to [the installation guide](http://bwapi-lua.readthedocs.io/en/latest/getting-started/installation.html)
- Download [init.lua from examples/LuaExampleAI](examples/LuaExampleAI/init.lua) and move it to `Starcraft/bwapi-data/AI`
- Run Chaoslauncher from the `Chaoslauncher` directory where BWAPI was installed (e.g. `C:\Program Files (x86)\BWAPI\Chaoslauncher`)
- In Chaoslauncher's *Plugins* tab, enable *BWAPI Injector [RELEASE]* and (optionally) *W-MODE*
- Start StarCraft (from Chaoslauncher) and create a new single player game. The AI should begin continuously mining and producing workers

## Important Links

- [Installatation](http://bwapi-lua.readthedocs.io/en/latest/getting-started/installation.html)
- [Your first Lua AI](http://bwapi-lua.readthedocs.io/en/latest/getting-started/your-first-ai.html)
- [Documentation](http://bwapi-lua.readthedocs.io/en/latest/index.html) *(work in progress)*

## Preview: 'Hello World' AI

```lua
local Broodwar = BWAPI.Broodwar

function BWAPI.onStart()
  Broodwar:sendText("Hello world!")
end
```

## Compiling and Testing

- Install [cmake](https://cmake.org/) and make sure it is available in the `PATH`
- Clone this repository
- Run `make.bat` to build. The resulting files can be found in `build/Release`
- Run `make.bat test` to build and run the available tests of the Lua bindings

## Contributing

Running `make.bat projects` will generate Visual Studio project/solution files inside the `build` directory. Once that's finished, open `build/BWAPI_Lua.sln`.

## License

BWAPI-Lua is made available under the [LGPLv3](LICENSE), the same license as [BWAPI](https://github.com/bwapi/bwapi).

The licenses of all dependencies can be found [in their respective directories within `dependencies`](dependencies).