#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindCoordinateType(sol::table module)
	{
		auto coordType = module.create_named("CoordinateType",
			"None", CoordinateType::None,
			"Screen", CoordinateType::Screen,
			"Map", CoordinateType::Map,
			"Mouse", CoordinateType::Mouse
		);
		coordType.new_enum("Enum",
			"None", CoordinateType::Enum::None,
			"Screen", CoordinateType::Enum::Screen,
			"Map", CoordinateType::Enum::Map,
			"Mouse", CoordinateType::Enum::Mouse
		);
	}
}