function constructors()
  race = BWAPI.Race(BWAPI.Races.Enum.Zerg)
end

function equality()
  race = BWAPI.Race(BWAPI.Races.Enum.Zerg)
  unknown = BWAPI.Race(BWAPI.Races.Enum.Unknown)

  assert(race ~= unknown)
  assert(race == BWAPI.Races.Zerg)
  assert(unknown == BWAPI.Races.Unknown)
end

function toStringTest()
  race = BWAPI.Race(BWAPI.Races.Enum.Zerg)
  unknown = BWAPI.Race(BWAPI.Races.Enum.Unknown)

  assert(tostring(race) == 'Zerg')
  assert(tostring(unknown) == 'Unknown')
end

function valuesZerg()
  race = BWAPI.Race(BWAPI.Races.Enum.Zerg)

  assert(race:getWorker() == BWAPI.UnitTypes.Zerg_Drone)
  assert(race:getCenter() == BWAPI.UnitTypes.Zerg_Hatchery)
  assert(race:getRefinery() == BWAPI.UnitTypes.Zerg_Extractor)
  assert(race:getTransport() == BWAPI.UnitTypes.Zerg_Overlord)
  assert(race:getSupplyProvider() == BWAPI.UnitTypes.Zerg_Overlord)
end

function valuesUnknown()
  race = BWAPI.Races.Unknown

  assert(race:getWorker() == BWAPI.UnitTypes.Unknown)
  assert(race:getCenter() == BWAPI.UnitTypes.Unknown)
  assert(race:getRefinery() == BWAPI.UnitTypes.Unknown)
  assert(race:getTransport() == BWAPI.UnitTypes.Unknown)
  assert(race:getSupplyProvider() == BWAPI.UnitTypes.Unknown)
end
