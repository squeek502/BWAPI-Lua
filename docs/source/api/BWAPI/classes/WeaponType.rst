WeaponType
**********

.. currentmodule:: BWAPI

.. class:: WeaponType

   This object identifies a weapon type used by a unit to attack and deal damage.

   Some weapon types can be upgraded while others are used for special abilities.

   .. seealso::
      :mod:`~BWAPI.WeaponTypes`

   .. rubric:: Constructors

   .. method:: WeaponType([id = WeaponTypes.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

   .. method:: damageAmount() -> int

      Retrieves the base amount of damage that this weapon can deal per attack.

      :return: Amount of base damage that this weapon deals.
      :rtype: int

      .. note::
         That this damage amount must go through a :class:`DamageType` and :class:`~BWAPI.UnitSizeType` filter before it is applied to a unit.

   .. method:: damageBonus() -> int

      Determines the bonus amount of damage that this weapon type increases by for every upgrade to this type.

      :return: Amount of damage added for every weapon upgrade.
      :rtype: int

      .. seealso::
         :meth:`upgradeType`

   .. method:: damageCooldown() -> int

      Retrieves the base amount of cooldown time between each attack, in frames.

      :return: The amount of base cooldown applied to the unit after an attack.
      :rtype: int

      .. seealso::
         :meth:`Unit.getGroundWeaponCooldown`, :meth:`Unit.getAirWeaponCooldown`

   .. method:: damageFactor() -> int

      Obtains the intended number of missiles/attacks that are used.

      This is used to multiply with the damage amount to obtain the full amount of damage for an attack.

      :return: The damage factor multiplied by the amount to obtain the total damage.
      :rtype: int

      .. seealso::
         :meth:`damageAmount`

   .. method:: damageType() -> DamageType

      Retrieves the damage type that this weapon applies to a unit type.

      :return: :class:`~BWAPI.DamageType` used for damage calculation.
      :rtype: :class:`BWAPI.DamageType`

      .. seealso::
         :class:`~BWAPI.DamageType`, :class:`~BWAPI.UnitSizeType`

   .. method:: explosionType() -> ExplosionType

      Retrieves the explosion type that indicates how the weapon deals damage.

      :return: :class:`~BWAPI.ExplosionType` identifying how damage is applied to a target location.
      :rtype: :class:`BWAPI.ExplosionType`

   .. method:: getTech() -> TechType

      Retrieves the technology type that must be researched before this weapon can be used.

      :return: :class:`~BWAPI.TechType` required by this weapon. Returns ``TechTypes.None`` if no tech type is required to use this weapon.
      :rtype: :class:`BWAPI.TechType`

      .. seealso::
         :meth:`TechType.getWeapon`

   .. method:: innerSplashRadius() -> int

      Retrieves the inner radius used for splash damage calculations, in pixels.

      :return: Radius of the inner splash area, in pixels.
      :rtype: int

   .. method:: maxRange() -> int

      Retrieves the maximum attack range of the weapon, measured in pixels.

      :return: Maximum attack range, in pixels.
      :rtype: int

   .. method:: medianSplashRadius() -> int

      Retrieves the middle radius used for splash damage calculations, in pixels.

      :return: Radius of the middle splash area, in pixels.
      :rtype: int

   .. method:: minRange() -> int

      Retrieves the minimum attack range of the weapon, measured in pixels.

      This value is 0 for almost all weapon types, except for :attr:`WeaponTypes.Arclite_Shock_Cannon` and :attr:`WeaponTypes.Arclite_Shock_Cannon_Edmund_Duke`.

      :return: Minimum attack range, in pixels.
      :rtype: int

   .. method:: outerSplashRadius() -> int

      Retrieves the outer radius used for splash damage calculations, in pixels.

      :return: Radius of the outer splash area, in pixels.
      :rtype: int

   .. method:: targetsAir() -> boolean

      Checks if this weapon type can target air units.

      :return: true if this weapon type can target air units, and false otherwise.
      :rtype: boolean

      .. seealso::
         :meth:`Unit.isFlying`, :meth:`UnitType.isFlyer`

   .. method:: targetsGround() -> boolean

      Checks if this weapon type can target ground units.

      :return: true if this weapon type can target ground units, and false otherwise.
      :rtype: boolean

      .. seealso::
         :meth:`Unit.isFlying`, :meth:`UnitType.isFlyer`

   .. method:: targetsMechanical() -> boolean

      Checks if this weapon type can only target mechanical units.

      :return: true if this weapon type can only target mechanical units, and false otherwise.
      :rtype: boolean

      .. seealso::
         :meth:`targetsOrgOrMech`, :meth:`UnitType.isMechanical`

   .. method:: targetsNonBuilding() -> boolean

      Checks if this weapon type cannot target structures.

      :return: true if this weapon type cannot target buildings, and false if it can.
      :rtype: boolean

      .. seealso::
         :meth:`UnitType.isBuilding`

   .. method:: targetsNonRobotic() -> boolean

      Checks if this weapon type cannot target robotic units.

      :return: true if this weapon type cannot target robotic units, and false if it can.
      :rtype: boolean

      .. seealso::
         :meth:`UnitType.isRobotic`

   .. method:: targetsOrganic() -> boolean

      Checks if this weapon type can only target organic units.

      :return: true if this weapon type can only target organic units, and false otherwise.
      :rtype: boolean

      .. seealso::
         :meth:`targetsOrgOrMech`, :meth:`UnitType.isOrganic`

   .. method:: targetsOrgOrMech() -> boolean

      Checks if this weapon type can only target organic or mechanical units.

      :return: true if this weapon type can only target organic or mechanical units, and false otherwise.
      :rtype: boolean

      .. seealso::
         :meth:`targetsOrganic`, :meth:`targetsMechanical`, :meth:`UnitType.isOrganic`, :meth:`UnitType.isMechanical`

   .. method:: targetsOwn() -> boolean

      Checks if this weapon type can only target units owned by the same player.

      This is used for :attr:`WeaponTypes.Consume`.

      :return: true if this weapon type can only target your own units, and false otherwise.
      :rtype: boolean

      .. seealso::
         :meth:`Unit.getPlayer`

   .. method:: targetsTerrain() -> boolean

      Checks if this weapon type can target the ground.

      :return: true if this weapon type can target a location, and false otherwise.
      :rtype: boolean

      .. note::
         This is more for attacks like `Psionic Storm <BWAPI.TechTypes.Psionic_Storm>` which can target a location, not to be confused with attack move.

   .. method:: upgradeType() -> UpgradeType

      Retrieves the upgrade type that increases this weapon's damage output.

      :return: The :class:`~BWAPI.UpgradeType` used to upgrade this weapon's damage.
      :rtype: :class:`BWAPI.UpgradeType`

      .. seealso::
         :meth:`damageBonus`

   .. method:: whatUses() -> UnitType

      Retrieves the unit type that is intended to use this weapon type.

      :return: The :class:`~BWAPI.UnitType` that uses this weapon.
      :rtype: :class:`BWAPI.UnitType`

      .. note::
         There is a rare case where some hero unit types use the same weapon.

      .. seealso::
         :meth:`UnitType.groundWeapon`, :meth:`UnitType.airWeapon`

WeaponTypeset
*************

.. class:: WeaponTypeset

   A container for a set of :class:`WeaponType` objects.

   .. rubric:: Constructors

   .. method:: WeaponTypeset()

      Default constructor.

   .. method:: WeaponTypeset(set)

      Copy constructor.

      :param BWAPI.WeaponTypeset set: The WeaponTypeset to copy.

   .. method:: WeaponTypeset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`WeaponType` are added to the set.

      :param table tbl: A table containing :class:`WeaponType` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
