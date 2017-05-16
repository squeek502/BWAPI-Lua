unit1 = BWAPI.MockUnit.new()
unit2 = BWAPI.MockUnit.new()

objs = {
  {val=5}, {val=4}, {val=3}, {val=10}, {val=1}, {val=7}
}
local objValFilter = function(obj) return obj.val end

function lowest()
  local bestFilter = BWAPI.Lowest(objValFilter)
  local best = nil

  for _, obj in ipairs(objs) do
    if best == nil then
      best = obj
    else
      best = bestFilter(best, obj)
    end
  end

  assert(best ~= nil)
  assert(best.val == 1)
end

function highest()
  local bestFilter = BWAPI.Highest(objValFilter)
  local best = nil

  for _, obj in ipairs(objs) do
    if best == nil then
      best = obj
    else
      best = bestFilter(best, obj)
    end
  end

  assert(best ~= nil)
  assert(best.val == 10)
end

function unaryUnitFilter()
  local isTransport = BWAPI.Filter.IsTransport(unit1)
  assert(isTransport == false)
end

function comparisonUnitFilter()
  -- int
  local hp = BWAPI.Filter.HP(unit1)
  assert(hp == 0)

  -- WeaponType
  local weaponType = BWAPI.Filter.GroundWeapon(unit1)
  assert(type(weaponType) == 'userdata')
end
