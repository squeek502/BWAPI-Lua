UnitSizeType
************

.. currentmodule:: BWAPI

.. class:: UnitSizeType

   Size types are used by unit types in Broodwar to determine how much damage will be applied.

   This corresponds with :class:`DamageType` for several different damage reduction applications.

   `View on Starcraft Campendium (Official Website) <http://classic.battle.net/scc/gs/damage.shtml>`_

   .. seealso::
      :class:`DamageType`, :class:`~BWAPI.UnitType`, :mod:`~BWAPI.UnitSizeTypes`

   Inherits from `BWAPI::Type< UnitSizeType, UnitSizeTypes::Enum::Unknown > <../namespace/namespace_b_w_a_p_i.rst#bwapiclass_b_w_a_p_i_1_1_type>`_

   .. rubric:: Constructors

   .. method:: UnitSizeType([id = UnitSizeTypes.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

UnitSizeTypeset
***************

.. class:: UnitSizeTypeset

   A container for a set of :class:`UnitSizeType` objects.

   .. rubric:: Constructors

   .. method:: UnitSizeTypeset()

      Default constructor.

   .. method:: UnitSizeTypeset(set)

      Copy constructor.

      :param BWAPI.UnitSizeTypeset set: The UnitSizeTypeset to copy.

   .. method:: UnitSizeTypeset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`UnitSizeType` are added to the set.

      :param table tbl: A table containing :class:`UnitSizeType` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
