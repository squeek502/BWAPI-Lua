function constructors()
  unknown = BWAPI.UnitType(BWAPI.UnitTypes.Enum.Unknown)
  scv = BWAPI.UnitType(BWAPI.UnitTypes.Enum.Terran_SCV)
end

function equality()
  unknown = BWAPI.UnitType(BWAPI.UnitTypes.Enum.Unknown)
  scv = BWAPI.UnitType(BWAPI.UnitTypes.Enum.Terran_SCV)

  assert(unknown ~= scv)
  assert(scv == BWAPI.UnitTypes.Terran_SCV)
  assert(unknown == BWAPI.UnitTypes.Unknown)
end

function toStringTest()
  unknown = BWAPI.UnitType(BWAPI.UnitTypes.Enum.Unknown)
  scv = BWAPI.UnitType(BWAPI.UnitTypes.Enum.Terran_SCV)

  assert(tostring(unknown) == 'Unknown')
  assert(tostring(scv) == 'Terran_SCV')
end

function allUnitTypes()
  local unitTypes = BWAPI.UnitTypes.allUnitTypes()
  assert(BWAPI.UnitTypeset.isInstance(unitTypes))
  assert(unitTypes:size() == 207, unitTypes:size())
  local excluded = {
    [BWAPI.UnitTypes.AllUnits] = true,
    [BWAPI.UnitTypes.Men] = true,
    [BWAPI.UnitTypes.Buildings] = true,
    [BWAPI.UnitTypes.Factories] = true
  }
  for k, v in pairs(BWAPI.UnitTypes) do
    if k ~= "Enum" and type(v) ~= "function" then
      if excluded[v] then
        assert(not unitTypes:contains(v), k)
      else
        assert(unitTypes:contains(v), k)
      end
    end
  end
end

