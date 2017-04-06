UnitCommandType
***************

.. currentmodule:: BWAPI

.. class:: UnitCommandType

   A representation of a unit command in :mod:`BWAPI`.

   This is used by bots to notify :mod:`BWAPI` which commands to use. :mod:`BWAPI` filters commands accordingly and then converts them to Broodwar commands, which differ in complexity.

   .. seealso::
      :mod:`BWAPI.UnitCommandTypes`

   .. rubric:: Constructors

   .. method:: UnitCommandType([id = UnitCommandTypes.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

UnitCommandTypeset
******************

.. class:: UnitCommandTypeset

   A container for a set of :class:`UnitCommandType` objects.

   .. rubric:: Constructors

   .. method:: UnitCommandTypeset()

      Default constructor.

   .. method:: UnitCommandTypeset(set)

      Copy constructor.

      :param BWAPI.UnitCommandTypeset set: The UnitCommandTypeset to copy.

   .. method:: UnitCommandTypeset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`UnitCommandType` are added to the set.

      :param table tbl: A table containing :class:`UnitCommandType` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
