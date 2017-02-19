#include <sol.hpp>
#include <BWAPI.h>
#include "CommonBindings.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnitSizeType(sol::table module)
	{
		auto unitSizeType = module.create_simple_usertype<UnitSizeType>();
		bindType<UnitSizeType>(unitSizeType);
		module.set_usertype("UnitSizeType", unitSizeType);

		auto unitSizeTypeSet = module.create_simple_usertype<UnitSizeType::set>();
		bindSetContainer<UnitSizeType::set, UnitSizeType>(unitSizeTypeSet);
		module.set_usertype("UnitSizeTypeset", unitSizeTypeSet);

		auto unitSizeTypes = module.create_named("UnitSizeTypes");
		unitSizeTypes["Independent"] = &UnitSizeTypes::Independent;
		unitSizeTypes["Small"] = &UnitSizeTypes::Small;
		unitSizeTypes["Medium"] = &UnitSizeTypes::Medium;
		unitSizeTypes["Large"] = &UnitSizeTypes::Large;
		unitSizeTypes["None"] = &UnitSizeTypes::None;
		unitSizeTypes["Unknown"] = &UnitSizeTypes::Unknown;

		auto unitSizeTypesEnum = unitSizeTypes.create_named("Enum");
		unitSizeTypesEnum["Independent"] = UnitSizeTypes::Enum::Independent;
		unitSizeTypesEnum["Small"] = UnitSizeTypes::Enum::Small;
		unitSizeTypesEnum["Medium"] = UnitSizeTypes::Enum::Medium;
		unitSizeTypesEnum["Large"] = UnitSizeTypes::Enum::Large;
		unitSizeTypesEnum["None"] = UnitSizeTypes::Enum::None;
		unitSizeTypesEnum["Unknown"] = UnitSizeTypes::Enum::Unknown;
		unitSizeTypesEnum["MAX"] = UnitSizeTypes::Enum::MAX;
	}
}