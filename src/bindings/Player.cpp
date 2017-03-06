#include <sol.hpp>
#include <BWAPI.h>
#include "Interface.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindPlayer(sol::table module)
	{
		sol::simple_usertype<PlayerInterface> player = module.create_simple_usertype<PlayerInterface>(
			sol::meta_function::construct, sol::no_constructor,
			sol::meta_function::to_string, &PlayerInterface::getName,
			sol::meta_function::equal_to, [](PlayerInterface* a, PlayerInterface* b) { return a->getID() == b->getID(); }
		);
		player.set("getID", &PlayerInterface::getID);
		player.set("getName", &PlayerInterface::getName);
		player.set("getUnits", &PlayerInterface::getUnits);
		player.set("getRace", &PlayerInterface::getRace);
		player.set("getType", &PlayerInterface::getType);
		player.set("getForce", &PlayerInterface::getForce);
		player.set("isAlly", &PlayerInterface::isAlly);
		player.set("isEnemy", &PlayerInterface::isEnemy);
		player.set("isNeutral", &PlayerInterface::isNeutral);
		player.set("getStartLocation", &PlayerInterface::getStartLocation);
		player.set("isVictorious", &PlayerInterface::isVictorious);
		player.set("isDefeated", &PlayerInterface::isDefeated);
		player.set("leftGame", &PlayerInterface::leftGame);
		player.set("minerals", &PlayerInterface::minerals);
		player.set("gas", &PlayerInterface::gas);
		player.set("gatheredMinerals", &PlayerInterface::gatheredMinerals);
		player.set("gatheredGas", &PlayerInterface::gatheredGas);
		player.set("repairedMinerals", &PlayerInterface::repairedMinerals);
		player.set("repairedGas", &PlayerInterface::repairedGas);
		player.set("refundedMinerals", &PlayerInterface::refundedMinerals);
		player.set("refundedGas", &PlayerInterface::refundedGas);
		player.set("spentMinerals", &PlayerInterface::spentMinerals);
		player.set("spentGas", &PlayerInterface::spentGas);
		player.set("supplyTotal", sol::overload(
			[](PlayerInterface* player) { return player->supplyTotal(); },
			&PlayerInterface::supplyTotal
		));
		player.set("supplyUsed", sol::overload(
			[](PlayerInterface* player) { return player->supplyUsed(); },
			&PlayerInterface::supplyUsed
		));
		player.set("allUnitCount", sol::overload(
			[](PlayerInterface* player) { return player->allUnitCount(); },
			&PlayerInterface::allUnitCount
		));
		player.set("visibleUnitCount", sol::overload(
			[](PlayerInterface* player) { return player->visibleUnitCount(); },
			&PlayerInterface::visibleUnitCount
		));
		player.set("completedUnitCount", sol::overload(
			[](PlayerInterface* player) { return player->completedUnitCount(); },
			&PlayerInterface::completedUnitCount
		));
		player.set("incompleteUnitCount", sol::overload(
			[](PlayerInterface* player) { return player->incompleteUnitCount(); },
			&PlayerInterface::incompleteUnitCount
		));
		player.set("deadUnitCount", sol::overload(
			[](PlayerInterface* player) { return player->deadUnitCount(); },
			&PlayerInterface::deadUnitCount
		));
		player.set("killedUnitCount", sol::overload(
			[](PlayerInterface* player) { return player->killedUnitCount(); },
			&PlayerInterface::killedUnitCount
		));
		player.set("getUpgradeLevel", &PlayerInterface::getUpgradeLevel);
		player.set("hasResearched", &PlayerInterface::hasResearched);
		player.set("isResearching", &PlayerInterface::isResearching);
		player.set("isUpgrading", &PlayerInterface::isUpgrading);
		player.set("getColor", &PlayerInterface::getColor);
		player.set("getTextColor", &PlayerInterface::getTextColor);
		player.set("maxEnergy", &PlayerInterface::maxEnergy);
		player.set("topSpeed", &PlayerInterface::topSpeed);
		player.set("weaponMaxRange", &PlayerInterface::weaponMaxRange);
		player.set("sightRange", &PlayerInterface::sightRange);
		player.set("weaponDamageCooldown", &PlayerInterface::weaponDamageCooldown);
		player.set("armor", &PlayerInterface::armor);
		player.set("damage", &PlayerInterface::damage);
		player.set("getUnitScore", &PlayerInterface::getUnitScore);
		player.set("getKillScore", &PlayerInterface::getKillScore);
		player.set("getBuildingScore", &PlayerInterface::getBuildingScore);
		player.set("getRazingScore", &PlayerInterface::getRazingScore);
		player.set("getCustomScore", &PlayerInterface::getCustomScore);
		player.set("isObserver", &PlayerInterface::isObserver);
		player.set("getMaxUpgradeLevel", &PlayerInterface::getMaxUpgradeLevel);
		player.set("isResearchAvailable", &PlayerInterface::isResearchAvailable);
		player.set("isUnitAvailable", &PlayerInterface::isUnitAvailable);
		player.set("hasUnitTypeRequirement", sol::overload(
			[](PlayerInterface* player, UnitType unit) { return player->hasUnitTypeRequirement(unit); },
			&PlayerInterface::hasUnitTypeRequirement
		));
		bindInterface(player);
		bindIsInstance(player);
		module.set_usertype("Player", player);
	}
}