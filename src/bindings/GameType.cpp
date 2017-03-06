#include <sol.hpp>
#include <BWAPI.h>
#include "Type.h"
#include "SetContainer.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindGameType(sol::table module)
	{
		auto gameType = module.create_simple_usertype<GameType>();
		bindType(gameType);
		bindIsInstance(gameType);
		module.set_usertype("GameType", gameType);

		auto gameTypeSet = module.create_simple_usertype<GameType::set>();
		bindSetContainer<GameType::set, GameType>(gameTypeSet);
		bindIsInstance(gameTypeSet);
		module.set_usertype("GameTypeset", gameTypeSet);

		auto gameTypes = module.create_named("GameTypes");
		gameTypes["Melee"] = GameTypes::Melee;
		gameTypes["Free_For_All"] = GameTypes::Free_For_All;
		gameTypes["One_on_One"] = GameTypes::One_on_One;
		gameTypes["Capture_The_Flag"] = GameTypes::Capture_The_Flag;
		gameTypes["Greed"] = GameTypes::Greed;
		gameTypes["Slaughter"] = GameTypes::Slaughter;
		gameTypes["Sudden_Death"] = GameTypes::Sudden_Death;
		gameTypes["Ladder"] = GameTypes::Ladder;
		gameTypes["Use_Map_Settings"] = GameTypes::Use_Map_Settings;
		gameTypes["Team_Melee"] = GameTypes::Team_Melee;
		gameTypes["Team_Free_For_All"] = GameTypes::Team_Free_For_All;
		gameTypes["Team_Capture_The_Flag"] = GameTypes::Team_Capture_The_Flag;
		gameTypes["Top_vs_Bottom"] = GameTypes::Top_vs_Bottom;
		gameTypes["None"] = GameTypes::None;
		gameTypes["Unknown"] = GameTypes::Unknown;

		auto gameTypesEnum = gameTypes.create_named("Enum");
		gameTypesEnum["None"] = GameTypes::Enum::None;
		gameTypesEnum["Custom"] = GameTypes::Enum::Custom;
		gameTypesEnum["Melee"] = GameTypes::Enum::Melee;
		gameTypesEnum["Free_For_All"] = GameTypes::Enum::Free_For_All;
		gameTypesEnum["One_on_One"] = GameTypes::Enum::One_on_One;
		gameTypesEnum["Capture_The_Flag"] = GameTypes::Enum::Capture_The_Flag;
		gameTypesEnum["Greed"] = GameTypes::Enum::Greed;
		gameTypesEnum["Slaughter"] = GameTypes::Enum::Slaughter;
		gameTypesEnum["Sudden_Death"] = GameTypes::Enum::Sudden_Death;
		gameTypesEnum["Ladder"] = GameTypes::Enum::Ladder;
		gameTypesEnum["Use_Map_Settings"] = GameTypes::Enum::Use_Map_Settings;
		gameTypesEnum["Team_Melee"] = GameTypes::Enum::Team_Melee;
		gameTypesEnum["Team_Free_For_All"] = GameTypes::Enum::Team_Free_For_All;
		gameTypesEnum["Team_Capture_The_Flag"] = GameTypes::Enum::Team_Capture_The_Flag;
		gameTypesEnum["Unknown_0x0E"] = GameTypes::Enum::Unknown_0x0E;
		gameTypesEnum["Top_vs_Bottom"] = GameTypes::Enum::Top_vs_Bottom;
		gameTypesEnum["Iron_Man_Ladder"] = GameTypes::Enum::Iron_Man_Ladder;

		gameTypesEnum["Pro_Gamer_League"] = GameTypes::Enum::Pro_Gamer_League;
		gameTypesEnum["Unknown"] = GameTypes::Enum::Unknown;
		gameTypesEnum["MAX"] = GameTypes::Enum::MAX;
	}
}