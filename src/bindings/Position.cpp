#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPosition(sol::table module)
	{
		module["POSITION_SCALE"] = POSITION_SCALE;
		module["WALKPOSITION_SCALE"] = WALKPOSITION_SCALE;
		module["TILEPOSITION_SCALE"] = TILEPOSITION_SCALE;

		module.new_simple_usertype<Position>("Position",
			sol::meta_function::construct, sol::nil,
			sol::call_constructor, sol::constructors<sol::types<>, sol::types<int, int>, sol::types<const TilePosition&>, sol::types<const WalkPosition&>>(),
			"x", &Position::x,
			"y", &Position::y,
			"isValid", &Position::isValid,
			"makeValid", &Position::makeValid,
			"setMin", sol::overload(static_cast<Position& (Position::*)(int, int)>(&Position::setMin), static_cast<Position& (Position::*)(const Position&)>(&Position::setMin)),
			"setMax", sol::overload(static_cast<Position& (Position::*)(int, int)>(&Position::setMax), static_cast<Position& (Position::*)(const Position&)>(&Position::setMax)),
			"getDistance", &Position::getDistance,
			"getLength", &Position::getLength,
			"getApproxDistance", &Position::getApproxDistance,
			sol::meta_function::addition, &Position::operator+,
			sol::meta_function::subtraction, &Position::operator-,
			sol::meta_function::equal_to, &Position::operator==,
			sol::meta_function::less_than, &Position::operator<,
			sol::meta_function::multiplication, &Position::operator*,
			sol::meta_function::division, &Position::operator/,
			sol::meta_function::modulus, &Position::operator%,
			sol::meta_function::to_string, [](const Position& pt) { std::stringstream ss; ss << pt; return ss.str(); }
		);
		module.new_simple_usertype<WalkPosition>("WalkPosition",
			sol::meta_function::construct, sol::nil,
			sol::call_constructor, sol::constructors<sol::types<>, sol::types<int, int>, sol::types<const Position&>, sol::types<const TilePosition&>>(),
			"x", &WalkPosition::x,
			"y", &WalkPosition::y,
			"isValid", &WalkPosition::isValid,
			"makeValid", &WalkPosition::makeValid,
			"setMin", sol::overload(static_cast<WalkPosition& (WalkPosition::*)(int, int)>(&WalkPosition::setMin), static_cast<WalkPosition& (WalkPosition::*)(const WalkPosition&)>(&WalkPosition::setMin)),
			"setMax", sol::overload(static_cast<WalkPosition& (WalkPosition::*)(int, int)>(&WalkPosition::setMax), static_cast<WalkPosition& (WalkPosition::*)(const WalkPosition&)>(&WalkPosition::setMax)),
			"getDistance", &WalkPosition::getDistance,
			"getLength", &WalkPosition::getLength,
			"getApproxDistance", &WalkPosition::getApproxDistance,
			sol::meta_function::addition, &WalkPosition::operator+,
			sol::meta_function::subtraction, &WalkPosition::operator-,
			sol::meta_function::equal_to, &WalkPosition::operator==,
			sol::meta_function::less_than, &WalkPosition::operator<,
			sol::meta_function::multiplication, &WalkPosition::operator*,
			sol::meta_function::division, &WalkPosition::operator/,
			sol::meta_function::modulus, &WalkPosition::operator%,
			sol::meta_function::to_string, [](const WalkPosition& pt) { std::stringstream ss; ss << pt; return ss.str(); }
		);
		module.new_simple_usertype<TilePosition>("TilePosition",
			sol::meta_function::construct, sol::nil,
			sol::call_constructor, sol::constructors<sol::types<>, sol::types<int, int>, sol::types<const Position&>, sol::types<const WalkPosition&>>(),
			"x", &TilePosition::x,
			"y", &TilePosition::y,
			"isValid", &TilePosition::isValid,
			"makeValid", &TilePosition::makeValid,
			"setMin", sol::overload(static_cast<TilePosition& (TilePosition::*)(int, int)>(&TilePosition::setMin), static_cast<TilePosition& (TilePosition::*)(const TilePosition&)>(&TilePosition::setMin)),
			"setMax", sol::overload(static_cast<TilePosition& (TilePosition::*)(int, int)>(&TilePosition::setMax), static_cast<TilePosition& (TilePosition::*)(const TilePosition&)>(&TilePosition::setMax)),
			"getDistance", &TilePosition::getDistance,
			"getLength", &TilePosition::getLength,
			"getApproxDistance", &TilePosition::getApproxDistance,
			sol::meta_function::addition, &TilePosition::operator+,
			sol::meta_function::subtraction, &TilePosition::operator-,
			sol::meta_function::equal_to, &TilePosition::operator==,
			sol::meta_function::less_than, &TilePosition::operator<,
			sol::meta_function::multiplication, &TilePosition::operator*,
			sol::meta_function::division, &TilePosition::operator/,
			sol::meta_function::modulus, &TilePosition::operator%,
			sol::meta_function::to_string, [](const TilePosition& pt) { std::stringstream ss; ss << pt; return ss.str(); }
		);

		module.create_named("Positions",
			"Invalid", &Positions::Invalid,
			"None", &Positions::None,
			"Origin", &Positions::Origin,
			"Unknown", &Positions::Unknown
		);
		module.create_named("WalkPositions",
			"Invalid", &WalkPositions::Invalid,
			"None", &WalkPositions::None,
			"Origin", &WalkPositions::Origin,
			"Unknown", &WalkPositions::Unknown
		);
		module.create_named("TilePositions",
			"Invalid", &TilePositions::Invalid,
			"None", &TilePositions::None,
			"Origin", &TilePositions::Origin,
			"Unknown", &TilePositions::Unknown
		);
	}
}