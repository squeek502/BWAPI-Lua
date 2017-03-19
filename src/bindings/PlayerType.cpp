#include <sol.hpp>
#include <BWAPI.h>
#include "Type.h"
#include "SetContainer.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPlayerType(sol::table module)
	{
		auto playerType = module.create_simple_usertype<PlayerType>(
			"isLobbyType", &PlayerType::isLobbyType,
			"isGameType", &PlayerType::isGameType
		);
		bindType(playerType);
		bindIsInstance(playerType);
		module.set_usertype("PlayerType", playerType);

		auto playerTypeSet = module.create_simple_usertype<PlayerType::set>();
		bindSetContainer<PlayerType::set, PlayerType>(playerTypeSet);
		bindIsInstance(playerTypeSet);
		module.set_usertype("PlayerTypeset", playerTypeSet);

		auto playerTypes = module.create_named("PlayerTypes");
		playerTypes["allPlayerTypes"] = &PlayerTypes::allPlayerTypes;
		playerTypes["None"] = &PlayerTypes::None;
		playerTypes["Computer"] = &PlayerTypes::Computer;
		playerTypes["Player"] = &PlayerTypes::Player;
		playerTypes["RescuePassive"] = &PlayerTypes::RescuePassive;
		playerTypes["EitherPreferComputer"] = &PlayerTypes::EitherPreferComputer;
		playerTypes["EitherPreferHuman"] = &PlayerTypes::EitherPreferHuman;
		playerTypes["Neutral"] = &PlayerTypes::Neutral;
		playerTypes["Closed"] = &PlayerTypes::Closed;
		playerTypes["PlayerLeft"] = &PlayerTypes::PlayerLeft;
		playerTypes["ComputerLeft"] = &PlayerTypes::ComputerLeft;
		playerTypes["Unknown"] = &PlayerTypes::Unknown;

		auto playerTypesEnum = playerTypes.create_named("Enum");
		playerTypesEnum["None"] = PlayerTypes::Enum::None;
		playerTypesEnum["Computer"] = PlayerTypes::Enum::Computer;
		playerTypesEnum["Player"] = PlayerTypes::Enum::Player;
		playerTypesEnum["RescuePassive"] = PlayerTypes::Enum::RescuePassive;
		playerTypesEnum["RescueActive"] = PlayerTypes::Enum::RescueActive;
		playerTypesEnum["EitherPreferComputer"] = PlayerTypes::Enum::EitherPreferComputer;
		playerTypesEnum["EitherPreferHuman"] = PlayerTypes::Enum::EitherPreferHuman;
		playerTypesEnum["Neutral"] = PlayerTypes::Enum::Neutral;
		playerTypesEnum["Closed"] = PlayerTypes::Enum::Closed;
		playerTypesEnum["Observer"] = PlayerTypes::Enum::Observer;
		playerTypesEnum["PlayerLeft"] = PlayerTypes::Enum::PlayerLeft;
		playerTypesEnum["ComputerLeft"] = PlayerTypes::Enum::ComputerLeft;
		playerTypesEnum["Unknown"] = PlayerTypes::Enum::Unknown;
		playerTypesEnum["MAX"] = PlayerTypes::Enum::MAX;
	}
}