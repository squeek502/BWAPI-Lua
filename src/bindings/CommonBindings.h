#pragma once

#include <sol.hpp>

template <typename SetClass, typename ContainedClass>
sol::simple_usertype<SetClass>& bindSetContainer(sol::simple_usertype<SetClass>& userType)
{
	auto factories = sol::factories(
		[] { return SetClass(); },
		[](sol::object obj)
		{
			if (obj.get_type() == sol::type::table)
			{
				auto tbl = obj.as<sol::table>();
				SetClass set = SetClass();
				for (auto v : tbl)
				{
					if (v.second.valid() && v.second.is<ContainedClass>())
					{
						set.insert(v.second.as<ContainedClass>());
					}
				}
				return set;
			}
			else if (obj.is<SetClass>())
			{
				return SetClass(obj.as<SetClass>());
			}
			else
			{
				return SetClass();
			}
		}
	);
	userType.set(sol::meta_function::construct, factories);
	userType.set(sol::call_constructor, factories);
	userType.set("iterator", [](const SetClass& set)
	{
		static std::list<ContainedClass>::const_iterator it;
		it = set.begin();
		return sol::as_function([&set](sol::this_state s)
		{
			if (it != set.end())
			{
				ContainedClass ret = *it;
				++it;
				return sol::make_object(s, ret);
			}
			return sol::make_object(s, sol::nil);
		});
	});
	userType.set("asTable", [](const SetClass& set, sol::this_state s)
	{
		return sol::as_table(set);
	});
	userType.set("count", &SetClass::count);
	userType.set("size", &SetClass::size);
	userType.set("contains", &SetClass::contains);
	userType.set("empty", &SetClass::empty);
	userType.set("insert", [](SetClass& set, const ContainedClass& val)
	{
		set.insert(val);
	});
	userType.set("erase", sol::resolve<SetClass::size_type(const ContainedClass&)>(&SetClass::erase));
	userType.set("clear", &SetClass::clear);
	userType.set(sol::meta_function::length, &SetClass::size);
	return userType;
}

template <typename TypeClass>
sol::simple_usertype<TypeClass>& bindType(sol::simple_usertype<TypeClass>& userType)
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