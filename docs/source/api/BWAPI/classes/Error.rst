Error
*****

.. currentmodule:: BWAPI

.. class:: Error

   The :class:`~BWAPI.Error` object is generally used to determine why certain functions in :mod:`BWAPI` have failed.

   For example, you may not have enough resources to construct a unit.

   .. seealso::
      :meth:`Game.getLastError`, :meth:`Game.setLastError`, :mod:`~BWAPI.Errors`

   .. rubric:: Constructors

   .. method:: Error([id = Errors.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

Errorset
********

.. class:: Errorset

   A container for a set of :class:`Error` objects.

   .. rubric:: Constructors

   .. method:: Errorset()

      Default constructor.

   .. method:: Errorset(set)

      Copy constructor.

      :param BWAPI.Errorset set: The Errorset to copy.

   .. method:: Errorset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`Error` are added to the set.

      :param table tbl: A table containing :class:`Error` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
