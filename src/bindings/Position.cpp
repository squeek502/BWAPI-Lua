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
			sol::constructors<sol::types<>, sol::types<int, int>, sol::types<const TilePosition&>, sol::types<const WalkPosition&>>(),
			sol::meta_function::addition, &Position::operator+,
			sol::meta_function::subtraction, &Position::operator-,
			sol::meta_function::to_string, [](const Position& pt) { std::stringstream ss; ss << pt; return ss.str(); }
		);
		module.new_simple_usertype<WalkPosition>("WalkPosition",
			sol::constructors<sol::types<>, sol::types<int, int>, sol::types<const Position&>, sol::types<const TilePosition&>>(),
			sol::meta_function::addition, &WalkPosition::operator+,
			sol::meta_function::subtraction, &WalkPosition::operator-,
			sol::meta_function::to_string, [](const WalkPosition& pt) { std::stringstream ss; ss << pt; return ss.str(); }
		);
		module.new_simple_usertype<TilePosition>("TilePosition",
			sol::constructors<sol::types<>, sol::types<int, int>, sol::types<const Position&>, sol::types<const WalkPosition&>>(),
			sol::meta_function::addition, &TilePosition::operator+,
			sol::meta_function::subtraction, &TilePosition::operator-,
			sol::meta_function::to_string, [](const TilePosition& pt) { std::stringstream ss; ss << pt; return ss.str(); }
		);
	}
}