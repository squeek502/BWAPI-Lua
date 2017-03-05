game = BWAPI.MockGame.new()

function mouseKeyStates()
  -- these return values are hard-coded in MockGame
  assert(game:getMouseState(BWAPI.MouseButton.M_LEFT) == true)
  assert(game:getMouseState(BWAPI.MouseButton.M_RIGHT) == false)

  assert(game:getKeyState(BWAPI.Key.K_4) == true)
  assert(game:getKeyState(BWAPI.Key.K_0) == false)
end
