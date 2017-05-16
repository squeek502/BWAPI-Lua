Unitset
*******

.. currentmodule:: BWAPI

.. class:: Unitset

   The :class:`~BWAPI.Unitset` is a container for a set of :class:`Unit` objects.

   It is typically used for groups of units instead of having to manage each Unit individually.

   .. seealso::
      :class:`~BWAPI.Unit`

   .. rubric:: Constructors

   .. method:: Unitset()

      Default constructor.

   .. method:: Unitset(set)

      Copy constructor.

      :param BWAPI.Unitset set: The Unitset to copy.

   .. method:: Unitset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`Unit` are added to the set.

      :param table tbl: A table containing :class:`Unit` objects.

   .. rubric:: Member Functions

   .. method:: issueCommand(command) -> boolean

      This function issues a command to the unit(s), however it is used for interfacing only, and is recommended to use one of the more specific command functions when writing an AI.

      :param BWAPI.UnitCommand command: A :class:`~BWAPI.UnitCommand` containing command parameters such as the type, position, target, etc.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :mod:`BWAPI.UnitCommandTypes`, :meth:`Game.getLastError`, :meth:`Unit.canIssueCommand`

   .. method:: attack(target, [shiftQueueCommand = false]) -> boolean

      Orders the unit(s) to attack move to the specified position or attack the specified unit.

      :param target: Can be either a :class:`Position` or :class:`Unit`. A Position or a Unit to designate as the target. If a Position is used, the unit will perform an Attack Move command.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. note::
         A :attr:`Medic <BWAPI.UnitTypes.Terran_Medic>` will use Heal Move instead of attack.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.canAttack`

   .. method:: build(type, [target = TilePositions.None]) -> boolean

      Orders the worker unit(s) to construct a structure at a target position.

      :param BWAPI.UnitType type: The :class:`~BWAPI.UnitType` to build.
      :param BWAPI.TilePosition target: A :class:`TilePosition` to specify the build location, specifically the upper-left corner of the location. If the target is not specified, then the function call will be redirected to the train command.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. note::
         You must have sufficient resources and meet the necessary requirements in order to build a structure.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.train`, :meth:`Unit.cancelConstruction`, :meth:`Unit.canBuild`

   .. method:: buildAddon(type) -> boolean

      Orders the :attr:`~BWAPI.Races.Terran` structure(s) to construct an add-on.

      :param BWAPI.UnitType type: The add-on :class:`~BWAPI.UnitType` to construct.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. note::
         You must have sufficient resources and meet the necessary requirements in order to build a structure.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.build`, :meth:`Unit.cancelAddon`, :meth:`Unit.canBuildAddon`

   .. method:: train(type) -> boolean

      Orders the unit(s) to add a :class:`~BWAPI.UnitType` to its training queue, or morphs into the :class:`~BWAPI.UnitType` if it is :attr:`~BWAPI.Races.Zerg`.

      :param BWAPI.UnitType type: The :class:`~BWAPI.UnitType` to train.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. note::
         You must have sufficient resources, supply, and meet the necessary requirements in order to train a unit.

      .. note::
         This command is also used for training :attr:`Interceptors <BWAPI.UnitTypes.Protoss_Interceptor>` and :attr:`Scarabs <BWAPI.UnitTypes.Protoss_Scarab>`.

      .. note::
         If you call this using a :attr:`~BWAPI.UnitTypes.Zerg_Hatchery`, :attr:`~BWAPI.UnitTypes.Zerg_Lair`, or :attr:`~BWAPI.UnitTypes.Zerg_Hive`, then it will automatically pass the command to one of its :attr:`~BWAPI.UnitTypes.Zerg_Larva`.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.build`, :meth:`Unit.morph`, :meth:`Unit.cancelTrain`, :meth:`Unit.isTraining`, :meth:`Unit.canTrain`

   .. method:: morph(type) -> boolean

      Orders the unit(s) to morph into a different :class:`~BWAPI.UnitType`.

      :param BWAPI.UnitType type: The :class:`~BWAPI.UnitType` to morph into.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`Game.getLastError`, :meth:`Unit.build`, :meth:`Unit.morph`, :meth:`Unit.canMorph`

   .. method:: setRallyPoint(target) -> boolean

      Orders the unit to set its rally position to the specified position or unit.

      :param target: Can be either a :class:`Position` or :class:`Unit`. The target position or target unit that this structure will rally to.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`getRallyPosition`, :meth:`getRallyUnit`, :meth:`canSetRallyPoint`, :meth:`canSetRallyPosition`, :meth:`canSetRallyUnit`

   .. method:: move(target, [shiftQueueCommand = false]) -> boolean

      Orders the unit to move from its current position to the specified position.

      :param BWAPI.Position target: The target position to move to.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: patrol(target, [shiftQueueCommand = false]) -> boolean

      Orders the unit to patrol between its current position and the specified position.

      While patrolling, units will attack and chase enemy units that they encounter, and then return to its patrol route. :attr:`Medics <BWAPI.UnitTypes.Terran_Medic>` will automatically heal units and then return to their patrol route.

      :param BWAPI.Position target: The position to patrol to.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: holdPosition([shiftQueueCommand = false]) -> boolean

      Orders the unit to hold its position.

      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: stop([shiftQueueCommand = false]) -> boolean

      Orders the unit to stop.

      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: follow(target, [shiftQueueCommand = false]) -> boolean

      Orders the unit to follow the specified unit.

      Units that are following other units will not perform any other actions such as attacking. They will ignore attackers.

      :param BWAPI.Unit target: The target unit to start following.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: gather(target, [shiftQueueCommand = false]) -> boolean

      Orders the unit to gather the specified unit (must be mineral or refinery type).

      :param BWAPI.Unit target: The target unit to gather from.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: returnCargo([shiftQueueCommand = false]) -> boolean

      Orders the unit to return its cargo to a nearby resource depot such as a Command Center.

      Only workers that are carrying minerals or gas can be ordered to return cargo.

      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: repair(target, [shiftQueueCommand = false]) -> boolean

      Orders the unit to repair the specified unit.

      Only Terran SCVs can be ordered to repair, and the target must be a mechanical :attr:`~BWAPI.Races.Terran` unit or building.

      :param BWAPI.Unit target: The unit to repair.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: burrow() -> boolean

      Orders the unit to burrow.

      Either the unit must be a :attr:`~BWAPI.UnitTypes.Zerg_Lurker`, or the unit must be a :attr:`~BWAPI.Races.Zerg` ground unit that is capable of :attr:`~BWAPI.TechTypes.Burrowing`, and :attr:`Burrow <BWAPI.TechTypes.Burrowing>` technology must be researched.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`unburrow`

   .. method:: unburrow() -> boolean

      Orders a burrowed unit to unburrow.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`burrow`

   .. method:: cloak() -> boolean

      Orders the unit to cloak.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`decloak`

   .. method:: decloak() -> boolean

      Orders a cloaked unit to decloak.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`cloak`

   .. method:: siege() -> boolean

      Orders the unit to siege.

      Only works for :attr:`Siege Tanks <BWAPI.UnitTypes.Terran_Siege_Tank_Tank_Mode>`.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`unsiege`

   .. method:: unsiege() -> boolean

      Orders the unit to unsiege.

      Only works for sieged :attr:`Siege Tanks <BWAPI.UnitTypes.Terran_Siege_Tank_Siege_Mode>`.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`siege`

   .. method:: lift() -> boolean

      Orders the unit to lift.

      Only works for liftable :attr:`~BWAPI.Races.Terran` structures.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`Unit.land`

   .. method:: load(target, [shiftQueueCommand = false]) -> boolean

      Orders the unit to load the target unit.

      Only works if this unit is a Transport (:attr:`~BWAPI.UnitTypes.Terran_Dropship`, :attr:`~BWAPI.UnitTypes.Protoss_Shuttle`, :attr:`~BWAPI.UnitTypes.Zerg_Overlord` ) or :attr:`~BWAPI.UnitTypes.Terran_Bunker` type.

      :param BWAPI.Unit target: The target unit to load into this Transport(:attr:`~BWAPI.UnitTypes.Terran_Dropship`, :attr:`~BWAPI.UnitTypes.Protoss_Shuttle`, :attr:`~BWAPI.UnitTypes.Zerg_Overlord` ) or :attr:`~BWAPI.UnitTypes.Terran_Bunker`.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`unload`, :meth:`unloadAll`, :meth:`getLoadedUnits`

   .. method:: unloadAll([shiftQueueCommand = false]) -> boolean

      Orders the unit to unload all loaded units at the unit's current position.

      Only works for Transports (:attr:`~BWAPI.UnitTypes.Terran_Dropship`, :attr:`~BWAPI.UnitTypes.Protoss_Shuttle`, :attr:`~BWAPI.UnitTypes.Zerg_Overlord`) and :attr:`~BWAPI.UnitTypes.Terran_Bunker`.

      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`load`, :meth:`getLoadedUnits`

   .. method:: unloadAll(target, [shiftQueueCommand = false]) -> boolean

      Orders the unit to unload all loaded units at the specified location.

      Only works for Transports (:attr:`~BWAPI.UnitTypes.Terran_Dropship`, :attr:`~BWAPI.UnitTypes.Protoss_Shuttle`, :attr:`~BWAPI.UnitTypes.Zerg_Overlord`). Not applicable to :attr:`Bunkers <BWAPI.UnitTypes.Terran_Bunker>`.

      :param BWAPI.Position target: The target position to unload the units at.
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`load`, :meth:`getLoadedUnits`

   .. method:: rightClick(target, [shiftQueueCommand = false]) -> boolean

      Works like the right click in the GUI.

      :param target: Can be either a :class:`Position` or :class:`Unit`. The target position or target unit to right click.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`
      :param boolean shiftQueueCommand: (optional) If this value is true, then the order will be queued instead of immediately executed. If this value is omitted, then the order will be executed immediately by default.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: haltConstruction() -> boolean

      Orders a :attr:`~BWAPI.UnitTypes.Terran_SCV` to stop constructing a structure.

      This leaves the structure in an incomplete state until it is either cancelled, razed, or completed by another :attr:`~BWAPI.UnitTypes.Terran_SCV`.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: cancelConstruction() -> boolean

      Orders this unit to cancel and refund itself from begin constructed.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: cancelAddon() -> boolean

      Orders this unit to cancel and refund an add-on that is being constructed.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: cancelTrain([slot = -2]) -> boolean

      Orders the unit to remove the specified unit from its training queue.

      .. important::
         See :ref:`the differences between the C++ and Lua implementations of this function <differences-unit-train>` for more information

      :param int slot: (optional) Identifies the slot that will be cancelled. If the specified value is at least 1, then the unit in the corresponding slot will be cancelled. If the value is either omitted or -2, then the last slot is cancelled.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         The value of slot is passed directly to Broodwar. Other negative values have no effect.

      .. seealso::
        :meth:`train`

   .. method:: cancelMorph() -> boolean

      Orders this unit to cancel and refund a unit that is morphing.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

      .. seealso::
         :meth:`morph`

   .. method:: cancelResearch() -> boolean

      Orders this unit to cancel and refund a research that is in progress.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: cancelUpgrade() -> boolean

      Orders this unit to cancel and refund an upgrade that is in progress.

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. note::
         There is a small chance for a command to fail after it has been passed to Broodwar.

   .. method:: useTech(tech, [target = nil]) -> boolean

      Orders the unit to use a technology.

      :param BWAPI.TechType tech: The technology type to use.
      :param target: (optional) Can be either a :class:`Position` or :class:`Unit`. If specified, indicates the target location or unit to use the tech on. If unspecified, causes the ``tech`` to be used without a target (i.e. :attr:`~BWAPI.TechTypes.Stim_Packs`).
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`

      :return: true if the command was passed to Broodwar, and false if :mod:`BWAPI` determined that the command would fail.
      :rtype: boolean

      .. seealso::
         :mod:`~BWAPI.TechTypes`

   .. method:: getClosestUnit([pred = nil], [radius = 999999]) -> Unit

      Retrieves the closest unit relative to the value of :meth:`getPosition`.

      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`). Defaults to ``nil``, which means no filter.
      :param int radius: (optional) The maximum radius to check for the closest unit. For performance reasons, a developer can limit the radius that is checked. If omitted, then the entire map is checked.

      :return: The closest unit that matches the predicate, or ``nil`` if no matching unit is found.
      :rtype: :class:`BWAPI.Unit`

      .. seealso::
         :meth:`getUnitsInRadius`, :meth:`Game.getUnitsInRadius`, :meth:`Game.getUnitsInRectangle`

   .. method:: getInterceptors() -> Unitset

      Creates a single set containing all the :attr:`Interceptors <BWAPI.UnitTypes.Protoss_Interceptor>` of all :attr:`Carriers <BWAPI.UnitTypes.Protoss_Carrier>` in this set.

      :return: The set of all :attr:`Interceptors <BWAPI.UnitTypes.Protoss_Interceptor>` .
      :rtype: :class:`BWAPI.Unitset`

      .. seealso::
         :meth:`Unit.getInterceptors`

   .. method:: getLarva() -> Unitset

      Creates a single set containing all the :attr:`~BWAPI.UnitTypes.Zerg_Larva` of all :attr:`Hatcheries <BWAPI.UnitTypes.Zerg_Hatchery>`, :attr:`Lairs <BWAPI.UnitTypes.Zerg_Lair>`, and :attr:`Hives <BWAPI.UnitTypes.Zerg_Hive>` in this set.

      :return: The set of all :attr:`~BWAPI.UnitTypes.Zerg_Larva` .
      :rtype: :class:`BWAPI.Unitset`

      .. seealso::
         :meth:`Unit.getLarva`

   .. method:: getLoadedUnits() -> Unitset

      Creates a single set containing all units that are loaded into units of this set.

      :return: The set of all loaded units.
      :rtype: :class:`BWAPI.Unitset`

      .. seealso::
         :meth:`Unit.getLoadedUnits`

   .. method:: getPosition() -> Position

      Calculates the average of all valid Unit positions in this set.

      :return: Average Position of all units in the set.
      :rtype: :class:`BWAPI.Position`

      .. seealso::
         :meth:`Unit.getPosition`

   .. method:: getUnitsInRadius(radius, [pred = nil]) -> Unitset

      Retrieves the set of all units in a given radius relative to the value of :meth:`getPosition`.

      Takes into account this unit's dimensions. Can optionally specify a filter to include only specific units (such as only ground units, etc.)

      :param int radius: The radius, in pixels, to search for units.
      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`). Defaults to ``nil``, which means no filter.

      :return: A :class:`~BWAPI.Unitset` containing the set of units that match the given criteria.
      :rtype: :class:`BWAPI.Unitset`

      .. seealso::
         :meth:`getClosestUnit`, :meth:`Unit.getUnitsInRadius`, :meth:`Game.getUnitsInRectangle`

   .. include:: /_include/set-container-functions.rst
