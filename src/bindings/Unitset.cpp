#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnitset(sol::table module)
	{
		module.new_simple_usertype<Unitset>("Unitset",
			"new", sol::nil,
			"iterator", [](Unitset* set) {
			static std::list<Unit>::const_iterator it;
			it = set->begin();
			return sol::as_function([set](sol::this_state s) {
				if (it != set->end())
				{
					Unit ret = *it;
					++it;
					return sol::make_object(s, ret);
				}
				return sol::make_object(s, sol::nil);
			});
		}
		);
	}
}