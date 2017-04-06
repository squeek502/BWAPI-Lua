Playerset
*********

.. currentmodule:: BWAPI

.. class:: Playerset

   A set containing :class:`Player` objects.

   .. rubric:: Constructors

   .. method:: Playerset()

      Default constructor.

   .. method:: Playerset(set)

      Copy constructor.

      :param BWAPI.Playerset set: The Playerset to copy.

   .. method:: Playerset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`Player` are added to the set.

      :param table tbl: A table containing :class:`Player` objects.

   .. rubric:: Member Functions

   .. method:: getRaces() -> Raceset

      Returns the list of races that each player in the set is.

      :return: :class:`~BWAPI.Raceset` containing :class:`~BWAPI.Playerset`'s races
      :rtype: :class:`BWAPI.Raceset`

      .. seealso::
         :meth:`Player.getRace`

   .. method:: getUnits() -> Unitset

      Returns the set of all units that every player in this set owns.

      :return: :class:`~BWAPI.Unitset` containing :class:`~BWAPI.Playerset`'s units
      :rtype: :class:`BWAPI.Unitset`

      .. seealso::
         :meth:`Player.getUnits`

   .. method:: setAlliance([allies = true], [alliedVictory = true])

      Sets the alliance status with all players contained in the :class:`~BWAPI.Playerset`.

      :param boolean allies: Set to true to set the player to allied, or false for enemy.
      :param boolean alliedVictory: Set to true to turn on allied victory, or false to disable it.

      .. seealso::
         :meth:`Game.setAlliance`

   .. include:: /_include/set-container-functions.rst
