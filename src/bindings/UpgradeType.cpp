#include <sol.hpp>
#include <BWAPI.h>
#include "Type.h"
#include "SetContainer.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindUpgradeType(sol::table module)
	{
		auto upgradeType = module.create_simple_usertype<UpgradeType>(
			"getRace", &UpgradeType::getRace,
			"mineralPrice", sol::overload(
				[](const UpgradeType& upgrade) { return upgrade.mineralPrice(); },
				&UpgradeType::mineralPrice
			),
			"mineralPriceFactor", &UpgradeType::mineralPriceFactor,
			"gasPrice", sol::overload(
				[](const UpgradeType& upgrade) { return upgrade.gasPrice(); },
				&UpgradeType::gasPrice
			),
			"gasPriceFactor", &UpgradeType::gasPriceFactor,
			"upgradeTime", sol::overload(
				[](const UpgradeType& upgrade) { return upgrade.upgradeTime(); },
				&UpgradeType::upgradeTime
			),
			"upgradeTimeFactor", &UpgradeType::upgradeTimeFactor,
			"maxRepeats", &UpgradeType::maxRepeats,
			"whatUpgrades", &UpgradeType::whatUpgrades,
			"whatsRequired", sol::overload(
				[](const UpgradeType& upgrade) { return upgrade.whatsRequired(); },
				&UpgradeType::whatsRequired
			),
			"whatUses", &UpgradeType::whatUses
		);
		bindType<UpgradeType>(upgradeType);
		module.set_usertype("UpgradeType", upgradeType);

		auto upgradeTypeSet = module.create_simple_usertype<UpgradeType::set>();
		bindSetContainer<UpgradeType::set, UpgradeType>(upgradeTypeSet);
		module.set_usertype("UpgradeTypeset", upgradeTypeSet);

		auto upgradeTypes = module.create_named("UpgradeTypes");
		upgradeTypes["Terran_Infantry_Armor"] = &UpgradeTypes::Terran_Infantry_Armor;
		upgradeTypes["Terran_Vehicle_Plating"] = &UpgradeTypes::Terran_Vehicle_Plating;
		upgradeTypes["Terran_Ship_Plating"] = &UpgradeTypes::Terran_Ship_Plating;
		upgradeTypes["Terran_Infantry_Weapons"] = &UpgradeTypes::Terran_Infantry_Weapons;
		upgradeTypes["Terran_Vehicle_Weapons"] = &UpgradeTypes::Terran_Vehicle_Weapons;
		upgradeTypes["Terran_Ship_Weapons"] = &UpgradeTypes::Terran_Ship_Weapons;
		upgradeTypes["U_238_Shells"] = &UpgradeTypes::U_238_Shells;
		upgradeTypes["Ion_Thrusters"] = &UpgradeTypes::Ion_Thrusters;
		upgradeTypes["Titan_Reactor"] = &UpgradeTypes::Titan_Reactor;
		upgradeTypes["Ocular_Implants"] = &UpgradeTypes::Ocular_Implants;
		upgradeTypes["Moebius_Reactor"] = &UpgradeTypes::Moebius_Reactor;
		upgradeTypes["Apollo_Reactor"] = &UpgradeTypes::Apollo_Reactor;
		upgradeTypes["Colossus_Reactor"] = &UpgradeTypes::Colossus_Reactor;
		upgradeTypes["Caduceus_Reactor"] = &UpgradeTypes::Caduceus_Reactor;
		upgradeTypes["Charon_Boosters"] = &UpgradeTypes::Charon_Boosters;
		upgradeTypes["Zerg_Carapace"] = &UpgradeTypes::Zerg_Carapace;
		upgradeTypes["Zerg_Flyer_Carapace"] = &UpgradeTypes::Zerg_Flyer_Carapace;
		upgradeTypes["Zerg_Melee_Attacks"] = &UpgradeTypes::Zerg_Melee_Attacks;
		upgradeTypes["Zerg_Missile_Attacks"] = &UpgradeTypes::Zerg_Missile_Attacks;
		upgradeTypes["Zerg_Flyer_Attacks"] = &UpgradeTypes::Zerg_Flyer_Attacks;
		upgradeTypes["Ventral_Sacs"] = &UpgradeTypes::Ventral_Sacs;
		upgradeTypes["Antennae"] = &UpgradeTypes::Antennae;
		upgradeTypes["Pneumatized_Carapace"] = &UpgradeTypes::Pneumatized_Carapace;
		upgradeTypes["Metabolic_Boost"] = &UpgradeTypes::Metabolic_Boost;
		upgradeTypes["Adrenal_Glands"] = &UpgradeTypes::Adrenal_Glands;
		upgradeTypes["Muscular_Augments"] = &UpgradeTypes::Muscular_Augments;
		upgradeTypes["Grooved_Spines"] = &UpgradeTypes::Grooved_Spines;
		upgradeTypes["Gamete_Meiosis"] = &UpgradeTypes::Gamete_Meiosis;
		upgradeTypes["Metasynaptic_Node"] = &UpgradeTypes::Metasynaptic_Node;
		upgradeTypes["Chitinous_Plating"] = &UpgradeTypes::Chitinous_Plating;
		upgradeTypes["Anabolic_Synthesis"] = &UpgradeTypes::Anabolic_Synthesis;
		upgradeTypes["Protoss_Ground_Armor"] = &UpgradeTypes::Protoss_Ground_Armor;
		upgradeTypes["Protoss_Air_Armor"] = &UpgradeTypes::Protoss_Air_Armor;
		upgradeTypes["Protoss_Ground_Weapons"] = &UpgradeTypes::Protoss_Ground_Weapons;
		upgradeTypes["Protoss_Air_Weapons"] = &UpgradeTypes::Protoss_Air_Weapons;
		upgradeTypes["Protoss_Plasma_Shields"] = &UpgradeTypes::Protoss_Plasma_Shields;
		upgradeTypes["Singularity_Charge"] = &UpgradeTypes::Singularity_Charge;
		upgradeTypes["Leg_Enhancements"] = &UpgradeTypes::Leg_Enhancements;
		upgradeTypes["Scarab_Damage"] = &UpgradeTypes::Scarab_Damage;
		upgradeTypes["Reaver_Capacity"] = &UpgradeTypes::Reaver_Capacity;
		upgradeTypes["Gravitic_Drive"] = &UpgradeTypes::Gravitic_Drive;
		upgradeTypes["Sensor_Array"] = &UpgradeTypes::Sensor_Array;
		upgradeTypes["Gravitic_Boosters"] = &UpgradeTypes::Gravitic_Boosters;
		upgradeTypes["Khaydarin_Amulet"] = &UpgradeTypes::Khaydarin_Amulet;
		upgradeTypes["Apial_Sensors"] = &UpgradeTypes::Apial_Sensors;
		upgradeTypes["Gravitic_Thrusters"] = &UpgradeTypes::Gravitic_Thrusters;
		upgradeTypes["Carrier_Capacity"] = &UpgradeTypes::Carrier_Capacity;
		upgradeTypes["Khaydarin_Core"] = &UpgradeTypes::Khaydarin_Core;
		upgradeTypes["Argus_Jewel"] = &UpgradeTypes::Argus_Jewel;
		upgradeTypes["Argus_Talisman"] = &UpgradeTypes::Argus_Talisman;

		upgradeTypes["Upgrade_60"] = &UpgradeTypes::Upgrade_60;
		upgradeTypes["None"] = &UpgradeTypes::None;
		upgradeTypes["Unknown"] = &UpgradeTypes::Unknown;

		auto upgradeTypesEnum = upgradeTypes.create_named("Enum");
		upgradeTypesEnum["Terran_Infantry_Armor"] = UpgradeTypes::Enum::Terran_Infantry_Armor;
		upgradeTypesEnum["Terran_Vehicle_Plating"] = UpgradeTypes::Enum::Terran_Vehicle_Plating;
		upgradeTypesEnum["Terran_Ship_Plating"] = UpgradeTypes::Enum::Terran_Ship_Plating;
		upgradeTypesEnum["Zerg_Carapace"] = UpgradeTypes::Enum::Zerg_Carapace;
		upgradeTypesEnum["Zerg_Flyer_Carapace"] = UpgradeTypes::Enum::Zerg_Flyer_Carapace;
		upgradeTypesEnum["Protoss_Ground_Armor"] = UpgradeTypes::Enum::Protoss_Ground_Armor;
		upgradeTypesEnum["Protoss_Air_Armor"] = UpgradeTypes::Enum::Protoss_Air_Armor;
		upgradeTypesEnum["Terran_Infantry_Weapons"] = UpgradeTypes::Enum::Terran_Infantry_Weapons;
		upgradeTypesEnum["Terran_Vehicle_Weapons"] = UpgradeTypes::Enum::Terran_Vehicle_Weapons;
		upgradeTypesEnum["Terran_Ship_Weapons"] = UpgradeTypes::Enum::Terran_Ship_Weapons;
		upgradeTypesEnum["Zerg_Melee_Attacks"] = UpgradeTypes::Enum::Zerg_Melee_Attacks;
		upgradeTypesEnum["Zerg_Missile_Attacks"] = UpgradeTypes::Enum::Zerg_Missile_Attacks;
		upgradeTypesEnum["Zerg_Flyer_Attacks"] = UpgradeTypes::Enum::Zerg_Flyer_Attacks;
		upgradeTypesEnum["Protoss_Ground_Weapons"] = UpgradeTypes::Enum::Protoss_Ground_Weapons;
		upgradeTypesEnum["Protoss_Air_Weapons"] = UpgradeTypes::Enum::Protoss_Air_Weapons;
		upgradeTypesEnum["Protoss_Plasma_Shields"] = UpgradeTypes::Enum::Protoss_Plasma_Shields;
		upgradeTypesEnum["U_238_Shells"] = UpgradeTypes::Enum::U_238_Shells;
		upgradeTypesEnum["Ion_Thrusters"] = UpgradeTypes::Enum::Ion_Thrusters;

		upgradeTypesEnum["Titan_Reactor"] = UpgradeTypes::Enum::Titan_Reactor;
		upgradeTypesEnum["Ocular_Implants"] = UpgradeTypes::Enum::Ocular_Implants;
		upgradeTypesEnum["Moebius_Reactor"] = UpgradeTypes::Enum::Moebius_Reactor;
		upgradeTypesEnum["Apollo_Reactor"] = UpgradeTypes::Enum::Apollo_Reactor;
		upgradeTypesEnum["Colossus_Reactor"] = UpgradeTypes::Enum::Colossus_Reactor;
		upgradeTypesEnum["Ventral_Sacs"] = UpgradeTypes::Enum::Ventral_Sacs;
		upgradeTypesEnum["Antennae"] = UpgradeTypes::Enum::Antennae;
		upgradeTypesEnum["Pneumatized_Carapace"] = UpgradeTypes::Enum::Pneumatized_Carapace;
		upgradeTypesEnum["Metabolic_Boost"] = UpgradeTypes::Enum::Metabolic_Boost;
		upgradeTypesEnum["Adrenal_Glands"] = UpgradeTypes::Enum::Adrenal_Glands;
		upgradeTypesEnum["Muscular_Augments"] = UpgradeTypes::Enum::Muscular_Augments;
		upgradeTypesEnum["Grooved_Spines"] = UpgradeTypes::Enum::Grooved_Spines;
		upgradeTypesEnum["Gamete_Meiosis"] = UpgradeTypes::Enum::Gamete_Meiosis;
		upgradeTypesEnum["Metasynaptic_Node"] = UpgradeTypes::Enum::Metasynaptic_Node;
		upgradeTypesEnum["Singularity_Charge"] = UpgradeTypes::Enum::Singularity_Charge;
		upgradeTypesEnum["Leg_Enhancements"] = UpgradeTypes::Enum::Leg_Enhancements;
		upgradeTypesEnum["Scarab_Damage"] = UpgradeTypes::Enum::Scarab_Damage;
		upgradeTypesEnum["Reaver_Capacity"] = UpgradeTypes::Enum::Reaver_Capacity;
		upgradeTypesEnum["Gravitic_Drive"] = UpgradeTypes::Enum::Gravitic_Drive;
		upgradeTypesEnum["Sensor_Array"] = UpgradeTypes::Enum::Sensor_Array;
		upgradeTypesEnum["Gravitic_Boosters"] = UpgradeTypes::Enum::Gravitic_Boosters;
		upgradeTypesEnum["Khaydarin_Amulet"] = UpgradeTypes::Enum::Khaydarin_Amulet;
		upgradeTypesEnum["Apial_Sensors"] = UpgradeTypes::Enum::Apial_Sensors;
		upgradeTypesEnum["Gravitic_Thrusters"] = UpgradeTypes::Enum::Gravitic_Thrusters;
		upgradeTypesEnum["Carrier_Capacity"] = UpgradeTypes::Enum::Carrier_Capacity;
		upgradeTypesEnum["Khaydarin_Core"] = UpgradeTypes::Enum::Khaydarin_Core;

		upgradeTypesEnum["Argus_Jewel"] = UpgradeTypes::Enum::Argus_Jewel;

		upgradeTypesEnum["Argus_Talisman"] = UpgradeTypes::Enum::Argus_Talisman;

		upgradeTypesEnum["Caduceus_Reactor"] = UpgradeTypes::Enum::Caduceus_Reactor;
		upgradeTypesEnum["Chitinous_Plating"] = UpgradeTypes::Enum::Chitinous_Plating;
		upgradeTypesEnum["Anabolic_Synthesis"] = UpgradeTypes::Enum::Anabolic_Synthesis;
		upgradeTypesEnum["Charon_Boosters"] = UpgradeTypes::Enum::Charon_Boosters;

		upgradeTypesEnum["Upgrade_60"] = UpgradeTypes::Enum::Upgrade_60;
		upgradeTypesEnum["None"] = UpgradeTypes::Enum::None;
		upgradeTypesEnum["Unknown"] = UpgradeTypes::Enum::Unknown;
		upgradeTypesEnum["MAX"] = UpgradeTypes::Enum::MAX;
	}
}