function constructors()
  color = BWAPI.Color(0)
  color = BWAPI.Color(255, 255, 255)
end

function equality()
  red = BWAPI.Colors.Red
  otherRed = BWAPI.Color(BWAPI.Colors.Red:getID())
  -- these constructors map to the closest index, so they can't be relied on
  -- for comparison purposes
  color = BWAPI.Color(235, 245, 230)

  assert(red ~= color)
  assert(red == BWAPI.Colors.Red)
  assert(red == otherRed)
end

function toStringTest()
  red = BWAPI.Colors.Red
  color = BWAPI.Color(235, 245, 230)

  assert(tostring(red) == 'Red')
  assert(tostring(color) == '')
end

function values()
  red = BWAPI.Colors.Red

  assert(red:red() == 244)
  assert(red:green() == 4)
  assert(red:blue() == 4)
end
