#pragma once

#include <sol.hpp>

namespace BWAPI_Lua
{
	template <typename Type>
	inline sol::simple_usertype<Type>& bindIsInstance(sol::simple_usertype<Type>& userType)
	{
		userType.set("isInstance", [](sol::stack_object inst) { return inst.is<Type>(); });
		return userType;
	}
}