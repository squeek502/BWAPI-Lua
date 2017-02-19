function constructors()
  unknown = BWAPI.UpgradeType(BWAPI.UpgradeTypes.Enum.Unknown)
  weapons = BWAPI.UpgradeType(BWAPI.UpgradeTypes.Enum.Terran_Infantry_Weapons)
end

function equality()
  unknown = BWAPI.UpgradeType(BWAPI.UpgradeTypes.Enum.Unknown)
  weapons = BWAPI.UpgradeType(BWAPI.UpgradeTypes.Enum.Terran_Infantry_Weapons)

  assert(unknown ~= weapons)
  assert(unknown == BWAPI.UpgradeTypes.Unknown)
  assert(weapons == BWAPI.UpgradeTypes.Terran_Infantry_Weapons)
end

function toStringTest()
  unknown = BWAPI.UpgradeType(BWAPI.UpgradeTypes.Enum.Unknown)
  weapons = BWAPI.UpgradeType(BWAPI.UpgradeTypes.Enum.Terran_Infantry_Weapons)

  assert(tostring(unknown) == 'Unknown')
  assert(tostring(weapons) == 'Terran_Infantry_Weapons')
end

function valuesOfTheWeaponsUpgradeType()
  upgrade = BWAPI.UpgradeTypes.Terran_Infantry_Weapons

  assert(upgrade:getID() == BWAPI.UpgradeTypes.Enum.Terran_Infantry_Weapons)
  assert(upgrade:getName() == "Terran_Infantry_Weapons")
  assert(upgrade:getRace() == BWAPI.Races.Terran)
  assert(upgrade:mineralPrice() == 100)
  assert(upgrade:mineralPrice() + upgrade:mineralPriceFactor() == upgrade:mineralPrice(2))
  assert(upgrade:gasPrice() == 100)
  assert(upgrade:gasPrice() + upgrade:gasPriceFactor() == upgrade:gasPrice(2))
  assert(upgrade:upgradeTime() == 4000)
  assert(upgrade:upgradeTime() + upgrade:upgradeTimeFactor() == upgrade:upgradeTime(2))
  assert(upgrade:maxRepeats() == 3)
  assert(upgrade:whatUpgrades() == BWAPI.UnitTypes.Terran_Engineering_Bay)
  assert(upgrade:whatsRequired() == BWAPI.UnitTypes.None)
  assert(upgrade:whatsRequired(1) == BWAPI.UnitTypes.None)
  assert(upgrade:whatsRequired(2) == BWAPI.UnitTypes.Terran_Science_Facility)
  assert(#upgrade:whatUses() == 11)
  assert(upgrade:whatUses():contains(BWAPI.UnitTypes.Terran_Marine))
end

function valuesOfTheUnknownUpgradeType()
  upgrade = BWAPI.UpgradeTypes.Unknown

  assert(upgrade:getID() == BWAPI.UpgradeTypes.Enum.Unknown)
  assert(upgrade:getName() == "Unknown")
  assert(upgrade:getRace() == BWAPI.Races.Unknown)
  assert(upgrade:mineralPrice() == 0)
  assert(upgrade:mineralPrice() + upgrade:mineralPriceFactor() == upgrade:mineralPrice(2))
  assert(upgrade:gasPrice() == 0)
  assert(upgrade:gasPrice() + upgrade:gasPriceFactor() == upgrade:gasPrice(2))
  assert(upgrade:upgradeTime() == 0)
  assert(upgrade:upgradeTime() + upgrade:upgradeTimeFactor() == upgrade:upgradeTime(2))
  assert(upgrade:maxRepeats() == 0)
  assert(upgrade:whatUpgrades() == BWAPI.UnitTypes.None)
  assert(upgrade:whatsRequired() == BWAPI.UnitTypes.None)
  assert(upgrade:whatsRequired(1) == BWAPI.UnitTypes.None)
  assert(upgrade:whatsRequired(2) == BWAPI.UnitTypes.None)
  assert(#upgrade:whatUses() == 0)
end
