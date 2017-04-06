GameType
********

.. currentmodule:: BWAPI

.. class:: GameType

   A class that represents game types in Broodwar.

   A game type is selected when creating a game.

   .. seealso::
      :mod:`~BWAPI.GameTypes`

   .. rubric:: Constructors

   .. method:: GameType([id = GameTypes.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

GameTypeset
***********

.. class:: GameTypeset

   A container for a set of :class:`GameType` objects.

   .. rubric:: Constructors

   .. method:: GameTypeset()

      Default constructor.

   .. method:: GameTypeset(set)

      Copy constructor.

      :param BWAPI.GameTypeset set: The GameTypeset to copy.

   .. method:: GameTypeset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`GameType` are added to the set.

      :param table tbl: A table containing :class:`GameType` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
