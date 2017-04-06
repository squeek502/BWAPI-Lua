Race
****

.. currentmodule:: BWAPI

.. class:: Race

   The :class:`~BWAPI.Race` object is used to get information about a particular race.

   For example, the default worker and supply provider :class:`~BWAPI.UnitType`.

   As you should already know, Starcraft has three races: :attr:`~BWAPI.Races.Terran` , :attr:`~BWAPI.Races.Protoss` , and :attr:`~BWAPI.Races.Zerg` .

   .. seealso::
      :meth:`UnitType.getRace`, :meth:`Player.getRace`, :mod:`BWAPI.Races`

   .. rubric:: Constructors

   .. method:: Race([id = Races.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

   .. method:: getCenter() -> UnitType

      Retrieves the default resource center :class:`~BWAPI.UnitType` that is used to create expansions for this :class:`~BWAPI.Race`.

      :return: :class:`~BWAPI.UnitType` of the center that this race uses.
      :rtype: :class:`BWAPI.UnitType`

      .. note::
         In Starcraft, the center is the very first structure of the :class:`~BWAPI.Race`'s technology tree. Also known as its base of operations or resource depot.

   .. method:: getRefinery() -> UnitType

      Retrieves the default structure :class:`~BWAPI.UnitType` for this :class:`~BWAPI.Race` that is used to harvest gas from :attr:`Vespene Geysers <BWAPI.UnitTypes.Resource_Vespene_Geyser>`.

      :return: :class:`~BWAPI.UnitType` of the structure used to harvest gas.
      :rtype: :class:`BWAPI.UnitType`

      .. note::
         In Starcraft, you must first construct a structure over a :attr:`Vespene Geyser <BWAPI.UnitTypes.Resource_Vespene_Geyser>` in order to begin harvesting Vespene Gas.

   .. method:: getSupplyProvider() -> UnitType

      Retrieves the default supply provider :class:`~BWAPI.UnitType` for this race that is used to construct units.

      :return: :class:`~BWAPI.UnitType` that provides the player with supply.
      :rtype: :class:`BWAPI.UnitType`

      .. note::
         In Starcraft, training, morphing, or warping in units requires that the player has sufficient supply available for their :class:`~BWAPI.Race`.

   .. method:: getTransport() -> UnitType

      Retrieves the default transport :class:`~BWAPI.UnitType` for this race that is used to transport ground units across the map.

      :return: :class:`~BWAPI.UnitType` for transportation.
      :rtype: :class:`BWAPI.UnitType`

      .. note::
         In Starcraft, transports will allow you to carry ground units over unpassable terrain.

   .. method:: getWorker() -> UnitType

      Retrieves the default worker type for this :class:`~BWAPI.Race`.

      :return: :class:`~BWAPI.UnitType` of the worker that this race uses.
      :rtype: :class:`BWAPI.UnitType`

      .. note::
         In Starcraft, workers are the units that are used to construct structures.

Raceset
*******

.. class:: Raceset

   A container for a set of :class:`Race` objects.

   .. rubric:: Constructors

   .. method:: Raceset()

      Default constructor.

   .. method:: Raceset(set)

      Copy constructor.

      :param BWAPI.Raceset set: The Raceset to copy.

   .. method:: Raceset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`Race` are added to the set.

      :param table tbl: A table containing :class:`Race` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
