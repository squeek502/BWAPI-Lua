local Broodwar = BWAPI.Broodwar
local Filter = BWAPI.Filter

function BWAPI.onStart()

  -- Hello World!
  Broodwar:sendText("Hello world!")

  -- Print the map name.
  -- BWAPI returns std::string when retrieving a string, don't forget to add .c_str() when printing!
  print(("The map is %s!"):format(Broodwar:mapName()))

  -- Enable the UserInput flag, which allows us to control the bot and type messages.
  Broodwar:enableFlag(BWAPI.Flag.UserInput)

  -- Uncomment the following line and the bot will know about everything through the fog of war (cheat).
  --Broodwar:enableFlag(BWAPI.Flag.CompleteMapInformation)

  -- Set the command optimization level so that common commands can be grouped
  -- and reduce the bot's APM (Actions Per Minute).
  Broodwar:setCommandOptimizationLevel(2)

  -- Check if this is a replay
  if Broodwar:isReplay() then
    -- Announce the players in the replay
    print("The following players are in this replay:")

    -- Iterate all the players in the game using a std:: iterator
    local players = Broodwar:getPlayers()
    for player in players:iterator() do
      -- Only print the player if they are not an observer
      if not player:isObserver() then
        print(("%s, playing as %s"):format(player:getName(), tostring(player:getRace())))
      end
    end

  else -- if this is not a replay
    -- Retrieve you and your enemy's races. enemy() will just return the first enemy.
    -- If you wish to deal with multiple enemies then you must use enemies().
    if Broodwar:enemy() then -- First make sure there is an enemy
      print(("The matchup is %s vs %s"):format(tostring(Broodwar:self():getRace()), tostring(Broodwar:enemy():getRace())))
    end
  end

end

function BWAPI.onEnd(isWinner)
  -- Called when the game ends
  if isWinner then
    -- Log your win here!
  end
end

local lastChecked = 0
function BWAPI.onFrame()
  -- Called once every game frame

  -- Display the game frame rate as text in the upper left area of the screen
  Broodwar:drawTextScreen(200, 0, string.format("FPS: %d", Broodwar:getFPS()))
  Broodwar:drawTextScreen(200, 20, string.format("Average FPS: %f", Broodwar:getAverageFPS()))

  -- Return if the game is a replay or is paused
  if Broodwar:isReplay() or Broodwar:isPaused() or not Broodwar:self() then
    return
  end

  -- Prevent spamming by only running our onFrame once every number of latency frames.
  -- Latency frames are the number of frames before commands are processed.
  if Broodwar:getFrameCount() % Broodwar:getLatencyFrames() ~= 0 then
    return
  end

  -- Iterate through all the units that we own
  for u in Broodwar:self():getUnits():iterator() do
    local shouldContinue = false
    -- Ignore the unit if it no longer exists
    -- Make sure to include this block when handling any Unit pointer!
    if not u:exists() then
      shouldContinue = true
    end

    -- Ignore the unit if it has one of the following status ailments
    if u:isLockedDown() or u:isMaelstrommed() or u:isStasised() then
      shouldContinue = true
    end

    -- Ignore the unit if it is in one of the following states
    if u:isLoaded() or not u:isPowered() or u:isStuck() then
      shouldContinue = true
    end

    -- Ignore the unit if it is incomplete or busy constructing
    if not u:isCompleted() or u:isConstructing() then
      shouldContinue = true
    end


    -- Finally make the unit do some stuff!

    if not shouldContinue then
      -- If the unit is a worker unit
      if u:getType():isWorker() then
        -- if our worker is idle
        if u:isIdle() then
          -- Order workers carrying a resource to return them to the center,
          -- otherwise find a mineral patch to harvest.
          if u:isCarryingGas() or u:isCarryingMinerals() then
            u:returnCargo()
          elseif not u:getPowerUp() then  -- The worker cannot harvest anything if it
                                          -- is carrying a powerup such as a flag
            -- Harvest from the nearest mineral patch or gas refinery
            if not u:gather( u:getClosestUnit( function(x) return Filter.IsMineralField(x) or Filter.IsRefinery(x) end )) then
              -- If the call fails, then print the last error message
              print(Broodwar:getLastError())
            end

          end -- closure: has no powerup
        end -- closure: if idle

      elseif u:getType():isResourceDepot() then -- A resource depot is a Command Center, Nexus, or Hatchery

        --print(u:getType():getRace():getSupplyProvider():whatBuilds(), Filter.GetType(u))

        -- Order the depot to construct more workers! But only when it is idle.
        if u:isIdle() and not u:train(u:getType():getRace():getWorker()) then
          -- If that fails, draw the error at the location so that you can visibly see what went wrong!
          -- However, drawing the error once will only appear for a single frame
          -- so create an event that keeps it on the screen for some frames
          local pos = u:getPosition()
          local lastErr = Broodwar:getLastError()
          local action = function() Broodwar:drawTextMap(pos, string.format("%c%s", BWAPI.Text.White, tostring(lastErr))) end
          Broodwar:registerEvent(action,   -- action
                                  nil,    -- condition
                                  Broodwar:getLatencyFrames())  -- frames to run

          -- Retrieve the supply provider type in the case that we have run out of supplies
          local supplyProviderType = u:getType():getRace():getSupplyProvider()

          -- If we are supply blocked and haven't tried constructing more recently
          if lastErr == BWAPI.Errors.Insufficient_Supply and
                lastChecked + 400 < Broodwar:getFrameCount() and
                Broodwar:self():incompleteUnitCount(supplyProviderType) == 0
          then
            lastChecked = Broodwar:getFrameCount()

            -- Retrieve a unit that is capable of constructing the supply needed
            local supplyBuilder = u:getClosestUnit(function(x)
              local supplyProviderBuilder = supplyProviderType:whatBuilds()
              return Filter.GetType(x) == supplyProviderBuilder and
                     (Filter.IsIdle(x) or Filter.IsGatheringMinerals(x)) and
                     Filter.IsOwned(x)
            end)
            -- If a unit was found
            if supplyBuilder then
              if supplyProviderType:isBuilding() then
                local targetBuildLocation = Broodwar:getBuildLocation(supplyProviderType, supplyBuilder:getTilePosition())
                if targetBuildLocation then
                  -- Register an event that draws the target build location
                  local drawBuildLocation = function()
                    Broodwar:drawBoxMap(
                      BWAPI.Position(targetBuildLocation),
                      BWAPI.Position(targetBuildLocation + supplyProviderType:tileSize()),
                      BWAPI.Colors.Blue
                    )
                  end
                  Broodwar:registerEvent(drawBuildLocation,
                                          nil,  -- condition
                                          supplyProviderType:buildTime() + 100 )  -- frames to run

                  -- Order the builder to construct the supply structure
                  supplyBuilder:build( supplyProviderType, targetBuildLocation )
                end
              else
                -- Train the supply provider (Overlord) if the provider is not a structure
                supplyBuilder:train( supplyProviderType )
              end
            end -- closure: supplyBuilder is valid
          end -- closure: insufficient supply
        end -- closure: failed to train idle unit

      end
    end
  end -- closure: unit iterator
