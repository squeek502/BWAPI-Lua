UpgradeType
***********

.. currentmodule:: BWAPI

.. class:: UpgradeType

   The upgrade type represents a passive upgrade that can be obtained with :meth:`Unit.upgrade`.

   .. seealso::
      :mod:`~BWAPI.UpgradeTypes`

   .. rubric:: Constructors

   .. method:: UpgradeType([id = UpgradeTypes.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

   .. method:: gasPrice([level = 1]) -> int

      Returns the vespene gas price for the first upgrade.

      :param int level: (optional) The next upgrade level.

      :return: The gas cost of the upgrade for the given ``level``.
      :rtype: int

      .. note::
         Upgrades start at level 0.

   .. method:: gasPriceFactor() -> int

      Returns the amount that the vespene gas price increases for each additional upgrade.

      :return: The gas cost added to the upgrade after each level.
      :rtype: int

   .. method:: getRace() -> Race

      Retrieves the race the upgrade is for.

      For example, ``BWAPI.UpgradeTypes.Terran_Infantry_Armor:getRace()`` will return :attr:`Races.Terran`.

      :return: :class:`~BWAPI.Race` that this upgrade belongs to.
      :rtype: :class:`BWAPI.Race`

   .. method:: maxRepeats() -> int

      Returns the maximum number of times the upgrade can be researched.

      :return: Maximum number of times this upgrade can be upgraded.
      :rtype: int

   .. method:: mineralPrice([level = 1]) -> int

      Returns the mineral price for the upgrade.

      :param int level: (optional) The next upgrade level.

      :return: The mineral cost of the upgrade for the given ``level``.
      :rtype: int

      .. note::
         Upgrades start at level 0.

   .. method:: mineralPriceFactor() -> int

      The amount that the mineral price increases for each additional upgrade.

      :return: The mineral cost added to the upgrade after each level.
      :rtype: int

   .. method:: upgradeTime([level = 1]) -> int

      Returns the number of frames needed to research the first upgrade.

      :param int level: (optional) The next upgrade level.

      :return: The time cost of the upgrade for the given ``level``.
      :rtype: int

      .. note::
         Upgrades start at level 0.

   .. method:: upgradeTimeFactor() -> int

      Returns the number of frames that the upgrade time increases for each additional upgrade.

      :return: The time cost added to the upgrade after each level.
      :rtype: int

   .. method:: whatsRequired([level = 1]) -> UnitType

      Returns the type of unit that is required for the upgrade.

      The player must have at least one of these units completed in order to start upgrading this upgrade.

      :param int level: (optional) The next upgrade level.

      :return: :class:`~BWAPI.UnitType` required to obtain this upgrade.
      :rtype: :class:`BWAPI.UnitType`

      .. note::
         Upgrades start at level 0.

   .. method:: whatUpgrades() -> UnitType

      Returns the type of unit that researches the upgrade.

      :return: The :class:`~BWAPI.UnitType` that is used to upgrade this type.
      :rtype: :class:`BWAPI.UnitType`

   .. method:: whatUses() -> UnitTypeset

      Returns the set of units that are affected by this upgrade.

      :return: Set of unit types that passively use this upgrade type.
      :rtype: :class:`BWAPI.UnitTypeset`

UpgradeTypeset
**************

.. class:: UpgradeTypeset

   A container for a set of :class:`UpgradeType` objects.

   .. rubric:: Constructors

   .. method:: UpgradeTypeset()

      Default constructor.

   .. method:: UpgradeTypeset(set)

      Copy constructor.

      :param BWAPI.UpgradeTypeset set: The UpgradeTypeset to copy.

   .. method:: UpgradeTypeset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`UpgradeType` are added to the set.

      :param table tbl: A table containing :class:`UpgradeType` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
