#include <sol.hpp>
#include <BWAPI.h>
#include "Interface.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnit(sol::table module)
	{
		sol::simple_usertype<UnitInterface> unit = module.create_simple_usertype<UnitInterface>(
			sol::meta_function::construct, sol::no_constructor,
			sol::meta_function::equal_to, [](UnitInterface* a, UnitInterface* b) { return a->getID() == b->getID();  }
		);
		unit.set("getID", &UnitInterface::getID);
		unit.set("exists", &UnitInterface::exists);
		unit.set("getReplayID", &UnitInterface::getReplayID);
		unit.set("getPlayer", &UnitInterface::getPlayer);
		unit.set("getType", &UnitInterface::getType);
		unit.set("getPosition", &UnitInterface::getPosition);
		unit.set("getTilePosition", &UnitInterface::getTilePosition);
		unit.set("getAngle", &UnitInterface::getAngle);
		unit.set("getVelocityX", &UnitInterface::getVelocityX);
		unit.set("getVelocityY", &UnitInterface::getVelocityY);
		unit.set("getRegion", &UnitInterface::getRegion);
		unit.set("getLeft", &UnitInterface::getLeft);
		unit.set("getTop", &UnitInterface::getTop);
		unit.set("getRight", &UnitInterface::getRight);
		unit.set("getBottom", &UnitInterface::getBottom);
		unit.set("getHitPoints", &UnitInterface::getHitPoints);
		unit.set("getShields", &UnitInterface::getShields);
		unit.set("getEnergy", &UnitInterface::getEnergy);
		unit.set("getResources", &UnitInterface::getResources);
		unit.set("getResourceGroup", &UnitInterface::getResourceGroup);
		unit.set("getDistance", &UnitInterface::getDistance);
		unit.set("hasPath", &UnitInterface::hasPath);
		unit.set("getLastCommandFrame", &UnitInterface::getLastCommandFrame);
		unit.set("getLastCommand", &UnitInterface::getLastCommand);
		unit.set("getLastAttackingPlayer", &UnitInterface::getLastAttackingPlayer);
		unit.set("getInitialType", &UnitInterface::getInitialType);
		unit.set("getInitialPosition", &UnitInterface::getInitialPosition);
		unit.set("getInitialTilePosition", &UnitInterface::getInitialTilePosition);
		unit.set("getInitialHitPoints", &UnitInterface::getInitialHitPoints);
		unit.set("getInitialResources", &UnitInterface::getInitialResources);
		unit.set("getKillCount", &UnitInterface::getKillCount);
		unit.set("getAcidSporeCount", &UnitInterface::getAcidSporeCount);
		unit.set("getInterceptorCount", &UnitInterface::getInterceptorCount);
		unit.set("getScarabCount", &UnitInterface::getScarabCount);
		unit.set("getSpiderMineCount", &UnitInterface::getSpiderMineCount);
		unit.set("getGroundWeaponCooldown", &UnitInterface::getGroundWeaponCooldown);
		unit.set("getAirWeaponCooldown", &UnitInterface::getAirWeaponCooldown);
		unit.set("getSpellCooldown", &UnitInterface::getSpellCooldown);
		unit.set("getDefenseMatrixPoints", &UnitInterface::getDefenseMatrixPoints);
		unit.set("getDefenseMatrixTimer", &UnitInterface::getDefenseMatrixTimer);
		unit.set("getEnsnareTimer", &UnitInterface::getEnsnareTimer);
		unit.set("getIrradiateTimer", &UnitInterface::getIrradiateTimer);
		unit.set("getLockdownTimer", &UnitInterface::getLockdownTimer);
		unit.set("getMaelstromTimer", &UnitInterface::getMaelstromTimer);
		unit.set("getOrderTimer", &UnitInterface::getOrderTimer);
		unit.set("getPlagueTimer", &UnitInterface::getPlagueTimer);
		unit.set("getRemoveTimer", &UnitInterface::getRemoveTimer);
		unit.set("getStasisTimer", &UnitInterface::getStasisTimer);
		unit.set("getStimTimer", &UnitInterface::getStimTimer);
		unit.set("getBuildType", &UnitInterface::getBuildType);
		unit.set("getTrainingQueue", [](UnitInterface* unit) { return sol::as_table(unit->getTrainingQueue()); });
		unit.set("getTech", &UnitInterface::getTech);
		unit.set("getUpgrade", &UnitInterface::getUpgrade);
		unit.set("getRemainingBuildTime", &UnitInterface::getRemainingBuildTime);
		unit.set("getRemainingResearchTime", &UnitInterface::getRemainingResearchTime);
		unit.set("getRemainingTrainTime", &UnitInterface::getRemainingTrainTime);
		unit.set("getRemainingUpgradeTime", &UnitInterface::getRemainingUpgradeTime);
		unit.set("getBuildUnit", &UnitInterface::getBuildUnit);
		unit.set("getTarget", &UnitInterface::getTarget);
		unit.set("getTargetPosition", &UnitInterface::getTargetPosition);
		unit.set("getOrder", &UnitInterface::getOrder);
		unit.set("getSecondaryOrder", &UnitInterface::getSecondaryOrder);
		unit.set("getOrderTarget", &UnitInterface::getOrderTarget);
		unit.set("getOrderTargetPosition", &UnitInterface::getOrderTargetPosition);
		unit.set("getRallyPosition", &UnitInterface::getRallyPosition);
		unit.set("getRallyUnit", &UnitInterface::getRallyUnit);
		unit.set("getAddon", &UnitInterface::getAddon);
		unit.set("getNydusExit", &UnitInterface::getNydusExit);
		unit.set("getPowerUp", &UnitInterface::getPowerUp);
		unit.set("getTransport", &UnitInterface::getTransport);
		unit.set("getLoadedUnits", &UnitInterface::getLoadedUnits);
		unit.set("getSpaceRemaining", &UnitInterface::getSpaceRemaining);
		unit.set("getCarrier", &UnitInterface::getCarrier);
		unit.set("getInterceptors", &UnitInterface::getInterceptors);
		unit.set("getHatchery", &UnitInterface::getHatchery);
		unit.set("getLarva", &UnitInterface::getLarva);
		unit.set("getUnitsInRadius", sol::overload(
			[](UnitInterface* unit, int radius)
			{
				return unit->getUnitsInRadius(radius);
			},
			[](UnitInterface* unit, int radius, const sol::function& pred)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return unit->getUnitsInRadius(radius, pred);
			},
			[](UnitInterface* unit, int radius, const UnitFilter& pred)
			{
				return unit->getUnitsInRadius(radius, pred);
			}
		));
		unit.set("getUnitsInWeaponRange", sol::overload(
			[](UnitInterface* unit, const WeaponType& weapon)
			{
				return unit->getUnitsInWeaponRange(weapon);
			},
			[](UnitInterface* unit, const WeaponType& weapon, const sol::function& pred)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return unit->getUnitsInWeaponRange(weapon, pred);
			},
			[](UnitInterface* unit, const WeaponType& weapon, const UnitFilter& pred)
			{
				return unit->getUnitsInWeaponRange(weapon, pred);
			}
		));
		unit.set("getClosestUnit", sol::overload(
			[](const UnitInterface* unit)
			{
				return unit->getClosestUnit();
			},
			[](const UnitInterface* unit, const sol::function& pred)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return unit->getClosestUnit(filter);
			},
			[](const UnitInterface* unit, const sol::function& pred, int radius)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return unit->getClosestUnit(filter, radius);
			},
			[](const UnitInterface* unit, const UnitFilter& pred)
			{
				return unit->getClosestUnit(pred);
			},
			[](const UnitInterface* unit, const UnitFilter& pred, int radius)
			{
				return unit->getClosestUnit(pred, radius);
			}
		));
		unit.set("hasNuke", &UnitInterface::hasNuke);
		unit.set("isAccelerating", &UnitInterface::isAccelerating);
		unit.set("isAttacking", &UnitInterface::isAttacking);
		unit.set("isAttackFrame", &UnitInterface::isAttackFrame);
		unit.set("isBeingConstructed", &UnitInterface::isBeingConstructed);
		unit.set("isBeingGathered", &UnitInterface::isBeingGathered);
		unit.set("isBeingHealed", &UnitInterface::isBeingHealed);
		unit.set("isBlind", &UnitInterface::isBlind);
		unit.set("isBraking", &UnitInterface::isBraking);
		unit.set("isBurrowed", &UnitInterface::isBurrowed);
		unit.set("isCarryingGas", &UnitInterface::isCarryingGas);
		unit.set("isCarryingMinerals", &UnitInterface::isCarryingMinerals);
		unit.set("isCloaked", &UnitInterface::isCloaked);
		unit.set("isCompleted", &UnitInterface::isCompleted);
		unit.set("isConstructing", &UnitInterface::isConstructing);
		unit.set("isDefenseMatrixed", &UnitInterface::isDefenseMatrixed);
		unit.set("isDetected", &UnitInterface::isDetected);
		unit.set("isEnsnared", &UnitInterface::isEnsnared);
		unit.set("isFlying", &UnitInterface::isFlying);
		unit.set("isFollowing", &UnitInterface::isFollowing);
		unit.set("isGatheringGas", &UnitInterface::isGatheringGas);
		unit.set("isGatheringMinerals", &UnitInterface::isGatheringMinerals);
		unit.set("isHallucination", &UnitInterface::isHallucination);
		unit.set("isHoldingPosition", &UnitInterface::isHoldingPosition);
		unit.set("isIdle", &UnitInterface::isIdle);
		unit.set("isInterruptible", &UnitInterface::isInterruptible);
		unit.set("isInvincible", &UnitInterface::isInvincible);
		unit.set("isInWeaponRange", &UnitInterface::isInWeaponRange);
		unit.set("isIrradiated", &UnitInterface::isIrradiated);
		unit.set("isLifted", &UnitInterface::isLifted);
		unit.set("isLoaded", &UnitInterface::isLoaded);
		unit.set("isLockedDown", &UnitInterface::isLockedDown);
		unit.set("isMaelstrommed", &UnitInterface::isMaelstrommed);
		unit.set("isMorphing", &UnitInterface::isMorphing);
		unit.set("isMoving", &UnitInterface::isMoving);
		unit.set("isParasited", &UnitInterface::isParasited);
		unit.set("isPatrolling", &UnitInterface::isPatrolling);
		unit.set("isPlagued", &UnitInterface::isPlagued);
		unit.set("isRepairing", &UnitInterface::isRepairing);
		unit.set("isResearching", &UnitInterface::isResearching);
		unit.set("isSelected", &UnitInterface::isSelected);
		unit.set("isSieged", &UnitInterface::isSieged);
		unit.set("isStartingAttack", &UnitInterface::isStartingAttack);
		unit.set("isStasised", &UnitInterface::isStasised);
		unit.set("isStimmed", &UnitInterface::isStimmed);
		unit.set("isStuck", &UnitInterface::isStuck);
		unit.set("isTraining", &UnitInterface::isTraining);
		unit.set("isUnderAttack", &UnitInterface::isUnderAttack);
		unit.set("isUnderDarkSwarm", &UnitInterface::isUnderDarkSwarm);
		unit.set("isUnderDisruptionWeb", &UnitInterface::isUnderDisruptionWeb);
		unit.set("isUnderStorm", &UnitInterface::isUnderStorm);
		unit.set("isPowered", &UnitInterface::isPowered);
		unit.set("isUpgrading", &UnitInterface::isUpgrading);
		unit.set("isVisible", &UnitInterface::isVisible);
		unit.set("isTargetable", &UnitInterface::isTargetable);
		unit.set("issueCommand", &UnitInterface::issueCommand);
		unit.set("attack", sol::overload(
			[](UnitInterface* unit, const PositionOrUnit& pos) { return unit->attack(pos); },
			static_cast<bool (UnitInterface::*)(PositionOrUnit, bool)>(&UnitInterface::attack)
		));
		unit.set("build", sol::overload(
			[](UnitInterface* unit, UnitType type) { return unit->build(type); },
			static_cast<bool (UnitInterface::*)(UnitType, TilePosition)>(&UnitInterface::build)
		));
		unit.set("buildAddon", &UnitInterface::buildAddon);
		unit.set("train", sol::overload(
			[](UnitInterface* unit) { return unit->train(); },
			static_cast<bool (UnitInterface::*)(UnitType)>(&UnitInterface::train)
		));
		unit.set("morph", &UnitInterface::morph);
		unit.set("research", &UnitInterface::research);
		unit.set("upgrade", &UnitInterface::upgrade);
		unit.set("setRallyPoint", &UnitInterface::setRallyPoint);
		unit.set("move", sol::overload(
			[](UnitInterface* unit, const Position& pos) { return unit->move(pos); },
			static_cast<bool (UnitInterface::*)(Position, bool)>(&UnitInterface::move)
		));
		unit.set("patrol", sol::overload(
			[](UnitInterface* unit, const Position& pos) { return unit->patrol(pos); },
			static_cast<bool (UnitInterface::*)(Position, bool)>(&UnitInterface::patrol)
		));
		unit.set("holdPosition", sol::overload(
			[](UnitInterface* unit) { return unit->holdPosition(); },
			static_cast<bool (UnitInterface::*)(bool)>(&UnitInterface::holdPosition)
		));
		unit.set("stop", sol::overload(
			[](UnitInterface* unit) { return unit->stop(); },
			static_cast<bool (UnitInterface::*)(bool)>(&UnitInterface::stop)
		));
		unit.set("follow", sol::overload(
			[](UnitInterface* unit, const Unit unitToFollow) { return unit->follow(unitToFollow); },
			static_cast<bool (UnitInterface::*)(Unit, bool)>(&UnitInterface::follow)
		));
		unit.set("gather", sol::overload(
			[](UnitInterface* unit, const Unit toGather) { return unit->gather(toGather); },
			static_cast<bool (UnitInterface::*)(Unit, bool)>(&UnitInterface::gather)
		));
		unit.set("returnCargo", sol::overload(
			[](UnitInterface* unit) { return unit->returnCargo(); },
			static_cast<bool (UnitInterface::*)(bool)>(&UnitInterface::returnCargo)
		));
		unit.set("repair", sol::overload(
			[](UnitInterface* unit, const Unit toRepair) { return unit->repair(toRepair); },
			static_cast<bool (UnitInterface::*)(Unit, bool)>(&UnitInterface::repair)
		));
		unit.set("burrow", &UnitInterface::burrow);
		unit.set("unburrow", &UnitInterface::unburrow);
		unit.set("cloak", &UnitInterface::cloak);
		unit.set("decloak", &UnitInterface::decloak);
		unit.set("siege", &UnitInterface::siege);
		unit.set("unsiege", &UnitInterface::unsiege);
		unit.set("lift", &UnitInterface::lift);
		unit.set("land", &UnitInterface::land);
		unit.set("load", sol::overload(
			[](UnitInterface* unit, const Unit target) { return unit->load(target); },
			static_cast<bool (UnitInterface::*)(Unit, bool)>(&UnitInterface::load)
		));
		unit.set("unload", &UnitInterface::unload);
		unit.set("unloadAll", sol::overload(
			[](UnitInterface* unit) { return unit->unloadAll(); },
			static_cast<bool (UnitInterface::*)(bool)>(&UnitInterface::unloadAll),
			[](UnitInterface* unit, const Position& pos) { return unit->unloadAll(pos); },
			static_cast<bool (UnitInterface::*)(Position, bool)>(&UnitInterface::unloadAll)
		));
		unit.set("rightClick", sol::overload(
			[](UnitInterface* unit, const PositionOrUnit& pos) { return unit->rightClick(pos); },
			static_cast<bool (UnitInterface::*)(PositionOrUnit, bool)>(&UnitInterface::rightClick)
		));
		unit.set("haltConstruction", &UnitInterface::haltConstruction);
		unit.set("cancelConstruction", &UnitInterface::cancelConstruction);
		unit.set("cancelAddon", &UnitInterface::cancelAddon);
		unit.set("cancelTrain", sol::overload(
			[](UnitInterface* unit) { return unit->cancelTrain(); },
			[](UnitInterface* unit, int slot)
			{
				// convert from Lua index to C++ index for slots >= 1
				if (slot >= 1)
					slot -= 1;

				return unit->cancelTrain(slot);
			}
		));
		unit.set("cancelMorph", &UnitInterface::cancelMorph);
		unit.set("cancelResearch", &UnitInterface::cancelResearch);
		unit.set("cancelUpgrade", &UnitInterface::cancelUpgrade);
		unit.set("useTech", sol::overload(
			[](UnitInterface* unit, const TechType& type) { return unit->useTech(type); },
			static_cast<bool (UnitInterface::*)(TechType, PositionOrUnit)>(&UnitInterface::useTech)
		));
		unit.set("placeCOP", &UnitInterface::placeCOP);
		unit.set("canIssueCommand", sol::overload(
			[](UnitInterface* unit, const UnitCommand& command) { return unit->canIssueCommand(command); },
			[](UnitInterface* unit, const UnitCommand& command, bool flag1) { return unit->canIssueCommand(command, flag1); },
			[](UnitInterface* unit, const UnitCommand& command, bool flag1, bool flag2) { return unit->canIssueCommand(command, flag1, flag2); },
			[](UnitInterface* unit, const UnitCommand& command, bool flag1, bool flag2, bool flag3) { return unit->canIssueCommand(command, flag1, flag2, flag3); },
			[](UnitInterface* unit, const UnitCommand& command, bool flag1, bool flag2, bool flag3, bool flag4) { return unit->canIssueCommand(command, flag1, flag2, flag3, flag4); },
			[](UnitInterface* unit, const UnitCommand& command, bool flag1, bool flag2, bool flag3, bool flag4, bool flag5) { return unit->canIssueCommand(command, flag1, flag2, flag3, flag4, flag5); },
			static_cast<bool (UnitInterface::*)(UnitCommand, bool, bool, bool, bool, bool, bool) const>(&UnitInterface::canIssueCommand)
		));
		unit.set("canIssueCommandGrouped", sol::overload(
			[](UnitInterface* unit, const UnitCommand& command) { return unit->canIssueCommandGrouped(command); },
			[](UnitInterface* unit, const UnitCommand& command, bool flag1) { return unit->canIssueCommandGrouped(command, flag1); },
			[](UnitInterface* unit, const UnitCommand& command, bool flag1, bool flag2) { return unit->canIssueCommandGrouped(command, flag1, flag2); },
			[](UnitInterface* unit, const UnitCommand& command, bool flag1, bool flag2, bool flag3) { return unit->canIssueCommandGrouped(command, flag1, flag2, flag3); },
			[](UnitInterface* unit, const UnitCommand& command, bool flag1, bool flag2, bool flag3, bool flag4) { return unit->canIssueCommandGrouped(command, flag1, flag2, flag3, flag4); },
			[](UnitInterface* unit, const UnitCommand& command, bool flag1, bool flag2, bool flag3, bool flag4, bool flag5) { return unit->canIssueCommandGrouped(command, flag1, flag2, flag3, flag4, flag5); },
			static_cast<bool (UnitInterface::*)(UnitCommand, bool, bool, bool, bool, bool, bool) const>(&UnitInterface::canIssueCommandGrouped)
		));
		unit.set("canCommand", &UnitInterface::canCommand);
		unit.set("canCommandGrouped", sol::overload(
			[](UnitInterface* unit) { return unit->canCommandGrouped(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canCommandGrouped)
		));
		unit.set("canIssueCommandType", sol::overload(
			[](UnitInterface* unit, UnitCommandType type) { return unit->canIssueCommandType(type); },
			static_cast<bool (UnitInterface::*)(UnitCommandType, bool) const>(&UnitInterface::canIssueCommandType)
		));
		unit.set("canIssueCommandTypeGrouped", sol::overload(
			[](UnitInterface* unit, UnitCommandType type) { return unit->canIssueCommandTypeGrouped(type); },
			[](UnitInterface* unit, UnitCommandType type, bool flag1) { return unit->canIssueCommandTypeGrouped(type, flag1); },
			static_cast<bool (UnitInterface::*)(UnitCommandType, bool, bool) const>(&UnitInterface::canIssueCommandTypeGrouped)
		));
		unit.set("canTargetUnit", sol::overload(
			[](UnitInterface* unit, Unit target) { return unit->canTargetUnit(target); },
			static_cast<bool (UnitInterface::*)(Unit, bool) const>(&UnitInterface::canTargetUnit)
		));
		unit.set("canAttack", sol::overload(
			[](UnitInterface* unit) { return unit->canAttack(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canAttack),
			[](UnitInterface* unit, const PositionOrUnit& pos) { return unit->canAttack(pos); },
			[](UnitInterface* unit, const PositionOrUnit& pos, bool flag1) { return unit->canAttack(pos, flag1); },
			[](UnitInterface* unit, const PositionOrUnit& pos, bool flag1, bool flag2) { return unit->canAttack(pos, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(PositionOrUnit, bool, bool, bool) const>(&UnitInterface::canAttack)
		));
		unit.set("canAttackGrouped", sol::overload(
			[](UnitInterface* unit) { return unit->canAttackGrouped(); },
			[](UnitInterface* unit, bool flag1) { return unit->canAttackGrouped(flag1); },
			static_cast<bool (UnitInterface::*)(bool, bool) const>(&UnitInterface::canAttackGrouped),
			[](UnitInterface* unit, const PositionOrUnit& pos) { return unit->canAttackGrouped(pos); },
			[](UnitInterface* unit, const PositionOrUnit& pos, bool flag1) { return unit->canAttackGrouped(pos, flag1); },
			[](UnitInterface* unit, const PositionOrUnit& pos, bool flag1, bool flag2) { return unit->canAttackGrouped(pos, flag1, flag2); },
			[](UnitInterface* unit, const PositionOrUnit& pos, bool flag1, bool flag2, bool flag3) { return unit->canAttackGrouped(pos, flag1, flag2, flag3); },
			static_cast<bool (UnitInterface::*)(PositionOrUnit, bool, bool, bool, bool) const>(&UnitInterface::canAttackGrouped)
		));
		unit.set("canAttackMove", sol::overload(
			[](UnitInterface* unit) { return unit->canAttackMove(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canAttackMove)
		));
		unit.set("canAttackMoveGrouped", sol::overload(
			[](UnitInterface* unit) { return unit->canAttackMoveGrouped(); },
			[](UnitInterface* unit, bool flag1) { return unit->canAttackMoveGrouped(flag1); },
			static_cast<bool (UnitInterface::*)(bool, bool) const>(&UnitInterface::canAttackMoveGrouped)
		));
		unit.set("canAttackUnit", sol::overload(
			[](UnitInterface* unit) { return unit->canAttackUnit(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canAttackUnit),
			[](UnitInterface* unit, Unit target) { return unit->canAttackUnit(target); },
			[](UnitInterface* unit, Unit target, bool flag1) { return unit->canAttackUnit(target, flag1); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2) { return unit->canAttackUnit(target, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(Unit, bool, bool, bool) const>(&UnitInterface::canAttackUnit)
		));
		unit.set("canAttackUnitGrouped", sol::overload(
			[](UnitInterface* unit) { return unit->canAttackUnitGrouped(); },
			[](UnitInterface* unit, bool flag1) { return unit->canAttackUnitGrouped(flag1); },
			static_cast<bool (UnitInterface::*)(bool, bool) const>(&UnitInterface::canAttackUnitGrouped),
			[](UnitInterface* unit, Unit target) { return unit->canAttackUnitGrouped(target); },
			[](UnitInterface* unit, Unit target, bool flag1) { return unit->canAttackUnitGrouped(target, flag1); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2) { return unit->canAttackUnitGrouped(target, flag1, flag2); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2, bool flag3) { return unit->canAttackUnitGrouped(target, flag1, flag2, flag3); },
			static_cast<bool (UnitInterface::*)(Unit, bool, bool, bool, bool) const>(&UnitInterface::canAttackUnitGrouped)
		));
		unit.set("canBuild", sol::overload(
			[](UnitInterface* unit) { return unit->canBuild(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canBuild),

			[](UnitInterface* unit, UnitType target) { return unit->canBuild(target); },
			[](UnitInterface* unit, UnitType target, bool flag1) { return unit->canBuild(target, flag1); },
			static_cast<bool (UnitInterface::*)(UnitType, bool, bool) const>(&UnitInterface::canBuild),

			[](UnitInterface* unit, UnitType target, TilePosition pos) { return unit->canBuild(target, pos); },
			[](UnitInterface* unit, UnitType target, TilePosition pos, bool flag1) { return unit->canBuild(target, pos, flag1); },
			[](UnitInterface* unit, UnitType target, TilePosition pos, bool flag1, bool flag2) { return unit->canBuild(target, pos, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(UnitType, TilePosition, bool, bool, bool) const>(&UnitInterface::canBuild)
		));
		unit.set("canBuildAddon", sol::overload(
			[](UnitInterface* unit) { return unit->canBuildAddon(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canBuildAddon),

			[](UnitInterface* unit, UnitType target) { return unit->canBuildAddon(target); },
			[](UnitInterface* unit, UnitType target, bool flag1) { return unit->canBuildAddon(target, flag1); },
			static_cast<bool (UnitInterface::*)(UnitType, bool, bool) const>(&UnitInterface::canBuildAddon)
		));
		unit.set("canTrain", sol::overload(
			[](UnitInterface* unit) { return unit->canTrain(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canTrain),

			[](UnitInterface* unit, UnitType target) { return unit->canTrain(target); },
			[](UnitInterface* unit, UnitType target, bool flag1) { return unit->canTrain(target, flag1); },
			static_cast<bool (UnitInterface::*)(UnitType, bool, bool) const>(&UnitInterface::canTrain)
		));
		unit.set("canMorph", sol::overload(
			[](UnitInterface* unit) { return unit->canMorph(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canMorph),

			[](UnitInterface* unit, UnitType target) { return unit->canMorph(target); },
			[](UnitInterface* unit, UnitType target, bool flag1) { return unit->canMorph(target, flag1); },
			static_cast<bool (UnitInterface::*)(UnitType, bool, bool) const>(&UnitInterface::canMorph)
		));
		unit.set("canResearch", sol::overload(
			[](UnitInterface* unit) { return unit->canResearch(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canResearch),

			[](UnitInterface* unit, TechType target) { return unit->canResearch(target); },
			static_cast<bool (UnitInterface::*)(TechType, bool) const>(&UnitInterface::canResearch)
		));
		unit.set("canUpgrade", sol::overload(
			[](UnitInterface* unit) { return unit->canUpgrade(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canUpgrade),

			[](UnitInterface* unit, UpgradeType target) { return unit->canUpgrade(target); },
			static_cast<bool (UnitInterface::*)(UpgradeType, bool) const>(&UnitInterface::canUpgrade)
		));
		unit.set("canSetRallyPoint", sol::overload(
			[](UnitInterface* unit) { return unit->canSetRallyPoint(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canSetRallyPoint),

			[](UnitInterface* unit, PositionOrUnit target) { return unit->canSetRallyPoint(target); },
			[](UnitInterface* unit, PositionOrUnit target, bool flag1) { return unit->canSetRallyPoint(target, flag1); },
			[](UnitInterface* unit, PositionOrUnit target, bool flag1, bool flag2) { return unit->canSetRallyPoint(target, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(PositionOrUnit, bool, bool, bool) const>(&UnitInterface::canSetRallyPoint)
		));
		unit.set("canSetRallyPosition", sol::overload(
			[](UnitInterface* unit) { return unit->canSetRallyPosition(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canSetRallyPosition)
		));
		unit.set("canSetRallyUnit", sol::overload(
			[](UnitInterface* unit) { return unit->canSetRallyUnit(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canSetRallyUnit),

			[](UnitInterface* unit, Unit target) { return unit->canSetRallyUnit(target); },
			[](UnitInterface* unit, Unit target, bool flag1) { return unit->canSetRallyUnit(target, flag1); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2) { return unit->canSetRallyUnit(target, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(Unit, bool, bool, bool) const>(&UnitInterface::canSetRallyUnit)
		));
		unit.set("canMove", sol::overload(
			[](UnitInterface* unit) { return unit->canMove(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canMove)
		));
		unit.set("canMoveGrouped", sol::overload(
			[](UnitInterface* unit) { return unit->canMoveGrouped(); },
			[](UnitInterface* unit, bool flag1) { return unit->canMoveGrouped(flag1); },
			static_cast<bool (UnitInterface::*)(bool, bool) const>(&UnitInterface::canMoveGrouped)
		));
		unit.set("canPatrol", sol::overload(
			[](UnitInterface* unit) { return unit->canPatrol(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canPatrol)
		));
		unit.set("canPatrolGrouped", sol::overload(
			[](UnitInterface* unit) { return unit->canPatrolGrouped(); },
			[](UnitInterface* unit, bool flag1) { return unit->canPatrolGrouped(flag1); },
			static_cast<bool (UnitInterface::*)(bool, bool) const>(&UnitInterface::canPatrolGrouped)
		));
		unit.set("canFollow", sol::overload(
			[](UnitInterface* unit) { return unit->canFollow(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canFollow),

			[](UnitInterface* unit, Unit target) { return unit->canFollow(target); },
			[](UnitInterface* unit, Unit target, bool flag1) { return unit->canFollow(target, flag1); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2) { return unit->canFollow(target, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(Unit, bool, bool, bool) const>(&UnitInterface::canFollow)
		));
		unit.set("canGather", sol::overload(
			[](UnitInterface* unit) { return unit->canGather(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canGather),

			[](UnitInterface* unit, Unit target) { return unit->canGather(target); },
			[](UnitInterface* unit, Unit target, bool flag1) { return unit->canGather(target, flag1); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2) { return unit->canGather(target, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(Unit, bool, bool, bool) const>(&UnitInterface::canGather)
		));
		unit.set("canReturnCargo", sol::overload(
			[](UnitInterface* unit) { return unit->canReturnCargo(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canReturnCargo)
		));
		unit.set("canHoldPosition", sol::overload(
			[](UnitInterface* unit) { return unit->canHoldPosition(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canHoldPosition)
		));
		unit.set("canStop", sol::overload(
			[](UnitInterface* unit) { return unit->canStop(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canStop)
		));
		unit.set("canRepair", sol::overload(
			[](UnitInterface* unit) { return unit->canRepair(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canRepair),

			[](UnitInterface* unit, Unit target) { return unit->canRepair(target); },
			[](UnitInterface* unit, Unit target, bool flag1) { return unit->canRepair(target, flag1); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2) { return unit->canRepair(target, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(Unit, bool, bool, bool) const>(&UnitInterface::canRepair)
		));
		unit.set("canBurrow", sol::overload(
			[](UnitInterface* unit) { return unit->canBurrow(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canBurrow)
		));
		unit.set("canUnburrow", sol::overload(
			[](UnitInterface* unit) { return unit->canUnburrow(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canUnburrow)
		));
		unit.set("canCloak", sol::overload(
			[](UnitInterface* unit) { return unit->canCloak(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canCloak)
		));
		unit.set("canDecloak", sol::overload(
			[](UnitInterface* unit) { return unit->canDecloak(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canDecloak)
		));
		unit.set("canSiege", sol::overload(
			[](UnitInterface* unit) { return unit->canSiege(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canSiege)
		));
		unit.set("canUnsiege", sol::overload(
			[](UnitInterface* unit) { return unit->canUnsiege(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canUnsiege)
		));
		unit.set("canLift", sol::overload(
			[](UnitInterface* unit) { return unit->canLift(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canLift)
		));
		unit.set("canLand", sol::overload(
			[](UnitInterface* unit) { return unit->canLand(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canLand),

			[](UnitInterface* unit, TilePosition target) { return unit->canLand(target); },
			[](UnitInterface* unit, TilePosition target, bool flag1) { return unit->canLand(target, flag1); },
			static_cast<bool (UnitInterface::*)(TilePosition, bool, bool) const>(&UnitInterface::canLand)
		));
		unit.set("canLoad", sol::overload(
			[](UnitInterface* unit) { return unit->canLoad(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canLoad),

			[](UnitInterface* unit, Unit target) { return unit->canLoad(target); },
			[](UnitInterface* unit, Unit target, bool flag1) { return unit->canLoad(target, flag1); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2) { return unit->canLoad(target, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(Unit, bool, bool, bool) const>(&UnitInterface::canLoad)
		));
		unit.set("canUnloadWithOrWithoutTarget", sol::overload(
			[](UnitInterface* unit) { return unit->canUnloadWithOrWithoutTarget(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canUnloadWithOrWithoutTarget)
		));
		unit.set("canUnloadAtPosition", sol::overload(
			[](UnitInterface* unit, Position target) { return unit->canUnloadAtPosition(target); },
			[](UnitInterface* unit, Position target, bool flag1) { return unit->canUnloadAtPosition(target, flag1); },
			static_cast<bool (UnitInterface::*)(Position, bool, bool) const>(&UnitInterface::canUnloadAtPosition)
		));
		unit.set("canUnload", sol::overload(
			[](UnitInterface* unit) { return unit->canUnload(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canUnload),

			[](UnitInterface* unit, Unit target) { return unit->canUnload(target); },
			[](UnitInterface* unit, Unit target, bool flag1) { return unit->canUnload(target, flag1); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2) { return unit->canUnload(target, flag1, flag2); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2, bool flag3) { return unit->canUnload(target, flag1, flag2, flag3); },
			static_cast<bool (UnitInterface::*)(Unit, bool, bool, bool, bool) const>(&UnitInterface::canUnload)
		));
		unit.set("canUnloadAll", sol::overload(
			[](UnitInterface* unit) { return unit->canUnloadAll(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canUnloadAll)
		));
		unit.set("canUnloadAllPosition", sol::overload(
			[](UnitInterface* unit) { return unit->canUnloadAllPosition(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canUnloadAllPosition),

			[](UnitInterface* unit, Position target) { return unit->canUnloadAllPosition(target); },
			[](UnitInterface* unit, Position target, bool flag1) { return unit->canUnloadAllPosition(target, flag1); },
			static_cast<bool (UnitInterface::*)(Position, bool, bool) const>(&UnitInterface::canUnloadAllPosition)
		));
		unit.set("canRightClick", sol::overload(
			[](UnitInterface* unit) { return unit->canRightClick(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canRightClick),

			[](UnitInterface* unit, PositionOrUnit target) { return unit->canRightClick(target); },
			[](UnitInterface* unit, PositionOrUnit target, bool flag1) { return unit->canRightClick(target, flag1); },
			[](UnitInterface* unit, PositionOrUnit target, bool flag1, bool flag2) { return unit->canRightClick(target, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(PositionOrUnit, bool, bool, bool) const>(&UnitInterface::canRightClick)
		));
		unit.set("canRightClickGrouped", sol::overload(
			[](UnitInterface* unit) { return unit->canRightClickGrouped(); },
			[](UnitInterface* unit, bool flag1) { return unit->canRightClickGrouped(flag1); },
			static_cast<bool (UnitInterface::*)(bool, bool) const>(&UnitInterface::canRightClickGrouped),

			[](UnitInterface* unit, PositionOrUnit target) { return unit->canRightClickGrouped(target); },
			[](UnitInterface* unit, PositionOrUnit target, bool flag1) { return unit->canRightClickGrouped(target, flag1); },
			[](UnitInterface* unit, PositionOrUnit target, bool flag1, bool flag2) { return unit->canRightClickGrouped(target, flag1, flag2); },
			[](UnitInterface* unit, PositionOrUnit target, bool flag1, bool flag2, bool flag3) { return unit->canRightClickGrouped(target, flag1, flag2, flag3); },
			static_cast<bool (UnitInterface::*)(PositionOrUnit, bool, bool, bool, bool) const>(&UnitInterface::canRightClickGrouped)
		));
		unit.set("canRightClickPosition", sol::overload(
			[](UnitInterface* unit) { return unit->canRightClickPosition(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canRightClickPosition)
		));
		unit.set("canRightClickPositionGrouped", sol::overload(
			[](UnitInterface* unit) { return unit->canRightClickPositionGrouped(); },
			[](UnitInterface* unit, bool flag1) { return unit->canRightClickPositionGrouped(flag1); },
			static_cast<bool (UnitInterface::*)(bool, bool) const>(&UnitInterface::canRightClickPositionGrouped)
		));
		unit.set("canRightClickUnit", sol::overload(
			[](UnitInterface* unit) { return unit->canRightClickUnit(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canRightClickUnit),

			[](UnitInterface* unit, Unit target) { return unit->canRightClickUnit(target); },
			[](UnitInterface* unit, Unit target, bool flag1) { return unit->canRightClickUnit(target, flag1); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2) { return unit->canRightClickUnit(target, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(Unit, bool, bool, bool) const>(&UnitInterface::canRightClickUnit)
		));
		unit.set("canRightClickUnitGrouped", sol::overload(
			[](UnitInterface* unit) { return unit->canRightClickUnitGrouped(); },
			[](UnitInterface* unit, bool flag1) { return unit->canRightClickUnitGrouped(flag1); },
			static_cast<bool (UnitInterface::*)(bool, bool) const>(&UnitInterface::canRightClickUnitGrouped),

			[](UnitInterface* unit, Unit target) { return unit->canRightClickUnitGrouped(target); },
			[](UnitInterface* unit, Unit target, bool flag1) { return unit->canRightClickUnitGrouped(target, flag1); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2) { return unit->canRightClickUnitGrouped(target, flag1, flag2); },
			[](UnitInterface* unit, Unit target, bool flag1, bool flag2, bool flag3) { return unit->canRightClickUnitGrouped(target, flag1, flag2, flag3); },
			static_cast<bool (UnitInterface::*)(Unit, bool, bool, bool, bool) const>(&UnitInterface::canRightClickUnitGrouped)
		));
		unit.set("canHaltConstruction", sol::overload(
			[](UnitInterface* unit) { return unit->canHaltConstruction(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canHaltConstruction)
		));
		unit.set("canCancelConstruction", sol::overload(
			[](UnitInterface* unit) { return unit->canCancelConstruction(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canCancelConstruction)
		));
		unit.set("canCancelAddon", sol::overload(
			[](UnitInterface* unit) { return unit->canCancelAddon(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canCancelAddon)
		));
		unit.set("canCancelTrain", sol::overload(
			[](UnitInterface* unit) { return unit->canCancelTrain(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canCancelTrain)
		));
		unit.set("canCancelTrainSlot", sol::overload(
			[](UnitInterface* unit) { return unit->canCancelTrainSlot(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canCancelTrainSlot),

			[](UnitInterface* unit, int slot) {
				// convert from Lua index to C++ index for slots >= 1
				if (slot >= 1)
					slot -= 1;

				return unit->canCancelTrainSlot(slot);
			},
			[](UnitInterface* unit, int slot, bool flag1) {
				// convert from Lua index to C++ index for slots >= 1
				if (slot >= 1)
					slot -= 1;

				return unit->canCancelTrainSlot(slot, flag1);
			},
			[](UnitInterface* unit, int slot, bool flag1, bool flag2) {
				// convert from Lua index to C++ index for slots >= 1
				if (slot >= 1)
					slot -= 1;

				return unit->canCancelTrainSlot(slot, flag1, flag2);
			}
		));
		unit.set("canCancelMorph", sol::overload(
			[](UnitInterface* unit) { return unit->canCancelMorph(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canCancelMorph)
		));
		unit.set("canCancelResearch", sol::overload(
			[](UnitInterface* unit) { return unit->canCancelResearch(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canCancelResearch)
		));
		unit.set("canCancelUpgrade", sol::overload(
			[](UnitInterface* unit) { return unit->canCancelUpgrade(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canCancelUpgrade)
		));
		unit.set("canUseTechWithOrWithoutTarget", sol::overload(
			[](UnitInterface* unit) { return unit->canUseTechWithOrWithoutTarget(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canUseTechWithOrWithoutTarget),

			[](UnitInterface* unit, TechType target) { return unit->canUseTechWithOrWithoutTarget(target); },
			[](UnitInterface* unit, TechType target, bool flag1) { return unit->canUseTechWithOrWithoutTarget(target, flag1); },
			static_cast<bool (UnitInterface::*)(TechType, bool, bool) const>(&UnitInterface::canUseTechWithOrWithoutTarget)
		));
		unit.set("canUseTech", sol::overload(
			[](UnitInterface* unit, TechType target) { return unit->canUseTech(target); },
			[](UnitInterface* unit, TechType target, PositionOrUnit pos) { return unit->canUseTech(target, pos); },
			[](UnitInterface* unit, TechType target, PositionOrUnit pos, bool flag1) { return unit->canUseTech(target, pos, flag1); },
			[](UnitInterface* unit, TechType target, PositionOrUnit pos, bool flag1, bool flag2) { return unit->canUseTech(target, pos, flag1, flag2); },
			[](UnitInterface* unit, TechType target, PositionOrUnit pos, bool flag1, bool flag2, bool flag3) { return unit->canUseTech(target, pos, flag1, flag2, flag3); },
			static_cast<bool (UnitInterface::*)(TechType, PositionOrUnit, bool, bool, bool, bool) const>(&UnitInterface::canUseTech)
		));
		unit.set("canUseTechWithoutTarget", sol::overload(
			[](UnitInterface* unit, TechType target) { return unit->canUseTechWithoutTarget(target); },
			[](UnitInterface* unit, TechType target, bool flag1) { return unit->canUseTechWithoutTarget(target, flag1); },
			static_cast<bool (UnitInterface::*)(TechType, bool, bool) const>(&UnitInterface::canUseTechWithoutTarget)
		));
		unit.set("canUseTechUnit", sol::overload(
			[](UnitInterface* unit, TechType target) { return unit->canUseTechUnit(target); },
			[](UnitInterface* unit, TechType target, bool flag1) { return unit->canUseTechUnit(target, flag1); },
			static_cast<bool (UnitInterface::*)(TechType, bool, bool) const>(&UnitInterface::canUseTechUnit),

			[](UnitInterface* unit, TechType type, Unit target) { return unit->canUseTechUnit(type, target); },
			[](UnitInterface* unit, TechType type, Unit target, bool flag1) { return unit->canUseTechUnit(type, target, flag1); },
			[](UnitInterface* unit, TechType type, Unit target, bool flag1, bool flag2) { return unit->canUseTechUnit(type, target, flag1, flag2); },
			[](UnitInterface* unit, TechType type, Unit target, bool flag1, bool flag2, bool flag3) { return unit->canUseTechUnit(type, target, flag1, flag2, flag3); },
			static_cast<bool (UnitInterface::*)(TechType, Unit, bool, bool, bool, bool) const>(&UnitInterface::canUseTechUnit)
		));
		unit.set("canUseTechPosition", sol::overload(
			[](UnitInterface* unit, TechType type) { return unit->canUseTechPosition(type); },
			[](UnitInterface* unit, TechType type, bool flag1) { return unit->canUseTechPosition(type, flag1); },
			static_cast<bool (UnitInterface::*)(TechType, bool, bool) const>(&UnitInterface::canUseTechPosition),

			[](UnitInterface* unit, TechType type, Position target) { return unit->canUseTechPosition(type, target); },
			[](UnitInterface* unit, TechType type, Position target, bool flag1) { return unit->canUseTechPosition(type, target, flag1); },
			[](UnitInterface* unit, TechType type, Position target, bool flag1, bool flag2) { return unit->canUseTechPosition(type, target, flag1, flag2); },
			static_cast<bool (UnitInterface::*)(TechType, Position, bool, bool, bool) const>(&UnitInterface::canUseTechPosition)
		));
		unit.set("canPlaceCOP", sol::overload(
			[](UnitInterface* unit) { return unit->canPlaceCOP(); },
			static_cast<bool (UnitInterface::*)(bool) const>(&UnitInterface::canPlaceCOP),

			[](UnitInterface* unit, TilePosition target) { return unit->canPlaceCOP(target); },
			[](UnitInterface* unit, TilePosition target, bool flag1) { return unit->canPlaceCOP(target, flag1); },
			static_cast<bool (UnitInterface::*)(TilePosition, bool, bool) const>(&UnitInterface::canPlaceCOP)
		));

		bindInterface(unit);
		bindIsInstance(unit);
		module.set_usertype("Unit", unit);
	}
}