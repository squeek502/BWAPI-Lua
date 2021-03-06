#include <sol.hpp>
#include <BWAPI.h>
#include "SetContainer.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindBulletset(sol::table module)
	{
		auto bulletset = module.create_simple_usertype<Bulletset>();
		bindSetContainer<Bulletset, Bullet>(bulletset);
		bindIsInstance(bulletset);
		module.set_usertype("Bulletset", bulletset);
	}
}