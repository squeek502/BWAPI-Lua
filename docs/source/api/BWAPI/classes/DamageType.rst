DamageType
**********

.. currentmodule:: BWAPI

.. class:: DamageType

   Damage types are used in Broodwar to determine the amount of damage that will be done to a unit.

   This corresponds with :class:`~BWAPI.UnitSizeType` to determine the damage done to a unit.

   * `View on Liquipedia <http://wiki.teamliquid.net/starcraft/Damage_Type>`_
   * `View on Starcraft Compendium (Official Website) <http://classic.battle.net/scc/gs/damage.shtml>`_
   * `View on Starcraft Wikia <http://starcraft.wikia.com/wiki/Damage_types>`_

   .. seealso::
      :class:`~BWAPI.WeaponType`, :mod:`~BWAPI.DamageTypes`, :class:`~BWAPI.UnitSizeType`

   .. rubric:: Constructors

   .. method:: DamageType([id = DamageTypes.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

DamageTypeset
*************

.. class:: DamageTypeset

   A container for a set of :class:`DamageType` objects.

   .. rubric:: Constructors

   .. method:: DamageTypeset()

      Default constructor.

   .. method:: DamageTypeset(set)

      Copy constructor.

      :param BWAPI.DamageTypeset set: The DamageTypeset to copy.

   .. method:: DamageTypeset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`DamageType` are added to the set.

      :param table tbl: A table containing :class:`DamageType` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
