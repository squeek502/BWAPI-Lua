Unit
****

.. currentmodule:: BWAPI

.. class:: Unit

   The Unit class is used to get information about individual units as well as issue orders to units.

   Every Unit in the game is either accessible or inaccessible. To determine if an AI can access a particular unit, BWAPI checks to see if :attr:`BWAPI.Flag.CompleteMapInformation` is enabled. So there are two cases to consider - either the flag is enabled, or it is disabled:

   If :attr:`BWAPI.Flag.CompleteMapInformation` is disabled, then a unit is accessible if and only if it is visible.  If :attr:`BWAPI.Flag.CompleteMapInformation` is enabled, then all units that exist in the game are accessible, and :meth:`Unit.exists` is accurate for all units. Similarly :meth:`BWAPI.onUnitDestroy` messages are generated for all units that get destroyed, not just visible ones.

   .. note::
      Some properties of visible enemy units will not be made available to the AI (such as the contents of visible enemy dropships). If a unit is not visible, :meth:`Unit.exists` will return ``false``, regardless of whether or not the unit exists. This is because absolutely no state information on invisible enemy units is made available to the AI. To determine if an enemy unit has been destroyed, the AI must watch for :meth:`BWAPI.onUnitDestroy` messages from BWAPI, which is only called for visible units which get destroyed.

   If a Unit is not accessible, then only the ``getInitial*`` functions will be available to the AI. However for units that were owned by the player, :meth:`Unit.getPlayer` and :meth:`Unit.getType` will continue to work for units that have been destroyed.

   .. rubric:: Constructors

   This class is not constructable through Lua.

   .. rubric:: Member Variables

   .. include:: /_include/interface-clientinfo.rst

   .. rubric:: Member Functions

   .. method:: getID() -> id

      Retrieves a unique identifier for this unit.

      :return: An integer containing the unit's identifier.
      :rtype: number

      .. seealso::
         :meth:`getReplayID`

   .. method:: exists() -> exists

      Checks if the Unit exists in the view of the BWAPI player.

      This is used primarily to check if BWAPI has access to a specific unit, or if the unit is alive. This function is more general and would be synonymous to an isAlive function if such a function were necessary.

      In the event that this function returns ``false``, there are two cases to consider:

      1. You own the unit. This means the unit is dead.
      2. Another player owns the unit. This could either mean that you don't have access to the unit or that the unit has died. You can specifically identify dead units by polling onUnitDestroy.

      :return: ``true`` if the unit exists on the map and is visible according to BWAPI or ``false`` if the unit is not accessible or the unit is dead.
      :rtype: boolean

      .. seealso::
         :meth:`isVisible`, :meth:`isCompleted`

   .. method:: getReplayID() -> id

      Retrieves the unit identifier for this unit as seen in replay data.

      .. note::
         This is only available if :attr:`BWAPI.Flag.CompleteMapInformation` is enabled.

      :return: An integer containing the replay unit identifier.

      .. seealso::
         :meth:`getID`


   .. method:: getPlayer() -> player

      Retrieves the player that owns this unit.

      :return: The owning :class:`Player` or :meth:`Game.neutral` if the unit is a neutral unit or inaccessible.
      :rtype: :class:`BWAPI.Player`

   .. method:: getType() -> type

      Retrieves the unit's type.

      :return: A :class:`UnitType` representing the unit's type or :attr:`~BWAPI.UnitTypes.Unknown` if this unit is inaccessible or cannot be determined.
      :rtype: :class:`BWAPI.UnitType`

      .. seealso::
         :meth:`getInitialType`


   .. method:: getPosition() -> position

      Retrieves the unit's position from the upper left corner of the map in pixels.

      The position returned is roughly the center if the unit.

      :return: Position object representing the unit's current position or :attr:`~BWAPI.Positions.Unknown` if this unit is inaccessible.
      :rtype: :class:`BWAPI.Position`

      .. note::
         The unit bounds are defined as this value plus/minus the values of :meth:`UnitType.dimensionLeft`, :meth:`UnitType.dimensionUp`, :meth:`UnitType.dimensionRight`, and :meth:`UnitType.dimensionDown`, which is conveniently expressed in :meth:`getLeft`, :meth:`getTop`, :meth:`getRight`, and :meth:`getBottom` respectively.

      .. seealso::
         :meth:`getTilePosition`, :meth:`getInitialPosition`, :meth:`getLeft`, :meth:`getTop`

   .. method:: getTilePosition() -> tilePosition

      Retrieves the unit's build position from the upper left corner of the map in tiles.

      :return: TilePosition object representing the unit's current tile position or :attr:`~BWAPI.TilePositions.Unknown` if this unit is inaccessible.
      :rtype: :class:`BWAPI.TilePosition`

      .. note::
         This tile position is the tile that is at the top left corner of the structure.

      .. seealso::
         :meth:`getPosition`, :meth:`getInitialTilePosition`

   .. method:: getAngle() -> angle

      Retrieves the unit's facing direction in radians.

      .. note::
         A value of 0.0 means the unit is facing east.

      :return: A double with the angle measure in radians.
      :rtype: number

   .. method:: getVelocityX() -> velocityX

      Retrieves the x component of the unit's velocity, measured in pixels per frame.

      :return: A double that represents the velocity's x component.
      :rtype: number

      .. seealso::
         :meth:`getVelocityY`

   .. method:: getVelocityY() -> velocityY

      Retrieves the y component of the unit's velocity, measured in pixels per frame.

      :return: A double that represents the velocity's y component.
      :rtype: number

      .. seealso::
         :meth:`getVelocityX`

   .. method:: getRegion() -> region

      Retrieves the Region that the center of the unit is in.

      :return: The :class:`Region` object that contains this unit or ``nil`` if the unit is inaccessible.
      :rtype: :class:`Region`

      .. code-block:: lua
         :caption: Example

         local Broodwar = BWAPI.Broodwar
         local myUnits = Broodwar:self():getUnits()
         for u in myUnits:iterator() do
           if u:isFlying() and u:isUnderAttack() then -- implies exists and isCompleted
             local r = u:getRegion()
             if r then
               u:move(r:getClosestInaccessibleRegion()) -- Retreat to inaccessible region
             end
           end
         end

      .. note::
         If this function returns a successful state, then the following functions will also return a successful state: :meth:`exists`

   .. method:: getLeft() -> left

      Retrieves the X coordinate of the unit's left boundary, measured in pixels from the left side of the map.

      :return: An integer representing the position of the left side of the unit.
      :rtype: number

      .. seealso::
         :meth:`getTop`, :meth:`getRight`, :meth:`getBottom`

   .. method:: getTop() -> top

      Retrieves the Y coordinate of the unit's top boundary, measured in pixels from the top of the map.

      :return: An integer representing the position of the top side of the unit.
      :rtype: number

      .. seealso::
         :meth:`getLeft`, :meth:`getRight`, :meth:`getBottom`

   .. method:: getRight() -> right

      Retrieves the X coordinate of the unit's right boundary, measured in pixels from the left side of the map.

      :return: An integer representing the position of the right side of the unit.
      :rtype: number

      .. seealso::
         :meth:`getLeft`, :meth:`getTop`, :meth:`getBottom`

   .. method:: getBottom() -> bottom

      Retrieves the Y coordinate of the unit's bottom boundary, measured in pixels from the top of the map.

      :return: An integer representing the position of the bottom side of the unit.
      :rtype: number

      .. seealso::
         :meth:`getLeft`, :meth:`getTop`, :meth:`getRight`

   .. method:: getHitPoints() -> hp

      Retrieves the unit's current Hit Points (HP) as seen in the game.

      :return: An integer representing the amount of hit points a unit currently has.
      :rtype: number

      .. note::
         In Starcraft, a unit usually dies when its HP reaches 0. It is possible however, to have abnormal HP values in the Use Map Settings game type and as the result of a hack over Battle.net. Such values include units that have 0 HP (can't be killed conventionally) or even negative HP (death in one hit).

      .. seealso::
         :meth:`UnitType.maxHitPoints`, :meth:`getShields`, :meth:`getInitialHitPoints`

   .. method:: getShields() -> shields

      Retrieves the unit's current Shield Points (Shields) as seen in the game.

      :return: An integer representing the amount of shield points a unit currently has.
      :rtype: number

      .. seealso::
         :meth:`UnitType.maxShields`, :meth:`getHitPoints`

   .. method:: getEnergy() -> energy

      Retrieves the unit's current Energy Points (Energy) as seen in the game.

      :return: An integer representing the amount of energy points a unit currently has.
      :rtype: number

      .. note::
         Energy is required in order for units to use abilities.

      .. seealso::
         :meth:`UnitType.maxEnergy`

   .. method:: getResources() -> resources

      Retrieves the resource amount from a resource container, such as a Mineral Field and Vespene Geyser.

      If the unit is inaccessible, then the last known resource amount is returned.

      :return: An integer representing the last known amount of resources remaining in this resource.
      :rtype: number

      .. seealso::
         :meth:`getInitialResources`

   .. method:: getResourceGroup() -> int

      Retrieves a grouping index from a resource container.

      Other resource containers of the same value are considered part of one expansion location (group of resources that are close together).

      .. note::
         This grouping method is explicitly determined by Starcraft itself and is used only by the internal AI.

      :return: An integer with an identifier between 0 and 250 that determine which resources are grouped together to form an expansion.

   .. method:: getDistance(target) -> distance

      Retrieves the distance between this unit and a target.

      .. note::
         Distance is calculated from the edge of this unit, using Starcraft's own distance algorithm.

      :param target: Can be either a :class:`Position` or :class:`Unit`. If it is a unit, then it will calculate the distance to the edge of the target unit.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`
      :return: An integer representation of the number of pixels between this unit and the ``target``.
      :rtype: number

   .. method:: hasPath(target) -> hasPath

      Using data provided by Starcraft, checks if there is a path available from this unit to the given target.

      .. note::
         This function only takes into account the terrain data, and does not include buildings when determining if a path is available. However, the complexity of this function is constant ( O(1) ), and no extensive calculations are necessary.

      .. note::
         If the current unit is an air unit, then this function will always return true.

      :param target: Can be either a :class:`Position` or :class:`Unit`. A Position or a Unit that is used to determine if this unit has a path to the target.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`
      :return: ``true`` if there is a path between this unit and the target or ``false`` if the target is on a different piece of land than this one (such as an island).
      :rtype: boolean

   .. method:: getLastCommandFrame() -> frameNum

      Retrieves the frame number that sent the last successful command.

      .. note::
         This value is comparable to :meth:`Game.getFrameCount`.

      :return: The frame number that sent the last successfully processed command to BWAPI.
      :rtype: number

      .. seealso::
         :meth:`Game.getFrameCount`, :meth:`getLastCommand`

   .. method:: getLastCommand() -> command

      Retrieves the last successful command that was sent to BWAPI.

      :return: The last command that was processed.
      :rtype: :class:`UnitCommand`

      .. seealso::
         :meth:`getLastCommandFrame`

   .. method:: getLastAttackingPlayer() -> player

      Retrieves the Player that last attacked this unit.

      :return: Player that last attacked this unit or ``nil`` if this unit was not attacked.
      :rtype: :class:`Player`

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: exists()

   .. method:: getInitialType() -> type

      Retrieves the initial type of the unit.

      This is the type that the unit starts as in the beginning of the game. This is used to access the types of static neutral units such as mineral fields when they are not visible.

      :return: :class:`UnitType` of this unit as it was when it was created or :attr:`~BWAPI.UnitTypes.Unknown` if this unit was not a static neutral unit in the beginning of the game.
      :rtype: :class:`UnitType`

   .. method:: getInitialPosition() -> position

      Retrieves the initial position of this unit.

      This is the position that the unit starts at in the beginning of the game. This is used to access the positions of static neutral units such as mineral fields when they are not visible.

      :return: Position indicating the unit's initial position when it was created or :attr:`~BWAPI.Positions.Unknown` if this unit was not a static neutral unit in the beginning of the game.
      :rtype: :class:`Position`

   .. method:: getInitialTilePosition() -> tilePosition

      Retrieves the initial build tile position of this unit.

      This is the tile position that the unit starts at in the beginning of the game. This is used to access the tile positions of static neutral units such as mineral fields when they are not visible. The build tile position corresponds to the upper left corner of the unit.

      :return: TilePosition indicating the unit's initial tile position when it was created or :attr:`~BWAPI.TilePositions.Unknown` if this unit was not a static neutral unit in the beginning of the game.
      :rtype: :class:`TilePosition`

   .. method:: getInitialHitPoints() -> hp

      Retrieves the amount of hit points that this unit started off with at the beginning of the game.

      The unit must be neutral.

      :return: Number of hit points that this unit started with or ``0`` if this unit was not a neutral unit at the beginning of the game.
      :rtype: number

      .. note::
         It is possible for the unit's initial hit points to differ from the maximum hit points.

      .. seealso::
         :meth:`Game.getStaticNeutralUnits`

   .. method:: getInitialResources() -> resources

      Retrieves the amount of resources contained in the unit at the beginning of the game.

      The unit must be a neutral resource container.

      :return: Amount of resources that this unit started with or ``0`` if this unit was not a neutral unit at the beginning of the game, or if this unit does not contain resources. It is possible that the unit simply contains 0 resources.

      .. seealso::
         :meth:`Game.getStaticNeutralUnits`

   .. method:: getKillCount() -> kills

      Retrieves the number of units that this unit has killed in total.

      .. note::
         The maximum amount of recorded kills per unit is 255.

      :return: integer indicating this unit's kill count.
      :rtype: number

   .. method:: getAcidSporeCount() -> count

      Retrieves the number of acid spores that this unit is inflicted with.

      :return: Number of acid spores on this unit.
      :rtype: number

   .. method:: getInterceptorCount() -> count

      Retrieves the number of interceptors that this unit manages.

      This function is only for the :attr:`Carrier <BWAPI.UnitTypes.Protoss_Carrier>`.

      :return: Number of interceptors in this unit.
      :rtype: number

   .. method:: getScarabCount() -> count

      Retrieves the number of scarabs that this unit has for use.

      This function is only for the :attr:`Reaver <BWAPI.UnitTypes.Protoss_Reaver>`.

      :return: Number of scarabs this unit has ready.
      :rtype: number

   .. method:: getSpiderMineCount() -> count

      Retrieves the amount of :attr:`Spider Mines <BWAPI.UnitTypes.Terran_Vulture_Spider_Mine>` this unit has available.

      This function is only for the :attr:`Vulture <BWAPI.UnitTypes.Terran_Vulture`.

      :return: Number of spider mines available for placement.
      :rtype: number

   .. method:: getGroundWeaponCooldown() -> framesLeft

      Retrieves the unit's ground weapon cooldown.

      This value decreases every frame, until it reaches 0. When the value is 0, this indicates that the unit is capable of using its ground weapon, otherwise it must wait until it reaches 0.

      .. note::
         This value will vary, because Starcraft adds an additional random value between (-1) and (+2) to the unit's weapon cooldown.

      :return: Number of frames needed for the unit's ground weapon to become available again.
      :rtype: number

   .. method:: getAirWeaponCooldown() -> framesLeft

      Retrieves the unit's air weapon cooldown.

      This value decreases every frame, until it reaches 0. When the value is 0, this indicates that the unit is capable of using its air weapon, otherwise it must wait until it reaches 0.

      .. note::
         This value will vary, because Starcraft adds an additional random value between (-1) and (+2) to the unit's weapon cooldown.

      :return: Number of frames needed for the unit's air weapon to become available again.
      :rtype: number

   .. method:: getSpellCooldown() -> framesLeft

      Retrieves the unit's ability cooldown.

      This value decreases every frame, until it reaches 0. When the value is 0, this indicates that the unit is capable of using one of its special abilities, otherwise it must wait until it reaches 0.

      .. note::
         This value will vary, because Starcraft adds an additional random value between (-1) and (+2) to the unit's ability cooldown.

      :return: Number of frames needed for the unit's abilities to become available again.
      :rtype: number

   .. method:: getDefenseMatrixPoints() -> hp

      Retrieves the amount of hit points remaining on the :attr:`Defensive Matrix <BWAPI.TechTypes.Defensive_Matrix>` created by a :attr:`Science Vessel <BWAPI.UnitTypes.Terran_Science_Vessel>`.

      The :attr:`Defensive Matrix <BWAPI.TechTypes.Defensive_Matrix>` ability starts with 250 hit points when it is used.

      :return: Number of hit points remaining on this unit's :attr:`Defensive Matrix <BWAPI.TechTypes.Defensive_Matrix>`.
      :rtype: number

      .. seealso::
         :meth:`getDefenseMatrixTimer`, :meth:`isDefenseMatrixed`

   .. method:: getDefenseMatrixTimer() -> framesLeft

      Retrieves the time, in frames, that the :attr:`Defensive Matrix <BWAPI.TechTypes.Defensive_Matrix>` will remain active on the current unit.

      :return: Number of frames remaining until the effect is removed.
      :rtype: number

      .. seealso::
         :meth:`getDefenseMatrixPoints`, :meth:`isDefenseMatrixed`

   .. method:: getEnsnareTimer() -> framesLeft

      Retrieves the time, in frames, that :attr:`Ensnare <BWAPI.TechTypes.Ensnare>` will remain active on the current unit.

      :return: Number of frames remaining until the effect is removed.
      :rtype: number

      .. seealso::
         :meth:`isEnsnared`

   .. method:: getIrradiateTimer() -> framesLeft

      Retrieves the time, in frames, that :attr:`Irradiate <BWAPI.TechTypes.Irradiate>` will remain active on the current unit.

      :return: Number of frames remaining until the effect is removed.
      :rtype: number

      .. seealso::
         :meth:`isIrradiated`

   .. method:: getLockdownTimer() -> framesLeft

      Retrieves the time, in frames, that :attr:`Lockdown <BWAPI.TechTypes.Lockdown>` will remain active on the current unit.

      :return: Number of frames remaining until the effect is removed.
      :rtype: number

      .. seealso::
         :meth:`isLockdowned`

   .. method:: getMaelstromTimer() -> framesLeft

      Retrieves the time, in frames, that :attr:`Maelstrom <BWAPI.TechTypes.Maelstrom>` will remain active on the current unit.

      :return: Number of frames remaining until the effect is removed.
      :rtype: number

      .. seealso::
         :meth:`isMaelstrommed`

   .. method:: getOrderTimer() -> framesLeft

      Retrieves an internal timer used for the primary order.

      Its use is specific to the order type that is currently assigned to the unit.

      :return: A value used as a timer for the primary order.
      :rtype: number

      .. seealso::
         :meth:`getOrder`

   .. method:: getPlagueTimer() -> framesLeft

      Retrieves the time, in frames, that :attr:`Plague <BWAPI.TechTypes.Plague>` will remain active on the current unit.

      :return: Number of frames remaining until the effect is removed.
      :rtype: number

      .. seealso::
         :meth:`isPlagued`

   .. method:: getRemoveTimer() -> framesLeft

      Retrieves the time, in frames, until this temporary unit is destroyed or removed. Once this value reaches 0, the unit is destroyed.

      This is used to determine the remaining time for the following units that were created by abilities:

      - :attr:`Hallucination <BWAPI.TechTypes.Hallucination>`
      - :attr:`Broodling <BWAPI.TechTypes.Spawn_Broodlings>`
      - :attr:`Dark Swarm <BWAPI.TechTypes.Dark_Swarm>`
      - :attr:`Disruption Web <BWAPI.TechTypes.Disruption_Web>`
      - :attr:`Scanner Sweep <BWAPI.TechTypes.Scanner_Sweep>`

      :return: Number of frames remaining until the unit is destroyed or removed.
      :rtype: number

   .. method:: getStasisTimer() -> framesLeft

      Retrieves the time, in frames, that :attr:`Stasis Field <BWAPI.TechTypes.Stasis_Field>` will remain active on the current unit.

      :return: Number of frames remaining until the effect is removed.
      :rtype: number

      .. seealso::
         :meth:`isStasised`

   .. method:: getStimTimer() -> framesLeft

      Retrieves the time, in frames, that :attr:`Stim Packs <BWAPI.TechTypes.Stim_Packs>` will remain active on the current unit.

      :return: Number of frames remaining until the effect is removed.
      :rtype: number

      .. seealso::
         :meth:`isStimmed`

   .. method:: getBuildType() -> type

      Retrieves the building type that a worker (:attr:`SCV <BWAPI.UnitTypes.Terran_SCV>`, :attr:`Probe <BWAPI.UnitTypes.Protoss_Probe>`, :attr:`Drone <BWAPI.UnitTypes.Zerg_Drone>`) is about to construct.

      If the unit is morphing or is an incomplete structure, then this returns the :class:`UnitType` that it will become when it has completed morphing/constructing.

      :return: :class:`UnitType` indicating the type that a worker (:attr:`SCV <BWAPI.UnitTypes.Terran_SCV>`, :attr:`Probe <BWAPI.UnitTypes.Protoss_Probe>`, :attr:`Drone <BWAPI.UnitTypes.Zerg_Drone>`) is about to construct, or the type that an incomplete unit will be when completed.
      :rtype: :class:`UnitType`

   .. method:: getTrainingQueue() -> queue

      Retrieves the list of units queued up to be trained.

      .. important::
         See :ref:`the differences between the C++ and Lua implementations of this function <differences-unit-train>` for more information

      :return: An array-like table containing all of the :class:`UnitType`'s that are in this building's training queue.
      :rtype: table of the format {1 = :class:`UnitType`, 2 = :class:`UnitType`, ...}

      .. seealso::
         :meth:`train`, :meth:`cancelTrain`, :meth:`isTraining`

   .. method:: getTech() -> tech

      Retrieves the technology that this unit is currently researching.

      :return: :class:`TechType` indicating the technology being researched by this unit, or :attr:`~BWAPI.TechTypes.None` if this unit is not researching anything.
      :rtype: :class:`TechType`

      .. seealso::
         :meth:`research`, :meth:`cancelResearch`, :meth:`isResearching`, :meth:`getRemainingResearchTime`

   .. method:: getUpgrade() -> upgrade

      Retrieves the upgrade that this unit is currently upgrading.

      :return: :class:`UpgradeType` indicating the upgrade in progress by this unit, or :attr:`~BWAPI.UpgradeTypes.None` if this unit is not upgrading anything.
      :rtype: :class:`UpgradeType`

      .. seealso::
         :meth:`upgrade`, :meth:`cancelUpgrade`, :meth:`isUpgrading`, :meth:`getRemainingUpgradeTime`

   .. method:: getRemainingBuildTime() -> framesLeft

      Retrieves the remaining build time for a unit or structure that is being trained or constructed.

      :return: Number of frames remaining until the unit's completion.
      :rtype: number

   .. method:: getRemainingResearchTime() -> framesLeft

      Retrieves the amount of time until the unit is done researching its currently assigned :class:`TechType`.

      :return: The remaining research time, in frames, for the current technology being researched by this unit, or ``0`` if the unit is not researching anything.
      :rtype: number

      .. seealso::
         :meth:`research`, :meth:`cancelResearch`, :meth:`isResearching`, :meth:`getTech`

   .. method:: getRemainingTrainTime() -> framesLeft

      Retrieves the remaining time, in frames, of the unit that is currently being trained.

      .. note::
         If the unit is a :attr:`Hatchery <BWAPI.UnitTypes.Zerg_Hatchery>`, :attr:`Lair <BWAPI.UnitTypes.Zerg_Lair>`, or :attr:`Hive <BWAPI.UnitTypes.Zerg_Hive>`, this retrieves the amount of time until the next larva spawns.

      :return: Number of frames remaining until the current training unit becomes completed, or the number of frames remaining until the next larva spawns, or ``0`` if the unit is not training or has three larvae.
      :rtype: number

      .. seealso::
         :meth:`train`, :meth:`getTrainingQueue`

   .. method:: getRemainingUpgradeTime() -> framesLeft

      Retrieves the amount of time until the unit is done upgrading its current upgrade.

      :return: The remaining upgrade time, in frames, for the current upgrade, or ``0`` if the unit is not upgrading anything.
      :rtype: number

      .. seealso::
         :meth:`upgrade`, :meth:`cancelUpgrade`, :meth:`isUpgrading`, :meth:`getUpgrade`

   .. method:: getBuildUnit() -> unit

      Retrieves the corresponding paired unit for :attr:`SCVs <BWAPI.UnitTypes.Terran_SCV>` and :attr:`~BWAPI.Races.Terran` structures.

      For example, if this unit is a :attr:`Factory <BWAPI.UnitTypes.Terran_Factory>` under construction, this function will return the :attr:`SCV <BWAPI.UnitTypes.Terran_SCV>` that is constructing it. If this unit is a :attr:`SCV <BWAPI.UnitTypes.Terran_SCV>`, then it will return the structure it is currently constructing.

      :return: Paired build unit that is either constructing this unit or being constructed by this unit, or ``nil`` if there is no unit constructing this one or this unit is not constructing another unit.
      :rtype: :class:`Unit`

   .. method:: getTarget() -> unit

      Generally returns the appropriate target unit after issuing an order that accepts a target unit (i.e. attack, repair, gather, etc.).

      To get a target that has been acquired automatically without issuing an order, use :meth:`getOrderTarget`.

      :return: Unit that is currently being targeted by this unit.
      :rtype: :class:`Unit`

      .. seealso::
         :meth:`getOrderTarget`

   .. method:: getTargetPosition() -> position

      Retrieves the target position the unit is moving to, provided a valid path to the target position exists.

      :return: Target position of a movement action.
      :rtype: :class:`Position`

   .. method:: getOrder() -> order

      Retrieves the primary :class:`Order` that the unit is assigned.

      Primary orders are distinct actions such as :attr:`~BWAPI.Orders.AttackUnit` and :attr:`~BWAPI.Orders.PlayerGuard`.

      :return: The primary :class:`Order` that the unit is executing.
      :rtype: :class:`Order`

   .. method:: getSecondaryOrder() -> order

      Retrieves the secondary :class:`Order` that the unit is assigned.

      Secondary orders are run in the background as a sub-order. An example would be :attr:`~BWAPI.Orders.TrainFighter`, because a :attr:`Carrier <BWAPI.UnitTypes.Protoss_Carrier>` can move and train fighters at the same time.

      :return: The secondary :class:`Order` that the unit is executing.
      :rtype: :class:`Order`

   .. method:: getOrderTarget() -> unit

      Retrieves the unit's primary order target.

      This is usually set when the low level unit AI acquires a new target automatically. For example if an enemy :attr:`Probe <BWAPI.UnitTypes.Protoss_Probe>` comes in range of your :attr:`Marine <BWAPI.UnitTypes.Terran_Marine>`, the :attr:`Marine <BWAPI.UnitTypes.Terran_Marine>` will start attacking it, and getOrderTarget will be set in this case, but not getTarget.

      :return: The Unit that this unit is currently targetting.
      :rtype: :class:`Unit`

      .. seealso::
         :meth:`getTarget`, :meth:`getOrder`

   .. method:: getOrderTargetPosition() -> position

      Retrieves the target position for the unit's order.

      For example, when :attr:`~BWAPI.Orders.Move` is assigned, :meth:`getTargetPosition` returns the end of the unit's path, but this returns the location that the unit is trying to move to.

      :return: Position that this unit is currently targetting.
      :rtype: :class:`Position`

      .. seealso::
         :meth:`getTargetPosition`, :meth:`getOrder`

   .. method:: getRallyPosition() -> position

      Retrieves the position the structure is rallying units to once they are completed.

      :return: Position that a completed unit coming from this structure will travel to, or :attr:`~BWAPI.Positions.None` if this building does not produce units.
      :rtype: :class:`Position`

      .. note::
         If :meth:`getRallyUnit` is valid, then this value is ignored.

      .. seealso::
         :meth:`setRallyPoint`, :meth:`getRallyUnit`

   .. method:: getRallyUnit() -> unit

      Retrieves the unit the structure is rallying units to once they are completed.

      Units will then follow the targetted unit.

      :return: Unit that a completed unit coming from this structure will travel to, or ``nil`` if the structure is not rallied to a unit or it does not produce units.
      :rtype: :class:`Unit`

      .. note::
         A rallied unit takes precedence over a rallied position. That is if the return value is valid (non-nil), then :meth:`getRallyPosition` is ignored.

      .. seealso::
         :meth:`setRallyPoint`, :meth:`getRallyPosition`

   .. method:: getAddon() -> unit

      Retrieves the add-on that is attached to this unit.

      :return: Unit interface that represents the add-on that is attached to this unit, or ``nil`` if this unit does not have an add-on.
      :rtype: :class:`Unit`

   .. method:: getNydusExit() -> unit

      Retrieves the :attr:`Nydus Canal <BWAPI.UnitTypes.Zerg_Nydus_Canal>` that is attached to this one.

      Every :attr:`Nydus Canal <BWAPI.UnitTypes.Zerg_Nydus_Canal>` can place a "Nydus Exit" which, when connected, can be travelled through by :attr:`~BWAPI.Races.Zerg` units.

      :return: Unit interface representing the :attr:`Nydus Canal <BWAPI.UnitTypes.Zerg_Nydus_Canal>` connected to this one, or ``nil`` if the unit is not a :attr:`Nydus Canal <BWAPI.UnitTypes.Zerg_Nydus_Canal>`, is not owned, or has not placed a Nydus Exit.
      :rtype: :class:`Unit`

   .. method:: getPowerUp() -> unit

      Retrieves the power-up that the worker unit is holding.

      Power-ups are special units such as the :attr:`Flag <BWAPI.UnitTypes.Powerup_Flag>` in the :attr:`Capture The Flag <BWAPI.GameTypes.Capture_The_Flag>` game type, which can be picked up by worker units.

      :return: The Unit interface object that represents the power-up, or ``nil`` if the unit is not carrying anything.
      :rtype: :class:`Unit`

      .. code-block:: lua
         :caption: Example

         local myUnits = BWAPI.Broodwar:self():getUnits()
         for u in myUnits:iterator() do
           -- If we are carrying a flag
           if u:getPowerUp() u:getPowerUp():getType() == BWAPI.UnitTypes.Powerup_Flag then
             local pred = function(x)
               return BWAPI.Filter.IsFlagBeacon(x) and BWAPI.Filter.IsOwned(x)
             end
             -- return it to our flag beacon to score
             u:move( u:getClosestUnit(pred) )
           end
         end

      .. note::
         If your bot is strictly melee/1v1, then this method is not necessary.

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: ``getType():isWorker()``, :meth:`isCompleted()`

   .. method:: getTransport() -> unit

      Retrieves the transport unit (:attr:`Dropship <BWAPI.UnitTypes.Terran_Dropship>`, :attr:`Shuttle <BWAPI.UnitTypes.Protoss_Shuttle>`, :attr:`Overlord <BWAPI.UnitTypes.Zerg_Overlord>` ) or :attr:`Bunker <BWAPI.UnitTypes.Terran_Bunker>` unit that has this unit loaded inside of it.

      :return: The unit that this unit is loaded inside of, or ``nil`` if the unit is not loaded inside of a unit.
      :rtype: :class:`Unit`

   .. method:: getLoadedUnits() -> units

      Retrieves the set of units that are contained within this :attr:`Bunker <BWAPI.UnitTypes.Terran_Bunker>`, :attr:`Dropship <BWAPI.UnitTypes.Terran_Dropship>`, :attr:`Shuttle <BWAPI.UnitTypes.Protoss_Shuttle>`, or :attr:`Overlord <BWAPI.UnitTypes.Zerg_Overlord>`.

      :return: A :class:`Unitset` containing all of the units that are loaded inside of the current unit.
      :rtype: :class:`Unitset`

   .. method:: getSpaceRemaining() -> spaceRemaining

      Retrieves the remaining unit-space available for :attr:`Bunkers <BWAPI.UnitTypes.Terran_Bunker>` and transports (:attr:`Dropships <BWAPI.UnitTypes.Terran_Dropship>`, :attr:`Shuttles <BWAPI.UnitTypes.Protoss_Shuttle>`, :attr:`Overlords <BWAPI.UnitTypes.Zerg_Overlord>` ).

      :return: The number of spots available to transport a unit.
      :rtype: number

      .. seealso::
         :meth:`getLoadedUnits`

   .. method:: getCarrier() -> unit

      Retrieves the parent :attr:`Carrier <BWAPI.UnitTypes.Protoss_Carrier>` that owns this :attr:`Interceptor <BWAPI.UnitTypes.Protoss_Interceptor>`.

      :return: The parent :attr:`Carrier <BWAPI.UnitTypes.Protoss_Carrier>` unit that has ownership of this one, or ``nil`` if the current unit is not an :attr:`Interceptor <BWAPI.UnitTypes.Protoss_Interceptor>`.
      :rtype: :class:`Unit`

   .. method:: getInterceptors() -> units

      Retrieves the set of :attr:`Interceptors <BWAPI.UnitTypes.Protoss_Interceptor>` controlled by this unit.

      This is intended for :attr:`Carriers <BWAPI.UnitTypes.Protoss_Carrier>`.

      :return: :class:`Unitset` containing :attr:`Interceptor <BWAPI.UnitTypes.Protoss_Interceptor>` units owned by this one.
      :rtype: :class:`Unitset`

   .. method:: getHatchery() -> unit

      Retrieves the parent :attr:`Hatchery <BWAPI.UnitTypes.Zerg_Hatchery>`, :attr:`Lair <BWAPI.UnitTypes.Zerg_Lair>`, or :attr:`Hive <BWAPI.UnitTypes.Zerg_Hive>` that owns this particular unit.

      This is intended for :attr:`Larvae <BWAPI.UnitTypes.Zerg_Larva>`.

      :return: Hatchery unit that has ownership of this larva, or ``nil`` if the current unit is not a :attr:`Larva <BWAPI.UnitTypes.Zerg_Larva>` or has no parent.
      :rtype: :class:`Unit`

   .. method:: getLarva() -> units

      Retrieves the set of :attr:`Larvae <BWAPI.UnitTypes.Zerg_Larva>` that were spawned by this unit.

      Only :attr:`Hatcheries <BWAPI.UnitTypes.Zerg_Hatchery>`, :attr:`Lairs <BWAPI.UnitTypes.Zerg_Lair>`, and :attr:`Hives <BWAPI.UnitTypes.Zerg_Hive>` are capable of spawning :attr:`Larvae <BWAPI.UnitTypes.Zerg_Larva>`. This is like clicking the "Select Larva" button and getting the selection of :attr:`Larvae <BWAPI.UnitTypes.Zerg_Larva>`.

      :return: :class:`Unitset` containing :attr:`Larva <BWAPI.UnitTypes.Zerg_Larva>` units owned by this unit. The set will be empty if there are none.
      :rtype: :class:`Unitset`

   .. method:: getUnitsInRadius(radius, [pred]) -> units

      Retrieves the set of all units in a given radius of the current unit.

      Takes into account this unit's dimensions. Can optionally specify a filter to include only specific units (such as only ground units, etc.)

      :param number radius: The radius, in pixels, to search for units.
      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise **or** a :class:`UnitFilter` instance. Defaults to ``nil``, which means no filter.
      :return: A :class:`Unitset` containing the set of units that match the given criteria.
      :rtype: :class:`Unitset`

      .. code-block:: lua
         :caption: Example usage

         -- Get main building closest to start location.
         local isResourceDepotPred = function(x) return BWAPI.Filter.IsResourceDepot(x) end
         local main = BWAPI.Broodwar:getClosestUnit( BWAPI.Broodwar:self():getStartLocation(), isResourceDepotPred )
         if main then -- check if main is valid
           -- Get sets of resources and workers
           local myResources = main:getUnitsInRadius(1024, BWAPI.Filter.IsMineralField);
           if not myResources:empty() then -- check if we have resources nearby
             local workerPred = function(x)
               BWAPI.Filter.IsWorker(x) and BWAPI.Filter.IsIdle(x) and BWAPI.Filter.IsOwned(x)
             end
             local myWorkers = main:getUnitsInRadius(512, workerPred)
             local myResourcesArray = myResources:asTable()
             for worker in myWorkers:iterator() do
               local randomResource = myResourcesArray[math.random(#myResourcesArray)]
               worker:gather(randomResource)
             end
           end
         end

      .. seealso::
         :ref:`UnitFilter differences between C++ and Lua <differences-unitfilter>`, :meth:`getClosestUnit`, :meth:`getUnitsInWeaponRange`, :meth:`Game.getUnitsInRadius`, :meth:`Game.getUnitsInRectangle`

   .. method:: getUnitsInWeaponRange(weapon, [pred]) -> units

      Obtains the set of units within weapon range of this unit.

      :param BWAPI.WeaponType weapon: The weapon type to use as a filter for distance and units that can be hit by it.
      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise **or** a :class:`UnitFilter` instance. If omitted, no additional filter is used.
      :return: The set of units within weapon range of this unit.
      :rtype: :class:`Unitset`

      .. seealso::
         :ref:`UnitFilter differences between C++ and Lua <differences-unitfilter>`, :meth:`getUnitsInRadius`, :meth:`getClosestUnit`, :meth:`Game.getUnitsInRadius`, :meth:`Game.getUnitsInRectangle`

   .. method:: getClosestUnit([pred], [radius = 999999]) -> unit

      Retrieves the closest unit to this one.

      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise **or** a :class:`UnitFilter` instance. If ``pred`` is omitted or ``nil``, then the closest unit owned by any player will be returned.
      :param number radius: (optional) The maximum radius to check for the closest unit. For performance reasons, a developer can limit the radius that is checked. If omitted, then the entire map is checked.
      :return: The closest unit that matches the predicate, or ``nil`` if no matching unit is found.
      :rtype: :class:`Unit`

      .. seealso::
         :ref:`UnitFilter differences between C++ and Lua <differences-unitfilter>`, :meth:`Unit.getUnitsInRadius`, :meth:`Game.getUnitsInRadius`, :meth:`Game.getUnitsInRectangle`

   .. method:: hasNuke() -> bool

      Checks if the current unit is housing a :attr:`Nuke <BWAPI.UnitTypes.Terran_Nuclear_Missile>`.

      This is only available for :attr:`Nuclear Silos <BWAPI.UnitTypes.Terran_Nuclear_Silo>`.

      :return: ``true`` if this unit has a :attr:`Nuke <BWAPI.UnitTypes.Terran_Nuclear_Missile>` ready, and ``false`` if there is no :attr:`Nuke <BWAPI.UnitTypes.Terran_Nuclear_Missile>`.
      :rtype: boolean

   .. method:: isAccelerating() -> bool

      Checks if the current unit is accelerating.

      :return: ``true`` if this unit is accelerating, and ``false`` otherwise
      :rtype: boolean

   .. method:: isAttacking() -> bool

      Checks if this unit is currently attacking something.

      :return: ``true`` if this unit is attacking another unit, and ``false`` if it is not.
      :rtype: boolean

   .. method:: isAttackFrame() -> bool

      Checks if this unit is currently playing an attack animation.

      Issuing commands while this returns ``true`` may interrupt the unit's next attack sequence.

      :return: ``true`` if this unit is currently running an attack frame, and ``false`` if interrupting the unit is feasible.
      :rtype: boolean

      .. note::
         This function is only available to some unit types, specifically those that play special animations when they attack.

   .. method:: isBeingConstructed() -> bool

      Checks if the current unit is being constructed.

      This is mostly applicable to Terran structures which require an SCV to be constructing a structure.

      :return: ``true`` if this is either a Protoss structure, Zerg structure, or Terran structure being constructed by an attached SCV, and ``false`` if this is either completed, not a structure, or has no SCV constructing it.
      :rtype: boolean

      .. seealso::
         :meth:`build`, :meth:`cancelConstruction`, :meth:`haltConstruction`, :meth:`isConstructing`

   .. method:: isBeingGathered() -> bool

      Checks this :attr:`Mineral Field <BWAPI.UnitTypes.Resource_Mineral_Field>` or :attr:`Refinery <BWAPI.UnitTypes.Terran_Refinery>` is currently being gathered from.

      :return: ``true`` if this unit is a resource container and being harvested by a worker, and ``false`` otherwise
      :rtype: boolean

   .. method:: isBeingHealed() -> bool

      Checks if this unit is currently being healed by a :attr:`Medic <UnitTypes.Terran_Medic>` or repaired by a :attr:`SCV <BWAPI.UnitTypes.Terran_SCV>`.

      :return: ``true`` if this unit is being healed, and ``false`` otherwise.
      :rtype: boolean

   .. method:: isBlind() -> bool

      Checks if this unit is currently blinded by a :attr:`Medic <UnitTypes.Terran_Medic>` 's :attr:`Optical Flare <BWAPI.TechTypes.Optical_Flare>` ability.

      Blinded units have reduced sight range and cannot detect other units.

      :return: ``true`` if this unit is blind, and ``false`` otherwise
      :rtype: boolean

   .. method:: isBraking() -> bool

      Checks if the current unit is slowing down to come to a stop.

      :return: ``true`` if this unit is breaking, ``false`` if it has stopped or is still moving at full speed.
      :rtype: boolean

   .. method:: isBurrowed() -> bool

      Checks if the current unit is burrowed, either using the :attr:`Burrow <BWAPI.TechTypes.Burrowing>` ability, or is an armed :attr:`Spider Mine <BWAPI.UnitTypes.Terran_Vulture_Spider_Mine>`.

      :return: ``true`` if this unit is burrowed, and ``false`` otherwise
      :rtype: boolean

      .. seealso::
         :meth:`burrow`, :meth:`unburrow`

   .. method:: isCarryingGas() -> bool

      Checks if this worker unit is carrying some vespene gas.

      :return: ``true`` if this is a worker unit carrying vespene gas, and ``false`` if it is either not a worker, or not carrying gas.
      :rtype: boolean

      .. code-block:: lua
         :caption: Example

         local myUnits = BWAPI.Broodwar:self():getUnits()
         for u in myUnits:iterator() do
           if u:isIdle() and (u:isCarryingGas() or u:isCarryingMinerals()) then
             u:returnCargo()
           end
         end

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: :meth:`isCompleted()`, ``getType():isWorker()``

      .. seealso::
         :meth:`returnCargo`, :meth:`isGatheringGas`, :meth:`isCarryingMinerals`

   .. method:: isCarryingMinerals() -> bool

      Checks if this worker unit is carrying some minerals.

      :return: ``true`` if this is a worker unit carrying minerals, and ``false`` if it is either not a worker, or not carrying minerals.
      :rtype: boolean

      .. code-block:: lua
         :caption: Example

         local myUnits = BWAPI.Broodwar:self():getUnits()
         for u in myUnits:iterator() do
           if u:isIdle() and (u:isCarryingGas() or u:isCarryingMinerals()) then
             u:returnCargo()
           end
         end

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: :meth:`isCompleted()`, ``getType():isWorker()``

      .. seealso::
         :meth:`returnCargo`, :meth:`isGatheringMinerals`, :meth:`isCarryingGas`

   .. method:: isCloaked() -> bool

      Checks if this unit is currently :attr:`cloaked <BWAPI.TechTypes.Cloaking_Field>`.

      :return: ``true`` if this unit is cloaked, and ``false`` if it is visible.
      :rtype: boolean

      .. seealso::
         :meth:`cloak`, :meth:`decloak`

   .. method:: isCompleted() -> bool

      Checks if this unit has finished being constructed, trained, morphed, or warped in, and can now receive orders.

      :return: ``true`` if this unit is completed, and ``false`` if it is under construction or inaccessible.
      :rtype: boolean

   .. method:: isConstructing() -> bool

      Checks if a unit is either constructing something or moving to construct something.

      :return: ``true`` when a unit has been issued an order to build a structure and is moving to the build location, or is currently constructing something.
      :rtype: boolean

      .. seealso::
         :meth:`isBeingConstructed`, :meth:`build`, :meth:`cancelConstruction`, :meth:`haltConstruction`

   .. method:: isDefenseMatrixed() -> bool

      Checks if this unit has the :attr:`Defensive Matrix <BWAPI.TechTypes.Defensive_Matrix>` effect.

      :return: ``true`` if the :attr:`Defensive Matrix <BWAPI.TechTypes.Defensive_Matrix>` ability was used on this unit, and ``false`` otherwise.
      :rtype: boolean

   .. method:: isDetected() -> bool

      Checks if this unit is visible or revealed by a detector unit.

      If this is ``false`` and isVisible is ``true``, then the unit is only partially visible and requires a detector in order to be targetted.

      :return: ``true`` if this unit is detected, and ``false`` if it needs a detector unit nearby in order to see it.
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: :meth:`isVisible`

   .. method:: isEnsnared() -> bool

      Checks if the :attr:`Queen <BWAPI.UnitTypes.Zerg_Queen>` ability :attr:`Ensnare <BWAPI.TechTypes.Ensnare>` has been used on this unit.

      :return: ``true`` if the unit is ensnared, and ``false`` if it is not
      :rtype: boolean

   .. method:: isFlying() -> bool

      This macro function checks if this unit is in the air.

      That is, the unit is either a flyer or a flying building.

      :return: ``true`` if this unit is in the air, and ``false`` if it is on the ground
      :rtype: boolean

      .. seealso::
         :meth:`UnitType.isFlyer`, :meth:`isLifted`

   .. method:: isFollowing() -> bool

      Checks if this unit is following another unit.

      When a unit is following another unit, it simply moves where the other unit does, and does not attack enemies when it is following.

      :return: ``true`` if this unit is following another unit, and ``false`` if it is not
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: :meth:`isCompleted`

      .. seealso::
         :meth:`follow`, :meth:`getTarget`

   .. method:: isGatheringGas() -> bool

      Checks if this unit is currently gathering gas.

      That is, the unit is either moving to a refinery, waiting to enter a refinery, harvesting from the refinery, or returning gas to a resource depot.

      :return: ``true`` if this unit is harvesting gas, and ``false`` if it is not
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: :meth:`isCompleted`, ``getType():isWorker()``

      .. seealso::
         :meth:`isCarryingGas`

   .. method:: isGatheringMinerals() -> bool

      Checks if this unit is currently harvesting minerals.

      That is, the unit is either moving to a :attr:`Mineral Field <BWAPI.UnitTypes.Resource_Mineral_Field>`, waiting to mine, mining minerals, or returning minerals to a resource depot.

      :return: ``true`` if this unit is gathering minerals, and ``false`` if it is not
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: :meth:`isCompleted`, ``getType():isWorker()``

      .. seealso::
         :meth:`isCarryingMinerals`

   .. method:: isHallucination() -> bool

      Checks if this unit is a hallucination.

      Hallucinations are created by the :attr:`High Templar <BWAPI.UnitTypes.Protoss_High_Templar>` using the :attr:`Hallucination <BWAPI.TechTypes.Hallucination>` ability. Enemy hallucinations are unknown if :attr:`BWAPI.Flag.CompleteMapInformation` is disabled. Hallucinations have a time limit until they are destroyed (see :meth:`getRemoveTimer`).

      :return: ``true`` if the unit is a hallucination and ``false`` otherwise.
      :rtype: boolean

      .. seealso::
         :meth:`getRemoveTimer`

   .. method:: isHoldingPosition() -> bool

      Checks if the unit is currently holding position.

      A unit that is holding position will attack other units, but will not chase after them.

      :return: ``true`` if this unit is holding position, and ``false`` if it is not.
      :rtype: boolean

      .. seealso::
         :meth:`holdPosition`

   .. method:: isIdle() -> bool

      Checks if this unit is running an idle order.

      This function is particularly useful when checking for units that aren't doing any tasks that you assigned.

      A unit is considered idle if it is **not** doing any of the following:

      * Training
      * Constructing
      * Morphing
      * Researching
      * Upgrading

      In **addition** to running one of the following orders:

      * :attr:`~BWAPI.Orders.PlayerGuard`: Player unit idle.
      * :attr:`~BWAPI.Orders.Guard`: Generic unit idle.
      * :attr:`~BWAPI.Orders.Stop`
      * :attr:`~BWAPI.Orders.PickupIdle`
      * :attr:`~BWAPI.Orders.Nothing`: Structure/generic idle.
      * :attr:`~BWAPI.Orders.Medic`: Medic idle.
      * :attr:`~BWAPI.Orders.Carrier`: Carrier idle.
      * :attr:`~BWAPI.Orders.Reaver`: Reaver idle.
      * :attr:`~BWAPI.Orders.Critter`: Critter idle.
      * :attr:`~BWAPI.Orders.Neutral`: Neutral unit idle.
      * :attr:`~BWAPI.Orders.TowerGuard`: Turret structure idle.
      * :attr:`~BWAPI.Orders.Burrowed`: Burrowed unit idle.
      * :attr:`~BWAPI.Orders.NukeTrain`
      * :attr:`~BWAPI.Orders.Larva`: Larva idle.

      .. code-block:: lua
         :caption: Example

         local myUnits = BWAPI.Broodwar:self():getUnits()
         for u in myUnits:iterator() do
           -- Order idle worker to gather from closest mineral field
           if u:getType():isWorker() and u:isIdle() then
             u:gather( u:getClosestUnit( BWAPI.Filter.IsMineralField ) )
           end
         end

      :return: ``true`` if this unit is idle, and ``false`` if this unit is performing any action, such as moving or attacking
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: :meth:`isCompleted`

      .. seealso::
         :meth:`stop`

   .. method:: isInterruptible() -> bool

      Checks if the unit can be interrupted.

      :return: ``true`` if this unit can be interrupted, or ``false`` if this unit is uninterruptable
      :rtype: boolean

   .. method:: isInvincible() -> bool

      Checks the invincibility state for this unit.

      :return: ``true`` if this unit is currently invulnerable, and ``false`` if it is vulnerable
      :rtype: boolean

   .. method:: isInWeaponRange(target) -> bool

      Checks if the target unit can immediately be attacked by this unit in the current frame.

      :param BWAPI.Unit target: The target unit to use in this check.
      :return: ``true`` if ``target`` is within weapon range of this unit's appropriate weapon, and ``false`` if ``target`` is invalid, inaccessible, too close, too far, or this unit does not have a weapon that can attack ``target``.
      :rtype: boolean

   .. method:: isIrradiated() -> bool

      Checks if this unit is irradiated by a :attr:`Science Vessel <BWAPI.UnitTypes.Terran_Science_Vessel>` 's :attr:`Irradiate <BWAPI.TechTypes.Irradiate>` ability.

      .. code-block:: lua
         :caption: Example

         local myUnits = BWAPI.Broodwar:self():getUnits()
         for u in myUnits:iterator() do
           if u:isIrradiated() and u:getIrradiateTimer > 50 and BWAPI.Broodwar:self():hasResearched(BWAPI.TechTypes.Restoration) then
             local medicPred = function(x)
               return BWAPI.Filter.GetType(x) == BWAPI.UnitTypes.Terran_Medic and BWAPI.Filter.Energy(x) >= BWAPI.TechTypes.Restoration:energyCost()
             end
             local medic = u:getClosestUnit( medicPred )
             if medic then
               medic:useTech(BWAPI.TechTypes.Restoration, u)
             end
           end
         end

      :return: ``true`` if this unit is irradiated, and ``false`` otherwise
      :rtype: boolean

      .. seealso::
         :meth:`getIrradiateTimer`

   .. method:: isLifted() -> bool

      Checks if this unit is a :attr:`~BWAPI.Races.Terran` building and lifted off the ground.

      This function generally implies ``getType():isBuilding()`` and ``isCompleted()`` both return true.

      :return: ``true`` if this unit is a :attr:`~BWAPI.Races.Terran` structure lifted off the ground.
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: :meth:`isCompleted`, ``getType():isFlyingBuilding()``

      .. seealso::
         :meth:`isFlying`

   .. method:: isLoaded() -> bool

      Checks if this unit is currently loaded into another unit such as a Transport (:attr:`Dropship <BWAPI.UnitTypes.Terran_Dropship>`, :attr:`Shuttle <BWAPI.UnitTypes.Protoss_Shuttle>`, :attr:`Overlord <BWAPI.UnitTypes.Zerg_Overlord>` ).

      :return: ``true`` if this unit is loaded in another one, and ``false`` otherwise
      :rtype: boolean

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: :meth:`isCompleted`

      .. seealso::
         :meth:`load`, :meth:`unload`, :meth:`unloadAll`

   .. method:: isLockedDown() -> bool

      Checks if this unit is currently :attr:`locked <BWAPI.TechTypes.Lockdown>` by a :attr:`Ghost <BWAPI.UnitTypes.Terran_Ghost>`.

      :return: ``true`` if this unit is locked down, and ``false`` otherwise
      :rtype: boolean

      .. seealso::
         :meth:`getLockdownTimer`

   .. method:: isMaelstrommed() -> bool

      Checks if this unit has been :attr:`maelstrommed <BWAPI.TechTypes.Maelstrom>` by a :attr:`Dark Archon <BWAPI.UnitTypes.Protoss_Dark_Archon>`.

      :return: ``true`` if this unit is maelstrommed, and ``false`` otherwise
      :rtype: boolean

      .. seealso::
         :meth:`getMaelstromTimer`

   .. method:: isMorphing() -> bool

      Finds out if the current unit is morphing or not.

      :attr:`~BWAPI.Races.Zerg` units and structures often have the ability to morph into different types of units. This function allows you to identify when this process is occurring.

      :return: ``true`` if the unit is currently morphing, and ``false`` if the unit is not morphing.
      :rtype: boolean

      .. seealso::
         :meth:`morph`, :meth:`cancelMorph`, :meth:`getBuildType`, :meth:`getRemainingBuildTime`

   .. method:: isMoving() -> bool

      Checks if this unit is currently moving.

      :return: ``true`` if this unit is moving, and ``false`` if it is not
      :rtype: boolean

      .. seealso::
         :meth:`stop`

   .. method:: isParasited() -> bool

      Checks if this unit has been parasited by some other player.

      :return: ``true`` if this unit is inflicted with :attr:`Parasite <BWAPI.TechTypes.Parasite>`, and ``false`` if it is clean
      :rtype: boolean

   .. method:: isPatrolling() -> bool

      Checks if this unit is patrolling between two positions.

      :return: ``true`` if this unit is patrolling and ``false`` if it is not
      :rtype: boolean

      .. seealso::
         :meth:`patrol`

   .. method:: isPlagued() -> bool

      Checks if this unit has been been :attr:`plagued <BWAPI.TechTypes.Plague>` by a :attr:`Defiler <BWAPI.UnitTypes.Zerg_Defiler>`.

      :return: ``true`` if this unit is inflicted with :attr:`Plague <BWAPI.TechTypes.Plague>` and is taking damage, and ``false`` if it is clean
      :rtype: boolean

      .. seealso::
         :meth:`getPlagueTimer`

   .. method:: isRepairing() -> bool

      Checks if this unit is repairing or moving to :attr:`repair <BWAPI.Orders.Repair>` another unit.

      This is only applicable to :attr:`SCVs <BWAPI.UnitTypes.Terran_SCV>`.

      :return: ``true`` if this unit is currently repairing or moving to :attr:`repair <BWAPI.Orders.Repair>` another unit, and ``false`` if it is not
      :rtype: boolean

   .. method:: isResearching() -> bool

      Checks if this unit is a structure that is currently researching a technology.

      See :mod:`~BWAPI.TechTypes` for a complete list of technologies in Broodwar.

      :return: ``true`` if this structure is researching a technology, ``false`` otherwise
      :rtype: boolean

      .. seealso::
         :meth:`research`, :meth:`cancelResearch`, :meth:`getTech`, :meth:`getRemainingResearchTime`

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: :meth:`exists`, :meth:`isCompleted`, ``getType():isBuilding()``

   .. method:: isSelected() -> bool

      Checks if this unit has been selected in the user interface.

      This function is only available if the flag :attr:`BWAPI.Flag.UserInput` is enabled.

      :return: ``true`` if this unit is currently selected, and ``false`` if this unit is not selected
      :rtype: boolean

      .. seealso::
         :meth:`Game.getSelectedUnits`

   .. method:: isSieged() -> bool

      Checks if this unit is currently :attr:`sieged <BWAPI.TechTypes.Tank_Siege_Mode>`.

      This is only applicable to :attr:`Siege Tanks <BWAPI.UnitTypes.Terran_Siege_Tank_Tank_Mode>`.

      :return: ``true`` if the unit is in siege mode, and ``false`` if it is either not in siege mode or not a :attr:`Siege Tank <BWAPI.UnitTypes.Terran_Siege_Tank_Tank_Mode>`
      :rtype: boolean

      .. seealso::
         :meth:`siege`, :meth:`unsiege`

   .. method:: isStartingAttack() -> bool

      Checks if the unit is starting to attack.

      :return: ``true`` if this unit is starting an attack.
      :rtype: boolean

      .. seealso::
         :meth:`attack`, :meth:`getGroundWeaponCooldown`, :meth:`getAirWeaponCooldown`

   .. method:: isStasised() -> bool

      Checks if this unit is inflicted with :attr:`Stasis Field <BWAPI.TechTypes.Stasis_Field>` by an :attr:`Arbiter <BWAPI.UnitTypes.Protoss_Arbiter>`.

      :return: ``true`` if this unit is locked in a :attr:`Stasis Field <BWAPI.TechTypes.Stasis_Field>` and is unable to move, and ``false`` if it is free.
      :rtype: boolean

      .. note::
         This function does not necessarily imply that the unit is invincible, since there is a feature in the :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game type that allows stasised units to be vulnerable.

      .. seealso::
         :meth:`getStasisTimer`

   .. method:: isStimmed() -> bool

      Checks if this unit is currently under the influence of a :attr:`Stim Packs <BWAPI.TechTypes.Stim_Packs>`.

      :return: ``true`` if this unit has used a stim pack, ``false`` otherwise
      :rtype: boolean

      .. seealso::
         :meth:`getStimTimer`

   .. method:: isStuck() -> bool

      Checks if this unit is currently trying to resolve a collision by randomly moving around.

      :return: ``true`` if this unit is currently stuck and trying to resolve a collision, and ``false`` if this unit is free
      :rtype: boolean

   .. method:: isTraining() -> bool

      Checks if this unit is training a new unit.

      For example, a :attr:`Barracks <BWAPI.UnitTypes.Terran_Barracks>` training a :attr:`Marine <BWAPI.UnitTypes.Terran_Marine>`.

      .. note::
         It is possible for a unit to remain in the training queue with no progress. In that case, this function will return ``false`` because of supply or unit count limitations.

      :return: ``true`` if this unit is currently training another unit, and ``false`` otherwise.

      .. seealso::
         :meth:`train`, :meth:`getTrainingQueue`, :meth:`cancelTrain`, :meth:`getRemainingTrainTime`

   .. method:: isUnderAttack() -> bool

      Checks if the current unit is being attacked.

      Has a small delay before this returns ``false`` again when the unit is no longer being attacked.

      :return: ``true`` if this unit has been attacked within the past few frames, and ``false`` if it has not
      :rtype: boolean

   .. method:: isUnderDarkSwarm() -> bool

      Checks if this unit is under the cover of a :attr:`Dark Swarm <BWAPI.TechTypes.Dark_Swarm>`.

      :return: ``true`` if this unit is protected by a :attr:`Dark Swarm <BWAPI.TechTypes.Dark_Swarm>`, and ``false`` if it is not
      :rtype: boolean

   .. method:: isUnderDisruptionWeb() -> bool

      Checks if this unit is currently being affected by a :attr:`Disruption Web <BWAPI.TechTypes.Disruption_Web>`.

      :return: ``true`` if this unit is under the effects of :attr:`Disruption Web <BWAPI.TechTypes.Disruption_Web>`.
      :rtype: boolean

   .. method:: isUnderStorm() -> bool

      Checks if this unit is currently taking damage from a :attr:`Psionic Storm <BWAPI.TechTypes.Psionic_Storm>`.

      :return: ``true`` if this unit is losing hit points from a :attr:`Psionic Storm <BWAPI.TechTypes.Psionic_Storm>`, and ``false`` otherwise.
      :rtype: boolean

   .. method:: isPowered() -> bool

      Checks if this unit has power.

      Most structures are powered by default, but :attr:`~BWAPI.Races.Protoss` structures require a :attr:`Pylon <BWAPI.UnitTypes.Protoss_Pylon>` to be powered and functional.

      :return: ``true`` if this unit has power or is inaccessible, and ``false`` if this unit is unpowered.
      :rtype: boolean

   .. method:: isUpgrading() -> bool

      Checks if this unit is a structure that is currently upgrading an upgrade.

      See :mod:`BWAPI.UpgradeTypes` for a full list of upgrades in Broodwar.

      :return: ``true`` if this structure is upgrading, ``false`` otherwise
      :rtype: boolean

      .. seealso::
         :meth:`upgrade`, :meth:`cancelUpgrade`, :meth:`getUpgrade`, :meth:`getRemainingUpgradeTime`

      .. note::
         If this function returns a successful state, then the following function calls will also return a successful state: :meth:`exists`, :meth:`isCompleted`, ``getType():isBuilding()``

   .. method:: isVisible([player]) -> bool

      Checks if this unit is visible.

      :param BWAPI.Player player: (optional) The player to check visibility for. If this parameter is omitted, then the BWAPI player obtained from :meth:`Game.self` will be used.
      :return: ``true`` if this unit is visible to the specified ``player``, and ``false`` if it is not.
      :rtype: boolean

      .. note::
         If the :attr:`BWAPI.Flag.CompleteMapInformation` flag is enabled, existing units hidden by the fog of war will be accessible, but :meth:`isVisible` will still return false.

      .. seealso::
         :meth:`exists`

   .. method:: isTargetable() -> bool

      Performs some cheap checks to attempt to quickly detect whether the unit is unable to be targetted as the target unit of an unspecified command.

      :return: ``true`` if BWAPI was unable to determine whether the unit can be a target, and ``false`` if an error occurred and the unit can not be a target.
      :rtype: boolean

      .. seealso::
         :meth:`Game.getLastError`, :meth:`canTargetUnit`

   .. method:: issueCommand(command) -> wasIssued

      This function issues a command to the unit, however it is used for interfacing only, and is recommended to use one of the more specific command functions when writing an AI.

      :param BWAPI.UnitCommand command: The command to be issued
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :mod:`BWAPI.UnitCommandTypes`, :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`

   .. method:: attack(target, [shiftQueueCommand = false]) -> wasIssued

      Orders the unit(s) to attack move to the specified position or attack the specified unit.

      :param target: Can be either a :class:`Position` or :class:`Unit`. If a Position is used, the unit will perform an Attack Move command.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`
      :param bool shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :returns: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

         A :attr:`Medic <UnitTypes.Terran_Medic>` will use Heal Move instead of attack.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canAttack`

   .. method:: build(type, [target]) -> wasIssued

      Orders the worker unit(s) to construct a structure at a target position.

      :param BWAPI.UnitType type: The :class:`UnitType` to build.
      :param BWAPI.TilePosition target: A TilePosition to specify the build location, specifically the upper-left corner of the location. If the target is not specified, then the function call will be redirected to the train command.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. note::
         You must have sufficient resources and meet the necessary requirements in order to build a structure.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`train`, :meth:`cancelConstruction`, :meth:`canBuild`

   .. method:: buildAddon(type) -> wasIssued

      Orders the :attr:`~BWAPI.Races.Terran` structure(s) to construct an add-on.

      :param BWAPI.UnitType type: The add-on :class:`UnitType` to construct.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. note::
         You must have sufficient resources and meet the necessary requirements in order to build a structure.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`build`, :meth:`cancelAddon`, :meth:`canBuildAddon`

   .. method:: train([type]) -> wasIssued

      Orders the unit(s) to add a :class:`UnitType` to its training queue, or morphs into the :class:`UnitType` if it is :attr:`~BWAPI.Races.Zerg`.

      :param BWAPI.UnitType type: The :class:`UnitType` to train. If the type is not specified, then this function will have no effect unless this unit is a Carrier or Reaver, in which case the type will default to :attr:`Interceptors <BWAPI.UnitTypes.Protoss_Interceptor>` or :attr:`Scarabs <BWAPI.UnitTypes.Protoss_Scarab>`.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. note::
         You must have sufficient resources, supply, and meet the necessary requirements in order to train a unit.

      .. note::
         This command is also used for training :attr:`Interceptors <BWAPI.UnitTypes.Protoss_Interceptor>` and :attr:`Scarabs <BWAPI.UnitTypes.Protoss_Scarab>`.

      .. note::
         If you call this using a :attr:`Hatchery <BWAPI.UnitTypes.Zerg_Hatchery>`, :attr:`Lair <BWAPI.UnitTypes.Zerg_Lair>`, or :attr:`Hive <BWAPI.UnitTypes.Zerg_Hive>`, then it will automatically pass the command to one of its :attr:`Larvae <BWAPI.UnitTypes.Zerg_Larva>`.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`build`, :meth:`morph`, :meth:`cancelTrain`, :meth:`isTraining`, :meth:`canTrain`

   .. method:: morph(type) -> wasIssued

      Orders the unit(s) to morph into a different :class:`UnitType`.

      :param BWAPI.UnitType type: The :class:`UnitType` to morph into.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`build`, :meth:`morph`, :meth:`canMorph`

   .. method:: research(tech) -> wasIssued

      Orders the unit to research the given tech type.

      :param BWAPI.TechType tech: The :class:`TechType` to research.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`cancelResearch`, :meth:`isResearching`, :meth:`getRemainingResearchTime`, :meth:`getTech`, :meth:`canResearch`

   .. method:: upgrade(upgrade) -> wasIssued

      Orders the unit to upgrade the given upgrade type.

      :param BWAPI.UpgradeType upgrade: The :class:`UpgradeType` to upgrade.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`cancelUpgrade`, :meth:`isUpgrading`, :meth:`getRemainingUpgradeTime`, :meth:`getUpgrade`, :meth:`canUpgrade`

   .. method:: setRallyPoint(target) -> wasIssued

      Orders the unit to set its rally position to the specified position or unit.

      :param target: Can be either a :class:`Position` or :class:`Unit`. The target position or target unit that this structure will rally to.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`getRallyPosition`, :meth:`getRallyUnit`, :meth:`canSetRallyPoint`, :meth:`canSetRallyPosition`, :meth:`canSetRallyUnit`

   .. method:: move(target, [shiftQueueCommand = false]) -> wasIssued

      Orders the unit to move from its current position to the specified position.

      :param BWAPI.Position target: The target position to move to.
      :param boolean shiftQueueCommand: (optional) If this value is ``true``, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`isMoving`, :meth:`canMove`

   .. method:: patrol(target, [shiftQueueCommand = false]) -> wasIssued

      Orders the unit to patrol between its current position and the specified position.

      While patrolling, units will attack and chase enemy units that they encounter, and then return to its patrol route. :attr:`Medics <BWAPI.UnitTypes.Terran_Medic>` will automatically heal units and then return to their patrol route.

      :param BWAPI.Position target: The target position to patrol to.
      :param boolean shiftQueueCommand: (optional) If this value is ``true``, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`isPatrolling`, :meth:`canPatrol`

   .. method:: holdPosition([shiftQueueCommand = false]) -> wasIssued

      Orders the unit to hold its position.

      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`canHoldPosition`, :meth:`isHoldingPosition`

   .. method:: stop([shiftQueueCommand = false]) -> wasIssued

      Orders the unit to stop.

      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`canStop`, :meth:`isIdle`

   .. method:: follow(target, [shiftQueueCommand = false]) -> wasIssued

      Orders the unit to follow the specified unit.

      Units that are following other units will not perform any other actions such as attacking. They will ignore attackers.

      :param BWAPI.Unit target: The target unit to start following.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`isFollowing`, :meth:`canFollow`, :meth:`getOrderTarget`

   .. method:: gather(target, [shiftQueueCommand = false]) -> wasIssued

      Orders the unit to gather the specified unit (must be mineral or refinery type).

      :param BWAPI.Unit target: The target unit to gather from.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`isGatheringGas`, :meth:`isGatheringMinerals`, :meth:`canGather`

   .. method:: returnCargo([shiftQueueCommand = false]) -> wasIssued

      Orders the unit to return its cargo to a nearby resource depot such as a Command Center.

      Only workers that are carrying minerals or gas can be ordered to return cargo.

      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`isCarryingGas`, :meth:`isCarryingMinerals`, :meth:`canReturnCargo`

   .. method:: repair(target, [shiftQueueCommand = false]) -> wasIssued

      Orders the unit to repair the specified unit.

      Only Terran SCVs can be ordered to repair, and the target must be a mechanical :attr:`~BWAPI.Races.Terran` unit or building.

      :param BWAPI.Unit target: The target unit to repair.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`isRepairing`, :meth:`canRepair`

   .. method:: burrow() -> wasIssued

      Orders the unit to burrow.

      Either the unit must be a :attr:`Lurker <BWAPI.UnitTypes.Zerg_Lurker>`, or the unit must be a :attr:`~BWAPI.Races.Zerg` ground unit that is capable of :attr:`Burrowing <BWAPI.TechTypes.Burrowing>`, and :attr:`Burrow <BWAPI.TechTypes.Burrowing>` technology must be researched.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`unburrow`, :meth:`isBurrowed`, :meth:`canBurrow`

   .. method:: unburrow() -> wasIssued

      Orders a burrowed unit to unburrow.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`burrow`, :meth:`isBurrowed`, :meth:`canUnburrow`

   .. method:: cloak() -> wasIssued

      Orders the unit to cloak.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`decloak`, :meth:`isCloaked`, :meth:`canCloak`

   .. method:: decloak() -> wasIssued

      Orders a cloaked unit to decloak.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`cloak`, :meth:`isCloaked`, :meth:`canDecloak`

   .. method:: siege() -> wasIssued

      Orders the unit to siege.

      Only works for :attr:`Siege Tanks <BWAPI.UnitTypes.Terran_Siege_Tank_Tank_Mode>`.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`unsiege`, :meth:`isSieged`, :meth:`canSiege`

   .. method:: unsiege() -> wasIssued

      Orders the unit to unsiege.

      Only works for sieged :attr:`Siege Tanks <BWAPI.UnitTypes.Terran_Siege_Tank_Tank_Mode>`.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`siege`, :meth:`isSieged`, :meth:`canUnsiege`

   .. method:: lift() -> wasIssued

      Orders the unit to lift.

      Only works for liftable :attr:`~BWAPI.Races.Terran` structures.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`land`, :meth:`isLifted`, :meth:`canLift`

   .. method:: land(target) -> wasIssued

      Orders the unit to land.

      Only works for :attr:`~BWAPI.Races.Terran` structures that are currently lifted.

      :param BWAPI.TilePosition target``: The tile position to land this structure at.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`lift`, :meth:`isLifted`, :meth:`canLand`

   .. method:: load(target, [shiftQueueCommand = false]) -> wasIssued

      Orders the unit to load the target unit.

      Only works if this unit is a Transport (:attr:`Dropship <BWAPI.UnitTypes.Terran_Dropship>`, :attr:`Shuttle <BWAPI.UnitTypes.Protoss_Shuttle>`, :attr:`Overlord <BWAPI.UnitTypes.Zerg_Overlord>` ) or :attr:`Bunker <BWAPI.UnitTypes.Terran_Bunker>` type.

      :param BWAPI.Unit target: The target unit to load into this Transport (:attr:`Dropship <BWAPI.UnitTypes.Terran_Dropship>`, :attr:`Shuttle <BWAPI.UnitTypes.Protoss_Shuttle>`, :attr:`Overlord <BWAPI.UnitTypes.Zerg_Overlord>` ) or :attr:`Bunker <BWAPI.UnitTypes.Terran_Bunker>`.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`unload`, :meth:`unloadAll`, :meth:`getLoadedUnits`, :meth:`isLoaded`

   .. method:: unload(target) -> wasIssued

      Orders the unit to unload the target unit.

      Only works for Transports (:attr:`Dropships <BWAPI.UnitTypes.Terran_Dropship>`, :attr:`Shuttles <BWAPI.UnitTypes.Protoss_Shuttle>`, :attr:`Overlords <BWAPI.UnitTypes.Zerg_Overlord>` ) and :attr:`Bunkers <BWAPI.UnitTypes.Terran_Bunker>`.

      :param BWAPI.Unit target: Unloads the target unit from this Transport(:attr:`Dropship <BWAPI.UnitTypes.Terran_Dropship>`, :attr:`Shuttle <BWAPI.UnitTypes.Protoss_Shuttle>`, :attr:`Overlord <BWAPI.UnitTypes.Zerg_Overlord>` ) or :attr:`Bunker <BWAPI.UnitTypes.Terran_Bunker>`.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`load`, :meth:`unloadAll`, :meth:`getLoadedUnits`, :meth:`isLoaded`, :meth:`canUnload`, :meth:`canUnloadAtPosition`

   .. method:: unloadAll([shiftQueueCommand = false]) -> wasIssued

      Orders the unit to unload all loaded units at the unit's current position.

      Only works for Transports (:attr:`Dropships <BWAPI.UnitTypes.Terran_Dropship>`, :attr:`Shuttles <BWAPI.UnitTypes.Protoss_Shuttle>`, :attr:`Overlords <BWAPI.UnitTypes.Zerg_Overlord>` ) and :attr:`Bunkers <BWAPI.UnitTypes.Terran_Bunker>`.

      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`load`, :meth:`unload`, :meth:`getLoadedUnits`, :meth:`isLoaded`, :meth:`canUnloadAll`, :meth:`canUnloadAtPosition`

   .. method:: unloadAll(target, [shiftQueueCommand = false]) -> wasIssued

      Orders the unit to unload all loaded units at the specified location.

      Only works for Transports (:attr:`Dropships <BWAPI.UnitTypes.Terran_Dropship>`, :attr:`Shuttles <BWAPI.UnitTypes.Protoss_Shuttle>`, :attr:`Overlords <BWAPI.UnitTypes.Zerg_Overlord>` )

      .. important::
         Not applicable to :attr:`Bunkers <BWAPI.UnitTypes.Terran_Bunker>`.

      :param BWAPI.Position target: The target position to unload the units at.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`load`, :meth:`unload`, :meth:`getLoadedUnits`, :meth:`isLoaded`, :meth:`canUnloadAllPosition`, :meth:`canUnloadAtPosition`

   .. method:: rightClick(target, [shiftQueueCommand = false]) -> wasIssued

      Works like the right click in the GUI.

      :param target: Can be either a :class:`Position` or :class:`Unit`. The target position or target unit to right click.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`canRightClick`, :meth:`canRightClickPosition`, :meth:`canRightClickUnit`

   .. method:: haltConstruction() -> wasIssued

      Orders a :attr:`SCV <BWAPI.UnitTypes.Terran_SCV>` to stop constructing a structure.

      This leaves the structure in an incomplete state until it is either cancelled, razed, or completed by another :attr:`SCV <BWAPI.UnitTypes.Terran_SCV>`.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`isConstructing`, :meth:`canHaltConstruction`

   .. method:: cancelConstruction() -> wasIssued

      Orders this unit to cancel and refund itself from begin constructed.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`isBeingConstructed`, :meth:`build`, :meth:`canCancelConstruction`

   .. method:: cancelAddon() -> wasIssued

      Orders this unit to cancel and refund an add-on that is being constructed.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`canCancelAddon`, :meth:`buildAddon`

   .. method:: cancelTrain([slot = -2]) -> wasIssued

      Orders the unit to remove the specified unit from its training queue.

      .. important::
         The first ``slot`` has an index of ``1``. See :ref:`the differences between the C++ and Lua implementations of this function <differences-unit-train>` for more information.

      :param number slot: (optional) Identifies the slot that will be cancelled. If the specified value is at least 1, then the unit in the corresponding slot from the list provided by :meth:`getTrainingQueue` will be cancelled. If the slot is either omitted or ``-2``, then the last slot is cancelled.
      :returns: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         Zero and negative values other than ``-2`` have no effect.

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`train`, :meth:`cancelTrain`, :meth:`isTraining`, :meth:`getTrainingQueue`, :meth:`canCancelTrain`, :meth:`canCancelTrainSlot`

   .. method:: cancelMorph() -> wasIssued

      Orders this unit to cancel and refund a unit that is morphing.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`morph`, :meth:`isMorphing`, :meth:`canCancelMorph`

   .. method:: cancelResearch() -> wasIssued

      Orders this unit to cancel and refund a research that is in progress.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`research`, :meth:`isResearching`, :meth:`getTech`, :meth:`canCancelResearch`

   .. method:: cancelUpgrade() -> wasIssued

      Orders this unit to cancel and refund an upgrade that is in progress.

      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`upgrade`, :meth:`isUpgrading`, :meth:`getUpgrade`, :meth:`canCancelUpgrade`

   .. method:: useTech([tech], [target]) -> wasIssued

      Orders the unit to use a technology.

      :param BWAPI.TechType tech: The technology type to use.
      :param target: (optional) Can be either a :class:`Position` or :class:`Unit`. If specified, indicates the target location or unit to use the tech on. If unspecified, causes the ``tech`` to be used without a target (i.e. :attr:`Stim Packs <BWAPI.TechTypes.Stim_Packs>`).
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. seealso::
         :meth:`canUseTechWithOrWithoutTarget`, :meth:`canUseTech`, :meth:`canUseTechWithoutTarget`, :meth:`canUseTechUnit`, :meth:`canUseTechPosition`, :mod:`BWAPI.TechTypes`

   .. method:: placeCOP( target) -> bool

      Moves a :attr:`Flag Beacon <BWAPI.UnitTypes.Special_Zerg_Flag_Beacon>` to a different location.

      This is only used for :attr:`Capture The Flag <BWAPI.GameTypes.Capture_The_Flag>` or :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game types.

      :param BWAPI.TilePosition target: The target tile position to place the :attr:`Flag Beacon <BWAPI.UnitTypes.Special_Zerg_Flag_Beacon>`.
      :return: ``true`` if the command was passed to Broodwar, and ``false`` if BWAPI determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. note::
         This command is only available for the first 10 minutes of the game, as in Broodwar.

      .. seealso::
         canPlaceCOP

   .. method:: canIssueCommand(command, [checkCanUseTechPositionOnPositions = true, checkCanUseTechUnitOnUnits = true, checkCanBuildUnitType = true, checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute the given command.

      If you are calling this function repeatedly (e.g. to generate a collection of valid commands), you can avoid repeating the same kinds of checks by specifying ``false`` for some of the optional boolean arguments. Make sure that the state hasn't changed since the check was done though (eg a new frame/event, or a command issued). Also see the more specific functions.

      :param BWAPI.UnitCommand command: A :class:`UnitCommand` to check.
      :param boolean checkCanUseTechPositionOnPositions: Only used if the command type is :attr:`BWAPI.UnitCommandTypes.Use_Tech_Position`. A boolean for whether to perform cheap checks for whether the unit is unable to target any positions using the command's :class:`TechType` (i.e. regardless of what the other command parameters are). You can set this to ``false`` if you know this check has already just been performed.
      :param boolean checkCanUseTechUnitOnUnits: Only used if the command type is :attr:`BWAPI.UnitCommandTypes.Use_Tech_Unit`. A boolean for whether to perform cheap checks for whether the unit is unable to target any units using the command's :class:`TechType` (i.e. regardless of what the other command parameters are). You can set this to ``false`` if you know this check has already just been performed.
      :param boolean checkCanBuildUnitType: Only used if the command type is :attr:`BWAPI.UnitCommandTypes.Build`. A boolean for whether to perform cheap checks for whether the unit is unable to build the specified :class:`UnitType` (i.e. regardless of what the other command parameters are). You can set this to ``false`` if you know this check has already just been performed.
      :param boolean checkCanTargetUnit: Only used for command types that can target a unit. A boolean for whether to perform :meth:`canTargetUnit` as a check. You can set this to ``false`` if you know this check has already just been performed.
      :param boolean checkCanIssueCommandType: A boolean for whether to perform :meth:`Unit.canIssueCommandType` as a check. You can set this to ``false`` if you know this check has already just been performed.
      :param boolean checkCommandibility: A boolean for whether to perform :meth:`canCommand` as a check. You can set this to ``false`` if you know this check has already just been performed.
      :return: ``true`` if BWAPI determined that the command is valid, or ``false`` if an error occurred and the command is invalid
      :rtype: boolean

      .. seealso::
         :mod:`BWAPI.UnitCommandTypes`, :meth:`Game.getLastError`, :meth:`canCommand`, :meth:`Unit.canIssueCommandType`, :meth:`canTargetUnit`

   .. method:: canIssueCommandGrouped(command, [checkCanUseTechPositionOnPositions = true, checkCanUseTechUnitOnUnits = true, checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute the given command as part of a :class:`Unitset` (even if none of the units in the :class:`Unitset` are able to execute the command individually).

      The reason this function exists is because some commands are valid for an individual unit but not for those individuals as a group (e.g. buildings, critters) and some commands are only valid for a unit if it is commanded as part of a unit group, e.g.:

      1. attackMove/attackUnit for a :class:`Unitset`, some of which can't attack, e.g. :attr:`High Templar <BWAPI.UnitTypes.Protoss_High_Templar>`. This is supported simply for consistency with BW's behaviour - you could issue move command(s) individually instead.
      2. attackMove/move/patrol/rightClickPosition for air unit(s) + e.g. :attr:`Larva <BWAPI.UnitTypes.Zerg_Larva>`, as part of the air stacking technique. This is supported simply for consistency with BW's behaviour - you could issue move/patrol/rightClickPosition command(s) for them individually instead.

      .. note::
         BWAPI allows the following special cases to command a unit individually (rather than only allowing it to be commanded as part of a :class:`Unitset`). These commands are not available to a user in BW when commanding units individually, but BWAPI allows them for convenience:

         * attackMove for :attr:`Medic <UnitTypes.Terran_Medic>`, which is equivalent to Heal Move.
         * holdPosition for burrowed :attr:`Lurker <BWAPI.UnitTypes.Zerg_Lurker>`, for ambushes.
         * stop for :attr:`Larva <BWAPI.UnitTypes.Zerg_Larva>`, to move it to a different side of the :attr:`Hatchery <BWAPI.UnitTypes.Zerg_Hatchery>` / :attr:`Lair <BWAPI.UnitTypes.Zerg_Lair>` / :attr:`Hive <BWAPI.UnitTypes.Zerg_Hive>` (e.g. so that :attr:`Drones <BWAPI.UnitTypes.Zerg_Drone>` morphed later morph nearer to minerals/gas).

      .. seealso::
         :mod:`BWAPI.UnitCommandTypes`, :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`canCommandGrouped`, :meth:`Unit.canIssueCommandTypeGrouped`, :meth:`canTargetUnit`

   .. method:: canCommand() -> bool

      Performs some cheap checks to attempt to quickly detect whether the unit is unable to execute any commands (eg the unit is stasised).

      :return: ``true`` if BWAPI was unable to determine whether the unit can be commanded, or ``false`` if an error occurred and the unit can not be commanded.
      :rtype: boolean

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`

   .. method:: canCommandGrouped([checkCommandibility = true]) -> bool

      Performs some cheap checks to attempt to quickly detect whether the unit is unable to execute any commands as part of a :class:`Unitset` (eg buildings, critters).

      :return: ``true`` if BWAPI was unable to determine whether the unit can be commanded grouped, or ``false`` if an error occurred and the unit can not be commanded grouped.
      :rtype: boolean

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`Unit.canIssueCommand`

   .. method:: canIssueCommandType(commandType, [checkCommandibility = true]) -> bool

      Performs some cheap checks to attempt to quickly detect whether the unit is unable to execute the given command type (i.e. regardless of what other possible command parameters could be).

      :param BWAPI.UnitCommandType commandType: A :class:`UnitCommandType`.
      :param boolean checkCommandibility: A boolean for whether to perform :meth:`canCommand` as a check. You can set this to ``false`` if you know this check has already just been performed.
      :return: ``true`` if BWAPI was unable to determine whether the command type is invalid, or ``false`` if an error occurred and the command type is invalid.
      :rtype: boolean

      .. seealso::
         :mod:`BWAPI.UnitCommandTypes`, :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`

   .. method:: canIssueCommandTypeGrouped(commandType, [checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Performs some cheap checks to attempt to quickly detect whether the unit is unable to execute the given command type (i.e.

      regardless of what other possible command parameters could be) as part of a :class:`Unitset`.

      :param BWAPI.UnitCommandType commandType: A :class:`UnitCommandType`.
      :param boolean checkCommandibilityGrouped: A boolean for whether to perform :meth:`canCommandGrouped` as a check. You can set this to ``false`` if you know this check has already just been performed.
      :param boolean checkCommandibility: A boolean for whether to perform :meth:`canCommand` as a check. You can set this to ``false`` if you know this check has already just been performed.
      :return: ``true`` if BWAPI was unable to determine whether the command type is invalid, or ``false`` if an error occurred and the command type is invalid.

      .. seealso::
         :mod:`BWAPI.UnitCommandTypes`, :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`

   .. method:: canTargetUnit(targetUnit, [checkCommandibility = true]) -> bool

      Performs some cheap checks to attempt to quickly detect whether the unit is unable to use the given unit as the target unit of an unspecified command.

      :param BWAPI.Unit targetUnit: A target unit for an unspecified command.
      :param boolean checkCommandibility: A boolean for whether to perform :meth:`canCommand` as a check. You can set this to ``false`` if you know this check has already just been performed.
      :return: ``true`` if BWAPI was unable to determine whether the unit can target the given unit, or ``false`` if an error occurred and the unit can not target the given unit.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`isTargetable`

   .. method:: canAttack([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute an attack command to attack-move or attack a unit.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`attack`, :meth:`canAttackMove`, :meth:`canAttackUnit`

   .. method:: canAttack(target, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute an attack command to attack-move or attack a (non-null) unit.

      :param target: Can be either a :class:`Position` or :class:`Unit`.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`attack`, :meth:`canAttackMove`, :meth:`canAttackUnit`

   .. method:: canAttackGrouped([checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute an attack command to attack-move or attack a unit, as part of a :class:`Unitset`.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canAttack`

   .. method:: canAttackGrouped(target, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute an attack command to attack-move or attack a (non-null) unit, as part of a :class:`Unitset`.

      :param target: Can be either a :class:`Position` or :class:`Unit`.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canAttack`

   .. method:: canAttackMove([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute an attack command to attack-move.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`attack`

   .. method:: canAttackMoveGrouped([checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute an attack command to attack-move, as part of a :class:`Unitset`.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canAttackMove`

   .. method:: canAttackUnit([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute an attack command to attack a unit.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`attack`

   .. method:: canAttackUnit(targetUnit, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute an attack command to attack a unit.

      :param BWAPI.Unit targetUnit:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`attack`

   .. method:: canAttackUnitGrouped([checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute an attack command to attack a unit, as part of a :class:`Unitset`.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canAttackUnit`

   .. method:: canAttackUnitGrouped(targetUnit, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute an attack command to attack a unit, as part of a :class:`Unitset`.

      :param BWAPI.Unit targetUnit:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canAttackUnit`

   .. method:: canBuild([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a build command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`build`

   .. method:: canBuild(unitType, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a build command for the given :class:`UnitType`.

      :param BWAPI.UnitType unitType:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`build`

   .. method:: canBuild(unitType, tilePos, [checkTargetUnitType = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a build command.

      :param BWAPI.UnitType unitType:
      :param BWAPI.TilePosition tilePos:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`build`

   .. method:: canBuildAddon([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a buildAddon command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`buildAddon`

   .. method:: canBuildAddon(unitType, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a buildAddon command.

      :param BWAPI.UnitType unitType:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`buildAddon`

   .. method:: canTrain([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a train command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`train`

   .. method:: canTrain(unitType, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a train command.

      :param BWAPI.UnitType unitType:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`train`

   .. method:: canMorph([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a morph command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`morph`

   .. method:: canMorph(unitType, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a morph command.

      :param BWAPI.UnitType unitType:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`morph`

   .. method:: canResearch([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a research command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`research`

   .. method:: canResearch(type, [checkCanIssueCommandType = true]) -> bool

      Checks whether the unit is able to execute a research command.

      :param BWAPI.TechType type:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`research`

   .. method:: canUpgrade([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute an upgrade command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`upgrade`

   .. method:: canUpgrade(type, [checkCanIssueCommandType = true]) -> bool

      Checks whether the unit is able to execute an upgrade command.

      :param BWAPI.UpgradeType type:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`upgrade`

   .. method:: canSetRallyPoint([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a setRallyPoint command to a position or unit.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`setRallyPoint`, :meth:`canSetRallyPosition`, :meth:`canSetRallyUnit`.

   .. method:: canSetRallyPoint(target, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a setRallyPoint command to a position or (non-null) unit.

      :param target: Can be either a :class:`Position` or :class:`Unit`.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`setRallyPoint`, :meth:`canSetRallyPosition`, :meth:`canSetRallyUnit`.

   .. method:: canSetRallyPosition([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a setRallyPoint command to a position.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`setRallyPoint`

   .. method:: canSetRallyUnit([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a setRallyPoint command to a unit.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`setRallyPoint`

   .. method:: canSetRallyUnit(targetUnit, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a setRallyPoint command to a unit.

      :param BWAPI.Unit targetUnit:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`setRallyPoint`

   .. method:: canMove([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a move command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`move`

   .. method:: canMoveGrouped([checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a move command, as part of a :class:`Unitset`.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canMove`

   .. method:: canPatrol([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a patrol command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`patrol`

   .. method:: canPatrolGrouped([checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a patrol command, as part of a :class:`Unitset`.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canPatrol`

   .. method:: canFollow([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a follow command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`follow`

   .. method:: canFollow(targetUnit, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a follow command.

      :param BWAPI.Unit targetUnit:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`follow`

   .. method:: canGather([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a gather command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`gather`

   .. method:: canGather(targetUnit, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a gather command.

      :param BWAPI.Unit targetUnit:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`gather`

   .. method:: canReturnCargo([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a returnCargo command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`returnCargo`

   .. method:: canHoldPosition([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a holdPosition command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`holdPosition`

   .. method:: canStop([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a stop command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`stop`

   .. method:: canRepair([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a repair command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`repair`

   .. method:: canRepair(targetUnit, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a repair command.

      :param BWAPI.Unit targetUnit:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`repair`

   .. method:: canBurrow([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a burrow command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`burrow`

   .. method:: canUnburrow([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute an unburrow command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`unburrow`

   .. method:: canCloak([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a cloak command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`cloak`

   .. method:: canDecloak([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a decloak command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`decloak`

   .. method:: canSiege([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a siege command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`siege`

   .. method:: canUnsiege([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute an unsiege command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`unsiege`

   .. method:: canLift([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a lift command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`lift`

   .. method:: canLand([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a land command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`land`

   .. method:: canLand(target, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a land command.

      :param BWAPI.TilePosition target:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`land`

   .. method:: canLoad(checkCommandibility = true) -> bool

      Cheap checks for whether the unit is able to execute a load command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`load`

   .. method:: canLoad(targetUnit, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a load command.

      :param BWAPI.Unit targetUnit:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`load`

   .. method:: canUnloadWithOrWithoutTarget([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute an unload command or unloadAll at current position command or unloadAll at a different position command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`unload`, :meth:`unloadAll`

   .. method:: canUnloadAtPosition(target, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute an unload command or unloadAll at current position command or unloadAll at a different position command, for a given position.

      :param BWAPI.Position target:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`unload`, :meth:`unloadAll`

   .. method:: canUnload([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute an unload command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`unload`

   .. method:: canUnload(targetUnit, [checkCanTargetUnit = true, checkPosition = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute an unload command.

      :param BWAPI.Unit targetUnit:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`unload`, :meth:`canUnloadAtPosition`

   .. method:: canUnloadAll([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute an unloadAll command for the current position.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`unloadAll`

   .. method:: canUnloadAllPosition([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute an unloadAll command for a different position.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`unloadAll`

   .. method:: canUnloadAllPosition(target, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute an unloadAll command for a different position.

      :param BWAPI.Position target:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`unloadAll`

   .. method:: canRightClick([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a rightClick command to a position or unit.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`rightClick`, :meth:`canRightClickPosition`, :meth:`canRightClickUnit`.

   .. method:: canRightClick(target, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a rightClick command to a position or (non-null) unit.

      :param target: Can be either a :class:`Position` or :class:`Unit`.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`rightClick`, :meth:`canRightClickPosition`, :meth:`canRightClickUnit`.

   .. method:: canRightClickGrouped([checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a rightClick command to a position or unit, as part of a :class:`Unitset`.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canRightClickUnit`

   .. method:: canRightClickGrouped(target, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a rightClick command to a position or (non-null) unit, as part of a :class:`Unitset`.

      :param target: Can be either a :class:`Position` or :class:`Unit`.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canRightClickUnit`

   .. method:: canRightClickPosition([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a rightClick command for a position.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`rightClick`

   .. method:: canRightClickPositionGrouped([checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a rightClick command for a position, as part of a :class:`Unitset`.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canRightClick`

   .. method:: canRightClickUnit([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a rightClick command to a unit.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`rightClick`

   .. method:: canRightClickUnit(targetUnit, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a rightClick command to a unit.

      :param BWAPI.Unit targetUnit:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`rightClick`

   .. method:: canRightClickUnitGrouped([checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a rightClick command to a unit, as part of a :class:`Unitset`.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canRightClickUnit`

   .. method:: canRightClickUnitGrouped(targetUnit, [checkCanTargetUnit = true, checkCanIssueCommandType = true, checkCommandibilityGrouped = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a rightClick command to a unit, as part of a :class:`Unitset`.

      :param BWAPI.Unit targetUnit:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommandGrouped`, :meth:`canRightClickUnit`

   .. method:: canHaltConstruction([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a haltConstruction command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`haltConstruction`

   .. method:: canCancelConstruction([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a cancelConstruction command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`cancelConstruction`

   .. method:: canCancelAddon([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a cancelAddon command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`cancelAddon`

   .. method:: canCancelTrain([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a cancelTrain command for any slot.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`cancelTrain`

   .. method:: canCancelTrainSlot([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a cancelTrain command for an unspecified slot.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`cancelTrain`

   .. method:: canCancelTrainSlot(slot, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a cancelTrain command for a specified slot.

      :param number slot:

      .. important::
         The first ``slot`` has an index of ``1``. See :meth:`cancelTrain` and :ref:`the differences between the C++ and Lua implementations of this function <differences-unit-train>` for more information.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`cancelTrain`

   .. method:: canCancelMorph([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a cancelMorph command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`cancelMorph`

   .. method:: canCancelResearch([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a cancelResearch command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`cancelResearch`

   .. method:: canCancelUpgrade([checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a cancelUpgrade command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`cancelUpgrade`

   .. method:: canUseTechWithOrWithoutTarget([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a useTech command without a target or or a useTech command with a target position or a useTech command with a target unit.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`useTech`

   .. method:: canUseTechWithOrWithoutTarget(tech, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a useTech command without a target or or a useTech command with a target position or a useTech command with a target unit, for a given :class:`TechType`.

      :param BWAPI.TechType tech:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`useTech`

   .. method:: canUseTech(tech, [target, checkCanTargetUnit = true, checkTargetsType = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a useTech command for a specified position or unit (only specify nullptr if the :class:`TechType` does not target another position/unit).

      :param BWAPI.TechType tech:
      :param target: Can be either a :class:`Position` or :class:`Unit`.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`useTech`, :meth:`canUseTechWithoutTarget`, :meth:`canUseTechUnit`, :meth:`canUseTechPosition`

   .. method:: canUseTechWithoutTarget(tech, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a useTech command without a target.

      :param BWAPI.TechType tech:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`useTech`

   .. method:: canUseTechUnit(tech, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a useTech command with an unspecified target unit.

      :param BWAPI.TechType tech:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`useTech`

   .. method:: canUseTechUnit(tech, targetUnit, [checkCanTargetUnit = true, checkTargetsUnits = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a useTech command with a target unit.

      :param BWAPI.TechType tech:
      :param BWAPI.Unit targetUnit:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`useTech`

   .. method:: canUseTechPosition(tech, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a useTech command with an unspecified target position.

      :param BWAPI.TechType tech:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`useTech`

   .. method:: canUseTechPosition(tech, target, [checkTargetsPositions = true, checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a useTech command with a target position.

      :param BWAPI.TechType tech:
      :param BWAPI.Position target:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`useTech`

   .. method:: canPlaceCOP([checkCommandibility = true]) -> bool

      Cheap checks for whether the unit is able to execute a placeCOP command.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`placeCOP`

   .. method:: canPlaceCOP(target, [checkCanIssueCommandType = true, checkCommandibility = true]) -> bool

      Checks whether the unit is able to execute a placeCOP command.

      :param BWAPI.TilePosition target:

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`, :meth:`placeCOP`

   .. include:: /_include/interface-functions.rst
