#include <sol.hpp>
#include <BWAPI.h>
#include "SetContainer.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUnitset(sol::table module)
	{
		auto unitset = module.create_simple_usertype<Unitset>();
		bindSetContainer<Unitset, Unit>(unitset);

		// static
		unitset.set("none", &Unitset::none);

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
			[](const Unitset& set, const PositionOrUnit& pos) { return set.attack(pos); },
			static_cast<bool (Unitset::*)(PositionOrUnit, bool) const>(&Unitset::attack)
		));
		unitset.set("build", sol::overload(
			[](const Unitset& set, UnitType type) { return set.build(type); },
			static_cast<bool (Unitset::*)(UnitType, TilePosition) const>(&Unitset::build)
		));
		unitset.set("buildAddon", &Unitset::buildAddon);
		unitset.set("train", sol::overload(
			[](const Unitset& set) { return set.train(); },
			static_cast<bool (Unitset::*)(UnitType) const>(&Unitset::train)
		));
		unitset.set("morph", &Unitset::morph);
		unitset.set("setRallyPoint", &Unitset::setRallyPoint);
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
			[](const Unitset& set, const PositionOrUnit& pos) { return set.rightClick(pos); },
			static_cast<bool (Unitset::*)(PositionOrUnit, bool) const>(&Unitset::rightClick)
		));
		unitset.set("haltConstruction", &Unitset::haltConstruction);
		unitset.set("cancelConstruction", &Unitset::cancelConstruction);
		unitset.set("cancelAddon", &Unitset::cancelAddon);
		unitset.set("cancelTrain", sol::overload(
			[](const Unitset& set) { return set.cancelTrain(); },
			[](const Unitset& set, int slot)
			{
				// convert from Lua index to C++ index for slots >= 1
				if (slot >= 1)
					slot -= 1;

				return set.cancelTrain(slot);
			}
		));
		unitset.set("cancelMorph", &Unitset::cancelMorph);
		unitset.set("cancelResearch", &Unitset::cancelResearch);
		unitset.set("cancelUpgrade", &Unitset::cancelUpgrade);
		unitset.set("useTech", sol::overload(
			[](const Unitset& set, const TechType& type) { return set.useTech(type); },
			static_cast<bool (Unitset::*)(TechType, PositionOrUnit) const>(&Unitset::useTech)
		));

		module.set_usertype("Unitset", unitset);
	}
}