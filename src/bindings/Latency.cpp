#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindLatency(sol::table module)
	{
		module.new_enum("Latency",
			"SinglePlayer", Latency::SinglePlayer,
			"LanLow", Latency::LanLow,
			"LanMedium", Latency::LanMedium,
			"LanHigh", Latency::LanHigh,
			"BattlenetLow", Latency::BattlenetLow,
			"BattlenetMedium", Latency::BattlenetMedium,
			"BattlenetHigh", Latency::BattlenetHigh
		);
	}
}