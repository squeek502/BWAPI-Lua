-- very basic REPL using the text entered by the client
-- any syntax/execution errors are handled by the default error handler,

function BWAPI.onStart()
  BWAPI.Broodwar:enableFlag(BWAPI.Flag.UserInput)
  print("Anything you type will be executed as Lua!")
end

function BWAPI.onSendText(text)
  -- execute the text as Lua and print the result
  local fn = assert(loadstring(text))
  local ret = {fn()}
  if #ret > 0 then
    print(unpack(ret))
  end
end
