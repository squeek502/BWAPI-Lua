# BWAPI-Lua
Lua bindings for the [Brood War API](https://github.com/bwapi/bwapi) using the [sol2](https://github.com/ThePhD/sol2) Lua bindings library.

Note: This is a work-in-progress: not everything has bindings yet

Currently supports BWAPI version 4.1.2

## Quick Start

- Install StarCraft: Brood War and make sure its updated it to the latest version
- Download and install [BWAPI](https://github.com/bwapi/bwapi/releases)
- Download the [BWAPI-Lua .dll for the version of Lua you want to use](https://github.com/squeek502/BWAPI-Lua/releases) and move it to `Starcraft/bwapi-data/AI` (e.g. `C:\Program Files (x86)\StarCraft\bwapi-data\AI`)
- Edit `Starcraft/bwapi-data/bwapi.ini` and change the line `ai = bwapi-data/AI/ExampleAIModule.dll` to point to the BWAPI-Lua dll you just installed (e.g. `ai = bwapi-data/AI/Lua51AIModule.dll`)
- Download [init.lua from examples/LuaExampleAI](examples/LUAExampleAI/init.lua) and move it to `Starcraft/bwapi-data/AI`
- Run Chaoslauncher from the `Chaoslauncher` directory where BWAPI was installed (e.g. `C:\Program Files (x86)\BWAPI\Chaoslauncher`)
- In Chaoslauncher's *Plugins* tab, enable *BWAPI Injector [RELEASE]* and (optionally) *W-MODE*
- Start StarCraft (from Chaoslauncher) and create a new single player game. The AI should begin continuously mining and producing workers

## Important Links

- [Your first Lua AI]() *(coming soon)*
- [Documentation]() *(coming soon)*

## Preview: 'Hello World' AI

```lua
local Broodwar = BWAPI.Broodwar

function BWAPI.onStart()
  Broodwar:sendText("Hello world!")
end
```

## Compiling and Testing

- Clone this repository
- Run `make.bat` to build. The resulting files can be found in `build/Release`
- Run `make.bat test` to build and run the available tests of the Lua bindings

## Contributing

Running `make.bat projects` will generate Visual Studio project/solution files inside the `build` directory. Once that's finished, open `build/BWAPI_Lua.sln`.

## License

BWAPI-Lua is made available under the [LGPLv3](LICENSE), the same license as [BWAPI](https://github.com/bwapi/bwapi).

The licenses of all dependencies can be found [in their respective directories within `dependencies`](dependencies).