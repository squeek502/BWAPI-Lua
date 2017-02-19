#pragma once

#include <sol.hpp>

namespace BWAPI_Lua
{
	template <typename PointClass>
	inline sol::simple_usertype<PointClass>& bindPoint(sol::simple_usertype<PointClass>& userType)
	{
		auto constructors = sol::constructors<sol::types<>, sol::types<int, int>, sol::types<const Position&>, sol::types<const TilePosition&>, sol::types<const WalkPosition&>>();
		userType.set(sol::meta_function::construct, constructors);
		userType.set(sol::call_constructor, constructors);
		userType.set("x", &PointClass::x);
		userType.set("y", &PointClass::y);
		userType.set("isValid", &PointClass::isValid);
		userType.set("makeValid", &PointClass::makeValid);
		userType.set("setMin", sol::overload(static_cast<PointClass& (PointClass::*)(int, int)>(&PointClass::setMin), static_cast<PointClass& (PointClass::*)(const PointClass&)>(&PointClass::setMin)));
		userType.set("setMax", sol::overload(static_cast<PointClass& (PointClass::*)(int, int)>(&PointClass::setMax), static_cast<PointClass& (PointClass::*)(const PointClass&)>(&PointClass::setMax)));
		userType.set("getDistance", &PointClass::getDistance);
		userType.set("getLength", &PointClass::getLength);
		userType.set("getApproxDistance", &PointClass::getApproxDistance);
		userType.set(sol::meta_function::addition, &PointClass::operator+);
		userType.set(sol::meta_function::subtraction, &PointClass::operator-);
		userType.set(sol::meta_function::equal_to, &PointClass::operator==);
		userType.set(sol::meta_function::less_than, &PointClass::operator<);
		userType.set(sol::meta_function::multiplication, &PointClass::operator*);
		userType.set(sol::meta_function::division, &PointClass::operator/);
		userType.set(sol::meta_function::modulus, &PointClass::operator%);
		userType.set(sol::meta_function::to_string, [](const PointClass& pt) { std::stringstream ss; ss << pt; return ss.str(); });
		return userType;
	}
}