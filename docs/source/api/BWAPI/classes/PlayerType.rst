PlayerType
**********

.. currentmodule:: BWAPI

.. class:: PlayerType

   Represents the type of controller for the player slot (i.e. human, computer).

   .. seealso::
      :mod:`BWAPI.PlayerTypes`

   .. rubric:: Constructors

   .. method:: PlayerType([id = PlayerTypes.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

   .. method:: isGameType() -> boolean

      Identifies whether or not this type is used in-game.

      A type such as :attr:`PlayerTypes.Closed` would not be a valid in-game type.

      :return: true if the type can appear in-game, false otherwise.
      :rtype: boolean

      .. seealso::
         :meth:`isLobbyType`

   .. method:: isLobbyType() -> boolean

      Identifies whether or not this type is used for the pre-game lobby.

      A type such as :attr:`PlayerTypes.ComputerLeft` would only appear in-game when a computer player is defeated.

      :return: true if this type can appear in the pre-game lobby, false otherwise.
      :rtype: boolean

PlayerTypeset
*************

.. class:: PlayerTypeset

   A container for a set of :class:`PlayerType` objects.

   .. rubric:: Constructors

   .. method:: PlayerTypeset()

      Default constructor.

   .. method:: PlayerTypeset(set)

      Copy constructor.

      :param BWAPI.PlayerTypeset set: The PlayerTypeset to copy.

   .. method:: PlayerTypeset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`PlayerType` are added to the set.

      :param table tbl: A table containing :class:`PlayerType` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
