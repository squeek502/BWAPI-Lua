-- cwd is the StarCraft .exe directory, so this is relative to that
-- make sure that the target directory exists!
local logFilePath = "bwapi-data/lua-ai-example-error.log"

function BWAPI.onError(msg)
  -- print to the screen
  print(msg)

  -- RFC1123 date
  local fmt = "!%a, %d %b %Y %T GMT"
  local date = os.date(fmt)

  -- log to file
  local log = io.open(logFilePath, "a")
  local str = string.format("[%s] %s\n", date, msg)
  log:write(str)
  log:close()
end

function BWAPI.onStart()
  -- lets trigger an error!
  local missing = nil
  print(missing.index)
end
