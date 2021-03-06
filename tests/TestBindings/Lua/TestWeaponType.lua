function constructors()
  unknown = BWAPI.WeaponType(BWAPI.WeaponTypes.Enum.Unknown)
  weapon = BWAPI.WeaponType(BWAPI.WeaponTypes.Enum.Gauss_Rifle)
end

function equality()
  unknown = BWAPI.WeaponType(BWAPI.WeaponTypes.Enum.Unknown)
  weapon = BWAPI.WeaponType(BWAPI.WeaponTypes.Enum.Gauss_Rifle)

  assert(unknown ~= weapon)
  assert(unknown == BWAPI.WeaponTypes.Unknown)
  assert(weapon == BWAPI.WeaponTypes.Gauss_Rifle)
end

function toStringTest()
  unknown = BWAPI.WeaponType(BWAPI.WeaponTypes.Enum.Unknown)
  weapon = BWAPI.WeaponType(BWAPI.WeaponTypes.Enum.Gauss_Rifle)

  assert(tostring(unknown) == 'Unknown')
  assert(tostring(weapon) == 'Gauss_Rifle')
end

function valuesOfTheGaussRifleType()
  weapon = BWAPI.WeaponTypes.Gauss_Rifle

  assert(weapon:getID() == BWAPI.WeaponTypes.Enum.Gauss_Rifle)
  assert(weapon:getName() == "Gauss_Rifle")
  assert(weapon:getTech() == BWAPI.TechTypes.None)
  assert(weapon:whatUses() == BWAPI.UnitTypes.Terran_Marine)
  assert(weapon:damageAmount() == 6)
  assert(weapon:damageBonus() == 1)
  assert(weapon:damageCooldown() == 15)
  assert(weapon:damageFactor() == 1)
  assert(weapon:upgradeType() == BWAPI.UpgradeTypes.Terran_Infantry_Weapons)
  assert(weapon:damageType() == BWAPI.DamageTypes.Normal)
  assert(weapon:explosionType() == BWAPI.ExplosionTypes.Normal)
  assert(weapon:minRange() == 0)
  assert(weapon:maxRange() == 128)
  assert(weapon:innerSplashRadius() == 0)
  assert(weapon:medianSplashRadius() == 0)
  assert(weapon:outerSplashRadius() == 0)
  assert(weapon:targetsAir() == true)
  assert(weapon:targetsGround() == true)
  assert(weapon:targetsMechanical() == false)
  assert(weapon:targetsOrganic() == false)
  assert(weapon:targetsNonBuilding() == false)
  assert(weapon:targetsNonRobotic() == false)
  assert(weapon:targetsTerrain() == false)
  assert(weapon:targetsOrgOrMech() == false)
  assert(weapon:targetsOwn() == false)
end

function valuesOfTheUnknownType()
  weapon = BWAPI.WeaponTypes.Unknown

  assert(weapon:getID() == BWAPI.WeaponTypes.Enum.Unknown)
  assert(weapon:getName() == "Unknown")
  assert(weapon:getTech() == BWAPI.TechTypes.None)
  assert(weapon:whatUses() == BWAPI.UnitTypes.Unknown)
  assert(weapon:damageAmount() == 0)
  assert(weapon:damageBonus() == 0)
  assert(weapon:damageCooldown() == 0)
  assert(weapon:damageFactor() == 0)
  assert(weapon:upgradeType() == BWAPI.UpgradeTypes.Unknown)
  assert(weapon:damageType() == BWAPI.DamageTypes.Unknown)
  assert(weapon:explosionType() == BWAPI.ExplosionTypes.Unknown)
  assert(weapon:minRange() == 0)
  assert(weapon:maxRange() == 0)
  assert(weapon:innerSplashRadius() == 0)
  assert(weapon:medianSplashRadius() == 0)
  assert(weapon:outerSplashRadius() == 0)
  assert(weapon:targetsAir() == false)
  assert(weapon:targetsGround() == false)
  assert(weapon:targetsMechanical() == false)
  assert(weapon:targetsOrganic() == false)
  assert(weapon:targetsNonBuilding() == false)
  assert(weapon:targetsNonRobotic() == false)
  assert(weapon:targetsTerrain() == false)
  assert(weapon:targetsOrgOrMech() == false)
  assert(weapon:targetsOwn() == false)
end
