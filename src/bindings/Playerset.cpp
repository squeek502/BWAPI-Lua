#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPlayerset(sol::table module)
	{
		module.new_simple_usertype<Playerset>("Playerset",
			"new", sol::nil,
			"iterator", [](Playerset* set) {
			static std::list<Player>::const_iterator it;
			it = set->begin();
			return sol::as_function([set](sol::this_state s) {
				if (it != set->end())
				{
					Player ret = *it;
					++it;
					return sol::make_object(s, ret);
				}
				return sol::make_object(s, sol::nil);
			});
		}
		);
	}
}