#include <sol.hpp>
#include <BWAPI.h>
#include "CommonBindings.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindError(sol::table module)
	{
		auto error = module.create_simple_usertype<Error>();
		bindType<Error>(error);
		module.set_usertype("Error", error);

		auto errors = module.create_named("Errors",
			"Unit_Does_Not_Exist", &Errors::Unit_Does_Not_Exist,
			"Unit_Not_Visible", &Errors::Unit_Not_Visible,
			"Unit_Not_Owned", &Errors::Unit_Not_Owned,
			"Unit_Busy", &Errors::Unit_Busy,
			"Incompatible_UnitType", &Errors::Incompatible_UnitType,
			"Incompatible_TechType", &Errors::Incompatible_TechType,
			"Incompatible_State", &Errors::Incompatible_State,
			"Already_Researched", &Errors::Already_Researched,
			"Fully_Upgraded", &Errors::Fully_Upgraded,
			"Currently_Researching", &Errors::Currently_Researching,
			"Currently_Upgrading", &Errors::Currently_Upgrading,
			"Insufficient_Minerals", &Errors::Insufficient_Minerals,
			"Insufficient_Gas", &Errors::Insufficient_Gas,
			"Insufficient_Supply", &Errors::Insufficient_Supply,
			"Insufficient_Energy", &Errors::Insufficient_Energy,
			"Insufficient_Tech", &Errors::Insufficient_Tech,
			"Insufficient_Ammo", &Errors::Insufficient_Ammo,
			"Insufficient_Space", &Errors::Insufficient_Space,
			"Invalid_Tile_Position", &Errors::Invalid_Tile_Position,
			"Unbuildable_Location", &Errors::Unbuildable_Location,
			"Unreachable_Location", &Errors::Unreachable_Location,
			"Out_Of_Range", &Errors::Out_Of_Range,
			"Unable_To_Hit", &Errors::Unable_To_Hit,
			"Access_Denied", &Errors::Access_Denied,
			"File_Not_Found", &Errors::File_Not_Found,
			"Invalid_Parameter", &Errors::Invalid_Parameter,
			"None", &Errors::None,
			"Unknown", &Errors::Unknown
		);
		errors.new_enum("Enum",
			"Unit_Does_Not_Exist", Errors::Enum::Unit_Does_Not_Exist,
			"Unit_Not_Visible", Errors::Enum::Unit_Not_Visible,
			"Unit_Not_Owned", Errors::Enum::Unit_Not_Owned,
			"Unit_Busy", Errors::Enum::Unit_Busy,
			"Incompatible_UnitType", Errors::Enum::Incompatible_UnitType,
			"Incompatible_TechType", Errors::Enum::Incompatible_TechType,
			"Incompatible_State", Errors::Enum::Incompatible_State,
			"Already_Researched", Errors::Enum::Already_Researched,
			"Fully_Upgraded", Errors::Enum::Fully_Upgraded,
			"Currently_Researching", Errors::Enum::Currently_Researching,
			"Currently_Upgrading", Errors::Enum::Currently_Upgrading,
			"Insufficient_Minerals", Errors::Enum::Insufficient_Minerals,
			"Insufficient_Gas", Errors::Enum::Insufficient_Gas,
			"Insufficient_Supply", Errors::Enum::Insufficient_Supply,
			"Insufficient_Energy", Errors::Enum::Insufficient_Energy,
			"Insufficient_Tech", Errors::Enum::Insufficient_Tech,
			"Insufficient_Ammo", Errors::Enum::Insufficient_Ammo,
			"Insufficient_Space", Errors::Enum::Insufficient_Space,
			"Invalid_Tile_Position", Errors::Enum::Invalid_Tile_Position,
			"Unbuildable_Location", Errors::Enum::Unbuildable_Location,
			"Unreachable_Location", Errors::Enum::Unreachable_Location,
			"Out_Of_Range", Errors::Enum::Out_Of_Range,
			"Unable_To_Hit", Errors::Enum::Unable_To_Hit,
			"Access_Denied", Errors::Enum::Access_Denied,
			"File_Not_Found", Errors::Enum::File_Not_Found,
			"Invalid_Parameter", Errors::Enum::Invalid_Parameter,
			"None", Errors::Enum::None,
			"Unknown", Errors::Enum::Unknown,
			"MAX", Errors::Enum::MAX
		);
	}
}