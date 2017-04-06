Order
*****

.. currentmodule:: BWAPI

.. class:: Order

   An :class:`Order` represents a :class:`Unit`'s current action and can be retrieved with :meth:`Unit.getOrder`.

   It can also be used to identify the current state of the unit during command execution (gathering minerals can consist of :attr:`Orders.MoveToMinerals`, :attr:`Orders.WaitForMinerals`, :attr:`Orders.MiningMinerals`, etc.).

   .. seealso::
      :meth:`Unit.getOrder`, :mod:`BWAPI.Orders`

   .. rubric:: Constructors

   .. method:: Order([id = Orders.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

Orderset
********

.. class:: Orderset

   A container for a set of :class:`Order` objects.

   .. rubric:: Constructors

   .. method:: Orderset()

      Default constructor.

   .. method:: Orderset(set)

      Copy constructor.

      :param BWAPI.Orderset set: The Orderset to copy.

   .. method:: Orderset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`Order` are added to the set.

      :param table tbl: A table containing :class:`Order` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
