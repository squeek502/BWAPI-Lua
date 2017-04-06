Forceset
********

.. currentmodule:: BWAPI

.. class:: Forceset

   A container that holds a group of Forces.

   .. seealso::
      :class:`~BWAPI.Force`

   .. rubric:: Constructors

   .. method:: Forceset()

      Default constructor.

   .. method:: Forceset(set)

      Copy constructor.

      :param BWAPI.Forceset set: The Forceset to copy.

   .. method:: Forceset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`Force` are added to the set.

      :param table tbl: A table containing :class:`Force` objects.

   .. rubric:: Member Functions

   .. method:: getPlayers() -> set

      Retrieves the set of players that belong to this set of forces.

      :return: A :class:`~BWAPI.Playerset` containing the players that are part of this Forceset.
      :rtype: :class:`BWAPI.Playerset`

   .. include:: /_include/set-container-functions.rst
