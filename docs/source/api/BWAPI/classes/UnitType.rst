UnitType
********

.. currentmodule:: BWAPI

.. class:: UnitType

   The :class:`~BWAPI.UnitType` is used to get information about a particular type of unit, such as its cost, build time, weapon, hit points, abilities, etc.

   .. seealso::
      :meth:`Unit.getType`, :mod:`~BWAPI.UnitTypes`

   .. rubric:: Constructors

   .. method:: UnitType([id = UnitTypes.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

   .. method:: abilities() -> TechTypeset

      Retrieves the set of abilities that this unit can use, provided it is available to you in the game.

      :return: Set of :class:`TechType`'s containing ability information.
      :rtype: :class:`BWAPI.TechTypeset`

   .. method:: acceleration() -> int

      Retrieves the unit's acceleration amount.

      :return: How fast the unit can accelerate to its top speed.
      :rtype: int

   .. method:: airWeapon() -> WeaponType

      Retrieves this unit type's weapon type used when attacking targets in the air.

      :return: :class:`~BWAPI.WeaponType` used as this unit type's air weapon.
      :rtype: :class:`BWAPI.WeaponType`

      .. seealso::
         :meth:`maxAirHits`, :meth:`groundWeapon`

   .. method:: armor() -> int

      Retrieves the default amount of armor that the unit type starts with, excluding upgrades.

      :return: The amount of armor the unit type has.
      :rtype: int

      .. note::
         This value may not necessarily match the value seen in the :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game type.

   .. method:: armorUpgrade() -> UpgradeType

      Retrieves the upgrade type used to increase the armor of this unit type.

      For each upgrade, this unit type gains +1 additional armor.

      :return: :class:`~BWAPI.UpgradeType` indicating the upgrade that increases this unit type's armor amount.
      :rtype: :class:`BWAPI.UpgradeType`

   .. method:: buildScore() -> int

      Retrieves the amount of score points awarded for constructing this unit type.

      This value is used for calculating scores in the post-game score screen.

      :return: Number of points awarded for constructing this unit type.
      :rtype: int

      .. seealso::
         :meth:`destroyScore`

   .. method:: buildsWhat() -> UnitTypeset

      Retrieves the set of units that this unit type is capable of creating.

      This includes training, constructing, warping, and morphing.

      :return: :class:`~BWAPI.UnitTypeset` containing the units it can build.
      :rtype: :class:`BWAPI.UnitTypeset`

      .. note::
         Some maps have special parameters that disable construction of units that are otherwise normally available. Use :meth:`Player.isUnitAvailable` to determine if a unit type is actually available in the current game for a specific player.

      .. seealso::
         :meth:`Player.isUnitAvailable`

   .. method:: buildTime() -> int

      Retrieves the default time, in frames, needed to train, morph, or build the unit.

      :return: Number of frames needed in order to build the unit.
      :rtype: int

      .. note::
         This value may not necessarily match the value seen in the :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game type.

      .. seealso::
         :meth:`Unit.getRemainingBuildTime`

   .. method:: canAttack() -> boolean

      Checks if this unit is capable of attacking.

      :return: true if this unit type is capable of damaging other units with a standard attack, and false otherwise.
      :rtype: boolean

      .. note::
         This function returns false for units that can only inflict damage via special abilities, such as the :attr:`High Templar <BWAPI.UnitTypes.Protoss_High_Templar>`.

   .. method:: canBuildAddon() -> boolean

      Checks if this unit type is capable of constructing an add-on.

      An add-on is an extension or attachment for :attr:`~BWAPI.Races.Terran` structures, specifically the :attr:`Command Center <BWAPI.UnitTypes.Terran_Command_Center>`, :attr:`Factory <BWAPI.UnitTypes.Terran_Factory>`, :attr:`Starport <BWAPI.UnitTypes.Terran_Starport>`, and :attr:`Science Facility <BWAPI.UnitTypes.Terran_Science_Facility>`.

      :return: true if this unit type can construct an add-on, and false if it can not.
      :rtype: boolean

      .. seealso::
         :meth:`isAddon`

   .. method:: canMove() -> boolean

      Checks if this unit type is capable of movement.

      :return: true if this unit can use a movement command, and false if they cannot move.
      :rtype: boolean

      .. note::
         Buildings will return false, including :attr:`~BWAPI.Races.Terran` liftable buildings which are capable of moving when lifted.

   .. method:: canProduce() -> boolean

      Determines if a unit can train other units.

      For example, ``BWAPI.UnitTypes.Terran_Barracks:canProduce()`` will return ``true``, while ``BWAPI.UnitTypes.Terran_Marine:canProduce()`` will return ``false``. This is also true for two non-structures: :attr:`~BWAPI.UnitTypes.Protoss_Carrier` (can produce interceptors) and :attr:`~BWAPI.UnitTypes.Protoss_Reaver` (can produce scarabs).

      :return: true if this unit type can have a production queue, and false otherwise.
      :rtype: boolean

   .. method:: cloakingTech() -> TechType

      Retrieves the cloaking technology associated with certain units.

      :return: :class:`~BWAPI.TechType` referring to the cloaking technology that this unit type uses as an ability. Returns ``TechTypes.None`` if this unit type does not have an active cloak ability.
      :rtype: :class:`BWAPI.TechType`

   .. method:: destroyScore() -> int

      Retrieves the amount of score points awarded for killing this unit type.

      This value is used for calculating scores in the post-game score screen.

      :return: Number of points awarded for killing this unit type.
      :rtype: int

      .. seealso::
         :meth:`buildScore`

   .. method:: dimensionDown() -> int

      Retrieves the distance from the center of the unit type to its bottom edge.

      :return: Distance to this unit type's bottom edge from its center, in pixels.
      :rtype: int

   .. method:: dimensionLeft() -> int

      Retrieves the distance from the center of the unit type to its left edge.

      :return: Distance to this unit type's left edge from its center, in pixels.
      :rtype: int

   .. method:: dimensionRight() -> int

      Retrieves the distance from the center of the unit type to its right edge.

      :return: Distance to this unit type's right edge from its center, in pixels.
      :rtype: int

   .. method:: dimensionUp() -> int

      Retrieves the distance from the center of the unit type to its top edge.

      :return: Distance to this unit type's top edge from its center, in pixels.
      :rtype: int

   .. method:: gasPrice() -> int

      Retrieves the default vespene gas price of purchasing the unit.

      :return: Vespene gas cost of the unit.
      :rtype: int

      .. note::
         This value may not necessarily match the value seen in the :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game type.

   .. method:: getRace() -> Race

      Retrieves the :class:`~BWAPI.Race` that the unit type belongs to.

      :return: :class:`~BWAPI.Race` indicating the race that owns this unit type. Returns ``Race.None`` indicating that the unit type does not belong to any particular race (a critter for example).
      :rtype: :class:`BWAPI.Race`

   .. method:: groundWeapon() -> WeaponType

      Retrieves this unit type's weapon type used when attacking targets on the ground.

      :return: :class:`~BWAPI.WeaponType` used as this unit type's ground weapon.
      :rtype: :class:`BWAPI.WeaponType`

      .. seealso::
         :meth:`maxGroundHits`, :meth:`airWeapon`

   .. method:: haltDistance() -> int

      Retrieves the unit's halting distance.

      This determines how fast a unit can stop moving.

      :return: A halting distance value.
      :rtype: int

   .. method:: hasPermanentCloak() -> boolean

      Checks if this unit type is permanently cloaked.

      This means the unit type is always cloaked and requires a detector in order to see it.

      :return: true if this unit type is permanently cloaked, and false otherwise.
      :rtype: boolean

   .. method:: height() -> int

      A macro for retrieving the height of the unit type, which is calculated using dimensionUp + dimensionDown + 1.

      :return: Height of the unit, in pixels.
      :rtype: int

   .. method:: isAddon() -> boolean

      Checks if this unit is an add-on.

      Add-ons are attachments used by some :attr:`~BWAPI.Races.Terran` structures such as the :attr:`Comsat Station <BWAPI.UnitTypes.Terran_Comsat_Station>`.

      :return: true if this unit is an add-on, and false otherwise.
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: ``getRace() == BWAPI.Races.Terran``, ``isBuilding()``

   .. method:: isBeacon() -> boolean

      Checks if this unit type is a beacon.

      Each race has exactly one beacon each. They are :attr:`UnitTypes.Special_Zerg_Beacon`, :attr:`UnitTypes.Special_Terran_Beacon`, and :attr:`UnitTypes.Special_Protoss_Beacon`.

      :return: true if this unit type is one of the three race beacons, and false otherwise.
      :rtype: boolean

      .. seealso::
         :meth:`isFlagBeacon`

   .. method:: isBuilding() -> boolean

      Checks if this unit is a structure.

      This includes :attr:`Mineral Fields <BWAPI.UnitTypes.Resource_Mineral_Field>` and :attr:`Vespene Geysers <BWAPI.UnitTypes.Resource_Vespene_Geyser>`.

      :return: true if this unit is a building, and false otherwise.
      :rtype: boolean

   .. method:: isBurrowable() -> boolean

      Checks if this unit type has the capability to use the :attr:`Burrow <BWAPI.TechTypes.Burrowing>` technology when it is researched.

      :return: true if this unit can use the :attr:`Burrow <BWAPI.TechTypes.Burrowing>` ability, and false otherwise.
      :rtype: boolean

      .. note::
         The `~BWAPI.UnitTypes.Zerg_Lurker` can burrow even without researching the ability.

      .. seealso::
         :attr:`BWAPI.TechTypes.Burrowing`

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: ``getRace() == BWAPI.Races.Zerg``, ``not isBuilding()``, ``canMove()``

   .. method:: isCloakable() -> boolean

      Checks if this unit type has the capability to use a cloaking ability when it is researched.

      This applies only to :attr:`Wraiths <BWAPI.UnitTypes.Terran_Wraith>` and :attr:`Ghosts <BWAPI.UnitTypes.Terran_Ghost>`, and does not include units which are permanently cloaked.

      :return: true if this unit has a cloaking ability, false otherwise.
      :rtype: boolean

      .. seealso::
         :meth:`hasPermanentCloak`, :attr:`TechTypes.Cloaking_Field`, :attr:`TechTypes.Personnel_Cloaking`

   .. method:: isCritter() -> boolean

      Checks if this unit type is a neutral critter.

      :return: true if this unit type is a critter, and false otherwise.
      :rtype: boolean

      .. code-block:: lua
         :caption: Example usage

         local myBasePosition = BWAPI.Position( BWAPI.Broodwar:self():getStartLocation() )
         local pred = function(unit) return not BWAPI.Filter.IsOwned(unit) and not BWAPI.Filter.IsParasited(unit) end
         local unitsAroundTheBase = BWAPI.Broodwar:getUnitsInRadius(myBasePosition, 1024, pred)
         for u in unitsAroundTheBase:iterator() do
           if u:getType():isCritter() and not u:isInvincible() then
             local myQueenPred = function(unit) return unit:getType() == BWAPI.UnitTypes.Zerg_Queen and BWAPI.Filter.IsOwned(unit) end
             local myQueen = u:getClosestUnit(myQueenPred)
             if myQueen then
               myQueen:useTech(BWAPI.TechTypes.Parasite, u)
             end
           end
         end

   .. method:: isDetector() -> boolean

      Checks if this unit type is capable of detecting units that are cloaked or burrowed.

      :return: true if this unit type is a detector by default, false if it does not have this property
      :rtype: boolean

   .. method:: isFlagBeacon() -> boolean

      Checks if this unit type is a flag beacon.

      Each race has exactly one flag beacon each. They are :attr:`UnitTypes.Special_Zerg_Flag_Beacon`, :attr:`UnitTypes.Special_Terran_Flag_Beacon`, and :attr:`UnitTypes.Special_Protoss_Flag_Beacon`. Flag beacons spawn a flag after some ARBITRARY I FORGOT AMOUNT OF FRAMES.

      :return: true if this unit type is one of the three race flag beacons, and false otherwise.
      :rtype: boolean

      .. seealso::
         :meth:`isBeacon`

   .. method:: isFlyer() -> boolean

      Checks if this unit type is a flying unit.

      Flying units ignore ground pathing and collisions.

      :return: true if this unit type is in the air by default, and false otherwise.
      :rtype: boolean

   .. method:: isFlyingBuilding() -> boolean

      Checks if this structure has the capability to use the lift-off command.

      :return: true if this unit type is a flyable building, false otherwise.
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: ``isBuilding()``

   .. method:: isHero() -> boolean

      Checks if this unit type is a hero.

      Heroes are types that the player cannot obtain normally, and are identified by the white border around their icon when selected with a group.

      :return: true if this unit type is a hero type, and false otherwise.
      :rtype: boolean

      .. note::
         There are two non-hero units included in this set, the `Civilian <BWAPI.UnitTypes.Terran_Civilian>` and `Dark Templar Hero <BWAPI.UnitTypes.Hero_Dark_Templar>`.

   .. method:: isInvincible() -> boolean

      Checks if this unit type is invincible by default.

      Invincible units cannot take damage.

      :return: true if this unit type is invincible, and false if it is vulnerable to attacks.
      :rtype: boolean

   .. method:: isMechanical() -> boolean

      Checks if this unit is mechanical.

      The mechanical property is required for some actions such as repair.

      :return: true if this unit type has the mechanical property, and false otherwise.
      :rtype: boolean

   .. method:: isMineralField() -> boolean

      Checks if this unit type is a mineral field and contains a resource amount.

      This indicates that the unit type is either :attr:`UnitTypes.Resource_Mineral_Field`, :attr:`UnitTypes.Resource_Mineral_Field_Type_2`, or :attr:`UnitTypes.Resource_Mineral_Field_Type_3`.

      :return: true if this unit type is a mineral field resource.
      :rtype: boolean

   .. method:: isNeutral() -> boolean

      Checks if this unit type is a neutral type, such as critters and resources.

      :return: true if this unit is intended to be neutral, and false otherwise.
      :rtype: boolean

   .. method:: isOrganic() -> boolean

      Checks if this unit is an organic unit.

      The organic property is required for some abilities such as `~BWAPI.TechTypes.Heal`.

      :return: true if this unit type has the organic property, and false otherwise.
      :rtype: boolean

   .. method:: isPowerup() -> boolean

      Checks if this unit type is a powerup.

      Powerups can be picked up and carried by workers. They are usually only seen in campaign maps and :attr:`Capture The Flag <BWAPI.GameTypes.Capture_The_Flag>`.

      :return: true if this unit type is a powerup type, and false otherwise.
      :rtype: boolean

   .. method:: isRefinery() -> boolean

      Checks if this unit type is a refinery.

      A refinery is a structure that is placed on top of a :attr:`Vespene Geyser <BWAPI.UnitTypes.Resource_Vespene_Geyser>` . Refinery types are :attr:`BWAPI.UnitTypes.Terran_Refinery` , :attr:`BWAPI.UnitTypes.Zerg_Extractor` , and :attr:`BWAPI.UnitTypes.Protoss_Assimilator`.

      :return: true if this unit type is a refinery, and false if it is not.
      :rtype: boolean

      .. code-block:: lua
         :caption: Example

         local myUnits = BWAPI.Broodwar:self():getUnits()
         for u in myUnits:iterator() do
           if u:getType():isRefinery() then
             local workersAssigned = u.clientInfo["work"]
             if not workersAssigned or workersAssigned < 3 then
               local idleWorkerFilter = function(unit) return BWAPI.Filter.IsWorker(unit) and BWAPI.Filter.IsIdle(unit) end
               local closestIdleWorker = u:getClosestUnit(idleWorkerFilter)
               if closestIdleWorker then
                 -- gather from the refinery (and check if successful)
                 if closestIdleWorker:gather(u) then
                   -- set a back reference for when the unit is killed or re-assigned (code not provided)
                   closestIdleWorker.clientInfo['ref'] = u

                   -- Increment the number of workers assigned and associate it with the refinery
                   workersAssigned = workersAssigned + 1
                   u.clientInfo['work'] = workersAssigned
                 end
               end
             end
           end
         end

   .. method:: isResourceContainer() -> boolean

      Checks if this unit type is capable of storing resources such as :attr:`Mineral Fields <BWAPI.UnitTypes.Resource_Mineral_Field>`.

      Resources are harvested from resource containers.

      :return: true if this unit type may contain resources that can be harvested, false otherwise.
      :rtype: boolean

   .. method:: isResourceDepot() -> boolean

      Checks if this unit type is a resource depot.

      Resource depots must be placed a certain distance from resources. Resource depots are typically the main building for any particular race. Workers will return resources to the nearest resource depot.

      :return: true if the unit type is a resource depot, false if it is not.
      :rtype: boolean

      .. code-block:: lua
         :caption: Example

         if BWAPI.Broodwar:self() then
           local myUnits = BWAPI.Broodwar:self():getUnits()
           for u in myUnits:iterator() do
             if u:isIdle() and u:getType():isResourceDepot() then
               u:train( u:getType():getRace():getWorker() )
            end
           end
         end

   .. method:: isRobotic() -> boolean

      Checks if this unit is robotic.

      The robotic property is applied to robotic units such as the :attr:`~BWAPI.UnitTypes.Protoss_Probe` which prevents them from taking damage from :attr:`BWAPI.TechTypes.Irradiate`.

      :return: true if this unit type has the robotic property, and false otherwise.
      :rtype: boolean

   .. method:: isSpecialBuilding() -> boolean

      Checks if this structure is special and cannot be obtained normally within the game.

      :return: true if this structure is a special building, and false otherwise.
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: ``isBuilding()``

   .. method:: isSpell() -> boolean

      Identifies if this unit type is used to complement some :mod:`abilities <BWAPI.TechTypes>`.

      These include :attr:`UnitTypes.Spell_Dark_Swarm`, :attr:`UnitTypes.Spell_Disruption_Web`, and :attr:`UnitTypes.Spell_Scanner_Sweep`, which correspond to :attr:`TechTypes.Dark_Swarm`, :attr:`TechTypes.Disruption_Web`, and :attr:`TechTypes.Scanner_Sweep` respectively.

      :return: true if this unit type is used for an ability, and false otherwise.
      :rtype: boolean

   .. method:: isSpellcaster() -> boolean

      Checks if this unit type has the capacity to store energy and use it for special abilities.

      :return: true if this unit type generates energy, and false if it does not have an energy pool.
      :rtype: boolean

   .. method:: isSuccessorOf(unitType) -> boolean

      Checks if the current type is equal to the provided type, or a successor of the provided type.

      For example, a Hive is a successor of a Hatchery, since it can still research the :attr:`~BWAPI.TechTypes.Burrowing` technology.

      :param BWAPI.UnitType unitType: The unit type to check.
      :return: true if this unit type is a successor of the given unit type, and false if it is not.
      :rtype: boolean

   .. method:: isTwoUnitsInOneEgg() -> boolean

      Checks if this unit type spawns two units when being hatched from an :attr:`~BWAPI.UnitTypes.Zerg_Egg`.

      This is only applicable to :attr:`Zerglings <BWAPI.UnitTypes.Zerg_Zergling>`.

      :return: true if morphing this unit type will spawn two of them, and false if only one is spawned.
      :rtype: boolean

   .. method:: isWorker() -> boolean

      Checks if this unit type is a worker unit.

      Worker units can harvest resources and build structures. Worker unit types include the :attr:`~BWAPI.UnitTypes.Terran_SCV` , :attr:`~BWAPI.UnitTypes.Protoss_Probe`, and :attr:`~BWAPI.UnitTypes.Zerg_Drone`.

      :return: true if this unit type is a worker, and false if it is not.
      :rtype: boolean

   .. method:: maxAirHits() -> int

      Retrieves the maximum number of hits this unit can deal to a flying target using its air weapon.

      This value is multiplied by the air weapon's damage to calculate the unit type's damage potential.

      :return: Maximum number of hits given to air targets.
      :rtype: int

      .. seealso::
         :meth:`airWeapon`, :meth:`maxGroundHits`

   .. method:: maxEnergy() -> int

      Retrieves the maximum amount of energy this unit type can have by default.

      :return: Integer indicating the maximum amount of energy for this unit type. Returns ``0`` if this unit does not gain energy for abilities.
      :rtype: int

   .. method:: maxGroundHits() -> int

      Retrieves the maximum number of hits this unit can deal to a ground target using its ground weapon.

      This value is multiplied by the ground weapon's damage to calculate the unit type's damage potential.

      :return: Maximum number of hits given to ground targets.
      :rtype: int

      .. seealso::
         :meth:`groundWeapon`, :meth:`maxAirHits`

   .. method:: maxHitPoints() -> int

      Retrieves the default maximum amount of hit points that this unit type can have.

      :return: Integer indicating the maximum amount of hit points for this unit type.
      :rtype: int

      .. note::
         This value may not necessarily match the value seen in the :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game type.

   .. method:: maxShields() -> int

      Retrieves the default maximum amount of shield points that this unit type can have.

      :return: Integer indicating the maximum amount of shield points for this unit type. Returns ``0`` if this unit type does not have shields.
      :rtype: int

      .. note::
         This value may not necessarily match the value seen in the :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game type.

   .. method:: mineralPrice() -> int

      Retrieves the default mineral price of purchasing the unit.

      :return: Mineral cost of the unit.
      :rtype: int

      .. note::
         This value may not necessarily match the value seen in the :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game type.

   .. method:: producesCreep() -> boolean

      Checks if this structure type produces creep.

      That is, the unit type spreads creep over a wide area so that :attr:`~BWAPI.Races.Zerg` structures can be placed on it.

      :return: true if this unit type spreads creep.
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: ``getRace() == BWAPI.Races.Zerg``, ``isBuilding()``

   .. method:: producesLarva() -> boolean

      Checks if this unit type produces larva.

      This is essentially used to check if the unit type is a :attr:`~BWAPI.UnitTypes.Zerg_Hatchery`, :attr:`~BWAPI.UnitTypes.Zerg_Lair`, or :attr:`~BWAPI.UnitTypes.Zerg_Hive`.

      :return: true if this unit type produces larva.
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: ``getRace() == BWAPI.Races.Zerg``, ``isBuilding()``

   .. method:: regeneratesHP() -> boolean

      Checks if this unit type can regenerate hit points.

      This generally applies to :attr:`~BWAPI.Races.Zerg` units.

      :return: true if this unit type regenerates its hit points, and false otherwise.
      :rtype: boolean

   .. method:: requiredTech() -> TechType

      Identifies the required :class:`~BWAPI.TechType` in order to create certain units.

      :return: :class:`~BWAPI.TechType` indicating the technology that must be researched in order to create this unit type. Returns ``TechTypes.None`` if creating this unit type does not require a technology to be researched.
      :rtype: :class:`BWAPI.TechType`

      .. note::
         The only unit that requires a technology is the :attr:`~BWAPI.UnitTypes.Zerg_Lurker`, which needs :attr:`~BWAPI.TechTypes.Lurker_Aspect`.

   .. method:: requiredUnits() -> table

      Retrieves the immediate technology tree requirements to make this unit type.

      .. important::
         See :ref:`the differences between the C++ and Lua implementations of this function <differences-requiredUnits>` for more information

      :return: Table containing the number of required units of each type that are necessary to make this unit type.
      :rtype: ``table`` of the format ``{ [<unitTypeID>] = <howMany> }``, where ``<unitTypeID>`` is the integer ID/Enum of a required UnitType (equal to ``UnitType:getID()``) and ``<howMany>`` is the required number of that unit.

      .. code-block:: lua
         :caption: Example usage

         local scv = BWAPI.UnitTypes.SCV
         local requiredUnits = scv:requiredUnits()
         for unitTypeID, howMany in pairs(requiredUnits) do
           local requiredUnitType = BWAPI.UnitType(unitTypeID)
           local str = string.format("%s requires %d %s",
             tostring(scv),
             howMany,
             tostring(requiredUnitType)
           )
           print(str)
         end

   .. method:: requiresCreep() -> boolean

      Checks if this structure must be placed on :attr:`~BWAPI.Races.Zerg` creep.

      :return: true if this unit type requires creep, false otherwise.
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: ``isBuilding()``, ``getRace() == BWAPI.Races.Zerg``

   .. method:: requiresPsi() -> boolean

      Checks if this structure is powered by a psi field.

      Structures powered by psi can only be placed near a :attr:`~BWAPI.UnitTypes.Protoss_Pylon`. If the :attr:`~BWAPI.UnitTypes.Protoss_Pylon` is destroyed, then this unit will lose power.

      :return: true if this unit type can only be placed in a psi field, false otherwise.
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: ``isBuilding()``, ``getRace() == BWAPI.Races.Protoss``

   .. method:: researchesWhat() -> TechTypeset

      Retrieves the set of technologies that this unit type is capable of researching.

      :return: :class:`TechTypeset` containing the technology types that can be researched.
      :rtype: :class:`BWAPI.TechTypeset`

      .. note::
         Some maps have special parameters that disable certain technologies. Use :meth:`Player.isResearchAvailable` to determine if a technology is actually available in the current game for a specific player.

      .. seealso::
         :meth:`Player.isResearchAvailable`

   .. method:: seekRange() -> int

      Retrieves the range at which this unit type will start targeting enemy units.

      :return: Distance at which this unit type begins to seek out enemy units, in pixels.
      :rtype: int

   .. method:: sightRange() -> int

      Retrieves the sight range of this unit type.

      :return: Sight range of this unit type, measured in pixels.
      :rtype: int

   .. method:: size() -> UnitSizeType

      Retrieves the :class:`~BWAPI.UnitSizeType` of this unit, which is used in calculations along with weapon damage types to determine the amount of damage that will be dealt to this type.

      :return: :class:`~BWAPI.UnitSizeType` indicating the conceptual size of the unit type.
      :rtype: :class:`BWAPI.UnitSizeType`

      .. seealso::
         :meth:`WeaponType.damageType`

   .. method:: spaceProvided() -> int

      Retrieves the amount of space provided by this :attr:`~BWAPI.UnitTypes.Terran_Bunker` or Transport(:attr:`~BWAPI.UnitTypes.Terran_Dropship`, :attr:`~BWAPI.UnitTypes.Protoss_Shuttle`, :attr:`~BWAPI.UnitTypes.Zerg_Overlord` ) for unit transportation.

      :return: The number of slots provided by this unit type.
      :rtype: int

      .. seealso::
         :meth:`spaceRequired`

   .. method:: spaceRequired() -> int

      Retrieves the amount of space required by this unit type to fit inside a :attr:`~BWAPI.UnitTypes.Terran_Bunker` or Transport(:attr:`~BWAPI.UnitTypes.Terran_Dropship`, :attr:`~BWAPI.UnitTypes.Protoss_Shuttle`, :attr:`~BWAPI.UnitTypes.Zerg_Overlord` ).

      :return: Amount of space required by this unit type for transport. Returns ``255`` if this unit type can not be transported.
      :rtype: int

      .. seealso::
         :meth:`spaceProvided`

   .. method:: supplyProvided() -> int

      Retrieves the amount of supply that this unit type produces for its appropriate :class:`~BWAPI.Race`'s supply pool.

      :return:
      :rtype: int

      .. note::
         In Starcraft programming, the managed supply values are double than what they appear in the game. The reason for this is because :attr:`Zerglings <BWAPI.UnitTypes.Zerg_Zergling>` use 0.5 visible supply.

      .. seealso::
         :meth:`supplyRequired`, :meth:`Player.supplyTotal`, :meth:`Player.supplyUsed`

   .. method:: supplyRequired() -> int

      Retrieves the amount of supply that this unit type will use when created.

      It will use the supply pool that is appropriate for its :class:`~BWAPI.Race`.

      :return: Integer containing the supply required to build this unit.
      :rtype: int

      .. note::
         In Starcraft programming, the managed supply values are double than what they appear in the game. The reason for this is because :attr:`Zerglings <BWAPI.UnitTypes.Zerg_Zergling>` use 0.5 visible supply.

      .. seealso::
         :meth:`supplyProvided`, :meth:`Player.supplyTotal`, :meth:`Player.supplyUsed`

   .. method:: tileHeight() -> int

      Retrieves the height of this unit type, in tiles.

      Used for determining the tile size of structures.

      :return: Height of this unit type, in tiles.
      :rtype: int

   .. method:: tileSize() -> TilePosition

      Retrieves the tile size of this unit type.

      Used for determining the tile size of structures.

      :return: TilePosition containing the width (x) and height (y) of the unit type, in tiles.
      :rtype: :class:`BWAPI.TilePosition`

   .. method:: tileWidth() -> int

      Retrieves the width of this unit type, in tiles.

      Used for determining the tile size of structures.

      :return: Width of this unit type, in tiles.
      :rtype: int

   .. method:: topSpeed() -> double

      Retrieves this unit type's top movement speed with no upgrades.

      :return: The approximate top speed, in pixels per frame, as a double. For liftable :attr:`~BWAPI.Races.Terran` structures, this function returns their movement speed while lifted.
      :rtype: double

      .. note::
         That some units have inconsistent movement and this value is sometimes an approximation.

   .. method:: turnRadius() -> int

      Retrieves a unit's turning radius.

      This determines how fast a unit can turn.

      :return: A turn radius value.
      :rtype: int

   .. method:: upgrades() -> UpgradeTypeset

      Retrieves the set of upgrades that this unit can use to enhance its fighting ability.

      :return: Set of :class:`UpgradeType`'s containing upgrade types that will impact this unit type.
      :rtype: :class:`BWAPI.UpgradeTypeset`

   .. method:: upgradesWhat() -> UpgradeTypeset

      Retrieves the set of upgrades that this unit type is capable of upgrading.

      :return: :class:`UpgradeTypeset` containing the upgrade types that can be upgraded.
      :rtype: :class:`BWAPI.UpgradeTypeset`

      .. note::
         Some maps have special upgrade limitations. Use :meth:`Player.getMaxUpgradeLevel` to check if an upgrade is available.

      .. seealso::
         :meth:`Player.getMaxUpgradeLevel`

   .. method:: whatBuilds() -> unitType, int

      Obtains the source unit type that is used to build or train this unit type, as well as the amount of them that are required.

      .. important::
         See :ref:`the differences between the C++ and Lua implementations of this function <differences-whatBuilds>` for more information

      :return: Two values, where the first value is the :class:`~BWAPI.UnitType` that builds this unit type, and the second value is the number of those types that are required (this value is 2 for `Archons <BWAPI.UnitType.Protoss_Archon>`, and 1 for all other types). Returns ``nil`` if this unit type cannot be made by the player.
      :rtype: :class:`~BWAPI.UnitType`, int

   .. method:: width() -> int

      A macro for retrieving the width of the unit type, which is calculated using dimensionLeft + dimensionRight + 1.

      :return: Width of the unit, in pixels.
      :rtype: int

UnitTypeset
***********

.. class:: UnitTypeset

   A container for a set of :class:`UnitType` objects.

   .. rubric:: Constructors

   .. method:: UnitTypeset()

      Default constructor.

   .. method:: UnitTypeset(set)

      Copy constructor.

      :param BWAPI.UnitTypeset set: The UnitTypeset to copy.

   .. method:: UnitTypeset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`UnitType` are added to the set.

      :param table tbl: A table containing :class:`UnitType` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
