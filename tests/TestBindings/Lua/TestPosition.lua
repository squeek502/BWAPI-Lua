-- note: for sharing state between tests, global variables must be used

function defaultConstructors()
  pos = BWAPI.Position()
  tpos = BWAPI.TilePosition()
  wpos = BWAPI.WalkPosition()

  assert(pos.x == 0)
  assert(pos.y == 0)
  assert(tpos.x == 0)
  assert(tpos.y == 0)
  assert(wpos.x == 0)
  assert(wpos.y == 0)
end

function constructorsWithValues()
  pos = BWAPI.Position(32, 32)
  tpos = BWAPI.TilePosition(32, 32)
  wpos = BWAPI.WalkPosition(32, 32)

  assert(pos.x == 32)
  assert(pos.y == 32)
  assert(tpos.x == 32)
  assert(tpos.y == 32)
  assert(wpos.x == 32)
  assert(wpos.y == 32)
end

function conversionConstructors()
  -- from position
  pos = BWAPI.Position(32, 32)
  tpos = BWAPI.TilePosition(pos)
  wpos = BWAPI.WalkPosition(pos)
  assert(pos.x == 32)
  assert(pos.y == 32)
  assert(tpos.x == 1)
  assert(tpos.y == 1)
  assert(wpos.x == 4)
  assert(wpos.y == 4)

  -- from tile position
  pos2 = BWAPI.Position(tpos)
  wpos2 = BWAPI.WalkPosition(tpos)
  assert(pos2.x == 32)
  assert(pos2.y == 32)
  assert(wpos2.x == 4)
  assert(wpos2.y == 4)

  -- from walk position
  pos3 = BWAPI.Position(wpos)
  tpos3 = BWAPI.TilePosition(wpos)
  assert(pos3.x == 32)
  assert(pos3.y == 32)
  assert(tpos3.x == 1)
  assert(tpos3.y == 1)
end

function equality()
  p1, p2 = BWAPI.TilePosition(0,0), BWAPI.TilePosition(2,2)

  assert(p1 ~= p2)

  assert(p1 == BWAPI.TilePositions.Origin)
  assert(p2 ~= BWAPI.TilePositions.Origin)
end

function positionsCanBeValidOrInvalid()
  p1, p2 = BWAPI.TilePosition(0,0), BWAPI.TilePosition(-1,0)
  p3, p4 = BWAPI.TilePosition(0,-1), BWAPI.TilePosition(-1,-1)
  p5, p6 = BWAPI.TilePosition(256,0), BWAPI.TilePosition(0,256)
  p7 = BWAPI.TilePosition(256,256)

  assert(p1:isValid())
  assert(not p2:isValid())
  assert(not p3:isValid())
  assert(not p4:isValid())
  assert(not p5:isValid())
  assert(not p6:isValid())
  assert(not p7:isValid())

  function positionsCanBeMadeValid()
    p1:makeValid()
    p2:makeValid()
    p3:makeValid()
    p4:makeValid()
    p5:makeValid()
    p6:makeValid()
    p7:makeValid()

    assert(p1:isValid())
    assert(p2:isValid())
    assert(p3:isValid())
    assert(p4:isValid())
    assert(p5:isValid())
    assert(p6:isValid())
    assert(p7:isValid())

    function validPositionValuesMatchExpectations()
      assert(p1 == BWAPI.TilePositions.Origin)
      assert(p2 == BWAPI.TilePositions.Origin)
      assert(p3 == BWAPI.TilePositions.Origin)
      assert(p4 == BWAPI.TilePositions.Origin)
      assert(p5 == BWAPI.TilePosition(255, 0))
      assert(p6 == BWAPI.TilePosition(0, 255))
      assert(p7 == BWAPI.TilePosition(255, 255))
    end
  end
end

function lessThanComparison()
  p1, p2 = BWAPI.Position(0,0), BWAPI.Position(1,0)
  p3, p4 = BWAPI.Position(0,1), BWAPI.Position(1,1)

  assert(not (p1 < p1))
  assert(p1 < p2)
  assert(p1 < p3)
  assert(p1 < p4)

  assert(not (p2 < p1))
  assert(not (p2 < p2))
  assert(not (p2 < p3))
  assert(p2 < p4)

  assert(not (p3 < p1))
  assert(p3 < p2)
  assert(not (p3 < p3))
  assert(p3 < p4)

  assert(not (p4 < p1))
  assert(not (p4 < p2))
  assert(not (p4 < p3))
  assert(not (p4 < p4))
