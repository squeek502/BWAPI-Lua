Player
******

.. currentmodule:: BWAPI

.. class:: Player

   The Player represents a unique controller in the game.

   Each player in a match will have his or her own player instance. There is also a neutral player which owns all the neutral units (such as mineral patches and vespene geysers).

   .. seealso::
      :class:`Playerset`, :class:`PlayerType`, :class:`Race`

   .. rubric:: Constructors

   This class is not constructable through Lua.

   .. rubric:: Member Variables

   .. include:: /_include/interface-clientinfo.rst

   .. rubric:: Member Functions

   .. method:: allUnitCount([unitType = UnitTypes.AllUnits]) -> int

      Retrieves the total number of units that the player has.

      If the information about the player is limited, then this function will only return the number of visible units.

      :param BWAPI.UnitType unitType: (optional) The unit type to query. :class:`~BWAPI.UnitType` macros are accepted. If this parameter is omitted, then it will use :attr:`UnitTypes.AllUnits` by default.

      :return: The total number of units of the given type that the player owns.
      :rtype: int

      .. note::
         While in-progress Protoss and Terran units will be counted, in-progress Zerg units (i.e. inside of an egg) do not.

      .. seealso::
         :meth:`visibleUnitCount`, :meth:`completedUnitCount`, :meth:`incompleteUnitCount`

   .. method:: armor(unitType) -> int

      Calculates the armor that a given unit type will have, including upgrades.

      :param BWAPI.UnitType unitType: The unit type to calculate armor for, using the current player's upgrades.

      :return: The amount of armor that the unit will have with the player's upgrades.
      :rtype: int

   .. method:: completedUnitCount([unitType = UnitTypes.AllUnits]) -> int

      Retrieves the number of completed units that the player has.

      If the information about the player is limited, then this function will only return the number of visible completed units.

      :param BWAPI.UnitType unitType: (optional) The unit type to query. :class:`~BWAPI.UnitType` macros are accepted. If this parameter is omitted, then it will use :attr:`UnitTypes.AllUnits` by default.

      :return: The number of completed units of the given type that the player owns.
      :rtype: int

      .. seealso::
         :meth:`allUnitCount`, :meth:`visibleUnitCount`, :meth:`incompleteUnitCount`

   .. method:: damage(weaponType) -> int

      Calculates the damage that a given weapon type can deal, including upgrades.

      :param BWAPI.WeaponType weaponType: The weapon type to calculate for.

      :return: The amount of damage that the weapon deals with this player's upgrades.
      :rtype: int

   .. method:: deadUnitCount([unitType = UnitTypes.AllUnits]) -> int

      Retrieves the number units that have died for this player.

      :param BWAPI.UnitType unitType: (optional) The unit type to query. :class:`~BWAPI.UnitType` macros are accepted. If this parameter is omitted, then it will use :attr:`UnitTypes.AllUnits` by default.

      :return: The total number of units that have died throughout the game.
      :rtype: int

   .. method:: gas() -> int

      Retrieves the current amount of vespene gas that this player has.

      :return: Amount of gas that the player currently has for spending.
      :rtype: int

      .. note::
         This function will return 0 if the player is inaccessible.

   .. method:: gatheredGas() -> int

      Retrieves the cumulative amount of vespene gas that this player has gathered since the beginning of the game, including the amount that the player starts the game with (if any).

      :return: Cumulative amount of gas that the player has gathered.
      :rtype: int

      .. note::
         This function will return 0 if the player is inaccessible.

   .. method:: gatheredMinerals() -> int

      Retrieves the cumulative amount of minerals/ore that this player has gathered since the beginning of the game, including the amount that the player starts the game with (if any).

      :return: Cumulative amount of minerals that the player has gathered.
      :rtype: int

      .. note::
         This function will return 0 if the player is inaccessible.

   .. method:: getBuildingScore() -> int

      Retrieves the total building score, as seen in the end-game score screen.

      :return: The player's building score.
      :rtype: int

   .. method:: getColor() -> BWAPI.Color

      Retrieves the color value of the current player.

      :return: :class:`~BWAPI.Color` object that represents the color of the current player.
      :rtype: :class:`BWAPI.Color`

   .. method:: getCustomScore() -> int

      Retrieves the player's custom score.

      This score is used in :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game types.

      :return: The player's custom score.
      :rtype: int

   .. method:: getForce() -> Force

      Retrieves the player's force.

      A force is the team that the player is playing on.

      :return: The Force object that the player is part of.
      :rtype: :class:`BWAPI.Force`

   .. method:: getID() -> int

      Retrieves a unique ID that represents the player.

      :return: An integer representing the ID of the player.
      :rtype: int

   .. method:: getKillScore() -> int

      Retrieves the total kill score, as seen in the end-game score screen.

      :return: The player's kill score.
      :rtype: int

   .. method:: getMaxUpgradeLevel(upgrade) -> int

      Retrieves the maximum upgrades available specific to the player.

      This value is only different from :meth:`UpgradeType.maxRepeats` in :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` games.

      :param BWAPI.UpgradeType upgrade: The :class:`UpgradeType` to retrieve the maximum upgrade level for.

      :return: Maximum upgrade level of the given ``upgrade`` type.
      :rtype: int

   .. method:: getName() -> string

      Retrieves the name of the player.

      :return: A string containing the player's name.
      :rtype: string

      .. code-block:: lua
         :caption: Example usage

         local myEnemy = BWAPI.Broodwar:enemy()
         if myEnemy then   -- Make sure there is an enemy!
           BWAPI.Broodwar:sendText(string.format("Prepare to be crushed, %s!", myEnemy:getName()))
         end

   .. method:: getRace() -> Race

      Retrieves the race of the player.

      This allows you to change strategies against different races, or generalize some commands for yourself.

      :return: The :class:`~BWAPI.Race` that the player is using. Returns ``Races.Unknown`` if the player chose ``Races.Random`` when the game started and they have not been seen.
      :rtype: :class:`BWAPI.Race`

      .. code-block:: lua
         :caption: Example usage

         if BWAPI.Broodwar:enemy() then
           local enemyRace = BWAPI.Broodwar:enemy():getRace()
           if enemyRace == BWAPI.Races.Zerg then
             BWAPI.Broodwar:sendText("Do you really think you can beat me with a zergling rush?")
           end
         end

   .. method:: getRazingScore() -> int

      Retrieves the total razing score, as seen in the end-game score screen.

      :return: The player's razing score.
      :rtype: int

   .. method:: getStartLocation() -> TilePosition

      Retrieve's the player's starting location.

      :return: A TilePosition containing the position of the start location. Returns ``TilePositions.None`` if the player does not have a start location, or ``TilePositions.Unknown`` if an error occured while trying to retrieve the start location.
      :rtype: :class:`BWAPI.TilePosition`

      .. seealso::
         :meth:`Game.getStartLocations`, :meth:`Game.getLastError`

   .. method:: getTextColor() -> string

      Retrieves the control code character that changes the color of text messages to represent this player.

      :return: character code to use for text in Broodwar, encoded as a string.
      :rtype: string

   .. method:: getType() -> PlayerType

      Retrieves the player's controller type.

      This allows you to distinguish betweeen computer and human players.

      :return: The :class:`~BWAPI.PlayerType` that identifies who is controlling a player.
      :rtype: :class:`BWAPI.PlayerType`

      .. code-block:: lua
         :caption: Example usage

         if BWAPI.Broodwar:enemy() then
           if BWAPI.Broodwar:enemy():getType() == BWAPI.PlayerTypes.Computer then
             print("Looks like something I can abuse!")
           end
         end

      .. note::
         Other players using :mod:`BWAPI` will be treated as a human player and return :attr:`PlayerTypes.Player`.

   .. method:: getUnits() -> Unitset

      Retrieves the set of all units that the player owns.

      This also includes incomplete units.

      :return: Reference to a :class:`~BWAPI.Unitset` containing the units.
      :rtype: :class:`BWAPI.Unitset`

      .. code-block:: lua
         :caption: Example usage

         local myUnits = BWAPI.Broodwar:self():getUnits()
         for u in myUnits:iterator() do
           -- Do something with your units
         end

      .. note::
         This does not include units that are loaded into transports, :attr:`Bunkers <BWAPI.UnitTypes.Terran_Bunker>`, :attr:`Refineries <BWAPI.UnitTypes.Terran_Refinery>`, :attr:`Assimilators <BWAPI.UnitTypes.Protoss_Assimilator>`, or :attr:`Extractors <BWAPI.UnitTypes.Zerg_Extractor>`.

   .. method:: getUnitScore() -> int

      Retrieves the total unit score, as seen in the end-game score screen.

      :return: The player's unit score.
      :rtype: int

   .. method:: getUpgradeLevel(upgrade) -> int

      Retrieves the current upgrade level that the player has attained for a given upgrade type.

      :param BWAPI.UpgradeType upgrade: The :class:`~BWAPI.UpgradeType` to query.

      :return: The number of levels that the ``upgrade`` has been upgraded for this player.
      :rtype: int

      .. seealso::
         :meth:`Unit.upgrade`, :meth:`getMaxUpgradeLevel`

   .. method:: hasResearched(tech) -> boolean

      Checks if the player has already researched a given technology.

      :param BWAPI.TechType tech: The :class:`~BWAPI.TechType` to query.

      :return: true if the player has obtained the given ``tech``, or false if they have not
      :rtype: boolean

      .. seealso::
         :meth:`isResearching`, :meth:`Unit.research`, :meth:`isResearchAvailable`

   .. method:: hasUnitTypeRequirement(unitType, [amount = 1]) -> boolean

      Verifies that this player satisfies a unit type requirement.

      This verifies complex type requirements involving morphable :attr:`~BWAPI.Races.Zerg` structures. For example, if something requires a :attr:`Spire <BWAPI.UnitTypes.Zerg_Spire>`, but the player has (or is in the process of morphing) a :attr:`Greater Spire <BWAPI.UnitTypes.Zerg_Greater_Spire>`, this function will identify the requirement. It is simply a convenience function that performs all of the requirement checks.

      :param BWAPI.UnitType unitType: The :class:`~BWAPI.UnitType` to check.
      :param int amount: (optional) The amount of units that are required.

      :return: true if the unit type requirements are met, and false otherwise.
      :rtype: boolean

   .. method:: incompleteUnitCount([unitType = UnitTypes.AllUnits]) -> int

      Retrieves the number of incomplete units that the player has.

      If the information about the player is limited, then this function will only return the number of visible incomplete units.

      :param BWAPI.UnitType unitType: (optional) The unit type to query. :class:`~BWAPI.UnitType` macros are accepted. If this parameter is omitted, then it will use :attr:`UnitTypes.AllUnits` by default.

      :return: The number of incomplete units of the given type that the player owns.
      :rtype: int

      .. note::
         This function is a macro for ``allUnitCount() - completedUnitCount()``.

      .. note::
         Incomplete Zerg units inside of eggs are not counted.

      .. seealso::
         :meth:`allUnitCount`, :meth:`visibleUnitCount`, :meth:`completedUnitCount`

   .. method:: isAlly(player) -> boolean

      Checks if this player is allied to the specified player.

      :param BWAPI.Player player: The player to check alliance with.

      :return: Returns ``true`` if this player is allied with ``player`` , or ``false`` if this player is not allied with ``player``
      :rtype: boolean

      .. note::
         This function will also return false if this player is neutral or an observer, or if ``player`` is neutral or an observer.

      .. seealso::
         :meth:`isEnemy`

   .. method:: isDefeated() -> boolean

      Checks if the player has been defeated.

      :return: true if the player is defeated, otherwise false
      :rtype: boolean

   .. method:: isEnemy(player) -> boolean

      Checks if this player is unallied to the specified player.

      :param BWAPI.Player player: The player to check alliance with.

      :return: Returns ``true`` if this player is allied with ``player`` , or ``false`` if this player is not allied with ``player``
      :rtype: boolean

      .. note::
         This function will also return false if this player is neutral or an observer, or if ``player`` is neutral or an observer.

      .. seealso::
         :meth:`isAlly`

   .. method:: isNeutral() -> boolean

      Checks if this player is the neutral player.

      :return: Returns ``true`` if this player is the neutral player, or ``false`` if this player is any other player
      :rtype: boolean

   .. method:: isObserver() -> boolean

      Checks if the player is an observer player, typically in a :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` observer game.

      An observer player does not participate in the game.

      :return: true if the player is observing, or false if the player is capable of playing in the game.
      :rtype: boolean

   .. method:: isResearchAvailable(tech) -> boolean

      Checks if a technology can be researched by the player.

      Certain technologies may be disabled in :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game types.

      :param BWAPI.TechType tech: The :class:`~BWAPI.TechType` to query.

      :return: true if the ``tech`` type is available to the player for research.
      :rtype: boolean

   .. method:: isResearching(tech) -> boolean

      Checks if the player is researching a given technology type.

      :param BWAPI.TechType tech: The :class:`~BWAPI.TechType` to query.

      :return: true if the player is currently researching the ``tech``, or false otherwise
      :rtype: boolean

      .. seealso::
         :meth:`Unit.research`, :meth:`hasResearched`

   .. method:: isUnitAvailable(unitType) -> boolean

      Checks if a unit type can be created by the player.

      Certain unit types may be disabled in :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game types.

      :param BWAPI.UnitType unitType: The :class:`~BWAPI.UnitType` to check.

      :return: true if the ``unitType`` is available to the player.
      :rtype: boolean

   .. method:: isUpgrading(upgrade) -> boolean

      Checks if the player is upgrading a given upgrade type.

      :param BWAPI.UpgradeType upgrade: The upgrade type to query.

      :return: true if the player is currently upgrading the given ``upgrade``, false otherwise
      :rtype: boolean

      .. seealso::
         :meth:`Unit.upgrade`

   .. method:: isVictorious() -> boolean

      Checks if the player has achieved victory.

      :return: true if this player has achieved victory, otherwise false
      :rtype: boolean

   .. method:: killedUnitCount([unit = UnitTypes.AllUnits]) -> int

      Retrieves the number units that the player has killed.

      :param BWAPI.UnitType unit: (optional) The unit type to query. :class:`~BWAPI.UnitType` macros are accepted. If this parameter is omitted, then it will use :attr:`UnitTypes.AllUnits` by default.

      :return: The total number of units that the player has killed throughout the game.
      :rtype: int

   .. method:: leftGame() -> boolean

      Checks if the player has left the game.

      :return: true if the player has left the game, otherwise false
      :rtype: boolean

   .. method:: maxEnergy(unitType) -> int

      Retrieves the maximum amount of energy that a unit type will have, taking the player's energy upgrades into consideration.

      :param BWAPI.UnitType unitType: The :class:`~BWAPI.UnitType` to retrieve the maximum energy for.

      :return: Maximum amount of energy that the given unit type can have.
      :rtype: int

   .. method:: minerals() -> int

      Retrieves the current amount of minerals/ore that this player has.

      :return: Amount of minerals that the player currently has for spending.
      :rtype: int

      .. note::
         This function will return 0 if the player is inaccessible.

   .. method:: refundedGas() -> int

      Retrieves the cumulative amount of vespene gas that this player has gained from refunding (cancelling) units and structures.

      :return: Cumulative amount of gas that the player has received from refunds.
      :rtype: int

      .. note::
         This function will return 0 if the player is inaccessible.

   .. method:: refundedMinerals() -> int

      Retrieves the cumulative amount of minerals/ore that this player has gained from refunding (cancelling) units and structures.

      :return: Cumulative amount of minerals that the player has received from refunds.
      :rtype: int

      .. note::
         This function will return 0 if the player is inaccessible.

   .. method:: repairedGas() -> int

      Retrieves the cumulative amount of vespene gas that this player has spent on repairing units since the beginning of the game.

      This function only applies to :attr:`~BWAPI.Races.Terran` players.

      :return: Cumulative amount of gas that the player has spent repairing.
      :rtype: int

      .. note::
         This function will return 0 if the player is inaccessible.

   .. method:: repairedMinerals() -> int

      Retrieves the cumulative amount of minerals/ore that this player has spent on repairing units since the beginning of the game.

      This function only applies to :attr:`~BWAPI.Races.Terran` players.

      :return: Cumulative amount of minerals that the player has spent repairing.
      :rtype: int

      .. note::
         This function will return 0 if the player is inaccessible.

   .. method:: sightRange(unitType) -> int

      Retrieves the sight range of a unit type, taking the player's sight range upgrades into consideration.

      :param BWAPI.UnitType unitType: The :class:`~BWAPI.UnitType` to retrieve the sight range for.

      :return: Sight range of the provided unit type for this player.
      :rtype: int

   .. method:: spentGas() -> int

      Retrieves the cumulative amount of vespene gas that this player has spent, excluding repairs.

      :return: Cumulative amount of gas that the player has spent.
      :rtype: int

      .. note::
         This function will return 0 if the player is inaccessible.

   .. method:: spentMinerals() -> int

      Retrieves the cumulative amount of minerals/ore that this player has spent, excluding repairs.

      :return: Cumulative amount of minerals that the player has spent.
      :rtype: int

      .. note::
         This function will return 0 if the player is inaccessible.

   .. method:: supplyTotal([race = Races.None]) -> int

      Retrieves the total amount of supply the player has available for unit control.

      :param BWAPI.Race race: (optional) The race to query the total supply for. If this is omitted, then the player's current race will be used.

      :return: The total supply available for this player and the given ``race``.
      :rtype: int

      .. code-block:: lua
         :caption: Example usage

         if BWAPI.Broodwar:self():supplyUsed() + 8 >= BWAPI.Broodwar:self():supplyTotal() then
           -- Construct pylons, supply depots, or overlords
         end

      .. note::
         In Starcraft programming, the managed supply values are double than what they appear in the game. The reason for this is because :attr:`Zerglings <BWAPI.UnitTypes.Zerg_Zergling>` use 0.5 visible supply.

      .. note::
         In Starcraft, the supply for each race is separate. Having a :attr:`Pylon <BWAPI.UnitTypes.Protoss_Pylon>` and an :attr:`Overlord <BWAPI.UnitTypes.Zerg_Overlord>` will not give you 32 supply. It will instead give you 16 :attr:`~BWAPI.Races.Protoss` supply and 16 :attr:`~BWAPI.Races.Zerg` supply.

      .. seealso::
         :meth:`supplyUsed`

   .. method:: supplyUsed([race = Races.None]) -> int

      Retrieves the current amount of supply that the player is using for unit control.

      :param BWAPI.Race race: (optional) The race to query the used supply for. If this is omitted, then the player's current race will be used.

      :return: The supply that is in use for this player and the given ``race``.
      :rtype: int

      .. note::
         In Starcraft programming, the managed supply values are double than what they appear in the game. The reason for this is because :attr:`Zerglings <BWAPI.UnitTypes.Zerg_Zergling>` use 0.5 visible supply.

      .. seealso::
         :meth:`supplyTotal`

   .. method:: topSpeed(unit) -> double

      Retrieves the top speed of a unit type, taking the player's speed upgrades into consideration.

      :param BWAPI.UnitType unit: The :class:`~BWAPI.UnitType` to retrieve the top speed for.

      :return: Top speed of the provided unit type for this player.
      :rtype: double

   .. method:: visibleUnitCount([unitType = UnitTypes.AllUnits]) -> int

      Retrieves the total number of strictly visible units that the player has, even if information on the player is unrestricted.

      :param BWAPI.UnitType unitType: (optional) The unit type to query. :class:`~BWAPI.UnitType` macros are accepted. If this parameter is omitted, then it will use :attr:`UnitTypes.AllUnits` by default.

      :return: The total number of units of the given type that the player owns, and is visible to the :mod:`BWAPI` player.
      :rtype: int

      .. seealso::
         :meth:`allUnitCount`, :meth:`completedUnitCount`, :meth:`incompleteUnitCount`

   .. method:: weaponDamageCooldown(unitType) -> int

      Retrieves the weapon cooldown of a unit type, taking the player's attack speed upgrades into consideration.

      :param BWAPI.UnitType unitType: The :class:`~BWAPI.UnitType` to retrieve the damage cooldown for.

      :return: Weapon cooldown of the provided unit type for this player.
      :rtype: int

   .. method:: weaponMaxRange(weapon) -> int

      Retrieves the maximum weapon range of a weapon type, taking the player's weapon upgrades into consideration.

      :param BWAPI.WeaponType weapon: The :class:`~BWAPI.WeaponType` to retrieve the maximum range for.

      :return: Maximum range of the given weapon type for units owned by this player.
      :rtype: int

   .. include:: /_include/interface-functions.rst
