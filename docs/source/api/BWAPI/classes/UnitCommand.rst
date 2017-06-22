UnitCommand
***********

.. currentmodule:: BWAPI

.. class:: UnitCommand

   .. rubric:: Constructors

   .. method:: UnitCommand()

   .. method:: UnitCommand(unit, commandType, target, x, y, extra)

      :param BWAPI.Unit unit:
      :param BWAPI.UnitCommandType commandType:
      :param BWAPI.Unit target:
      :param int x:
      :param int y:
      :param int extra:

   .. rubric:: Member Functions

   .. method:: getSlot() -> int

      .. important::
         See :ref:`the differences between the C++ and Lua implementations of this function <differences-unit-train>` for more information

      :return:
      :rtype: int

   .. method:: getTarget() -> Unit

      :return:
      :rtype: :class:`BWAPI.Unit`

   .. method:: getTargetPosition() -> Position

      :return:
      :rtype: :class:`BWAPI.Position`

   .. method:: getTargetTilePosition() -> TilePosition

      :return:
      :rtype: :class:`BWAPI.TilePosition`

   .. method:: getTechType() -> TechType

      :return:
      :rtype: :class:`BWAPI.TechType`

   .. method:: getType() -> UnitCommandType

      :return:
      :rtype: :class:`BWAPI.UnitCommandType`

   .. method:: getUnit() -> Unit

      :return:
      :rtype: :class:`BWAPI.Unit`

   .. method:: getUnitType() -> UnitType

      :return:
      :rtype: :class:`BWAPI.UnitType`

   .. method:: getUpgradeType() -> UpgradeType

      :return:
      :rtype: :class:`BWAPI.UpgradeType`

   .. method:: isQueued() -> boolean

      :return:
      :rtype: boolean

   .. method:: assignTarget(target)

      :param BWAPI.Position target: The new target.

   .. rubric:: Static Functions

   .. staticmethod:: attack(unit, target, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param target: Can be either a :class:`Position` or :class:`Unit`.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: build(unit, target, type) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.TilePosition target:
      :param BWAPI.UnitType type:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: buildAddon(unit, type) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.UnitType type:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: burrow(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: cancelAddon(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: cancelConstruction(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: cancelMorph(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: cancelResearch(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: cancelTrain(unit, [slot = -2]) -> UnitCommand

      .. important::
         See :ref:`the differences between the C++ and Lua implementations of this function <differences-unit-train>` for more information

      :param BWAPI.Unit unit:
      :param int slot: Identifies the slot that will be cancelled. If the specified value is at least 1, then the unit in the corresponding slot will be cancelled. If the value is either omitted or -2, then the last slot is cancelled.

      :return:
      :rtype: UnitCommand

   .. staticmethod:: cancelUpgrade(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: cloak(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: decloak(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: follow(unit, target, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.Unit target:
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: gather(unit, target, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.Unit target:
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: haltConstruction(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: holdPosition(unit, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: land(unit, target) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.TilePosition target:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: lift(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: load(unit, target, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.Unit target:
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: morph(unit, type) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.UnitType type:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: move(unit, target, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.Position target:
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: patrol(unit, target, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.Position target:
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: placeCOP(unit, target) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.TilePosition target:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: repair(unit, target, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.Unit target:
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: research(unit, tech) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.TechType tech:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: returnCargo(unit, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: rightClick(unit, target, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param target: Can be either a :class:`Position` or :class:`Unit`.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: setRallyPoint(unit, target) -> UnitCommand

      :param BWAPI.Unit unit:
      :param target: Can be either a :class:`Position` or :class:`Unit`.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`

      :return:
      :rtype: UnitCommand

   .. staticmethod:: siege(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: stop(unit, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: train(unit, type) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.UnitType type:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: unburrow(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: unload(unit, target) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.Unit target:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: unloadAll(unit, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: unloadAll(unit, target, [shiftQueueCommand = false]) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.Position target:
      :param boolean shiftQueueCommand:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: unsiege(unit) -> UnitCommand

      :param BWAPI.Unit unit:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: upgrade(unit, upgrade) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.UpgradeType upgrade:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: useTech(unit, tech) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.TechType tech:

      :return:
      :rtype: UnitCommand

   .. staticmethod:: useTech(unit, tech, target) -> UnitCommand

      :param BWAPI.Unit unit:
      :param BWAPI.TechType tech:
      :param target: Can be either a :class:`Position` or :class:`Unit`.
      :type target: :class:`BWAPI.Position` or :class:`BWAPI.Unit`

      :return:
      :rtype: UnitCommand
