#include <sol.hpp>
#include <BWAPI.h>
#include "SetContainer.h"
#include "IsInstance.h"
#include "TrainingSlot.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnitset(sol::table module)
	{
		auto unitset = module.create_simple_usertype<Unitset>();
		bindSetContainer<Unitset, Unit>(unitset);
		bindIsInstance(unitset);

		// member functions
		unitset.set("getPosition", &Unitset::getPosition);
		unitset.set("getLoadedUnits", &Unitset::getLoadedUnits);
		unitset.set("getInterceptors", &Unitset::getInterceptors);
		unitset.set("getLarva", &Unitset::getLarva);
		unitset.set("getUnitsInRadius", sol::overload(
			[](const Unitset& set, int radius) { return set.getUnitsInRadius(radius); },
			[](const Unitset& set, int radius, const sol::function& pred) 
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return set.getUnitsInRadius(radius, filter); 
			},
			&Unitset::getUnitsInRadius
		));
		unitset.set("getClosestUnit", sol::overload(
			[](const Unitset& set) { return set.getClosestUnit(); },
			[](const Unitset& set, const sol::function& pred) 
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return set.getClosestUnit(filter);
			},
			[](const Unitset& set, const sol::function& pred, int radius)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return set.getClosestUnit(filter, radius);
			},
			[](const Unitset& set, const UnitFilter& filter)
			{
				return set.getClosestUnit(filter);
			},
			&Unitset::getClosestUnit
		));
		unitset.set("issueCommand", &Unitset::issueCommand);

		// commands
		unitset.set("attack", sol::overload(
			[](const Unitset& set, const Position& pos) { return set.attack(PositionOrUnit(pos)); },
			[](const Unitset& set, const Position& pos, bool flag1) { return set.attack(PositionOrUnit(pos), flag1); },
			[](const Unitset& set, Unit pos) { return set.attack(PositionOrUnit(pos)); },
			[](const Unitset& set, Unit pos, bool flag1) { return set.attack(PositionOrUnit(pos), flag1); }
		));
		unitset.set("build", sol::overload(
			[](const Unitset& set, UnitType type) { return set.build(type); },
			static_cast<bool (Unitset::*)(UnitType, TilePosition) const>(&Unitset::build)
		));
		unitset.set("buildAddon", &Unitset::buildAddon);
		unitset.set("train", &Unitset::train);
		unitset.set("morph", &Unitset::morph);
		unitset.set("setRallyPoint", sol::overload(
			[](const Unitset& set, const Position& pos) { return set.setRallyPoint(PositionOrUnit(pos)); },
			[](const Unitset& set, Unit pos) { return set.setRallyPoint(PositionOrUnit(pos)); }
		));
		unitset.set("move", sol::overload(
			[](const Unitset& set, const Position& pos) { return set.move(pos); },
			static_cast<bool (Unitset::*)(Position, bool) const>(&Unitset::move)
		));
		unitset.set("patrol", sol::overload(
			[](const Unitset& set, const Position& pos) { return set.patrol(pos); },
			static_cast<bool (Unitset::*)(Position, bool) const>(&Unitset::patrol)
		));
		unitset.set("holdPosition", sol::overload(
			[](const Unitset& set) { return set.holdPosition(); },
			static_cast<bool (Unitset::*)(bool) const>(&Unitset::holdPosition)
		));
		unitset.set("stop", sol::overload(
			[](const Unitset& set) { return set.stop(); },
			static_cast<bool (Unitset::*)(bool) const>(&Unitset::stop)
		));
		unitset.set("follow", sol::overload(
			[](const Unitset& set, const Unit unitToFollow) { return set.follow(unitToFollow); },
			static_cast<bool (Unitset::*)(Unit, bool) const>(&Unitset::follow)
		));
		unitset.set("gather", sol::overload(
			[](const Unitset& set, const Unit toGather) { return set.gather(toGather); },
			static_cast<bool (Unitset::*)(Unit, bool) const>(&Unitset::gather)
		));
		unitset.set("returnCargo", sol::overload(
			[](const Unitset& set) { return set.returnCargo(); },
			static_cast<bool (Unitset::*)(bool) const>(&Unitset::returnCargo)
		));
		unitset.set("repair", sol::overload(
			[](const Unitset& set, const Unit toRepair) { return set.repair(toRepair); },
			static_cast<bool (Unitset::*)(Unit, bool) const>(&Unitset::repair)
		));
		unitset.set("burrow", &Unitset::burrow);
		unitset.set("unburrow", &Unitset::unburrow);
		unitset.set("cloak", &Unitset::cloak);
		unitset.set("decloak", &Unitset::decloak);
		unitset.set("siege", &Unitset::siege);
		unitset.set("unsiege", &Unitset::unsiege);
		unitset.set("lift", &Unitset::lift);
		unitset.set("load", sol::overload(
			[](const Unitset& set, const Unit target) { return set.load(target); },
			static_cast<bool (Unitset::*)(Unit, bool) const>(&Unitset::load)
		));
		unitset.set("unloadAll", sol::overload(
			[](const Unitset& set) { return set.unloadAll(); },
			static_cast<bool (Unitset::*)(bool) const>(&Unitset::unloadAll),
			[](const Unitset& set, const Position& pos) { return set.unloadAll(pos); },
			static_cast<bool (Unitset::*)(Position, bool) const>(&Unitset::unloadAll)
		));
		unitset.set("rightClick", sol::overload(
			[](const Unitset& set, const Position& pos) { return set.rightClick(PositionOrUnit(pos)); },
			[](const Unitset& set, const Position& pos, bool flag1) { return set.rightClick(PositionOrUnit(pos), flag1); },
			[](const Unitset& set, Unit pos) { return set.rightClick(PositionOrUnit(pos)); },
			[](const Unitset& set, Unit pos, bool flag1) { return set.rightClick(PositionOrUnit(pos), flag1); }
		));
		unitset.set("haltConstruction", &Unitset::haltConstruction);
		unitset.set("cancelConstruction", &Unitset::cancelConstruction);
		unitset.set("cancelAddon", &Unitset::cancelAddon);
		unitset.set("cancelTrain", sol::overload(
			[](const Unitset& set) { return set.cancelTrain(); },
			[](const Unitset& set, int slot)
			{
				slot = toActualTrainingSlot(slot);
				return set.cancelTrain(slot);
			}
		));
		unitset.set("cancelMorph", &Unitset::cancelMorph);
		unitset.set("cancelResearch", &Unitset::cancelResearch);
		unitset.set("cancelUpgrade", &Unitset::cancelUpgrade);
		unitset.set("useTech", sol::overload(
			[](const Unitset& set, const TechType& type) { return set.useTech(type); },
			[](const Unitset& set, const TechType& tech, const Position& pos) { return set.useTech(tech, PositionOrUnit(pos)); },
			[](const Unitset& set, const TechType& tech, Unit pos) { return set.useTech(tech, PositionOrUnit(pos)); }
		));

		module.set_usertype("Unitset", unitset);
	}
}