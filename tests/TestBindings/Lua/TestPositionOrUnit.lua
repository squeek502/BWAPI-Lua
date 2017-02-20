unitInst = BWAPI.MockUnit.new()

function constructors()
  nullType = BWAPI.PositionOrUnit()
  unitType = BWAPI.PositionOrUnit(unitInst)
  posType = BWAPI.PositionOrUnit(BWAPI.Position(5,5))
end

function nullUnit()
  nullType = BWAPI.PositionOrUnit()
  assert(nullType:isUnit() == true) -- it's a unit type if the Position constructor is not used
  assert(nullType:getUnit() == nil)
  assert(nullType:isPosition() == false)
  assert(nullType:getPosition() == BWAPI.Positions.None) -- returns Positions.None if unit is null
end

function unit()
  unitType = BWAPI.PositionOrUnit(unitInst)
  assert(unitType:isUnit() == true)
  assert(unitType:getUnit() ~= nil)
  assert(unitType:isPosition() == false)
  assert(unitType:getPosition() == BWAPI.Positions.Origin) -- returns the Unit's position if Unit is set
end

function position()
  local pos = BWAPI.Position(5,5)
  posType = BWAPI.PositionOrUnit(pos)
  assert(posType:isUnit() == false)
  assert(posType:getUnit() == nil)
  assert(posType:isPosition() == true)
  assert(posType:getPosition() == pos)
end