end

function addition()
  p1, p2 = BWAPI.Position(1,1), BWAPI.Position(1,2)

  p3 = p1 + p2
  assert(p3 == BWAPI.Position(2, 3))

  p3 = p3 + p1
  assert(p3 == BWAPI.Position(3, 4))

  p3 = p3 + BWAPI.Positions.Origin
  assert(p3 == BWAPI.Position(3, 4))
end

function subtraction()
  p1, p2 = BWAPI.Position(1,1), BWAPI.Position(1,2)

  p3 = p1 - p2
  assert(p3 == BWAPI.Position(0, -1))

  p3 = p3 - p1
  assert(p3 == BWAPI.Position(-1, -2))

  p3 = p3 - BWAPI.Positions.Origin
  assert(p3 == BWAPI.Position(-1, -2))
end

function multiplication()
  p1 = BWAPI.Position(1,2)

  p2 = p1 * 1
  p3 = p1 * 2
  assert(p2 == BWAPI.Position(1, 2))
  assert(p3 == BWAPI.Position(2, 4))

  p2 = p2 * 2
  p3 = p3 * 1
  assert(p2 == BWAPI.Position(2, 4))
  assert(p3 == BWAPI.Position(2, 4))
end

function division()
  p1 = BWAPI.Position(1,2)

  p2 = p1 / 1
  p3 = p1 / 2
  assert(p2 == BWAPI.Position(1, 2))
  assert(p3 == BWAPI.Position(0, 1))

  p2 = p2 / 2
  p3 = p3 / 1
  assert(p2 == BWAPI.Position(0, 1))
  assert(p3 == BWAPI.Position(0, 1))

  p2 = p1 / 0
  p3 = p3 / 0
  assert(p2 == BWAPI.Positions.Invalid)
  assert(p3 == BWAPI.Positions.Invalid)
end

function modulus()
  p1 = BWAPI.Position(1,2)

  p2 = p1 % 1
  p3 = p1 % 2
  assert(p2 == BWAPI.Position(0, 0))
  assert(p3 == BWAPI.Position(1, 0))

  p2, p3 = BWAPI.Position(3, 4), BWAPI.Position(3, 4)
  p2 = p2 % 2
  p3 = p3 % 1
  assert(p2 == BWAPI.Position(1, 0))
  assert(p3 == BWAPI.Position(0, 0))

  p2 = p1 % 0
  p3 = p3 % 0
  assert(p2 == BWAPI.Positions.Invalid)
  assert(p3 == BWAPI.Positions.Invalid)
end

function setMin()
  p1, p2 = BWAPI.Position(0,0), BWAPI.Position(3,3)

  p1:setMin(1, 0)
  p2:setMin(BWAPI.Position(0,4))
  assert(p1 == BWAPI.Position(1, 0))
  assert(p2 == BWAPI.Position(3, 4))
end

function setMax()
  p1, p2 = BWAPI.Position(0,0), BWAPI.Position(3,3)

  p1:setMax(1, -1)
  p2:setMax(BWAPI.Position(2,2))
  assert(p1 == BWAPI.Position(0, -1))
  assert(p2 == BWAPI.Position(2, 2))
end

function testToString()
  p1 = BWAPI.Position(2,-3)

  assert(tostring(p1) == '(2,-3)')
end

function getLength()
  p1, p2 = BWAPI.Position(0,5), BWAPI.Position(5,0)

  assert(p1:getLength() == 5)
  assert(p2:getLength() == 5)
  assert(p1:getLength() == p2:getLength())
end

function getDistance()
  p1, p2 = BWAPI.Position(0,5), BWAPI.Position(5,0)

  assert(p1:getDistance(BWAPI.Positions.Origin) == 5)
  assert(BWAPI.Positions.Origin:getDistance(p2) == 5)
end

function getApproxDistance()
  p1, p2 = BWAPI.Position(0,5), BWAPI.Position(5,0)

  assert(p1:getApproxDistance(BWAPI.Positions.Origin) == 5)
  assert(BWAPI.Positions.Origin:getApproxDistance(p2) == 5)
  assert(p1:getApproxDistance(p2) == 6)
end
