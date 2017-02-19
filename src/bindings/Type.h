#pragma once

#include <sol.hpp>

namespace BWAPI_Lua
{
	template <typename TypeClass>
	inline sol::simple_usertype<TypeClass>& bindType(sol::simple_usertype<TypeClass>& userType)
	{
		auto constructors = sol::constructors<sol::types<int>>();
		userType.set(sol::meta_function::construct, constructors);
		userType.set(sol::call_constructor, constructors);
		userType.set("isValid", &TypeClass::isValid);
		userType.set("getID", &TypeClass::getID);
		userType.set("getName", &TypeClass::getName);
		userType.set(sol::meta_function::to_string, &TypeClass::toString);
		userType.set(sol::meta_function::equal_to, [](const TypeClass& a, const TypeClass& b) { return a == b; });
		return userType;
	}
}