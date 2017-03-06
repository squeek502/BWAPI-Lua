#include <sol.hpp>
#include <BWAPI.h>
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnitCommand(sol::table module)
	{
		auto constructors = sol::constructors <sol::types<>, sol::types<Unit, UnitCommandType, Unit, int, int, int>>();
		auto unitCommand = module.create_simple_usertype<UnitCommand>(
			sol::meta_function::construct, constructors,
			sol::call_constructor, constructors,
			"getType", &UnitCommand::getType,
			"getUnit", &UnitCommand::getUnit,
			"getTarget", &UnitCommand::getTarget,
			"getTargetPosition", &UnitCommand::getTargetPosition,
			"getTargetTilePosition", &UnitCommand::getTargetTilePosition,
			"getUnitType", &UnitCommand::getUnitType,
			"getTechType", &UnitCommand::getTechType,
			"getUpgradeType", &UnitCommand::getUpgradeType,
			"getSlot", &UnitCommand::getSlot,
			"isQueued", &UnitCommand::isQueued,
			sol::meta_function::equal_to, &UnitCommand::operator==
		);

		// static functions
		unitCommand.set("attack", sol::overload(
			[](Unit unit, const PositionOrUnit& posOrUnit) { return UnitCommand::attack(unit, posOrUnit); },
			&UnitCommand::attack
		));
		unitCommand.set("build", &UnitCommand::build);
		unitCommand.set("buildAddon", &UnitCommand::buildAddon);
		unitCommand.set("train", &UnitCommand::train);
		unitCommand.set("morph", &UnitCommand::morph);
		unitCommand.set("research", &UnitCommand::research);
		unitCommand.set("upgrade", &UnitCommand::upgrade);
		unitCommand.set("setRallyPoint", &UnitCommand::setRallyPoint);
		unitCommand.set("move", sol::overload(
			[](Unit unit, const Position& pos) { return UnitCommand::move(unit, pos); },
			&UnitCommand::move
		));
		unitCommand.set("patrol", sol::overload(
			[](Unit unit, const Position& pos) { return UnitCommand::patrol(unit, pos); },
			&UnitCommand::patrol
		));
		unitCommand.set("holdPosition", sol::overload(
			[](Unit unit) { return UnitCommand::holdPosition(unit); },
			&UnitCommand::holdPosition
		));
		unitCommand.set("stop", sol::overload(
			[](Unit unit) { return UnitCommand::stop(unit); },
			&UnitCommand::stop
		));
		unitCommand.set("follow", sol::overload(
			[](Unit unit, Unit target) { return UnitCommand::follow(unit, target); },
			&UnitCommand::follow
		));
		unitCommand.set("gather", sol::overload(
			[](Unit unit, Unit target) { return UnitCommand::gather(unit, target); },
			&UnitCommand::gather
		));
		unitCommand.set("returnCargo", sol::overload(
			[](Unit unit) { return UnitCommand::returnCargo(unit); },
			&UnitCommand::returnCargo
		));
		unitCommand.set("repair", sol::overload(
			[](Unit unit, Unit target) { return UnitCommand::repair(unit, target); },
			&UnitCommand::repair
		));
		unitCommand.set("burrow", &UnitCommand::burrow);
		unitCommand.set("unburrow", &UnitCommand::unburrow);
		unitCommand.set("cloak", &UnitCommand::cloak);
		unitCommand.set("decloak", &UnitCommand::decloak);
		unitCommand.set("siege", &UnitCommand::siege);
		unitCommand.set("unsiege", &UnitCommand::unsiege);
		unitCommand.set("lift", &UnitCommand::lift);
		unitCommand.set("land", &UnitCommand::land);
		unitCommand.set("load", sol::overload(
			[](Unit unit, Unit target) { return UnitCommand::load(unit, target); },
			&UnitCommand::load
		));
		unitCommand.set("unload", &UnitCommand::unload);
		unitCommand.set("unloadAll", sol::overload(
			[](Unit unit) { return UnitCommand::unloadAll(unit); },
			sol::resolve<UnitCommand(Unit, bool)>(&UnitCommand::unloadAll),
			[](Unit unit, const Position& pos) { return UnitCommand::unloadAll(unit, pos); },
			sol::resolve<UnitCommand(Unit, Position, bool)>(&UnitCommand::unloadAll)
		));
		unitCommand.set("rightClick", sol::overload(
			[](Unit unit, PositionOrUnit target) { return UnitCommand::rightClick(unit, target); },
			&UnitCommand::rightClick
		));
		unitCommand.set("haltConstruction", &UnitCommand::haltConstruction);
		unitCommand.set("cancelConstruction", &UnitCommand::cancelConstruction);
		unitCommand.set("cancelAddon", &UnitCommand::cancelAddon);
		unitCommand.set("cancelTrain", sol::overload(
			[](Unit unit) { return UnitCommand::cancelTrain(unit); },
			&UnitCommand::cancelTrain
		));
		unitCommand.set("cancelMorph", &UnitCommand::cancelMorph);
		unitCommand.set("cancelResearch", &UnitCommand::cancelResearch);
		unitCommand.set("cancelUpgrade", &UnitCommand::cancelUpgrade);
		unitCommand.set("useTech", sol::overload(
			sol::resolve<UnitCommand(Unit, TechType)>(&UnitCommand::useTech), 
			sol::resolve<UnitCommand(Unit, TechType, PositionOrUnit)>(&UnitCommand::useTech)
		));
		unitCommand.set("placeCOP", &UnitCommand::placeCOP);

		bindIsInstance(unitCommand);
		module.set_usertype("UnitCommand", unitCommand);
	}
}