Game
****

.. currentmodule:: BWAPI

.. class:: Game

   The :class:`~BWAPI.Game` class is implemented by :mod:`BWAPI` and is the primary means of obtaining all game state information from Starcraft Broodwar.

   Game state information includes all units, resources, players, forces, bullets, terrain, fog of war, regions, etc.

   .. seealso::
      :attr:`BWAPI.Broodwar`

   .. rubric:: Constructors

   This class is not constructable through Lua.

   .. rubric:: Member Variables

   .. include:: /_include/interface-clientinfo.rst

   .. rubric:: Member Functions

   .. include:: /_include/interface-functions.rst

   .. method:: allies() -> Playerset

      Retrieves a set of all the current player's remaining allies.

      :return: :class:`~BWAPI.Playerset` containing all allied players.
      :rtype: :class:`BWAPI.Playerset`

   .. method:: canBuildHere(position, type, [builder = nil], [checkExplored = false]) -> boolean

      Checks if the given unit type can be built at the given build tile position.

      This function checks for creep, power, and resource distance requirements in addition to the tiles' buildability and possible units obstructing the build location.

      :param BWAPI.TilePosition position: Indicates the tile position that the top left corner of the structure is intended to go.
      :param BWAPI.UnitType type: The :class:`~BWAPI.UnitType` to check for.
      :param BWAPI.Unit builder: (optional) The intended unit that will build the structure. If specified, then this function will also check if there is a path to the build site and exclude the builder from the set of units that may be blocking the build site.
      :param boolean checkExplored: (optional) If this parameter is true, it will also check if the target position has been explored by the current player. This value is false by default, ignoring the explored state of the build site.

      :return: true indicating that the structure can be placed at the given tile position, and false if something may be obstructing the build location.
      :rtype: boolean

      .. note::
         If the type is an addon and a builer is provided, then the location of the addon will be placed 4 tiles to the right and 1 tile down from the given ``position``. If the builder is not given, then the check for the addon will be conducted at position.

   .. method:: canMake(type, [builder = nil]) -> boolean

      Checks all the requirements in order to make a given unit type for the current player.

      These include resources, supply, technology tree, availability, and required units.

      :param BWAPI.UnitType type: The :class:`~BWAPI.UnitType` to check.
      :param BWAPI.Unit builder: (optional) The Unit that will be used to build/train the provided unit ``type``. If this value is nil or excluded, then the builder will be excluded in the check.

      :return: true indicating that the type can be made. If ``builder`` is provided, then it is only true if ``builder`` can make the ``type``. Otherwise it will return false, indicating that the unit type can not be made.
      :rtype: boolean

   .. method:: canResearch(type, [unit = nil], [checkCanIssueCommandType = true]) -> boolean

      Checks all the requirements in order to research a given technology type for the current player.

      These include resources, technology tree, availability, and required units.

      :param BWAPI.TechType type: The :class:`~BWAPI.TechType` to check.
      :param BWAPI.Unit unit: (optional) The Unit that will be used to research the provided technology ``type``. If this value is nil or excluded, then the unit will be excluded in the check.
      :param boolean checkCanIssueCommandType: (optional) TODO fill this in

      :return: true indicating that the type can be researched. If ``unit`` is provided, then it is only true if ``unit`` can research the ``type``. Otherwise it will return false, indicating that the technology can not be researched.
      :rtype: boolean

   .. method:: canUpgrade(type, [unit = nil], [checkCanIssueCommandType = true]) -> boolean

      Checks all the requirements in order to upgrade a given upgrade type for the current player.

      These include resources, technology tree, availability, and required units.

      :param BWAPI.UpgradeType type: The :class:`~BWAPI.UpgradeType` to check.
      :param BWAPI.Unit unit: (optional) The Unit that will be used to upgrade the provided upgrade ``type``. If this value is nil or excluded, then the unit will be excluded in the check.
      :param boolean checkCanIssueCommandType: (optional) TODO fill this in

      :return: true indicating that the type can be upgraded. If ``unit`` is provided, then it is only true if ``unit`` can upgrade the ``type``. Otherwise it will return false, indicating that the upgrade can not be upgraded.
      :rtype: boolean

   .. method:: countdownTimer() -> int

      Returns the remaining countdown time.

      The countdown timer is used in :attr:`Capture The Flag <BWAPI.GameTypes.Capture_The_Flag>` and :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game types.

      :return: Integer containing the time (in game seconds) on the countdown timer.
      :rtype: int

      .. code-block:: lua
         :caption: Example usage

         local Broodwar = BWAPI.Broodwar

         function BWAPI.onStart()
           -- Register a callback that only occurs once when the countdown timer reaches 0
           if Broodwar:getGameType() == BWAPI.GameTypes.Capture_The_Flag or
              Broodwar:getGameType() == BWAPI.GameTypes.Team_Capture_The_Flag
           then
             Broodwar:registerEvent(
               function() Broodwar:sendText("Try to find my flag!") end,
               function() return Broodwar:countdownTimer() == 0 end,
               1
             )
           end
         end

   .. method:: elapsedTime() -> int

      Retrieves current amount of time in seconds that the game has elapsed.

      :return: Time, in seconds, that the game has elapsed as an integer.
      :rtype: int

   .. method:: enableFlag(flag)

      Enables the state of a given flag.

      :param int flag: The :mod:`~BWAPI.Flag` entry describing the flag's effects on :mod:`BWAPI`.

      .. note::
         Flags may only be enabled at the start of the match during the :meth:`BWAPI.onStart` callback.

      .. seealso::
         :mod:`~BWAPI.Flag`

   .. method:: enemies() -> Playerset

      Retrieves a set of all the current player's remaining enemies.

      :return: :class:`~BWAPI.Playerset` containing all enemy players.
      :rtype: :class:`BWAPI.Playerset`

   .. method:: enemy() -> Player

      Retrieves the Player interface that represents the enemy player.

      If there is more than one enemy, and that enemy is destroyed, then this function will still retrieve the same, defeated enemy. If you wish to handle multiple opponents, see the :meth:`Game.enemies` function.

      :return: Player interface representing an enemy player. Returns ``nil`` if there is no enemy or the current game is a replay.
      :rtype: :class:`BWAPI.Player`

      .. seealso::
         :meth:`enemies`

   .. method:: getAllRegions() -> Regionset

      Retrieves the set of all regions on the map.

      :return: :class:`~BWAPI.Regionset` containing all map regions.
      :rtype: :class:`BWAPI.Regionset`

   .. method:: getAllUnits() -> Unitset

      Retrieves the set of all accessible units.

      If :attr:`BWAPI.Flag.CompleteMapInformation` is enabled, then the set also includes units that are not visible to the player.

      :return: :class:`~BWAPI.Unitset` containing all known units in the game.
      :rtype: :class:`BWAPI.Unitset`

      .. note::
         Units that are inside refineries are not included in this set.

   .. method:: getAPM([includeSelects = false]) -> int

      Retrieves the Actions Per Minute (APM) that the bot is producing.

      :param boolean includeSelects: (optional) If true, the return value will include selections as individual commands, otherwise it will exclude selections. This value is false by default.

      :return: The number of actions that the bot has executed per minute, on average.
      :rtype: int

   .. method:: getAverageFPS() -> double

      Retrieves the average logical frame rate of the game in frames per second (FPS).

      :return: Average logical frames per second that the game is currently running at as a double.
      :rtype: double

      .. seealso::
         :meth:`getFPS`

   .. method:: getBestUnit(best, pred, [center = Positions.Origin], [radius = 999999]) -> Unit

      Compares all units that match ``pred`` using ``best`` to determine which of them is the best.

      All units are checked. If center and radius are specified, then it will check all units that are within the radius of the position.

      :param function best: A function that takes two :class:`Unit` arguments and returns the best out of the two.
      :param function pred: A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`).
      :param BWAPI.Position center: (optional) The position to use in the search. If omitted, then the entire map is searched.
      :param int radius: (optional) The distance from ``center`` to search for units. If omitted, then the entire map is searched.

      :return: The desired unit that best matches the given criteria. Returns ``nil`` if a suitable unit was not found.
      :rtype: :class:`BWAPI.Unit`

      .. seealso::
         :meth:`getClosestUnit`, :mod:`~BWAPI.Filter`, :meth:`BWAPI.Lowest`, :meth:`BWAPI.Highest`

   .. method:: getBuildLocation(type, desiredPosition, [maxRange = 64], [creep = false]) -> TilePosition

      Retrieves a basic build position just as the default Computer AI would.

      This allows users to find simple build locations without relying on external libraries.

      :param BWAPI.UnitType type: A valid :class:`~BWAPI.UnitType` representing the unit type to accomodate space for.
      :param BWAPI.TilePosition desiredPosition: A valid TilePosition containing the desired placement position.
      :param int maxRange: (optional) The maximum distance (in tiles) to build from ``desiredPosition``.
      :param boolean creep: (optional) A special boolean value that changes the behaviour of :attr:`~BWAPI.UnitTypes.Zerg_Creep_Colony>` placement.

      :return: A TilePosition containing the location that the structure should be constructed at. Returns ``TilePositions.Invalid`` if a build location could not be found within ``maxRange``.
      :rtype: :class:`BWAPI.TilePosition`

   .. method:: getBullets() -> Bulletset

      Retrieves the set of all accessible bullets.

      :return: :class:`~BWAPI.Bulletset` containing all accessible Bullet objects.
      :rtype: :class:`BWAPI.Bulletset`

   .. method:: getClosestUnit(center, [pred = nil], [radius = 999999]) -> Unit

      Retrieves the closest unit to center that matches the criteria of the callback pred within an optional radius.

      :param BWAPI.Position center: The position to start searching for the closest unit.
      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`). Defaults to ``nil``, which means no filter.
      :param int radius: (optional) The radius to search in. If omitted, the entire map will be searched.

      :return: The desired unit that is closest to center. Returns ``nil`` if a suitable unit was not found.
      :rtype: :class:`BWAPI.Unit`

      .. seealso::
         :meth:`getBestUnit`, :mod:`~BWAPI.Filter`

   .. method:: getClosestUnitInRectangle(center, [pred = nil], [left = 0], [top = 0], [right = 999999], [bottom = 999999]) -> Unit

      Retrieves the closest unit to center that matches the criteria of the callback pred within an optional rectangle.

      :param BWAPI.Position center: The position to start searching for the closest unit.
      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`). Defaults to ``nil``, which means no filter.
      :param int left: (optional) The left position of the rectangle. This value is 0 by default.
      :param int top: (optional) The top position of the rectangle. This value is 0 by default.
      :param int right: (optional) The right position of the rectangle. This value includes the entire map width by default.
      :param int bottom: (optional) The bottom position of the rectangle. This value includes the entire map height by default.

      :return:
      :rtype: :class:`BWAPI.Unit`

      .. seealso::
         :mod:`~BWAPI.Filter`

   .. method:: getDamageFrom(fromType, toType, [fromPlayer = nil], [toPlayer = nil]) -> int

      Calculates the damage received for a given player.

      It can be understood as the damage from ``fromType`` to ``toType``. Does not include shields in calculation. Includes upgrades if players are provided.

      :param BWAPI.UnitType fromType: The unit type that will be dealing the damage.
      :param BWAPI.UnitType toType: The unit type that will be receiving the damage.
      :param BWAPI.Player fromPlayer: (optional) The player owner of the given type that will be dealing the damage. If omitted, then no player will be used to calculate the upgrades for ``fromType``.
      :param BWAPI.Player toPlayer: (optional) The player owner of the type that will be receiving the damage. If omitted, then this parameter will default to ``Broodwar:self()``.

      :return: The amount of damage that fromType would deal to toType.
      :rtype: int

      .. seealso::
         :meth:`getDamageTo`

   .. method:: getDamageTo(toType, fromType, [toPlayer = nil], [fromPlayer = nil]) -> int

      Calculates the damage dealt for a given player.

      It can be understood as the damage to ``toType`` from ``fromType``. Does not include shields in calculation. Includes upgrades if players are provided.

      :param BWAPI.UnitType toType: The unit type that will be receiving the damage.
      :param BWAPI.UnitType fromType: The unit type that will be dealing the damage.
      :param BWAPI.Player toPlayer: (optional) The player owner of the type that will be receiving the damage. If omitted, then no player will be used to calculate the upgrades for ``toType``.
      :param BWAPI.Player fromPlayer: (optional) The player owner of the given type that will be dealing the damage. If omitted, then this parameter will default to ``Broodwar:self()``.

      :return: The amount of damage that fromType would deal to toType.
      :rtype: int

      .. note::
         This function is nearly the same as getDamageFrom. The only difference is that the last parameter is intended to default to ``Broodwar:self()``.

      .. seealso::
         :meth:`getDamageFrom`

   .. method:: getForce(forceID) -> Force

      Retrieves the Force interface object associated with a given identifier.

      :param int forceID: The identifier for the Force object.

      :return: Force interface object mapped to the given ``forceID``. Returns ``nil`` if the given identifier is invalid.
      :rtype: :class:`BWAPI.Force`

   .. method:: getForces() -> Forceset

      Retrieves the set of all teams/forces.

      Forces are commonly seen in :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game types and some others such as :attr:`Top vs Bottom <BWAPI.GameTypes.Top_vs_Bottom>` and the team versions of game types.

      :return: :class:`~BWAPI.Forceset` containing all forces in the game.
      :rtype: :class:`BWAPI.Forceset`

   .. method:: getFPS() -> int

      Retrieves the logical frame rate of the game in frames per second (FPS).

      :return: Logical frames per second that the game is currently running at as an integer.
      :rtype: int

      .. code-block:: lua
         :caption: Example:

         BWAPI.Broodwar:setLocalSpeed(0)

         -- Log and display the best logical FPS seen in the game
         local bestFPS = 0
         function BWAPI.onFrame()
           bestFPS = math.max(bestFPS, BWAPI.Broodwar:getFPS())
           BWAPI.Broodwar:drawTextScreen(BWAPI.Positions.Origin, string.format("%cBest: %d GFPS\nCurrent: %d GFPS", BWAPI.Text.White, bestFPS, BWAPI.Broodwar:getFPS()))
         end

      .. seealso::
         :meth:`getAverageFPS`

   .. method:: getFrameCount() -> int

      Retrieves the number of logical frames since the beginning of the match.

      If the game is paused, then getFrameCount will not increase.

      :return: Number of logical frames that have elapsed since the game started as an integer.
      :rtype: int

   .. method:: getGameType() -> GameType

      Retrieves the :class:`~BWAPI.GameType` of the current game.

      :return: :class:`~BWAPI.GameType` indicating the rules of the match.
      :rtype: :class:`BWAPI.GameType`

      .. seealso::
         :class:`~BWAPI.GameType`

   .. method:: getGeysers() -> Unitset

      Retrieves the set of all accessible :attr:`Vespene Geysers <BWAPI.UnitTypes.Resource_Vespene_Geyser>` in the game.

      :return: :class:`~BWAPI.Unitset` containing :attr:`Vespene Geysers <BWAPI.UnitTypes.Resource_Vespene_Geyser>`
      :rtype: :class:`BWAPI.Unitset`

   .. method:: getGroundHeight(tileX, tileY) -> int

      Returns the ground height at the given tile position.

      :param int tileX: X position to query, in tiles
      :param int tileY: Y position to query, in tiles

      :return: The tile height as an integer. Possible values are: 0: Low ground; 1: Low ground doodad; 2: High ground; 3: High ground doodad; 4: Very high ground; 5: Very high ground doodad
      :rtype: int

   .. method:: getGroundHeight(position) -> int

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.TilePosition position:

      :return: The tile height as an integer. Possible values are: 0: Low ground; 1: Low ground doodad; 2: High ground; 3: High ground doodad; 4: Very high ground; 5: Very high ground doodad
      :rtype: int

   .. method:: getInstanceNumber() -> int

      Retrieves the Starcraft instance number recorded by :mod:`BWAPI` to identify which Starcraft instance an AI module belongs to.

      The very first instance should return 0.

      :return: An integer value representing the instance number.
      :rtype: int

      .. note::
         This function is considered thread-safe.

   .. method:: getKeyState(key) -> boolean

      Retrieves the state of the given keyboard key.

      :param BWAPI.Key key: A Key enum member indicating which key on the keyboard to check.

      :return: A bool indicating the state of the given ``key``. Returns ``true`` if the key was pressed and ``false`` if it was not. Returns ``false`` always if :attr:`Flag.UserInput` is disabled.
      :rtype: boolean

      .. seealso::
         :mod:`~BWAPI.Key`

   .. method:: getLastError() -> Error

      Returns the last error that was set using setLastError.

      If a function call in :mod:`BWAPI` has failed, you can use this function to retrieve the reason it failed.

      :return: :class:`~BWAPI.Error` type containing the reason for failure.
      :rtype: :class:`BWAPI.Error`

      .. seealso::
         :meth:`setLastError`, :mod:`~BWAPI.Errors`

   .. method:: getLastEventTime() -> int

      Retrieves the amount of time (in milliseconds) that has elapsed when running the last AI module callback.

      This is used by tournament modules to penalize AI modules that use too much processing time.

      :return: Time in milliseconds spent in last AI module call. Returns ``0`` when called from an AI module.
      :rtype: int

   .. method:: getLatency() -> int

      Retrieves the current latency setting that the game is set to.

      :mod:`~BWAPI.Latency` indicates the delay between issuing a command and having it processed.

      :return: The latency setting of the game, which is of :mod:`~BWAPI.Latency`.
      :rtype: int

      .. seealso::
         :mod:`~BWAPI.Latency`

   .. method:: getLatencyFrames() -> int

      Retrieves the maximum delay, in number of frames, between a command being issued and the command being executed by Broodwar.

      :return: Difference in frames between commands being sent and executed.
      :rtype: int

      .. note::
         In Broodwar, latency is used to keep the game synchronized between players without introducing lag.

      .. seealso::
         :meth:`getLatencyTime`, :meth:`getRemainingLatencyFrames`

   .. method:: getLatencyTime() -> int

      Retrieves the maximum delay, in milliseconds, between a command being issued and the command being executed by Broodwar.

      :return: Difference in milliseconds between commands being sent and executed.
      :rtype: int

      .. seealso::
         :meth:`getLatencyFrames`, :meth:`getRemainingLatencyTime`

   .. method:: getMinerals() -> Unitset

      Retrieves the set of all accessible :attr:`Mineral Fields <BWAPI.UnitTypes.Resource_Mineral_Field>` in the game.

      :return: :class:`~BWAPI.Unitset` containing :attr:`Mineral Fields <BWAPI.UnitTypes.Resource_Mineral_Field>`
      :rtype: :class:`BWAPI.Unitset`

   .. method:: getMousePosition() -> Position

      Retrieves the position of the user's mouse on the screen, in Position coordinates.

      :return: Position indicating the location of the mouse. Returns ``Positions.Unknown`` if ``Flag.UserInput`` is disabled.
      :rtype: :class:`BWAPI.Position`

   .. method:: getMouseState(button) -> boolean

      Retrieves the state of the given mouse button.

      :param BWAPI.MouseButton button: A MouseButton enum member indicating which button on the mouse to check.

      :return: A bool indicating the state of the given ``button``. true if the button was pressed and false if it was not. Returns ``false`` always if Flag::UserInput is disabled.
      :rtype: boolean

      .. seealso::
         :mod:`~BWAPI.MouseButton`

   .. method:: getNeutralUnits() -> Unitset

      Retrieves the set of all accessible neutral units in the game.

      This includes :attr:`Mineral Fields <BWAPI.UnitTypes.Resource_Mineral_Field>`, :attr:`Vespene Geysers <BWAPI.UnitTypes.Resource_Vespene_Geyser>`, and `Critters <../namespace/namespace_b_w_a_p_i_1_1_unit_types.rst#bwapinamespace_b_w_a_p_i_1_1_unit_types_1a258b7c3abdc36ca7eef7214efdd9328b>`_.

      :return: :class:`~BWAPI.Unitset` containing all neutral units.
      :rtype: :class:`BWAPI.Unitset`

   .. method:: getNukeDots() -> positions

      Retrieves the set of all accessible :attr:`Nuke <BWAPI.UnitTypes.Terran_Nuclear_Missile>` dots.

      :return: Table of :class:`Positions <BWAPI.Position>` giving the coordinates of nuke locations.
      :rtype: table

      .. note::
         Nuke dots are the red dots painted by a :attr:`Ghost <BWAPI.UnitTypes.Terran_Ghost>` when using the nuclear strike ability.

   .. method:: getPlayer(playerID) -> Player

      Retrieves the :class:`~BWAPI.Player` associated with a given identifier.

      :param int playerID: The identifier for the Player object.

      :return: Player interface object mapped to the given ``playerID``. Returns ``nil`` if the given identifier is invalid.
      :rtype: :class:`BWAPI.Player`

   .. method:: getPlayers() -> Playerset

      Retrieves the set of all players in the match.

      This includes the neutral player, which owns all the resources and critters by default.

      :return: :class:`~BWAPI.Playerset` containing all players in the game.
      :rtype: :class:`BWAPI.Playerset`

   .. method:: getRegion(regionID) -> Region

      Retrieves the Region associated with a given identifier.

      :param int regionID: The identifier for the Region object.

      :return: Region object mapped to the given ``regionID``. Returns ``nil`` if the given ID is invalid.
      :rtype: :class:`BWAPI.Region`

   .. method:: getRegionAt(x, y) -> Region

      Retrieves the region at a given position.

      :param int x: The x coordinate, in pixels.
      :param int y: The y coordinate, in pixels.

      :return: The Region at the given position. Returns ``nil`` if the provided position is not valid (i.e. not within the map bounds).
      :rtype: :class:`BWAPI.Region`

      .. note::
         If the provided position is invalid, the error :attr:`Errors.Invalid_Parameter` is set.

      .. seealso::
         :meth:`getAllRegions`, :meth:`getRegion`

   .. method:: getRegionAt(position) -> Region

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position position:

      :return:
      :rtype: :class:`BWAPI.Region`

   .. method:: getRemainingLatencyFrames() -> int

      Retrieves the number of frames it will take before a command sent in the current frame will be executed by the game.

      :return: Number of frames until a command is executed if it were sent in the current frame.
      :rtype: int

      .. seealso::
         :meth:`getRemainingLatencyTime`, :meth:`getLatencyFrames`

   .. method:: getRemainingLatencyTime() -> int

      Retrieves the number of milliseconds it will take before a command sent in the current frame will be executed by Broodwar.

      :return: Amount of time, in milliseconds, until a command is executed if it were sent in the current frame.
      :rtype: int

      .. seealso::
         :meth:`getRemainingLatencyFrames`, :meth:`getLatencyTime`

   .. method:: getReplayFrameCount() -> int

      Retrieves the maximum number of logical frames that have been recorded in a replay.

      If the game is not a replay, then the value returned is undefined.

      :return: The number of logical frames that the replay contains.
      :rtype: int

   .. method:: getRevision() -> int

      Retrieves the current revision of :mod:`BWAPI`.

      :return: The revision number of the current :mod:`BWAPI` interface.
      :rtype: int

      .. note::
         This function is considered thread-safe.

   .. method:: getScreenPosition() -> Position

      Retrieves the top left position of the viewport from the top left corner of the map, in pixels.

      :return: Position containing the coordinates of the top left corner of the game's viewport. Returns ``Positions.Unknown`` always if ``Flag.UserInput`` is disabled.
      :rtype: :class:`BWAPI.Position`

      .. seealso::
         :meth:`setScreenPosition`

   .. method:: getSelectedUnits() -> Unitset

      Retrieves the set of units that are currently selected by the user outside of :mod:`BWAPI`.

      This function requires that :attr:`BWAPI.Flag.UserInput` be enabled.

      :return: A :class:`~BWAPI.Unitset` containing the user's selected units. If :attr:`BWAPI.Flag.UserInput` is disabled, then this set is always empty.
      :rtype: :class:`BWAPI.Unitset`

      .. seealso::
         enableFlag

   .. method:: getStartLocations() -> tilePositions

      Retrieves the set of all starting locations for the current map.

      A starting location is essentially a candidate for a player's spawn point.

      :return: An array-like table containing all the TilePosition objects that indicate a start location.
      :rtype: table

      .. seealso::
         :meth:`Player.getStartLocation`

   .. method:: getStaticGeysers() -> Unitset

      Retrieves the set of all :attr:`Vespene Geysers <BWAPI.UnitTypes.Resource_Vespene_Geyser>` that were available at the beginning of the game.

      :return: :class:`~BWAPI.Unitset` containing static :attr:`Vespene Geysers <BWAPI.UnitTypes.Resource_Vespene_Geyser>`
      :rtype: :class:`BWAPI.Unitset`

      .. note::
         This set includes resources that are inaccessible.

   .. method:: getStaticMinerals() -> Unitset

      Retrieves the set of all :attr:`Mineral Fields <BWAPI.UnitTypes.Resource_Mineral_Field>` that were available at the beginning of the game.

      :return: :class:`~BWAPI.Unitset` containing static :attr:`Mineral Fields <BWAPI.UnitTypes.Resource_Mineral_Field>`
      :rtype: :class:`BWAPI.Unitset`

      .. note::
         This set includes resources that have been mined out or are inaccessible.

   .. method:: getStaticNeutralUnits() -> Unitset

      Retrieves the set of all units owned by the neutral player (resources, critters, etc.) that were available at the beginning of the game.

      :return: :class:`~BWAPI.Unitset` containing static neutral units
      :rtype: :class:`BWAPI.Unitset`

      .. note::
         This set includes units that are inaccessible.

   .. method:: getUnit(unitID) -> Unit

      Retrieves the Unit interface object associated with a given identifier.

      :param int unitID: The identifier for the Unit object.

      :return: Unit interface object mapped to the given ``unitID``. Returns ``nil`` if the given identifier is invalid.
      :rtype: :class:`BWAPI.Unit`

   .. method:: getUnitsInRadius(x, y, radius, [pred = nil]) -> Unitset

      Retrieves the set of accessible units that are within a given radius of a position.

      :param int x: The x coordinate of the center, in pixels.
      :param int y: The y coordinate of the center, in pixels.
      :param int radius: The radius from the center, in pixels, to include units.
      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`). Defaults to ``nil``, which means no filter.

      :return: A :class:`~BWAPI.Unitset` object consisting of all the units that have any part of them within the given radius from the center position.
      :rtype: :class:`BWAPI.Unitset`

   .. method:: getUnitsInRadius(center, radius, [pred = nil]) -> Unitset

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position center: The coordinate of the center.
      :param int radius: The radius from the center, in pixels, to include units.
      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`). Defaults to ``nil``, which means no filter.

      :return: A :class:`~BWAPI.Unitset` object consisting of all the units that have any part of them within the given radius from the center position.
      :rtype: :class:`BWAPI.Unitset`

   .. method:: getUnitsInRectangle(left, top, right, bottom, [pred = nil]) -> Unitset

      Retrieves the set of accessible units that are in a given rectangle.

      :param int left: The X coordinate of the left position of the bounding box, in pixels.
      :param int top: The Y coordinate of the top position of the bounding box, in pixels.
      :param int right: The X coordinate of the right position of the bounding box, in pixels.
      :param int bottom: The Y coordinate of the bottom position of the bounding box, in pixels.
      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`). Defaults to ``nil``, which means no filter.

      :return: A :class:`~BWAPI.Unitset` object consisting of all the units that have any part of them within the given rectangle bounds.
      :rtype: :class:`BWAPI.Unitset`

   .. method:: getUnitsInRectangle(topLeft, bottomRight, [pred = nil]) -> Unitset

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position topLeft:
      :param BWAPI.Position bottomRight:
      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`). Defaults to ``nil``, which means no filter.

      :return: A :class:`~BWAPI.Unitset` object consisting of all the units that have any part of them within the given rectangle bounds.
      :rtype: :class:`BWAPI.Unitset`

   .. method:: getUnitsOnTile(tileX, tileY, [pred = nil]) -> Unitset

      Retrieves the set of accessible units that are on a given build tile.

      :param int tileX: The X position, in tiles.
      :param int tileY: The Y position, in tiles.
      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`). Defaults to ``nil``, which means no filter.

      :return: A :class:`~BWAPI.Unitset` object consisting of all the units that have any part of them on the given build tile.
      :rtype: :class:`BWAPI.Unitset`

   .. method:: getUnitsOnTile(tile, [pred = nil]) -> Unitset

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.TilePosition tile:
      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`). Defaults to ``nil``, which means no filter.

      :return: A :class:`~BWAPI.Unitset` object consisting of all the units that have any part of them on the given build tile.
      :rtype: :class:`BWAPI.Unitset`

   .. method:: hasCreep(tileX, tileY) -> boolean

      Checks if the given tile position has :attr:`~BWAPI.Races.Zerg` creep on it.

      :param int tileX: The x tile coordinate to check.
      :param int tileY: The y tile coordinate to check.

      :return: Returns ``true`` if the given tile has creep on it, or ``false`` if the given tile does not have creep, or if it is concealed by the fog of war
      :rtype: boolean

   .. method:: hasCreep(position) -> boolean

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.TilePosition position: The coordinate to check

      :return: Returns ``true`` if the given tile has creep on it, or ``false`` if the given tile does not have creep, or if it is concealed by the fog of war
      :rtype: boolean

   .. method:: hasPath(source, destination) -> boolean

      Checks if there is a path from source to destination.

      This only checks if the source position is connected to the destination position. This function does not check if all units can actually travel from source to destination. Because of this limitation, it has an O(1) complexity, and cases where this limitation hinders gameplay is uncommon at best.

      :param BWAPI.Position source: The source position.
      :param BWAPI.Position destination: The destination position.

      :return: Returns ``true`` if there is a path between the two positions, or ``false`` if there is no path
      :rtype: boolean

   .. method:: hasPower(tileX, tileY, [unitType = UnitTypes.None]) -> boolean

      Checks if the given tile position if powered by an owned :attr:`~BWAPI.UnitTypes.Protoss_Pylon` for an optional unit type.

      :param int tileX: The x tile coordinate to check.
      :param int tileY: The y tile coordinate to check.
      :param BWAPI.UnitType unitType: (optional) Checks if the given :class:`~BWAPI.UnitType` will be powered if placed at the given tile position. If omitted, then only the immediate tile position is checked for power, and the function will assume that the location requires power for any unit type.

      :return: Returns ``true`` if the type at the given tile position will receive power, or ``false`` if the type will be unpowered at the given tile position
      :rtype: boolean

   .. method:: hasPower(position, [unitType = UnitTypes.None]) -> boolean

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.TilePosition position: The tile coordinate to check
      :param BWAPI.UnitType unitType: (optional) Checks if the given :class:`~BWAPI.UnitType` will be powered if placed at the given tile position. If omitted, then only the immediate tile position is checked for power, and the function will assume that the location requires power for any unit type.

      :return: Returns ``true`` if the type at the given tile position will receive power, or ``false`` if the type will be unpowered at the given tile position
      :rtype: boolean

   .. method:: hasPower(tileX, tileY, tileWidth, tileHeight, [unitType = UnitTypes.None]) -> boolean

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int tileX:
      :param int tileY:
      :param int tileWidth:
      :param int tileHeight:
      :param BWAPI.UnitType unitType:

      :return:
      :rtype: boolean

   .. method:: hasPower(position, tileWidth, tileHeight, [unitType = UnitTypes.None]) -> boolean

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.TilePosition position:
      :param int tileWidth:
      :param int tileHeight:
      :param BWAPI.UnitType unitType:

      :return:
      :rtype: boolean

   .. method:: hasPowerPrecise(x, y, [unitType = UnitTypes.None]) -> boolean

      Checks if the given pixel position is powered by an owned :attr:`~BWAPI.UnitTypes.Protoss_Pylon` for an optional unit type.

      :param int x: The x pixel coordinate to check.
      :param int y: The y pixel coordinate to check.
      :param BWAPI.UnitType unitType: (optional) Checks if the given :class:`~BWAPI.UnitType` requires power or not. If ommitted, then it will assume that the position requires power for any unit type.

      :return: Returns ``true`` if the type at the given position will have power, or ``false`` if the type at the given position will be unpowered
      :rtype: boolean

   .. method:: hasPowerPrecise(position, [unitType = UnitTypes.None]) -> boolean

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position position:
      :param BWAPI.UnitType unitType:

      :return:
      :rtype: boolean

   .. method:: indexToUnit(unitIndex) -> Unit

      Retrieves a Unit interface object from a given unit index.

      The value given as an index maps directly to Broodwar's unit array index and matches the index found in replay files. In order to use this function, :attr:`~BWAPI.Flag.CompleteMapInformation` must be enabled.

      :param int unitIndex: The unitIndex to identify the Unit with. A valid index is 0 <= unitIndex & 0x7FF < 1700.

      :return: Unit interface object that matches the given ``unitIndex``. Returns ``nil`` if the given index is invalid.
      :rtype: :class:`BWAPI.Unit`

   .. method:: isBattleNet() -> boolean

      Checks if the client is in a game that was created through the Battle.net multiplayer gaming service.

      :return: true if the client is in a multiplayer Battle.net game and false if it is not.
      :rtype: boolean

   .. method:: isBuildable(tileX, tileY, [includeBuildings = false]) -> boolean

      Checks if a given tile position is buildable.

      This means that, if all other requirements are met, a structure can be placed on this tile. This function uses static map data.

      :param int tileX: The x value of the tile to check.
      :param int tileY: The y value of the tile to check.
      :param boolean includeBuildings: (optional) If this is true, then this function will also check if any visible structures are occupying the space. If this value is false, then it only checks the static map data for tile buildability. This value is false by default.

      :return: boolean identifying if the given tile position is buildable (true) or not (false). If ``includeBuildings`` was provided, then it will return false if a structure is currently occupying the tile.
      :rtype: boolean

   .. method:: isBuildable(position, [includeBuildings = false]) -> boolean

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.TilePosition position:
      :param boolean includeBuildings:

      :return:
      :rtype: boolean

   .. method:: isDebug() -> boolean

      Retrieves the debug state of the :mod:`BWAPI` build.

      :return: true if the :mod:`BWAPI` module is a DEBUG build, and false if it is a RELEASE build.
      :rtype: boolean

      .. note::
         This function is considered thread-safe.

   .. method:: isExplored(tileX, tileY) -> boolean

      Checks if a given tile position has been explored by the player.

      An explored tile position indicates that the player has seen the location at some point in the match, partially revealing the fog of war for the remainder of the match.

      :param int tileX: The x tile coordinate to check.
      :param int tileY: The y tile coordinate to check.

      :return: Returns ``true`` if the player has explored the given tile position (partially revealed fog), or ``false`` if the tile position was never explored (completely black fog)
      :rtype: boolean

      .. seealso::
         isVisible

   .. method:: isExplored(position) -> boolean

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.TilePosition position:

      :return:
      :rtype: boolean

   .. method:: isFlagEnabled(flag) -> boolean

      Checks if the state of the given flag is enabled or not.

      :param int flag: The :mod:`BWAPI.Flag` entry describing the flag's effects on :mod:`BWAPI`.

      :return: true if the given ``flag`` is enabled, false if the flag is disabled.
      :rtype: boolean

      .. note::
         Flags may only be enabled at the start of the match during the `AIModule::onStart <class_b_w_a_p_i_1_1_a_i_module.rst#bwapiclass_b_w_a_p_i_1_1_a_i_module_1aa1068e4f30fd50cb52a678bbf7a7c6f9>`_ callback.

      .. seealso::
         :mod:`BWAPI.Flag`

   .. method:: isGUIEnabled() -> boolean

      Checks if the GUI is enabled.

      The GUI includes all drawing functions of :mod:`BWAPI`, as well as screen updates from Broodwar.

      :return: Returns ``true`` if the GUI is enabled, and everything is visible, or ``false`` if the GUI is disabled and drawing functions are rejected
      :rtype: boolean

      .. seealso::
         :meth:`setGUIEnabled`

   .. method:: isInGame() -> boolean

      Checks if the current client is inside a game.

      :return: true if the client is in a game, and false if it is not.
      :rtype: boolean

   .. method:: isLatComEnabled() -> boolean

      Checks the state of latency compensation.

      :return: true if latency compensation is enabled, false if it is disabled.
      :rtype: boolean

      .. seealso::
         :meth:`setLatCom`

   .. method:: isMultiplayer() -> boolean

      Checks if the current client is inside a multiplayer game.

      :return: true if the client is in a multiplayer game, and false if it is a single player game, a replay, or some other state.
      :rtype: boolean

   .. method:: isPaused() -> boolean

      Checks if the current game is paused.

      While paused, :meth:`BWAPI.onFrame` will still be called.

      :return: true if the game is paused and false otherwise
      :rtype: boolean

      .. seealso::
         :meth:`pauseGame`, :meth:`resumeGame`

   .. method:: isReplay() -> boolean

      Checks if the client is watching a replay.

      :return: true if the client is watching a replay and false otherwise
      :rtype: boolean

   .. method:: issueCommand(units, command) -> boolean

      Issues a given command to a set of units.

      This function automatically splits the set into groups of 12 and issues the same command to each of them. If a unit is not capable of executing the command, then it is simply ignored.

      :param BWAPI.Unitset units: A :class:`~BWAPI.Unitset` containing all the units to issue the command for.
      :param BWAPI.UnitCommand command: A :class:`~BWAPI.UnitCommand` object containing relevant information about the command to be issued. The :class:`~BWAPI.Unit` associated with the command will be ignored.

      :return: true if any one of the units in the :class:`~BWAPI.Unitset` were capable of executing the command, and false if none of the units were capable of executing the command.
      :rtype: boolean

   .. method:: isVisible(tileX, tileY) -> boolean

      Checks if a given tile position is visible to the current player.

      :param int tileX: The x value of the tile to check.
      :param int tileY: The y value of the tile to check.

      :return: boolean identifying the visibility of the tile. If the given tile is visible, then the value is ``true``. If the given tile is concealed by the fog of war, then this value will be ``false``.
      :rtype: boolean

   .. method:: isVisible(position) -> boolean

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.TilePosition position:

      :return:
      :rtype: boolean

   .. method:: isWalkable(walkX, walkY) -> boolean

      Checks if the given mini-tile position is walkable.

      :param int walkX: The x coordinate of the mini-tile, in mini-tile units (8 pixels).
      :param int walkY: The y coordinate of the mini-tile, in mini-tile units (8 pixels).

      :return: true if the mini-tile is walkable and false if it is impassable for ground units.
      :rtype: boolean

      .. note::
         This function only checks if the static terrain is walkable. Its current occupied state is excluded from this check. To see if the space is currently occupied or not, then see :meth:`getUnitsInRectangle`.

   .. method:: isWalkable(position) -> boolean

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.WalkPosition position:

      :return:
      :rtype: boolean

   .. method:: leaveGame()

      Leaves the current game by surrendering and enters the post-game statistics/score screen.

   .. method:: mapFileName() -> string

      Retrieves the file name of the currently loaded map.

      :return: Map file name.
      :rtype: string

      .. seealso::
         :meth:`mapPathName`, :meth:`mapName`

   .. method:: mapHash() -> string

      Calculates the SHA-1 hash of the currently loaded map file.

      :return: string containing SHA-1 hash.
      :rtype: string

      .. note::
         Campaign maps will return a hash of their internal map chunk components (.chk), while standard maps will return a hash of their entire map archive (.scm, .scx).

   .. method:: mapHeight() -> int

      Retrieves the height of the map in build tile units.

      :return: Height of the map in tiles.
      :rtype: int

      .. seealso::
         :meth:`mapWidth`

   .. method:: mapName() -> string

      Retrieves the title of the currently loaded map.

      :return: Map title.
      :rtype: string

      .. seealso::
         :meth:`mapFileName`, :meth:`mapPathName`

   .. method:: mapPathName() -> string

      Retrieves the full path name of the currently loaded map.

      :return: Map file name.
      :rtype: string

      .. seealso::
         :meth:`mapFileName`, :meth:`mapName`

   .. method:: mapWidth() -> int

      Retrieves the width of the map in build tile units.

      :return: Width of the map in tiles.
      :rtype: int

      .. seealso::
         :meth:`mapHeight`

   .. method:: neutral() -> Player

      Retrieves the Player interface object representing the neutral player.

      The neutral player owns all the resources and critters on the map by default.

      :return: :class:`Player` indicating the neutral player.
      :rtype: :class:`BWAPI.Player`

   .. method:: observers() -> Playerset

      Retrieves a set of all players currently observing the game.

      An observer is defined typically in a :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game type as not having any impact on the game. This means an observer cannot start with any units, and cannot have any active trigger actions that create units for it.

      :return: :class:`~BWAPI.Playerset` containing all currently active observer players
      :rtype: :class:`BWAPI.Playerset`

   .. method:: pauseGame()

      Pauses the game.

      While paused, :meth:`BWAPI.onFrame` will still be called.

      .. seealso::
         :meth:`resumeGame`

   .. method:: pingMinimap(x, y)

      Pings the minimap at the given position.

      Minimap pings are visible to allied players.

      :param int x: The x coordinate to ping at, in pixels, from the map's origin (left).
      :param int y: The y coordinate to ping at, in pixels, from the map's origin (top).

   .. method:: pingMinimap(pos)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position pos: The coordinate to ping at, from the map's origin (top left).

   .. method:: printf(msg)

      Prints text to the screen as a notification.

      .. important::
         Any formatting needs to be done before the string is passed to the function (e.g. using ``string.format``). See :ref:`the differences between the C++ and Lua implementations of this function <differences-string-format>`.

      .. note::
         This function allows text formatting using :mod:`BWAPI.Text` members. The best way to do this is to use the ``%c`` conversion specifier like so: ``string.format("%cYour string", BWAPI.Text.White)``

      :param string msg: The string to be printed.

      .. note::
         That text printed through this function is not seen by other players or in replays.

   .. method:: restartGame()

      Restarts the match.

      Works the same as if the match was restarted from the in-game menu (F10). This option is only available in single player games.

   .. method:: resumeGame()

      Resumes the game from a paused state.

      .. seealso::
         :meth:`pauseGame`

   .. method:: self() -> Player

      Retrieves the player object that :mod:`BWAPI` is controlling.

      :return: :class:`Player` object representing the current player. Returns ``nil`` if the current game is a replay.
      :rtype: :class:`BWAPI.Player`

      .. code-block:: lua
         :caption: Example usage

         function BWAPI.onStart()
           if BWAPI.Broodwar:self() then
             BWAPI.Broodwar:sendText("Hello, my name is %s.", BWAPI.Broodwar:self():getName())
           end
         end

   .. method:: sendText(msg)

      Sends a text message to all other players in the game.

      .. important::
         Any formatting needs to be done before the string is passed to the function (e.g. using ``string.format``). See :ref:`the differences between the C++ and Lua implementations of this function <differences-string-format>`.

      :param string msg: The string to be sent.

      .. note::
         In a single player game this function can be used to execute cheat codes.

      .. seealso::
         :meth:`sendTextEx`, :meth:`sendTextToAllies`

   .. method:: sendTextEx(toAllies, msg)

      An extended version of :meth:`Game.sendText` which allows messages to be forwarded to allies.

      :param boolean toAllies: If this parameter is set to true, then the message is only sent to allied players, otherwise it will be sent to all players.
      :param string msg: The string to be sent.

      .. seealso::
         :ref:`Differences Between the C++ and Lua API: Game.sendTextEx <differences-sendTextEx>`, :meth:`sendTextToAllies`, :meth:`sendText`

   .. method:: sendTextToAllies(msg)

      An extended version of :meth:`Game.sendText` which always sends messages to allies.

      :param string msg: The string to be sent.

      .. seealso::
         :ref:`Differences Between the C++ and Lua API: Game.sendTextEx <differences-sendTextEx>`, :meth:`sendTextEx`, :meth:`sendText`

   .. method:: setAlliance(player, [allied = true], [alliedVictory = true]) -> boolean

      Sets the alliance state of the current player with the target player.

      :param BWAPI.Player player: The target player to set alliance with.
      :param boolean allied: (optional) If true, the current player will ally the target player. If false, the current player will make the target player an enemy. This value is true by default.
      :param boolean alliedVictory: (optional) Sets the state of "allied victory". If true, the game will end in a victory if all allied players have eliminated their opponents. Otherwise, the game will only end if no other players are remaining in the game. This value is true by default.

      :return: Returns ``true`` if the command was successfully sent to BW, or ``false`` otherwise.
      :rtype: boolean

   .. method:: setCommandOptimizationLevel(level)

      Sets the command optimization level.

      Command optimization is a feature in :mod:`BWAPI` that tries to reduce the APM of the bot by grouping or eliminating unnecessary game actions. For example, suppose the bot told 24 :attr:`Zerglings <BWAPI.UnitTypes.Zerg_Zergling>` to :attr:`Burrow <BWAPI.TechTypes.Burrowing>`. At command optimization level 0, :mod:`BWAPI` is designed to select each Zergling to burrow individually, which costs 48 actions. With command optimization level 1, it can perform the same behaviour using only 4 actions. The command optimizer also reduces the amount of bytes used for each action if it can express the same action using a different command. For example, Right_Click uses less bytes than Move.

      :param int level: An integer representation of the aggressiveness for which commands are optimized. A lower level means less optimization, and a higher level means more optimization.

   .. method:: setFrameSkip(frameSkip)

      Sets the number of graphical frames for every logical frame.

      This allows the game to run more logical frames per graphical frame, increasing the speed at which the game runs.

      :param int frameSkip: Number of graphical frames per logical frame. If this value is 0 or less, then it will default to 1.

      .. seealso::
         :meth:`setLocalSpeed`

   .. method:: setGUI(enabled)

      Alias for :meth:`setGUIEnabled`.

   .. method:: setGUIEnabled(enabled)

      Sets the rendering state of the Starcraft GUI.

      This typically gives Starcraft a very low graphical frame rate and disables all drawing functionality in :mod:`BWAPI`.

      :param boolean enabled: A boolean value that determines the state of the GUI. Passing false to this function will disable the GUI, and true will enable it.

      .. code-block:: lua
         :caption: Example Usage

         -- Make our bot run thousands of games as fast as possible!
         function BWAPI.onStart()
           BWAPI.Broodwar:setLocalSpeed(0)
           BWAPI.Broodwar:setGUIEnabled(false)
         end

      .. seealso::
         :meth:`isGUIEnabled`

   .. method:: setLastError([e = Errors.None]) -> boolean

      Sets the last error so that future calls to getLastError will return the value that was set.

      :param BWAPI.Error e: (optional) The error code to set. If omitted, then the last error will be cleared.

      :return: Returns ``true`` if the type passed was :attr:`BWAPI.Errors.None`, clearing the last error, or ``false`` if any other error type was passed
      :rtype: boolean

      .. seealso::
         :meth:`getLastError`, :mod:`~BWAPI.Errors`

   .. method:: setLatCom(isEnabled)

      Changes the state of latency compensation.

      :mod:`~BWAPI.Latency` compensation modifies the state of :mod:`BWAPI`'s representation of units to reflect the implications of issuing a command immediately after the command was performed, instead of waiting consecutive frames for the results. :mod:`~BWAPI.Latency` compensation is enabled by default.

      :param boolean isEnabled: Set whether the latency compensation feature will be enabled (true) or disabled (false).

      .. seealso::
         :meth:`isLatComEnabled`

   .. method:: setLocalSpeed(speed)

      Sets the number of milliseconds Broodwar spends in each frame.

      The default values are as follows:

      * Fastest: 42ms/frame
      * Faster: 48ms/frame
      * Fast: 56ms/frame
      * Normal: 67ms/frame
      * Slow: 83ms/frame
      * Slower: 111ms/frame
      * Slowest: 167ms/frame

      :param int speed: The time spent per frame, in milliseconds. A value of 0 indicates that frames are executed immediately with no delay. Negative values will restore the default value as listed above.

      .. note::
         Specifying a value of 0 will not guarantee that logical frames are executed as fast as possible. If that is the intention, use this in combination with setFrameSkip.

      .. seealso::
         :meth:`setFrameSkip`, :meth:`getFPS`

   .. method:: setMap(mapFileName) -> boolean

      Changes the map to the one specified.

      Once restarted, the game will load the map that was provided. Changes do not take effect unless the game is restarted.

      :param string mapFileName: A string containing the path and file name to the desired map.

      :return: Returns ``true`` if the function succeeded and has changed the map, or ``false`` if the function failed, does not have permission from the tournament module, failed to find the map specified, or received an invalid parameter
      :rtype: boolean

   .. method:: setRevealAll([reveal = true]) -> boolean

      Sets the state of the fog of war when watching a replay.

      :param boolean reveal: (optional) The state of the reveal all flag. If false, all fog of war will be enabled. If true, then the fog of war will be revealed. It is true by default.

      :return: Returns ``true`` when successful, or ``false`` otherwise.
      :rtype: boolean

   .. method:: setScreenPosition(x, y)

      Moves the top left corner of the viewport to the provided position relative to the map's origin (top left (0,0)).

      :param int x: The x coordinate to move the screen to, in pixels.
      :param int y: The y coordinate to move the screen to, in pixels.

      .. seealso::
         :meth:`getScreenPosition`

   .. method:: setScreenPosition(pos)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position pos: The coordinate to move the screen to.

   .. method:: setVision(player, [enabled = true]) -> boolean

      In a game, this function shares the vision of the current :mod:`BWAPI` player with the target player.

      In a replay, this function toggles the visibility of the target player.

      :param BWAPI.Player player: The target player to toggle vision.
      :param boolean enabled: (optional) The vision state. If true, and in a game, the current player will enable shared vision with the target player, otherwise it will unshare vision. If in a replay, the vision of the target player will be shown, otherwise the target player will be hidden. This value is true by default.

      :return: Returns ``true`` when successful, or ``false`` otherwise.
      :rtype: boolean

   .. method:: setTextSize([size = Text.Size.Default])

      Sets the size of the text for all calls to drawText following this one.

      :param BWAPI.Text.Size size: (optional) The size of the text. This value is one of :mod:`BWAPI.Text.Size`. If this value is omitted, then a default value of :attr:`Text.Size.Default` is used.

      .. code-block:: lua
         :caption: Example usage

         function BWAPI.onFrame()
           -- Centers the name of the player in the upper middle of the screen
           BWAPI.Broodwar:setTextSize(BWAPI.Text.Size.Large)
           BWAPI.Broodwar:drawTextScreen(
             BWAPI.Positions.Origin,
             string.format("%c%c%s",
               BWAPI.Text.Align_Center,
               BWAPI.Text.Green,
               BWAPI.Broodwar:self():getName()
             )
           )
           -- Set text size back to default
           BWAPI.Broodwar:setTextSize()
         end

      .. seealso::
         :mod:`BWAPI.Text.Size`

   .. method:: drawText(ctype, x, y, text)

      Draws text on the screen at the given coordinates.

      Text can be drawn in different colors or formatted using the :mod:`BWAPI.Text` members.

      .. important::
         Any formatting needs to be done before the string is passed to the function (e.g. using ``string.format``). See :ref:`the differences between the C++ and Lua implementations of this function <differences-string-format>`.

      .. note::
         This function allows text formatting using :mod:`BWAPI.Text` members. The best way to do this is to use the ``%c`` conversion specifier like so: ``string.format("%cYour string", BWAPI.Text.White)``

      :param BWAPI.CoordinateType ctype: The coordinate type. Indicates the relative position to draw the shape.
      :param int x: The x coordinate, in pixels, relative to ctype.
      :param int y: The y coordinate, in pixels, relative to ctype.
      :param string text: The text to draw.

   .. method:: drawTextMap(x, y, text)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x: The x coordinate, in pixels, relative to the top left of the map.
      :param int y: The y coordinate, in pixels, relative to the top left of the map.
      :param string text: The text to draw.

   .. method:: drawTextMap(pos, text)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position pos: The coordinate, relative to the top left of the map.
      :param string text: The text to draw.

   .. method:: drawTextMouse(x, y, text)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x: The x coordinate, in pixels, relative to the current mouse position.
      :param int y: The x coordinate, in pixels, relative to the current mouse position.
      :param string text: The text to draw.

   .. method:: drawTextMouse(pos, text)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position pos: The coordinate, relative to the current mouse position.
      :param string text: The text to draw.

   .. method:: drawTextScreen(x, y, text)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x: The x coordinate, in pixels, relative to the top left of the screen.
      :param int y: The y coordinate, in pixels, relative to the top left of the screen.
      :param string text: The text to draw.

   .. method:: drawTextScreen(pos, text)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position pos: The coordinate, relative to the top left of the screen.
      :param string text: The text to draw.

   .. method:: drawBox(ctype, left, top, right, bottom, color, [isSolid = false])

      Draws a rectangle on the screen with the given color.

      :param BWAPI.CoordinateType ctype: The coordinate type. Indicates the relative position to draw the shape.
      :param int left: The x coordinate, in pixels, relative to ctype, of the left edge of the rectangle.
      :param int top: The y coordinate, in pixels, relative to ctype, of the top edge of the rectangle.
      :param int right: The x coordinate, in pixels, relative to ctype, of the right edge of the rectangle.
      :param int bottom: The y coordinate, in pixels, relative to ctype, of the bottom edge of the rectangle.
      :param BWAPI.Color color: The color of the rectangle.
      :param boolean isSolid: (optional) If true, then the shape will be filled and drawn as a solid, otherwise it will be drawn as an outline. If omitted, this value will default to false.

   .. method:: drawBoxMap(left, top, right, bottom, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int left:
      :param int top:
      :param int right:
      :param int bottom:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawBoxMap(leftTop, rightBottom, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position leftTop:
      :param BWAPI.Position rightBottom:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawBoxMouse(left, top, right, bottom, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int left:
      :param int top:
      :param int right:
      :param int bottom:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawBoxMouse(leftTop, rightBottom, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position leftTop:
      :param BWAPI.Position rightBottom:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawBoxScreen(left, top, right, bottom, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int left:
      :param int top:
      :param int right:
      :param int bottom:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawBoxScreen(leftTop, rightBottom, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position leftTop:
      :param BWAPI.Position rightBottom:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawTriangle(ctype, ax, ay, bx, by, cx, cy, color, [isSolid = false])

      Draws a triangle on the screen with the given color.

      :param BWAPI.CoordinateType ctype: The coordinate type. Indicates the relative position to draw the shape.
      :param int ax: The x coordinate, in pixels, relative to ctype, of the first point.
      :param int ay: The y coordinate, in pixels, relative to ctype, of the first point.
      :param int bx: The x coordinate, in pixels, relative to ctype, of the second point.
      :param int by: The y coordinate, in pixels, relative to ctype, of the second point.
      :param int cx: The x coordinate, in pixels, relative to ctype, of the third point.
      :param int cy: The y coordinate, in pixels, relative to ctype, of the third point.
      :param BWAPI.Color color: The color of the triangle.
      :param boolean isSolid: (optional) If true, then the shape will be filled and drawn as a solid, otherwise it will be drawn as an outline. If omitted, this value will default to false.

   .. method:: drawTriangleMap(ax, ay, bx, by, cx, cy, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int ax:
      :param int ay:
      :param int bx:
      :param int by:
      :param int cx:
      :param int cy:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawTriangleMap(a, b, c, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position a:
      :param BWAPI.Position b:
      :param BWAPI.Position c:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawTriangleMouse(ax, ay, bx, by, cx, cy, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int ax:
      :param int ay:
      :param int bx:
      :param int by:
      :param int cx:
      :param int cy:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawTriangleMouse(a, b, c, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position a:
      :param BWAPI.Position b:
      :param BWAPI.Position c:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawTriangleScreen(ax, ay, bx, by, cx, cy, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int ax:
      :param int ay:
      :param int bx:
      :param int by:
      :param int cx:
      :param int cy:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawTriangleScreen(a, b, c, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position a:
      :param BWAPI.Position b:
      :param BWAPI.Position c:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawCircle(ctype, x, y, radius, color, [isSolid = false])

      Draws a circle on the screen with the given color.

      :param BWAPI.CoordinateType ctype: The coordinate type. Indicates the relative position to draw the shape.
      :param int x: The x coordinate, in pixels, relative to ctype.
      :param int y: The y coordinate, in pixels, relative to ctype.
      :param int radius: The radius of the circle, in pixels.
      :param BWAPI.Color color: The color of the circle.
      :param boolean isSolid: (optional) If true, then the shape will be filled and drawn as a solid, otherwise it will be drawn as an outline. If omitted, this value will default to false.

   .. method:: drawCircleMap(x, y, radius, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x:
      :param int y:
      :param int radius:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawCircleMap(p, radius, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position p:
      :param int radius:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawCircleMouse(x, y, radius, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x:
      :param int y:
      :param int radius:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawCircleMouse(p, radius, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position p:
      :param int radius:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawCircleScreen(x, y, radius, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x:
      :param int y:
      :param int radius:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawCircleScreen(p, radius, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position p:
      :param int radius:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawEllipse(ctype, x, y, xrad, yrad, color, [isSolid = false])

      Draws an ellipse on the screen with the given color.

      :param BWAPI.CoordinateType ctype: The coordinate type. Indicates the relative position to draw the shape.
      :param int x: The x coordinate, in pixels, relative to ctype.
      :param int y: The y coordinate, in pixels, relative to ctype.
      :param int xrad: The x radius of the ellipse, in pixels.
      :param int yrad: The y radius of the ellipse, in pixels.
      :param BWAPI.Color color: The color of the ellipse.
      :param boolean isSolid: (optional) If true, then the shape will be filled and drawn as a solid, otherwise it will be drawn as an outline. If omitted, this value will default to false.

   .. method:: drawEllipseMap(x, y, xrad, yrad, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x:
      :param int y:
      :param int xrad:
      :param int yrad:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawEllipseMap(p, xrad, yrad, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position p:
      :param int xrad:
      :param int yrad:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawEllipseMouse(x, y, xrad, yrad, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x:
      :param int y:
      :param int xrad:
      :param int yrad:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawEllipseMouse(p, xrad, yrad, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position p:
      :param int xrad:
      :param int yrad:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawEllipseScreen(x, y, xrad, yrad, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x:
      :param int y:
      :param int xrad:
      :param int yrad:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawEllipseScreen(p, xrad, yrad, color, [isSolid = false])

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position p:
      :param int xrad:
      :param int yrad:
      :param BWAPI.Color color:
      :param boolean isSolid:

   .. method:: drawDot(ctype, x, y, color)

      Draws a dot on the map or screen with a given color.

      :param BWAPI.CoordinateType ctype: The coordinate type. Indicates the relative position to draw the shape.
      :param int x: The x coordinate, in pixels, relative to ctype.
      :param int y: The y coordinate, in pixels, relative to ctype.
      :param BWAPI.Color color: The color of the dot.

   .. method:: drawDotMap(x, y, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x:
      :param int y:
      :param BWAPI.Color color:

   .. method:: drawDotMap(p, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position p:
      :param BWAPI.Color color:

   .. method:: drawDotMouse(x, y, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x:
      :param int y:
      :param BWAPI.Color color:

   .. method:: drawDotMouse(p, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position p:
      :param BWAPI.Color color:

   .. method:: drawDotScreen(x, y, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x:
      :param int y:
      :param BWAPI.Color color:

   .. method:: drawDotScreen(p, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position p:
      :param BWAPI.Color color:

   .. method:: drawLine(ctype, x1, y1, x2, y2, color)

      Draws a line on the map or screen with a given color.

      :param BWAPI.CoordinateType ctype: The coordinate type. Indicates the relative position to draw the shape.
      :param int x1: The starting x coordinate, in pixels, relative to ctype.
      :param int y1: The starting y coordinate, in pixels, relative to ctype.
      :param int x2: The ending x coordinate, in pixels, relative to ctype.
      :param int y2: The ending y coordinate, in pixels, relative to ctype.
      :param BWAPI.Color color: The color of the line.

   .. method:: drawLineMap(x1, y1, x2, y2, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x1:
      :param int y1:
      :param int x2:
      :param int y2:
      :param BWAPI.Color color:

   .. method:: drawLineMap(a, b, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position a:
      :param BWAPI.Position b:
      :param BWAPI.Color color:

   .. method:: drawLineMouse(x1, y1, x2, y2, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x1:
      :param int y1:
      :param int x2:
      :param int y2:
      :param BWAPI.Color color:

   .. method:: drawLineMouse(a, b, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position a:
      :param BWAPI.Position b:
      :param BWAPI.Color color:

   .. method:: drawLineScreen(x1, y1, x2, y2, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param int x1:
      :param int y1:
      :param int x2:
      :param int y2:
      :param BWAPI.Color color:

   .. method:: drawLineScreen(a, b, color)

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.Position a:
      :param BWAPI.Position b:
      :param BWAPI.Color color:
