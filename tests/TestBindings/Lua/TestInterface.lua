game = BWAPI.MockGame.new()
otherGame = BWAPI.MockGame.new()
unit1 = BWAPI.MockUnit.new()
unit2 = BWAPI.MockUnit.new()
unit3 = BWAPI.MockUnit.new()

function clientInfo()
  local info = game.clientInfo
  assert(type(info) == "table")
  local fn = function() end
  info["test"] = fn

  assert(info.test == fn)
  assert(game.clientInfo == info)
  assert(game.clientInfo.test == fn)

  local otherInfo = otherGame.clientInfo
  assert(type(otherInfo) == "table")
  assert(otherInfo.test == nil)

  assert(unit1.clientInfo ~= unit2.clientInfo)
  assert(unit2.clientInfo ~= unit3.clientInfo)
  assert(unit1.clientInfo ~= unit3.clientInfo)
  unit1.clientInfo.test = fn
  unit2.clientInfo.test = 5
  assert(unit1.clientInfo.test == fn)
  assert(unit2.clientInfo.test == 5)
end
