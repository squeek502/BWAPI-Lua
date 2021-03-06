#pragma once

#include <sol.hpp>

namespace BWAPI_Lua
{
	// we can use a stateless iterator here because we know the values will only occur once, as
	// SetContainer uses an unordered_set, so we can get the iterator by looking up the current val
	template <typename SetClass, typename ContainedClass>
	inline sol::object statelessSetContainerIterator(const SetClass& set, sol::stack_object currentValue, sol::this_state s)
	{
		std::list<ContainedClass>::const_iterator it;

		if (currentValue.valid())
		{
			it = set.find(currentValue.as<ContainedClass>());
			++it;
		}
		else
			it = set.begin();

		if (it != set.end())
		{
			ContainedClass ret = *it;
			return sol::make_object(s, ret);
		}
		return sol::make_object(s, sol::nil);
	}

	template <typename SetClass, typename ContainedClass>
	inline sol::simple_usertype<SetClass>& bindSetContainer(sol::simple_usertype<SetClass>& userType)
	{
		auto factories = sol::factories(
			[] { return SetClass(); },
			[](const sol::object& obj)
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
		userType.set("iterator", [](const SetClass& set, sol::this_state s)
		{
			return std::make_tuple(sol::as_function(&statelessSetContainerIterator<SetClass, ContainedClass>), set, sol::make_object(s, sol::nil));
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

		auto erase_if = [](SetClass& set, const sol::function& pred)
		{
			UnaryFilter<ContainedClass> filter(nullptr);
			if (pred.valid())
				filter = UnaryFilter<ContainedClass>(sol::protected_function(pred));
			set.erase_if(filter);
		};
		userType.set("erase_if", erase_if);
		userType.set("eraseIf", erase_if); // alias specific to BWAPI-Lua

		// New convenience method specific to BWAPI-Lua
		auto keep_if = [](SetClass& set, const sol::function& pred)
		{
			UnaryFilter<ContainedClass> filter(nullptr);
			if (pred.valid())
				filter = UnaryFilter<ContainedClass>(sol::protected_function(pred));
			set.erase_if(!filter);
		};
		userType.set("keep_if", keep_if);
		userType.set("keepIf", keep_if);
		userType.set("filter", keep_if);

		userType.set("clear", &SetClass::clear);
		userType.set(sol::meta_function::length, &SetClass::size);
		userType.set(sol::meta_function::equal_to, [](const SetClass& a, const SetClass& b) { return a == b; });
		return userType;
	}
}