#pragma once

namespace BWAPI_Lua
{
	inline int toLuaTrainingSlot(int cTrainingSlot)
	{
		if (cTrainingSlot >= 0)
			return cTrainingSlot + 1;

		return cTrainingSlot;
	}

	inline int toActualTrainingSlot(int luaTrainingSlot)
	{
		if (luaTrainingSlot >= 1)
			return luaTrainingSlot - 1;

		return luaTrainingSlot;
	}
}