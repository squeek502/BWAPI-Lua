#pragma once
#include <sol.hpp>
#include "Point.h"
#include "SetContainer.h"
#include "Type.h"

namespace BWAPI_Lua
{
	void bindGame(sol::table module);
	void bindUnit(sol::table module);
	void bindFlag(sol::table module);
	void bindDamageType(sol::table module);
	void bindUnitType(sol::table module);
	void bindColor(sol::table module);
	void bindError(sol::table module);
	void bindRace(sol::table module);
	void bindPlayer(sol::table module);
	void bindPlayerset(sol::table module);
	void bindUnitset(sol::table module);
	void bindFilters(sol::table module);
	void bindPosition(sol::table module);
	void bindTechType(sol::table module);
	void bindUpgradeType(sol::table module);
	void bindUnitSizeType(sol::table module);
	void bindWeaponType(sol::table module);
	void bindExplosionType(sol::table module);
	void bindForceset(sol::table module);
	void bindForce(sol::table module);
	void bindBulletType(sol::table module);
	void bindGameType(sol::table module);
	void bindOrder(sol::table module);
	void bindPlayerType(sol::table module);
	void bindRegion(sol::table module);
	void bindRegionset(sol::table module);
	void bindUnitCommand(sol::table module);
	void bindUnitCommandType(sol::table module);
	void bindCoordinateType(sol::table module);
	void bindBullet(sol::table module);
	void bindBulletset(sol::table module);
	void bindInput(sol::table module);
	void bindLatency(sol::table module);

	sol::table requireBWAPI(sol::state_view& s);
	sol::table openBWAPI(sol::this_state s);
}