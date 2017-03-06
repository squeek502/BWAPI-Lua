#include <sol.hpp>
#include <BWAPI.h>
#include "SetContainer.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindRegionset(sol::table module)
	{
		sol::simple_usertype<Regionset> userTypeRegionset = module.create_simple_usertype<Regionset>(
			"getUnits", sol::overload(
				[](const Regionset& regionset) { return regionset.getUnits(); },
				[](const Regionset& regionset, const sol::function& pred)
				{
					UnitFilter filter(nullptr);
					if (pred.valid())
						filter = UnitFilter(sol::protected_function(pred));
					return regionset.getUnits(filter);
				},
				&Regionset::getUnits
			),
			"getCenter", &Regionset::getCenter
		);
		bindSetContainer<Regionset, Region>(userTypeRegionset);
		bindIsInstance(userTypeRegionset);
		module.set_usertype("Regionset", userTypeRegionset);
	}
}