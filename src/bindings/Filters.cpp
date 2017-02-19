#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindFilters(sol::table module)
	{
		module.new_simple_usertype<UnitFilter>("UnitFilter",
			"new", sol::nil,
			sol::meta_function::call, [](const UnitFilter& filter, Unit unit) {
				return filter(unit);
			}
		);
		module.new_simple_usertype<PtrUnitFilter>("PtrUnitFilter",
			"new", sol::nil,
			sol::meta_function::call, [](const PtrUnitFilter& filter, Unit unit) {
				return filter(unit);
			}
		);
		module.new_simple_usertype<BestUnitFilter>("BestUnitFilter",
			"new", sol::nil,
			sol::meta_function::call, [](const BestUnitFilter& filter, Unit unit1, Unit unit2) {
				return filter(unit1, unit2);
			}
		);
		module.new_simple_usertype<CompareFilter<Unit, UnitType, UnitType(*)(Unit)>>("UnitTypeCompareFilter",
			"new", sol::nil,
			sol::meta_function::call, [](const CompareFilter<Unit, UnitType, UnitType(*)(Unit)>& filter, Unit unit) {
				return filter(unit);
			}
		);
		auto filter = module.create_named("Filter");
		filter["IsTransport"] = &Filter::IsTransport;
		filter["CanProduce"] = &Filter::CanProduce;
		filter["CanAttack"] = &Filter::CanAttack;
		filter["CanMove"] = &Filter::CanMove;
		filter["IsFlyer"] = &Filter::IsFlyer;
		filter["IsFlying"] = &Filter::IsFlying;
		filter["RegeneratesHP"] = &Filter::RegeneratesHP;
		filter["IsSpellcaster"] = &Filter::IsSpellcaster;
		filter["HasPermanentCloak"] = &Filter::HasPermanentCloak;
		filter["IsOrganic"] = &Filter::IsOrganic;
		filter["IsMechanical"] = &Filter::IsMechanical;
		filter["IsRobotic"] = &Filter::IsRobotic;
		filter["IsDetector"] = &Filter::IsDetector;
		filter["IsResourceContainer"] = &Filter::IsResourceContainer;
		filter["IsResourceDepot"] = &Filter::IsResourceDepot;
		filter["IsRefinery"] = &Filter::IsRefinery;
		filter["IsWorker"] = &Filter::IsWorker;
		filter["RequiresPsi"] = &Filter::RequiresPsi;
		filter["RequiresCreep"] = &Filter::RequiresCreep;
		filter["IsBurrowable"] = &Filter::IsBurrowable;
		filter["IsCloakable"] = &Filter::IsCloakable;
		filter["IsBuilding"] = &Filter::IsBuilding;
		filter["IsAddon"] = &Filter::IsAddon;
		filter["IsFlyingBuilding"] = &Filter::IsFlyingBuilding;
		filter["IsNeutral"] = &Filter::IsNeutral;
		filter["IsHero"] = &Filter::IsHero;
		filter["IsPowerup"] = &Filter::IsPowerup;
		filter["IsBeacon"] = &Filter::IsBeacon;
		filter["IsFlagBeacon"] = &Filter::IsFlagBeacon;
		filter["IsSpecialBuilding"] = &Filter::IsSpecialBuilding;
		filter["IsSpell"] = &Filter::IsSpell;
		filter["ProducesLarva"] = &Filter::ProducesLarva;
		filter["IsMineralField"] = &Filter::IsMineralField;
		filter["IsCritter"] = &Filter::IsCritter;
		filter["CanBuildAddon"] = &Filter::CanBuildAddon;
		filter["HP"] = &Filter::HP;
		filter["MaxHP"] = &Filter::MaxHP;
		filter["HP_Percent"] = &Filter::HP_Percent;
		filter["Shields"] = &Filter::Shields;
		filter["MaxShields"] = &Filter::MaxShields;
		filter["Shields_Percent"] = &Filter::Shields_Percent;
		filter["Energy"] = &Filter::Energy;
		filter["MaxEnergy"] = &Filter::MaxEnergy;
		filter["Energy_Percent"] = &Filter::Energy_Percent;
		filter["Armor"] = &Filter::Armor;
		filter["ArmorUpgrade"] = &Filter::ArmorUpgrade;
		filter["MineralPrice"] = &Filter::MineralPrice;
		filter["GasPrice"] = &Filter::GasPrice;
		filter["BuildTime"] = &Filter::BuildTime;
		filter["SupplyRequired"] = &Filter::SupplyRequired;
		filter["SupplyProvided"] = &Filter::SupplyProvided;
		filter["SpaceRequired"] = &Filter::SpaceRequired;
		filter["SpaceRemaining"] = &Filter::SpaceRemaining;
		filter["SpaceProvided"] = &Filter::SpaceProvided;
		filter["BuildScore"] = &Filter::BuildScore;
		filter["DestroyScore"] = &Filter::DestroyScore;
		filter["TopSpeed"] = &Filter::TopSpeed;
		filter["SightRange"] = &Filter::SightRange;
		filter["WeaponCooldown"] = &Filter::WeaponCooldown;
		filter["SizeType"] = &Filter::SizeType;
		filter["GroundWeapon"] = &Filter::GroundWeapon;
		filter["AirWeapon"] = &Filter::AirWeapon;
		filter["GetType"] = &Filter::GetType;
		filter["GetRace"] = &Filter::GetRace;
		filter["GetPlayer"] = &Filter::GetPlayer;
		filter["Resources"] = &Filter::Resources;
		filter["ResourceGroup"] = &Filter::ResourceGroup;
		filter["AcidSporeCount"] = &Filter::AcidSporeCount;
		filter["InterceptorCount"] = &Filter::InterceptorCount;
		filter["ScarabCount"] = &Filter::ScarabCount;
		filter["SpiderMineCount"] = &Filter::SpiderMineCount;
		filter["MaxWeaponCooldown"] = &Filter::MaxWeaponCooldown;
		filter["SpellCooldown"] = &Filter::SpellCooldown;
		filter["DefenseMatrixPoints"] = &Filter::DefenseMatrixPoints;
		filter["DefenseMatrixTime"] = &Filter::DefenseMatrixTime;
		filter["EnsnareTime"] = &Filter::EnsnareTime;
		filter["IrradiateTime"] = &Filter::IrradiateTime;
		filter["LockdownTime"] = &Filter::LockdownTime;
		filter["MaelstromTime"] = &Filter::MaelstromTime;
		filter["OrderTime"] = &Filter::OrderTime;
		filter["PlagueTimer"] = &Filter::PlagueTimer;
		filter["RemoveTime"] = &Filter::RemoveTime;
		filter["StasisTime"] = &Filter::StasisTime;
		filter["StimTime"] = &Filter::StimTime;
		filter["BuildType"] = &Filter::BuildType;
		filter["RemainingBuildTime"] = &Filter::RemainingBuildTime;
		filter["RemainingTrainTime"] = &Filter::RemainingTrainTime;
		filter["Target"] = &Filter::Target;
		filter["CurrentOrder"] = &Filter::CurrentOrder;
		filter["SecondaryOrder"] = &Filter::SecondaryOrder;
		filter["OrderTarget"] = &Filter::OrderTarget;
		filter["GetLeft"] = &Filter::GetLeft;
		filter["GetTop"] = &Filter::GetTop;
		filter["GetRight"] = &Filter::GetRight;
		filter["GetBottom"] = &Filter::GetBottom;
		filter["Exists"] = &Filter::Exists;
		filter["IsAttacking"] = &Filter::IsAttacking;
		filter["IsBeingConstructed"] = &Filter::IsBeingConstructed;
		filter["IsBeingGathered"] = &Filter::IsBeingGathered;
		filter["IsBeingHealed"] = &Filter::IsBeingHealed;
		filter["IsBlind"] = &Filter::IsBlind;
		filter["IsBraking"] = &Filter::IsBraking;
		filter["IsBurrowed"] = &Filter::IsBurrowed;
		filter["IsCarryingGas"] = &Filter::IsCarryingGas;
		filter["IsCarryingMinerals"] = &Filter::IsCarryingMinerals;
		filter["IsCarryingSomething"] = &Filter::IsCarryingSomething;
		filter["IsCloaked"] = &Filter::IsCloaked;
		filter["IsCompleted"] = &Filter::IsCompleted;
		filter["IsConstructing"] = &Filter::IsConstructing;
		filter["IsDefenseMatrixed"] = &Filter::IsDefenseMatrixed;
		filter["IsDetected"] = &Filter::IsDetected;
		filter["IsEnsnared"] = &Filter::IsEnsnared;
		filter["IsFollowing"] = &Filter::IsFollowing;
		filter["IsGatheringGas"] = &Filter::IsGatheringGas;
		filter["IsGatheringMinerals"] = &Filter::IsGatheringMinerals;
		filter["IsHallucination"] = &Filter::IsHallucination;
		filter["IsHoldingPosition"] = &Filter::IsHoldingPosition;
		filter["IsIdle"] = &Filter::IsIdle;
		filter["IsInterruptible"] = &Filter::IsInterruptible;
		filter["IsInvincible"] = &Filter::IsInvincible;
		filter["IsIrradiated"] = &Filter::IsIrradiated;
		filter["IsLifted"] = &Filter::IsLifted;
		filter["IsLoaded"] = &Filter::IsLoaded;
		filter["IsLockedDown"] = &Filter::IsLockedDown;
		filter["IsMaelstrommed"] = &Filter::IsMaelstrommed;
		filter["IsMorphing"] = &Filter::IsMorphing;
		filter["IsMoving"] = &Filter::IsMoving;
		filter["IsParasited"] = &Filter::IsParasited;
		filter["IsPatrolling"] = &Filter::IsPatrolling;
		filter["IsPlagued"] = &Filter::IsPlagued;
		filter["IsRepairing"] = &Filter::IsRepairing;
		filter["IsResearching"] = &Filter::IsResearching;
		filter["IsSieged"] = &Filter::IsSieged;
		filter["IsStartingAttack"] = &Filter::IsStartingAttack;
		filter["IsStasised"] = &Filter::IsStasised;
		filter["IsStimmed"] = &Filter::IsStimmed;
		filter["IsStuck"] = &Filter::IsStuck;
		filter["IsTraining"] = &Filter::IsTraining;
		filter["IsUnderAttack"] = &Filter::IsUnderAttack;
		filter["IsUnderDarkSwarm"] = &Filter::IsUnderDarkSwarm;
		filter["IsUnderDisruptionWeb"] = &Filter::IsUnderDisruptionWeb;
		filter["IsUnderStorm"] = &Filter::IsUnderStorm;
		filter["IsPowered"] = &Filter::IsPowered;
		filter["IsVisible"] = &Filter::IsVisible;
		filter["IsEnemy"] = &Filter::IsEnemy;
		filter["IsAlly"] = &Filter::IsAlly;
		filter["IsOwned"] = &Filter::IsOwned;
	}
}