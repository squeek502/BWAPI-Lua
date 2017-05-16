Region
******

.. currentmodule:: BWAPI

.. class:: Region

   Region objects are created by Starcraft: Broodwar to contain several tiles with the same properties, and create a node in pathfinding and other algorithms.

   Regions may not contain detailed information, but have a sufficient amount of data to identify general chokepoints, accessibility to neighboring terrain, be used in general pathing algorithms, and used as nodes to rally units to.

   Most parameters that are available are explicitly assigned by Broodwar itself.

   .. seealso::
      :meth:`Game.getAllRegions`, :meth:`Game.getRegionAt`, :meth:`Unit.getRegion`

   .. rubric:: Constructors

   This class is not constructable through Lua.

   .. rubric:: Member Variables

   .. include:: /_include/interface-clientinfo.rst

   .. rubric:: Member Functions

   .. method:: getBoundsBottom() -> int

      Retrieves the approximate bottom boundary of the region.

      :return: The y coordinate, in pixels, of the approximate bottom boundary of the region.
      :rtype: int

   .. method:: getBoundsLeft() -> int

      Retrieves the approximate left boundary of the region.

      :return: The x coordinate, in pixels, of the approximate left boundary of the region.
      :rtype: int

   .. method:: getBoundsRight() -> int

      Retrieves the approximate right boundary of the region.

      :return: The x coordinate, in pixels, of the approximate right boundary of the region.
      :rtype: int

   .. method:: getBoundsTop() -> int

      Retrieves the approximate top boundary of the region.

      :return: The y coordinate, in pixels, of the approximate top boundary of the region.
      :rtype: int

   .. method:: getCenter() -> Position

      Retrieves the center of the region.

      This position is used as the node of the region.

      :return: A :class:`Position` indicating the center location of the :class:`Region`, in pixels.
      :rtype: :class:`BWAPI.Position`

   .. method:: getClosestAccessibleRegion() -> Region

      Retrieves the closest accessible neighbor region.

      :return: The closest :class:`Region` that is accessible.
      :rtype: :class:`BWAPI.Region`

   .. method:: getClosestInaccessibleRegion() -> Region

      Retrieves the closest inaccessible neighbor region.

      :return: The closest :class:`Region` that is inaccessible.
      :rtype: :class:`BWAPI.Region`

   .. method:: getDefensePriority() -> int

      Retrieves a value that represents the strategic advantage of this region relative to other regions.

      A value of 2 may indicate a possible choke point, and a value of 3 indicates a signficant strategic position.

      :return: An integer indicating this region's strategic potential.
      :rtype: int

      .. note::
         This value is explicitly assigned by Broodwar.

   .. method:: getDistance(other) -> int

      Retrieves the center-to-center distance between two regions.

      :param BWAPI.Region other: The target :class:`Region` to calculate distance to.

      :return: The integer distance from this Region to ``other``.
      :rtype: int

   .. method:: getID() -> int

      Retrieves a unique identifier for this region.

      :return: An integer that represents this region.
      :rtype: int

      .. note::
         This identifier is explicitly assigned by Broodwar.

      .. seealso::
         :meth:`Game.getRegion`

   .. method:: getNeighbors() -> Regionset

      Retrieves the set of neighbor Regions that this one is connected to.

      :return: A reference to a :class:`~BWAPI.Regionset` containing the neighboring Regions.
      :rtype: :class:`BWAPI.Regionset`

   .. method:: getRegionGroupID() -> int

      Retrieves a unique identifier for a group of regions that are all connected and accessible by each other.

      That is, all accessible regions will have the same group ID. This function is generally used to check if a path is available between two points in constant time.

      :return: An integer that represents the group of regions that this one is attached to.
      :rtype: int

      .. note::
         This identifier is explicitly assigned by Broodwar.

   .. method:: getUnits([pred = nil]) -> Unitset

      Retrieves a :class:`~BWAPI.Unitset` containing all the units that are in this region.

      Also has the ability to filter the units before the creation of the :class:`~BWAPI.Unitset`.

      :param function pred: (optional) A predicate function that takes a :class:`Unit` and returns ``true`` for units that satisfy the intended filter and ``false`` otherwise (can be a :ref:`BWAPI.Filter unary filter <unary-filters>`). Defaults to ``nil``, which means no filter.

      :return: A :class:`~BWAPI.Unitset` containing all units in this region that have met the requirements of ``pred``.
      :rtype: :class:`BWAPI.Unitset`

   .. method:: isAccessible() -> boolean

      Retrieves the state of accessibility of the region.

      The region is considered accessible if it can be accessed by ground units.

      :return: true if ground units can traverse this region, and false if the tiles in this region are inaccessible or unwalkable.
      :rtype: boolean

   .. method:: isHigherGround() -> boolean

      Checks if this region is part of higher ground.

      Higher ground may be used in strategic placement of units and structures.

      :return: true if this region is part of strategic higher ground, and false otherwise.
      :rtype: boolean

   .. include:: /_include/interface-functions.rst