end

function BWAPI.onSendText(text)
  -- Send the text to the game if it is not being processed.
  Broodwar:sendText(text)
end

function BWAPI.onReceiveText(player, text)
  -- Parse the received text
  print(string.format("%s said \"%s\"", player:getName(), text))
end

function BWAPI.onPlayerLeft(player)
  -- Interact verbally with the other players in the game by
  -- announcing that the other player has left.
  Broodwar:sendText(string.format("Goodbye %s!", player:getName()))
end

function BWAPI.onNukeDetect(target)

  -- Check if the target is a valid position
  if target then
    -- if so, print the location of the nuclear strike target
    print("Nuclear Launch Detected at " .. tostring(target))
  else
    -- Otherwise, ask other players where the nuke is!
    Broodwar:sendText("Where's the nuke?")
  end

  -- You can also retrieve all the nuclear missile targets using Broodwar:getNukeDots()!
end

function BWAPI.onUnitDiscover(unit)

end

function BWAPI.onUnitEvade(unit)

end

function BWAPI.onUnitShow(unit)

end

function BWAPI.onUnitHide(unit)

end

function BWAPI.onUnitCreate(unit)
  if Broodwar:isReplay() then
    -- if we are in a replay, then we will print out the build order of the structures
    if unit:getType():isBuilding() and not unit:getPlayer():isNeutral() then
      local seconds = Broodwar:getFrameCount()/24
      local minutes = seconds/60
      seconds = seconds % 60
      Broodwar:sendText(string.format("%.2d:%.2d: %s creates a %s", minutes, seconds, unit:getPlayer():getName(), unit:getType()))
    end
  end
end

function BWAPI.onUnitDestroy(unit)

end

function BWAPI.onUnitMorph(unit)
  if Broodwar:isReplay() then
    -- if we are in a replay, then we will print out the build order of the structures
    if unit:getType():isBuilding() and not unit:getPlayer():isNeutral() then
      local seconds = Broodwar:getFrameCount()/24
      local minutes = seconds/60
      seconds = seconds % 60
      Broodwar:sendText(string.format("%.2d:%.2d: %s morphs a %s", minutes, seconds, unit:getPlayer():getName(), unit:getType()))
    end
  end
end

function BWAPI.onUnitRenegade(unit)

end

function BWAPI.onSaveGame(gameName)
  print(string.format("The game was saved to \"%s\"", gameName))
end

function BWAPI.onUnitComplete(unit)

end
