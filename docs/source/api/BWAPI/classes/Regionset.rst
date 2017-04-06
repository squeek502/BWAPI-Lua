Regionset
*********

.. currentmodule:: BWAPI

.. class:: Regionset

   A container that holds a set of :class:`Region` objects.

   .. rubric:: Constructors

   .. method:: Regionset()

      Default constructor.

   .. method:: Regionset(set)

      Copy constructor.

      :param BWAPI.Regionset set: The Regionset to copy.

   .. method:: Regionset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`Region` are added to the set.

      :param table tbl: A table containing :class:`Region` objects.

   .. rubric:: Member Functions

   .. method:: getCenter() -> Position

      Retrieves the center of the region.

      This position is used as the node of the region.

      :return: A Position indicating the center location of the :class:`Regionset`, in pixels.
      :rtype: :class:`BWAPI.Position`

   .. method:: getUnits([pred = nil]) -> Unitset

      Retrieves a :class:`~BWAPI.Unitset` containing all the units that are in this region.

      Also has the ability to filter the units before the creation of the :class:`~BWAPI.Unitset`.

      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise **or** a :class:`UnitFilter` instance. Defaults to ``nil``, which means no filter.

      :return: A :class:`~BWAPI.Unitset` containing all units in this region that have met the requirements of ``pred``.
      :rtype: :class:`BWAPI.Unitset`

   .. include:: /_include/set-container-functions.rst
