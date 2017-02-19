#include <sol.hpp>
#include <BWAPI.h>
#include "CommonBindings.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPlayerset(sol::table module)
	{
		auto userTypePlayerset = module.create_simple_usertype<Playerset>();
		bindSetContainer<Playerset, Player>(userTypePlayerset);
		module.set_usertype("Playerset", userTypePlayerset);
		/*
		module.new_simple_usertype<Playerset>("Playerset",
			sol::meta_function::construct, sol::nil,
			"iterator", [](Playerset* set)
			{
				static std::list<Player>::const_iterator it;
				it = set->begin();
				return sol::as_function([set](sol::this_state s)
				{
					if (it != set->end())
					{
						Player ret = *it;
						++it;
						return sol::make_object(s, ret);
					}
					return sol::make_object(s, sol::nil);
				});
			},
			sol::meta_function::length, &Playerset::count
		);
		*/
	}
}