function valuesOfTheSCVUnitType()
  scv = BWAPI.UnitTypes.Terran_SCV

  assert(scv:getID() == BWAPI.UnitTypes.Enum.Terran_SCV)
  assert(scv:getName() == "Terran_SCV")
  assert(scv:getRace() == BWAPI.Races.Terran)

  local whatBuildsUnit, whatBuildsHowMany = scv:whatBuilds()
  assert(whatBuildsUnit == BWAPI.UnitTypes.Terran_Command_Center)
  assert(whatBuildsHowMany == 1)

  local requiredUnits = scv:requiredUnits()
  assert(requiredUnits[BWAPI.UnitTypes.Enum.Terran_Command_Center] == 1)

  assert(scv:requiredTech() == BWAPI.TechTypes.None)
  assert(scv:cloakingTech() == BWAPI.TechTypes.None)
  assert(#scv:abilities() == 0)
  assert(#scv:upgrades() == 1)
  assert(scv:upgrades():contains(BWAPI.UpgradeTypes.Terran_Infantry_Armor))
  assert(scv:armorUpgrade() == BWAPI.UpgradeTypes.Terran_Infantry_Armor)
  assert(scv:maxHitPoints() == 60)
  assert(scv:maxShields() == 0)
  assert(scv:maxEnergy() == 0)
  assert(scv:armor() == 0)
  assert(scv:mineralPrice() == 50)
  assert(scv:gasPrice() == 0)
  assert(scv:buildTime() == 300)
  assert(scv:supplyRequired() == 2)
  assert(scv:supplyProvided() == 0)
  assert(scv:spaceRequired() == 1)
  assert(scv:spaceProvided() == 0)
  assert(scv:buildScore() == 50)
  assert(scv:destroyScore() == 100)
  assert(scv:size() == BWAPI.UnitSizeTypes.Small)
  assert(scv:tileWidth() == 1)
  assert(scv:tileHeight() == 1)
  assert(scv:tileSize() == BWAPI.TilePosition(1,1))
  assert(scv:tileSize() == BWAPI.TilePosition(scv:tileWidth(), scv:tileHeight()))
  assert(scv:dimensionLeft() == 11)
  assert(scv:dimensionUp() == 11)
  assert(scv:dimensionRight() == 11)
  assert(scv:dimensionDown() == 11)
  assert(scv:width() == 23)
  assert(scv:dimensionLeft() + 1 + scv:dimensionRight() == scv:width())
  assert(scv:height() == 23)
  assert(scv:dimensionUp() + 1 + scv:dimensionDown() == scv:height())
  assert(scv:seekRange() == 32)
  assert(scv:sightRange() == 224)
  assert(scv:groundWeapon() == BWAPI.WeaponTypes.Fusion_Cutter)
  assert(scv:maxGroundHits() == 1)
  assert(scv:airWeapon() == BWAPI.WeaponTypes.None)
  assert(scv:maxAirHits() == 0)
  assert(scv:topSpeed() == 4.92)
  assert(scv:acceleration() == 67)
  assert(scv:haltDistance() == 12227)
  assert(scv:turnRadius() == 40)
  assert(scv:canProduce() == false)
  assert(scv:canAttack() == true)
  assert(scv:canMove() == true)
  assert(scv:isFlyer() == false)
  assert(scv:regeneratesHP() == false)
  assert(scv:isSpellcaster() == false)
  assert(scv:hasPermanentCloak() == false)
  assert(scv:isInvincible() == false)
  assert(scv:isOrganic() == true)
  assert(scv:isMechanical() == true)
  assert(scv:isRobotic() == false)
  assert(scv:isDetector() == false)
  assert(scv:isResourceContainer() == false)
  assert(scv:isResourceDepot() == false)
  assert(scv:isRefinery() == false)
  assert(scv:isWorker() == true)
  assert(scv:requiresPsi() == false)
  assert(scv:requiresCreep() == false)
  assert(scv:isTwoUnitsInOneEgg() == false)
  assert(scv:isBurrowable() == false)
  assert(scv:isCloakable() == false)
  assert(scv:isBuilding() == false)
  assert(scv:isAddon() == false)
  assert(scv:isFlyingBuilding() == false)
  assert(scv:isNeutral() == false)
  assert(scv:isHero() == false)
  assert(scv:isPowerup() == false)
  assert(scv:isBeacon() == false)
  assert(scv:isFlagBeacon() == false)
  assert(scv:isSpecialBuilding() == false)
  assert(scv:isSpell() == false)
  assert(scv:producesCreep() == false)
  assert(scv:producesLarva() == false)
  assert(scv:isMineralField() == false)
  assert(scv:isCritter() == false)
  assert(scv:canBuildAddon() == false)
  assert(#scv:buildsWhat() == 12)
  assert(#scv:researchesWhat() == 0)
  assert(#scv:upgradesWhat() == 0)
end

function valuesOfTheUnknownUnitType()
  unknown = BWAPI.UnitTypes.Unknown

  assert(unknown:getID() == BWAPI.UnitTypes.Enum.Unknown)
  assert(unknown:getName() == "Unknown")
  assert(unknown:getRace() == BWAPI.Races.Unknown)

  local whatBuildsUnit, whatBuildsHowMany = unknown:whatBuilds()
  assert(whatBuildsUnit == BWAPI.UnitTypes.Unknown)
  assert(whatBuildsHowMany == 1)

  local requiredUnits = unknown:requiredUnits()
  assert(requiredUnits[BWAPI.UnitTypes.Enum.Unknown] == 1)

  assert(unknown:requiredTech() == BWAPI.TechTypes.None)
  assert(unknown:cloakingTech() == BWAPI.TechTypes.None)
  assert(#unknown:abilities() == 0)
  assert(#unknown:upgrades() == 0)
  assert(unknown:armorUpgrade() == BWAPI.UpgradeTypes.Unknown)
  assert(unknown:maxHitPoints() == 0)
  assert(unknown:maxShields() == 0)
  assert(unknown:maxEnergy() == 0)
  assert(unknown:armor() == 0)
  assert(unknown:mineralPrice() == 0)
  assert(unknown:gasPrice() == 0)
  assert(unknown:buildTime() == 0)
  assert(unknown:supplyRequired() == 0)
  assert(unknown:supplyProvided() == 0)
  assert(unknown:spaceRequired() == 0)
  assert(unknown:spaceProvided() == 0)
  assert(unknown:buildScore() == 0)
  assert(unknown:destroyScore() == 0)
  assert(unknown:size() == BWAPI.UnitSizeTypes.Unknown)
  assert(unknown:tileWidth() == 0)
  assert(unknown:tileHeight() == 0)
  assert(unknown:tileSize() == BWAPI.TilePosition(0,0))
  assert(unknown:tileSize() == BWAPI.TilePosition(unknown:tileWidth(), unknown:tileHeight()))
  assert(unknown:dimensionLeft() == 0)
  assert(unknown:dimensionUp() == 0)
  assert(unknown:dimensionRight() == 0)
  assert(unknown:dimensionDown() == 0)
  assert(unknown:width() == 1)
  assert(unknown:dimensionLeft() + 1 + unknown:dimensionRight() == unknown:width())
  assert(unknown:height() == 1)
  assert(unknown:dimensionUp() + 1 + unknown:dimensionDown() == unknown:height())
  assert(unknown:seekRange() == 0)
  assert(unknown:sightRange() == 0)
  assert(unknown:groundWeapon() == BWAPI.WeaponTypes.Unknown)
  assert(unknown:maxGroundHits() == 0)
  assert(unknown:airWeapon() == BWAPI.WeaponTypes.Unknown)
  assert(unknown:maxAirHits() == 0)
  assert(unknown:topSpeed() == 0.0)
  assert(unknown:acceleration() == 0)
  assert(unknown:haltDistance() == 0)
  assert(unknown:turnRadius() == 0)
  assert(unknown:canProduce() == false)
  assert(unknown:canAttack() == true)
  assert(unknown:canMove() == false)
  assert(unknown:isFlyer() == false)
  assert(unknown:regeneratesHP() == false)
  assert(unknown:isSpellcaster() == false)
  assert(unknown:hasPermanentCloak() == false)
  assert(unknown:isInvincible() == false)
  assert(unknown:isOrganic() == false)
  assert(unknown:isMechanical() == false)
  assert(unknown:isRobotic() == false)
  assert(unknown:isDetector() == false)
  assert(unknown:isResourceContainer() == false)
  assert(unknown:isResourceDepot() == false)
  assert(unknown:isRefinery() == false)
  assert(unknown:isWorker() == false)
  assert(unknown:requiresPsi() == false)
  assert(unknown:requiresCreep() == false)
  assert(unknown:isTwoUnitsInOneEgg() == false)
  assert(unknown:isBurrowable() == false)
  assert(unknown:isCloakable() == false)
  assert(unknown:isBuilding() == false)
  assert(unknown:isAddon() == false)
  assert(unknown:isFlyingBuilding() == false)
  assert(unknown:isNeutral() == false)
  assert(unknown:isHero() == false)
  assert(unknown:isPowerup() == false)
  assert(unknown:isBeacon() == false)
  assert(unknown:isFlagBeacon() == false)
  assert(unknown:isSpecialBuilding() == false)
  assert(unknown:isSpell() == false)
  assert(unknown:producesCreep() == false)
  assert(unknown:producesLarva() == false)
  assert(unknown:isMineralField() == false)
  assert(unknown:isCritter() == false)
  assert(unknown:canBuildAddon() == false)
  assert(#unknown:buildsWhat() == 0)
  assert(#unknown:researchesWhat() == 0)
  assert(#unknown:upgradesWhat() == 0)
end
