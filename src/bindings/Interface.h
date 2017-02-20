#pragma once

#include <sol.hpp>
#include <BWAPI/Interface.h>
#include <sstream>

namespace BWAPI_Lua
{
	static const char* CLIENT_INFO_PROXY_TABLE = "___BWAPI_ClientInfo";

	template <typename InterfaceClass>
	inline sol::table getClientInfo(InterfaceClass& inst, sol::this_state state)
	{
		std::string classKey = typeid(InterfaceClass).name();
		std::stringstream ss;
		ss << (void*)(&inst);
		std::string instKey = ss.str();

		sol::state_view lua(state);

		if (!lua[CLIENT_INFO_PROXY_TABLE].valid())
			lua[CLIENT_INFO_PROXY_TABLE] = lua.create_table();
		if (!lua[CLIENT_INFO_PROXY_TABLE][classKey].valid())
			lua[CLIENT_INFO_PROXY_TABLE][classKey] = lua.create_table();
		if (!lua[CLIENT_INFO_PROXY_TABLE][classKey][instKey].valid())
			lua[CLIENT_INFO_PROXY_TABLE][classKey][instKey] = lua.create_table();

		return lua[CLIENT_INFO_PROXY_TABLE][classKey][instKey];
	}

	template <typename InterfaceClass>
	inline sol::simple_usertype<InterfaceClass>& bindInterface(sol::simple_usertype<InterfaceClass>& userType)
	{
		userType.set("clientInfo", sol::readonly_property(&getClientInfo<InterfaceClass>));

		userType.set("registerEvent", sol::overload(
			[](InterfaceClass* inst, const sol::function &action)
			{
				return inst->registerEvent(sol::protected_function(action));
			},
			[](InterfaceClass* inst, const sol::function &action, const sol::function& condition)
			{
				if (condition.valid())
					return inst->registerEvent(sol::protected_function(action), sol::protected_function(condition));
				else
					return inst->registerEvent(sol::protected_function(action), nullptr);
			},
			[](InterfaceClass* inst, const sol::function &action, const sol::function& condition, int timesToRun)
			{
				if (condition.valid())
					return inst->registerEvent(sol::protected_function(action), sol::protected_function(condition), timesToRun);
				else
					return inst->registerEvent(sol::protected_function(action), nullptr, timesToRun);
			},
			[](InterfaceClass* inst, const sol::function &action, const sol::function& condition, int timesToRun, int framesToCheck)
			{
				if (condition.valid())
					return inst->registerEvent(sol::protected_function(action), sol::protected_function(condition), timesToRun, framesToCheck);
				else
					return inst->registerEvent(sol::protected_function(action), nullptr, timesToRun, framesToCheck);
			}
		));
		return userType;
	}
}