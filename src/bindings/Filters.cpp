#include <sol.hpp>
#include <BWAPI.h>
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	template<typename Type>
	auto unaryFilterAsFunction(const UnaryFilter<Type, bool(*)(Type)>& filter)
	{
		return sol::as_function([&filter](const Unit val) { return filter(val); });
	}

	template<typename Type, typename CompareType>
	auto compareFilterAsFunction(const CompareFilter<Type, CompareType, CompareType(*)(Type)>& filter)
	{
		return sol::as_function([&filter](const Unit val) { return filter(val); });
	}

	void bindFilters(sol::table module)
	{
		sol::state_view lua(module.lua_state());

		sol::function Lowest = lua.do_string(R"(
return function(filter)
	return function(a, b)
		if filter(b) < filter(a) then
			return b
		else
			return a
		end
	end
end
		)");
		module.set("Lowest", Lowest);

		sol::function Highest = lua.do_string(R"(
return function(filter)
	return function(a, b)
		if filter(b) > filter(a) then
			return b
		else
			return a
		end
	end
end
		)");
		module.set("Highest", Highest);

		auto filter = module.create_named("Filter");
		filter["IsTransport"] = unaryFilterAsFunction(Filter::IsTransport);
		filter["CanProduce"] = unaryFilterAsFunction(Filter::CanProduce);
		filter["CanAttack"] = unaryFilterAsFunction(Filter::CanAttack);
		filter["CanMove"] = unaryFilterAsFunction(Filter::CanMove);
		filter["IsFlyer"] = unaryFilterAsFunction(Filter::IsFlyer);
		filter["IsFlying"] = unaryFilterAsFunction(Filter::IsFlying);
		filter["RegeneratesHP"] = unaryFilterAsFunction(Filter::RegeneratesHP);
		filter["IsSpellcaster"] = unaryFilterAsFunction(Filter::IsSpellcaster);
		filter["HasPermanentCloak"] = unaryFilterAsFunction(Filter::HasPermanentCloak);
		filter["IsOrganic"] = unaryFilterAsFunction(Filter::IsOrganic);
		filter["IsMechanical"] = unaryFilterAsFunction(Filter::IsMechanical);
		filter["IsRobotic"] = unaryFilterAsFunction(Filter::IsRobotic);
		filter["IsDetector"] = unaryFilterAsFunction(Filter::IsDetector);
		filter["IsResourceContainer"] = unaryFilterAsFunction(Filter::IsResourceContainer);
		filter["IsResourceDepot"] = unaryFilterAsFunction(Filter::IsResourceDepot);
		filter["IsRefinery"] = unaryFilterAsFunction(Filter::IsRefinery);
		filter["IsWorker"] = unaryFilterAsFunction(Filter::IsWorker);
		filter["RequiresPsi"] = unaryFilterAsFunction(Filter::RequiresPsi);
		filter["RequiresCreep"] = unaryFilterAsFunction(Filter::RequiresCreep);
		filter["IsBurrowable"] = unaryFilterAsFunction(Filter::IsBurrowable);
		filter["IsCloakable"] = unaryFilterAsFunction(Filter::IsCloakable);
		filter["IsBuilding"] = unaryFilterAsFunction(Filter::IsBuilding);
		filter["IsAddon"] = unaryFilterAsFunction(Filter::IsAddon);
		filter["IsFlyingBuilding"] = unaryFilterAsFunction(Filter::IsFlyingBuilding);
		filter["IsNeutral"] = unaryFilterAsFunction(Filter::IsNeutral);
		filter["IsHero"] = unaryFilterAsFunction(Filter::IsHero);
		filter["IsPowerup"] = unaryFilterAsFunction(Filter::IsPowerup);
		filter["IsBeacon"] = unaryFilterAsFunction(Filter::IsBeacon);
		filter["IsFlagBeacon"] = unaryFilterAsFunction(Filter::IsFlagBeacon);
		filter["IsSpecialBuilding"] = unaryFilterAsFunction(Filter::IsSpecialBuilding);
		filter["IsSpell"] = unaryFilterAsFunction(Filter::IsSpell);
		filter["ProducesLarva"] = unaryFilterAsFunction(Filter::ProducesLarva);
		filter["IsMineralField"] = unaryFilterAsFunction(Filter::IsMineralField);
		filter["IsCritter"] = unaryFilterAsFunction(Filter::IsCritter);
		filter["CanBuildAddon"] = unaryFilterAsFunction(Filter::CanBuildAddon);

		filter["HP"] = compareFilterAsFunction(Filter::HP);
		filter["MaxHP"] = compareFilterAsFunction(Filter::MaxHP);
		filter["HP_Percent"] = compareFilterAsFunction(Filter::HP_Percent);
		filter["Shields"] = compareFilterAsFunction(Filter::Shields);
		filter["MaxShields"] = compareFilterAsFunction(Filter::MaxShields);
		filter["Shields_Percent"] = compareFilterAsFunction(Filter::Shields_Percent);
		filter["Energy"] = compareFilterAsFunction(Filter::Energy);
		filter["MaxEnergy"] = compareFilterAsFunction(Filter::MaxEnergy);
		filter["Energy_Percent"] = compareFilterAsFunction(Filter::Energy_Percent);
		filter["Armor"] = compareFilterAsFunction(Filter::Armor);
		filter["ArmorUpgrade"] = compareFilterAsFunction(Filter::ArmorUpgrade);
		filter["MineralPrice"] = compareFilterAsFunction(Filter::MineralPrice);
		filter["GasPrice"] = compareFilterAsFunction(Filter::GasPrice);
		filter["BuildTime"] = compareFilterAsFunction(Filter::BuildTime);
		filter["SupplyRequired"] = compareFilterAsFunction(Filter::SupplyRequired);
		filter["SupplyProvided"] = compareFilterAsFunction(Filter::SupplyProvided);
		filter["SpaceRequired"] = compareFilterAsFunction(Filter::SpaceRequired);
		filter["SpaceRemaining"] = compareFilterAsFunction(Filter::SpaceRemaining);
		filter["SpaceProvided"] = compareFilterAsFunction(Filter::SpaceProvided);
		filter["BuildScore"] = compareFilterAsFunction(Filter::BuildScore);
		filter["DestroyScore"] = compareFilterAsFunction(Filter::DestroyScore);
		filter["TopSpeed"] = compareFilterAsFunction(Filter::TopSpeed);
		filter["SightRange"] = compareFilterAsFunction(Filter::SightRange);
		filter["WeaponCooldown"] = compareFilterAsFunction(Filter::WeaponCooldown);
		filter["SizeType"] = compareFilterAsFunction(Filter::SizeType);
		filter["GroundWeapon"] = compareFilterAsFunction(Filter::GroundWeapon);
		filter["AirWeapon"] = compareFilterAsFunction(Filter::AirWeapon);
		filter["GetType"] = compareFilterAsFunction(Filter::GetType);
		filter["GetRace"] = compareFilterAsFunction(Filter::GetRace);
		filter["GetPlayer"] = compareFilterAsFunction(Filter::GetPlayer);
		filter["Resources"] = compareFilterAsFunction(Filter::Resources);
		filter["ResourceGroup"] = compareFilterAsFunction(Filter::ResourceGroup);
		filter["AcidSporeCount"] = compareFilterAsFunction(Filter::AcidSporeCount);
		filter["InterceptorCount"] = compareFilterAsFunction(Filter::InterceptorCount);
		filter["ScarabCount"] = compareFilterAsFunction(Filter::ScarabCount);
		filter["SpiderMineCount"] = compareFilterAsFunction(Filter::SpiderMineCount);
		filter["MaxWeaponCooldown"] = compareFilterAsFunction(Filter::MaxWeaponCooldown);
		filter["SpellCooldown"] = compareFilterAsFunction(Filter::SpellCooldown);
		filter["DefenseMatrixPoints"] = compareFilterAsFunction(Filter::DefenseMatrixPoints);
		filter["DefenseMatrixTime"] = compareFilterAsFunction(Filter::DefenseMatrixTime);
		filter["EnsnareTime"] = compareFilterAsFunction(Filter::EnsnareTime);
		filter["IrradiateTime"] = compareFilterAsFunction(Filter::IrradiateTime);
		filter["LockdownTime"] = compareFilterAsFunction(Filter::LockdownTime);
		filter["MaelstromTime"] = compareFilterAsFunction(Filter::MaelstromTime);
		filter["OrderTime"] = compareFilterAsFunction(Filter::OrderTime);
		filter["PlagueTimer"] = compareFilterAsFunction(Filter::PlagueTimer);
		filter["RemoveTime"] = compareFilterAsFunction(Filter::RemoveTime);
		filter["StasisTime"] = compareFilterAsFunction(Filter::StasisTime);
		filter["StimTime"] = compareFilterAsFunction(Filter::StimTime);
		filter["BuildType"] = compareFilterAsFunction(Filter::BuildType);
		filter["RemainingBuildTime"] = compareFilterAsFunction(Filter::RemainingBuildTime);
		filter["RemainingTrainTime"] = compareFilterAsFunction(Filter::RemainingTrainTime);
		filter["Target"] = compareFilterAsFunction(Filter::Target);
		filter["CurrentOrder"] = compareFilterAsFunction(Filter::CurrentOrder);
		filter["SecondaryOrder"] = compareFilterAsFunction(Filter::SecondaryOrder);
		filter["OrderTarget"] = compareFilterAsFunction(Filter::OrderTarget);
		filter["GetLeft"] = compareFilterAsFunction(Filter::GetLeft);
		filter["GetTop"] = compareFilterAsFunction(Filter::GetTop);
		filter["GetRight"] = compareFilterAsFunction(Filter::GetRight);
		filter["GetBottom"] = compareFilterAsFunction(Filter::GetBottom);

		filter["Exists"] = unaryFilterAsFunction(Filter::Exists);
		filter["IsAttacking"] = unaryFilterAsFunction(Filter::IsAttacking);
		filter["IsBeingConstructed"] = unaryFilterAsFunction(Filter::IsBeingConstructed);
		filter["IsBeingGathered"] = unaryFilterAsFunction(Filter::IsBeingGathered);
		filter["IsBeingHealed"] = unaryFilterAsFunction(Filter::IsBeingHealed);
		filter["IsBlind"] = unaryFilterAsFunction(Filter::IsBlind);
		filter["IsBraking"] = unaryFilterAsFunction(Filter::IsBraking);
		filter["IsBurrowed"] = unaryFilterAsFunction(Filter::IsBurrowed);
		filter["IsCarryingGas"] = unaryFilterAsFunction(Filter::IsCarryingGas);
		filter["IsCarryingMinerals"] = unaryFilterAsFunction(Filter::IsCarryingMinerals);
		filter["IsCarryingSomething"] = unaryFilterAsFunction(Filter::IsCarryingSomething);
		filter["IsCloaked"] = unaryFilterAsFunction(Filter::IsCloaked);
		filter["IsCompleted"] = unaryFilterAsFunction(Filter::IsCompleted);
		filter["IsConstructing"] = unaryFilterAsFunction(Filter::IsConstructing);
		filter["IsDefenseMatrixed"] = unaryFilterAsFunction(Filter::IsDefenseMatrixed);
		filter["IsDetected"] = unaryFilterAsFunction(Filter::IsDetected);
		filter["IsEnsnared"] = unaryFilterAsFunction(Filter::IsEnsnared);
		filter["IsFollowing"] = unaryFilterAsFunction(Filter::IsFollowing);
		filter["IsGatheringGas"] = unaryFilterAsFunction(Filter::IsGatheringGas);
		filter["IsGatheringMinerals"] = unaryFilterAsFunction(Filter::IsGatheringMinerals);
		filter["IsHallucination"] = unaryFilterAsFunction(Filter::IsHallucination);
		filter["IsHoldingPosition"] = unaryFilterAsFunction(Filter::IsHoldingPosition);
		filter["IsIdle"] = unaryFilterAsFunction(Filter::IsIdle);
		filter["IsInterruptible"] = unaryFilterAsFunction(Filter::IsInterruptible);
		filter["IsInvincible"] = unaryFilterAsFunction(Filter::IsInvincible);
		filter["IsIrradiated"] = unaryFilterAsFunction(Filter::IsIrradiated);
		filter["IsLifted"] = unaryFilterAsFunction(Filter::IsLifted);
		filter["IsLoaded"] = unaryFilterAsFunction(Filter::IsLoaded);
		filter["IsLockedDown"] = unaryFilterAsFunction(Filter::IsLockedDown);
		filter["IsMaelstrommed"] = unaryFilterAsFunction(Filter::IsMaelstrommed);
		filter["IsMorphing"] = unaryFilterAsFunction(Filter::IsMorphing);
		filter["IsMoving"] = unaryFilterAsFunction(Filter::IsMoving);
		filter["IsParasited"] = unaryFilterAsFunction(Filter::IsParasited);
		filter["IsPatrolling"] = unaryFilterAsFunction(Filter::IsPatrolling);
		filter["IsPlagued"] = unaryFilterAsFunction(Filter::IsPlagued);
		filter["IsRepairing"] = unaryFilterAsFunction(Filter::IsRepairing);
		filter["IsResearching"] = unaryFilterAsFunction(Filter::IsResearching);
		filter["IsSieged"] = unaryFilterAsFunction(Filter::IsSieged);
		filter["IsStartingAttack"] = unaryFilterAsFunction(Filter::IsStartingAttack);
		filter["IsStasised"] = unaryFilterAsFunction(Filter::IsStasised);
		filter["IsStimmed"] = unaryFilterAsFunction(Filter::IsStimmed);
		filter["IsStuck"] = unaryFilterAsFunction(Filter::IsStuck);
		filter["IsTraining"] = unaryFilterAsFunction(Filter::IsTraining);
		filter["IsUnderAttack"] = unaryFilterAsFunction(Filter::IsUnderAttack);
		filter["IsUnderDarkSwarm"] = unaryFilterAsFunction(Filter::IsUnderDarkSwarm);
		filter["IsUnderDisruptionWeb"] = unaryFilterAsFunction(Filter::IsUnderDisruptionWeb);
		filter["IsUnderStorm"] = unaryFilterAsFunction(Filter::IsUnderStorm);
		filter["IsPowered"] = unaryFilterAsFunction(Filter::IsPowered);
		filter["IsVisible"] = unaryFilterAsFunction(Filter::IsVisible);
		filter["IsEnemy"] = unaryFilterAsFunction(Filter::IsEnemy);
		filter["IsAlly"] = unaryFilterAsFunction(Filter::IsAlly);
		filter["IsOwned"] = unaryFilterAsFunction(Filter::IsOwned);
	}
}