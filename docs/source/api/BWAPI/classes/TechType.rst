TechType
********

.. currentmodule:: BWAPI

.. class:: TechType

   The :class:`~BWAPI.TechType` (or Technology Type, also referred to as an Ability) represents a :class:`Unit`'s ability which can be researched with :meth:`Unit.research` or used with :meth:`Unit.useTech`.

   In order for a Unit to use its own specialized ability, it must first be available and researched.

   .. seealso::
      :mod:`BWAPI.TechTypes`

   .. rubric:: Constructors

   .. method:: TechType([id = TechTypes.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

   .. method:: energyCost() -> int

      Retrieves the amount of energy needed to use this :class:`~BWAPI.TechType` as an ability.

      :return: Energy cost of the ability.
      :rtype: int

      .. seealso::
         :meth:`Unit.getEnergy`

   .. method:: gasPrice() -> int

      Retrieves the vespene gas cost of researching this technology.

      :return: Amount of vespene gas needed in order to research this technology.
      :rtype: int

   .. method:: getOrder() -> Order

      Retrieves the :class:`~BWAPI.Order` that a :class:`Unit` uses when using this ability.

      :return: :class:`~BWAPI.Order` representing the action a Unit uses to perform this ability
      :rtype: :class:`BWAPI.Order`

   .. method:: getRace() -> Race

      Retrieves the race that is required to research or use the :class:`~BWAPI.TechType`.

      :return: :class:`~BWAPI.Race` object indicating which race is designed to use this technology type.
      :rtype: :class:`BWAPI.Race`

      .. note::
         There is an exception where :attr:`Infested Kerrigan <BWAPI.UnitTypes.Hero_Infested_Kerrigan>` can use :attr:`Psionic Storm <BWAPI.TechTypes.Psionic_Storm>`. This does not apply to the behavior of this function.

   .. method:: getWeapon() -> WeaponType

      Retrieves the Weapon that is attached to this tech type.

      A technology's :class:`~BWAPI.WeaponType` is used to indicate the range and behaviour of the ability when used by a Unit.

      :return: :class:`~BWAPI.WeaponType` containing information about the ability's behavior. Returns :attr:`WeaponTypes.None` if there is no corresponding :class:`~BWAPI.WeaponType`.
      :rtype: :class:`BWAPI.WeaponType`

   .. method:: mineralPrice() -> int

      Retrieves the mineral cost of researching this technology.

      :return: Amount of minerals needed in order to research this technology.
      :rtype: int

   .. method:: requiredUnit() -> UnitType

      Retrieves the :class:`~BWAPI.UnitType` required to research this technology.

      The required unit type must be a completed unit owned by the player researching the technology.

      :return: :class:`~BWAPI.UnitType` that is needed to research this tech type. Returns :attr:`UnitTypes.None` if no unit is required to research this tech type.
      :rtype: :class:`BWAPI.UnitType`

      .. seealso::
         :meth:`Player.completedUnitCount`

   .. method:: researchTime() -> int

      Retrieves the number of frames needed to research the tech type.

      :return: The time, in frames, it will take for the research to complete.
      :rtype: int

      .. seealso::
         :meth:`Unit.getRemainingResearchTime`

   .. method:: targetsPosition() -> boolean

      Checks if this ability can be used on the terrain (ground).

      :return: true if the ability can be used on the terrain.
      :rtype: boolean

   .. method:: targetsUnit() -> boolean

      Checks if this ability can be used on other units.

      :return: true if the ability can be used on other units, and false if it can not.
      :rtype: boolean

   .. method:: whatResearches() -> UnitType

      Retrieves the :class:`~BWAPI.UnitType` that can research this technology.

      :return: :class:`~BWAPI.UnitType` that is able to research the technology in the game. Returns :attr:`UnitTypes.None` if the technology/ability is either provided for free or never available.
      :rtype: :class:`BWAPI.UnitType`

   .. method:: whatUses() -> UnitTypeset

      Retrieves the set of all :class:`UnitTypes <BWAPI.UnitType>` that are capable of using this ability.

      :return: Set of :class:`UnitTypes <BWAPI.UnitType>` that can use this ability when researched.
      :rtype: :class:`BWAPI.UnitTypeset`

TechTypeset
***********

.. class:: TechTypeset

   A container for a set of :class:`TechType` objects.

   .. rubric:: Constructors

   .. method:: TechTypeset()

      Default constructor.

   .. method:: TechTypeset(set)

      Copy constructor.

      :param BWAPI.TechTypeset set: The TechTypeset to copy.

   .. method:: TechTypeset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`TechType` are added to the set.

      :param table tbl: A table containing :class:`TechType` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
