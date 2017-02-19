#include <sol.hpp>
#include <BWAPI.h>
#include "BWAPI_Lua.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindDamageType(sol::table module)
	{
		auto damageType = module.create_simple_usertype<DamageType>();
		bindType(damageType);
		module.set_usertype("DamageType", damageType);

		auto damageTypes = module.create_named("DamageTypes",
			"Independent", &DamageTypes::Independent,
			"Explosive", &DamageTypes::Explosive,
			"Concussive", &DamageTypes::Concussive,
			"Normal", &DamageTypes::Normal,
			"Ignore_Armor", &DamageTypes::Ignore_Armor,
			"None", &DamageTypes::None,
			"Unknown", &DamageTypes::Unknown
		);
		damageTypes.new_enum("Enum",
			"Independent", DamageTypes::Enum::Independent,
			"Explosive", DamageTypes::Enum::Explosive,
			"Concussive", DamageTypes::Enum::Concussive,
			"Normal", DamageTypes::Enum::Normal,
			"Ignore_Armor", DamageTypes::Enum::Ignore_Armor,
			"None", DamageTypes::Enum::None,
			"Unknown", DamageTypes::Enum::Unknown,
			"MAX", DamageTypes::Enum::MAX
		);
	}
}