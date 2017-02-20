#include <sol.hpp>
#include <BWAPI.h>
#include "Point.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPosition(sol::table module)
	{
		module["POSITION_SCALE"] = POSITION_SCALE;
		module["WALKPOSITION_SCALE"] = WALKPOSITION_SCALE;
		module["TILEPOSITION_SCALE"] = TILEPOSITION_SCALE;

		auto position = module.create_simple_usertype<Position>();
		bindPoint<Position>(position);
		module.set_usertype("Position", position);

		auto walkPosition = module.create_simple_usertype<WalkPosition>();
		bindPoint<WalkPosition>(walkPosition);
		module.set_usertype("WalkPosition", walkPosition);

		auto tilePosition = module.create_simple_usertype<TilePosition>();
		bindPoint<TilePosition>(tilePosition);
		module.set_usertype("TilePosition", tilePosition);

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