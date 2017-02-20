#include <sol.hpp>
#include <BWAPI.h>
#include "Type.h"
#include "SetContainer.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnitCommandType(sol::table module)
	{
		auto unitCommandType = module.create_simple_usertype<UnitCommandType>();
		bindType(unitCommandType);
		module.set_usertype("UnitCommandType", unitCommandType);

		auto unitCommandTypeSet = module.create_simple_usertype<UnitCommandType::set>();
		bindSetContainer<UnitCommandType::set, UnitCommandType>(unitCommandTypeSet);
		module.set_usertype("UnitCommandTypeset", unitCommandTypeSet);

		auto unitCommandTypes = module.create_named("UnitCommandTypes");
		unitCommandTypes["Attack_Move"] = UnitCommandTypes::Attack_Move;
		unitCommandTypes["Attack_Unit"] = UnitCommandTypes::Attack_Unit;
		unitCommandTypes["Build"] = UnitCommandTypes::Build;
		unitCommandTypes["Build_Addon"] = UnitCommandTypes::Build_Addon;
		unitCommandTypes["Train"] = UnitCommandTypes::Train;
		unitCommandTypes["Morph"] = UnitCommandTypes::Morph;
		unitCommandTypes["Research"] = UnitCommandTypes::Research;
		unitCommandTypes["Upgrade"] = UnitCommandTypes::Upgrade;
		unitCommandTypes["Set_Rally_Position"] = UnitCommandTypes::Set_Rally_Position;
		unitCommandTypes["Set_Rally_Unit"] = UnitCommandTypes::Set_Rally_Unit;
		unitCommandTypes["Move"] = UnitCommandTypes::Move;
		unitCommandTypes["Patrol"] = UnitCommandTypes::Patrol;
		unitCommandTypes["Hold_Position"] = UnitCommandTypes::Hold_Position;
		unitCommandTypes["Stop"] = UnitCommandTypes::Stop;
		unitCommandTypes["Follow"] = UnitCommandTypes::Follow;
		unitCommandTypes["Gather"] = UnitCommandTypes::Gather;
		unitCommandTypes["Return_Cargo"] = UnitCommandTypes::Return_Cargo;
		unitCommandTypes["Repair"] = UnitCommandTypes::Repair;
		unitCommandTypes["Burrow"] = UnitCommandTypes::Burrow;
		unitCommandTypes["Unburrow"] = UnitCommandTypes::Unburrow;
		unitCommandTypes["Cloak"] = UnitCommandTypes::Cloak;
		unitCommandTypes["Decloak"] = UnitCommandTypes::Decloak;
		unitCommandTypes["Siege"] = UnitCommandTypes::Siege;
		unitCommandTypes["Unsiege"] = UnitCommandTypes::Unsiege;
		unitCommandTypes["Lift"] = UnitCommandTypes::Lift;
		unitCommandTypes["Land"] = UnitCommandTypes::Land;
		unitCommandTypes["Load"] = UnitCommandTypes::Load;
		unitCommandTypes["Unload"] = UnitCommandTypes::Unload;
		unitCommandTypes["Unload_All"] = UnitCommandTypes::Unload_All;
		unitCommandTypes["Unload_All_Position"] = UnitCommandTypes::Unload_All_Position;
		unitCommandTypes["Right_Click_Position"] = UnitCommandTypes::Right_Click_Position;
		unitCommandTypes["Right_Click_Unit"] = UnitCommandTypes::Right_Click_Unit;
		unitCommandTypes["Halt_Construction"] = UnitCommandTypes::Halt_Construction;
		unitCommandTypes["Cancel_Construction"] = UnitCommandTypes::Cancel_Construction;
		unitCommandTypes["Cancel_Addon"] = UnitCommandTypes::Cancel_Addon;
		unitCommandTypes["Cancel_Train"] = UnitCommandTypes::Cancel_Train;
		unitCommandTypes["Cancel_Train_Slot"] = UnitCommandTypes::Cancel_Train_Slot;
		unitCommandTypes["Cancel_Morph"] = UnitCommandTypes::Cancel_Morph;
		unitCommandTypes["Cancel_Research"] = UnitCommandTypes::Cancel_Research;
		unitCommandTypes["Cancel_Upgrade"] = UnitCommandTypes::Cancel_Upgrade;
		unitCommandTypes["Use_Tech"] = UnitCommandTypes::Use_Tech;
		unitCommandTypes["Use_Tech_Position"] = UnitCommandTypes::Use_Tech_Position;
		unitCommandTypes["Use_Tech_Unit"] = UnitCommandTypes::Use_Tech_Unit;
		unitCommandTypes["Place_COP"] = UnitCommandTypes::Place_COP;
		unitCommandTypes["None"] = UnitCommandTypes::None;
		unitCommandTypes["Unknown"] = UnitCommandTypes::Unknown;

		auto unitCommandTypesEnum = unitCommandTypes.create_named("Enum");
		unitCommandTypesEnum["Attack_Move"] = UnitCommandTypes::Enum::Attack_Move;
		unitCommandTypesEnum["Attack_Unit"] = UnitCommandTypes::Enum::Attack_Unit;
		unitCommandTypesEnum["Build"] = UnitCommandTypes::Enum::Build;
		unitCommandTypesEnum["Build_Addon"] = UnitCommandTypes::Enum::Build_Addon;
		unitCommandTypesEnum["Train"] = UnitCommandTypes::Enum::Train;
		unitCommandTypesEnum["Morph"] = UnitCommandTypes::Enum::Morph;
		unitCommandTypesEnum["Research"] = UnitCommandTypes::Enum::Research;
		unitCommandTypesEnum["Upgrade"] = UnitCommandTypes::Enum::Upgrade;
		unitCommandTypesEnum["Set_Rally_Position"] = UnitCommandTypes::Enum::Set_Rally_Position;
		unitCommandTypesEnum["Set_Rally_Unit"] = UnitCommandTypes::Enum::Set_Rally_Unit;
		unitCommandTypesEnum["Move"] = UnitCommandTypes::Enum::Move;
		unitCommandTypesEnum["Patrol"] = UnitCommandTypes::Enum::Patrol;
		unitCommandTypesEnum["Hold_Position"] = UnitCommandTypes::Enum::Hold_Position;
		unitCommandTypesEnum["Stop"] = UnitCommandTypes::Enum::Stop;
		unitCommandTypesEnum["Follow"] = UnitCommandTypes::Enum::Follow;
		unitCommandTypesEnum["Gather"] = UnitCommandTypes::Enum::Gather;
		unitCommandTypesEnum["Return_Cargo"] = UnitCommandTypes::Enum::Return_Cargo;
		unitCommandTypesEnum["Repair"] = UnitCommandTypes::Enum::Repair;
		unitCommandTypesEnum["Burrow"] = UnitCommandTypes::Enum::Burrow;
		unitCommandTypesEnum["Unburrow"] = UnitCommandTypes::Enum::Unburrow;
		unitCommandTypesEnum["Cloak"] = UnitCommandTypes::Enum::Cloak;
		unitCommandTypesEnum["Decloak"] = UnitCommandTypes::Enum::Decloak;
		unitCommandTypesEnum["Siege"] = UnitCommandTypes::Enum::Siege;
		unitCommandTypesEnum["Unsiege"] = UnitCommandTypes::Enum::Unsiege;
		unitCommandTypesEnum["Lift"] = UnitCommandTypes::Enum::Lift;
		unitCommandTypesEnum["Land"] = UnitCommandTypes::Enum::Land;
		unitCommandTypesEnum["Load"] = UnitCommandTypes::Enum::Load;
		unitCommandTypesEnum["Unload"] = UnitCommandTypes::Enum::Unload;
		unitCommandTypesEnum["Unload_All"] = UnitCommandTypes::Enum::Unload_All;
		unitCommandTypesEnum["Unload_All_Position"] = UnitCommandTypes::Enum::Unload_All_Position;
		unitCommandTypesEnum["Right_Click_Position"] = UnitCommandTypes::Enum::Right_Click_Position;
		unitCommandTypesEnum["Right_Click_Unit"] = UnitCommandTypes::Enum::Right_Click_Unit;
		unitCommandTypesEnum["Halt_Construction"] = UnitCommandTypes::Enum::Halt_Construction;
		unitCommandTypesEnum["Cancel_Construction"] = UnitCommandTypes::Enum::Cancel_Construction;
		unitCommandTypesEnum["Cancel_Addon"] = UnitCommandTypes::Enum::Cancel_Addon;
		unitCommandTypesEnum["Cancel_Train"] = UnitCommandTypes::Enum::Cancel_Train;
		unitCommandTypesEnum["Cancel_Train_Slot"] = UnitCommandTypes::Enum::Cancel_Train_Slot;
		unitCommandTypesEnum["Cancel_Morph"] = UnitCommandTypes::Enum::Cancel_Morph;
		unitCommandTypesEnum["Cancel_Research"] = UnitCommandTypes::Enum::Cancel_Research;
		unitCommandTypesEnum["Cancel_Upgrade"] = UnitCommandTypes::Enum::Cancel_Upgrade;
		unitCommandTypesEnum["Use_Tech"] = UnitCommandTypes::Enum::Use_Tech;
		unitCommandTypesEnum["Use_Tech_Position"] = UnitCommandTypes::Enum::Use_Tech_Position;
		unitCommandTypesEnum["Use_Tech_Unit"] = UnitCommandTypes::Enum::Use_Tech_Unit;
		unitCommandTypesEnum["Place_COP"] = UnitCommandTypes::Enum::Place_COP;
		unitCommandTypesEnum["None"] = UnitCommandTypes::Enum::None;
		unitCommandTypesEnum["Unknown"] = UnitCommandTypes::Enum::Unknown;
		unitCommandTypesEnum["MAX"] = UnitCommandTypes::Enum::MAX;
	}
}