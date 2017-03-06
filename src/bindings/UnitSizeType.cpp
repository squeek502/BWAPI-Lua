#include <sol.hpp>
#include <BWAPI.h>
#include "Type.h"
#include "SetContainer.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnitSizeType(sol::table module)
	{
		sol::simple_usertype<UnitSizeType> unitSizeType = module.create_simple_usertype<UnitSizeType>();
		bindType<UnitSizeType>(unitSizeType);
		bindIsInstance(unitSizeType);
		module.set_usertype("UnitSizeType", unitSizeType);

		sol::simple_usertype<UnitSizeType::set> unitSizeTypeSet = module.create_simple_usertype<UnitSizeType::set>();
		bindSetContainer<UnitSizeType::set, UnitSizeType>(unitSizeTypeSet);
		bindIsInstance(unitSizeTypeSet);
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