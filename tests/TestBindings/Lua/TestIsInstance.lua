local unitInst = BWAPI.MockUnit.new()
local pos = BWAPI.Position()
local tilePos = BWAPI.TilePosition()
local walkPos = BWAPI.WalkPosition()

function isInstance()
  assert(BWAPI.Unit.isInstance(unitInst))
  assert(not BWAPI.Unit.isInstance(nil))
  assert(not BWAPI.Unit.isInstance({}))
  assert(not BWAPI.Unit.isInstance(function() end))
  assert(not BWAPI.Unit.isInstance(5))
  assert(not BWAPI.Unit.isInstance(pos))

  assert(BWAPI.Position.isInstance(pos))
  assert(not BWAPI.Position.isInstance(tilePos))
  assert(not BWAPI.Position.isInstance(walkPos))

  assert(BWAPI.TilePosition.isInstance(tilePos))
  assert(BWAPI.WalkPosition.isInstance(walkPos))
end
