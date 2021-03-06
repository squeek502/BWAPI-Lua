#include <sol.hpp>
#include <BWAPI.h>
#include "Type.h"
#include "SetContainer.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindWeaponType(sol::table module)
	{
		auto weaponType = module.create_simple_usertype<WeaponType>(
			"getTech", &WeaponType::getTech,
			"whatUses", &WeaponType::whatUses,
			"damageAmount", &WeaponType::damageAmount,
			"damageBonus", &WeaponType::damageBonus,
			"damageCooldown", &WeaponType::damageCooldown,
			"damageFactor", &WeaponType::damageFactor,
			"upgradeType", &WeaponType::upgradeType,
			"damageType", &WeaponType::damageType,
			"explosionType", &WeaponType::explosionType,
			"minRange", &WeaponType::minRange,
			"maxRange", &WeaponType::maxRange,
			"innerSplashRadius", &WeaponType::innerSplashRadius,
			"medianSplashRadius", &WeaponType::medianSplashRadius,
			"outerSplashRadius", &WeaponType::outerSplashRadius,
			"targetsAir", &WeaponType::targetsAir,
			"targetsGround", &WeaponType::targetsGround,
			"targetsMechanical", &WeaponType::targetsMechanical,
			"targetsOrganic", &WeaponType::targetsOrganic,
			"targetsNonBuilding", &WeaponType::targetsNonBuilding,
			"targetsNonRobotic", &WeaponType::targetsNonRobotic,
			"targetsTerrain", &WeaponType::targetsTerrain,
			"targetsOrgOrMech", &WeaponType::targetsOrgOrMech,
			"targetsOwn", &WeaponType::targetsOwn
		);
		bindType<WeaponType>(weaponType);
		bindIsInstance(weaponType);
		module.set_usertype("WeaponType", weaponType);

		auto weaponTypeSet = module.create_simple_usertype<WeaponType::set>();
		bindSetContainer<WeaponType::set, WeaponType>(weaponTypeSet);
		bindIsInstance(weaponTypeSet);
		module.set_usertype("WeaponTypeset", weaponTypeSet);

		auto weaponTypes = module.create_named("WeaponTypes");
		weaponTypes["allWeaponTypes"] = &WeaponTypes::allWeaponTypes;
		weaponTypes["Gauss_Rifle"] = &WeaponTypes::Gauss_Rifle;
		weaponTypes["Gauss_Rifle_Jim_Raynor"] = &WeaponTypes::Gauss_Rifle_Jim_Raynor;
		weaponTypes["C_10_Canister_Rifle"] = &WeaponTypes::C_10_Canister_Rifle;
		weaponTypes["C_10_Canister_Rifle_Sarah_Kerrigan"] = &WeaponTypes::C_10_Canister_Rifle_Sarah_Kerrigan;
		weaponTypes["C_10_Canister_Rifle_Samir_Duran"] = &WeaponTypes::C_10_Canister_Rifle_Samir_Duran;
		weaponTypes["C_10_Canister_Rifle_Infested_Duran"] = &WeaponTypes::C_10_Canister_Rifle_Infested_Duran;
		weaponTypes["C_10_Canister_Rifle_Alexei_Stukov"] = &WeaponTypes::C_10_Canister_Rifle_Alexei_Stukov;
		weaponTypes["Fragmentation_Grenade"] = &WeaponTypes::Fragmentation_Grenade;
		weaponTypes["Fragmentation_Grenade_Jim_Raynor"] = &WeaponTypes::Fragmentation_Grenade_Jim_Raynor;
		weaponTypes["Spider_Mines"] = &WeaponTypes::Spider_Mines;
		weaponTypes["Twin_Autocannons"] = &WeaponTypes::Twin_Autocannons;
		weaponTypes["Twin_Autocannons_Alan_Schezar"] = &WeaponTypes::Twin_Autocannons_Alan_Schezar;
		weaponTypes["Hellfire_Missile_Pack"] = &WeaponTypes::Hellfire_Missile_Pack;
		weaponTypes["Hellfire_Missile_Pack_Alan_Schezar"] = &WeaponTypes::Hellfire_Missile_Pack_Alan_Schezar;
		weaponTypes["Arclite_Cannon"] = &WeaponTypes::Arclite_Cannon;
		weaponTypes["Arclite_Cannon_Edmund_Duke"] = &WeaponTypes::Arclite_Cannon_Edmund_Duke;
		weaponTypes["Fusion_Cutter"] = &WeaponTypes::Fusion_Cutter;
		weaponTypes["Gemini_Missiles"] = &WeaponTypes::Gemini_Missiles;
		weaponTypes["Gemini_Missiles_Tom_Kazansky"] = &WeaponTypes::Gemini_Missiles_Tom_Kazansky;
		weaponTypes["Burst_Lasers"] = &WeaponTypes::Burst_Lasers;
		weaponTypes["Burst_Lasers_Tom_Kazansky"] = &WeaponTypes::Burst_Lasers_Tom_Kazansky;
		weaponTypes["ATS_Laser_Battery"] = &WeaponTypes::ATS_Laser_Battery;
		weaponTypes["ATS_Laser_Battery_Hero"] = &WeaponTypes::ATS_Laser_Battery_Hero;
		weaponTypes["ATS_Laser_Battery_Hyperion"] = &WeaponTypes::ATS_Laser_Battery_Hyperion;
		weaponTypes["ATA_Laser_Battery"] = &WeaponTypes::ATA_Laser_Battery;
		weaponTypes["ATA_Laser_Battery_Hero"] = &WeaponTypes::ATA_Laser_Battery_Hero;
		weaponTypes["ATA_Laser_Battery_Hyperion"] = &WeaponTypes::ATA_Laser_Battery_Hyperion;
		weaponTypes["Flame_Thrower"] = &WeaponTypes::Flame_Thrower;
		weaponTypes["Flame_Thrower_Gui_Montag"] = &WeaponTypes::Flame_Thrower_Gui_Montag;
		weaponTypes["Arclite_Shock_Cannon"] = &WeaponTypes::Arclite_Shock_Cannon;
		weaponTypes["Arclite_Shock_Cannon_Edmund_Duke"] = &WeaponTypes::Arclite_Shock_Cannon_Edmund_Duke;
		weaponTypes["Longbolt_Missile"] = &WeaponTypes::Longbolt_Missile;
		weaponTypes["Claws"] = &WeaponTypes::Claws;
		weaponTypes["Claws_Devouring_One"] = &WeaponTypes::Claws_Devouring_One;
		weaponTypes["Claws_Infested_Kerrigan"] = &WeaponTypes::Claws_Infested_Kerrigan;
		weaponTypes["Needle_Spines"] = &WeaponTypes::Needle_Spines;
		weaponTypes["Needle_Spines_Hunter_Killer"] = &WeaponTypes::Needle_Spines_Hunter_Killer;
		weaponTypes["Kaiser_Blades"] = &WeaponTypes::Kaiser_Blades;
		weaponTypes["Kaiser_Blades_Torrasque"] = &WeaponTypes::Kaiser_Blades_Torrasque;
		weaponTypes["Toxic_Spores"] = &WeaponTypes::Toxic_Spores;
		weaponTypes["Spines"] = &WeaponTypes::Spines;
		weaponTypes["Acid_Spore"] = &WeaponTypes::Acid_Spore;
		weaponTypes["Acid_Spore_Kukulza"] = &WeaponTypes::Acid_Spore_Kukulza;
		weaponTypes["Glave_Wurm"] = &WeaponTypes::Glave_Wurm;
		weaponTypes["Glave_Wurm_Kukulza"] = &WeaponTypes::Glave_Wurm_Kukulza;
		weaponTypes["Seeker_Spores"] = &WeaponTypes::Seeker_Spores;
		weaponTypes["Subterranean_Tentacle"] = &WeaponTypes::Subterranean_Tentacle;
		weaponTypes["Suicide_Infested_Terran"] = &WeaponTypes::Suicide_Infested_Terran;
		weaponTypes["Suicide_Scourge"] = &WeaponTypes::Suicide_Scourge;
		weaponTypes["Particle_Beam"] = &WeaponTypes::Particle_Beam;
		weaponTypes["Psi_Blades"] = &WeaponTypes::Psi_Blades;
		weaponTypes["Psi_Blades_Fenix"] = &WeaponTypes::Psi_Blades_Fenix;
		weaponTypes["Phase_Disruptor"] = &WeaponTypes::Phase_Disruptor;
		weaponTypes["Phase_Disruptor_Fenix"] = &WeaponTypes::Phase_Disruptor_Fenix;
		weaponTypes["Psi_Assault"] = &WeaponTypes::Psi_Assault;
		weaponTypes["Psionic_Shockwave"] = &WeaponTypes::Psionic_Shockwave;
		weaponTypes["Psionic_Shockwave_TZ_Archon"] = &WeaponTypes::Psionic_Shockwave_TZ_Archon;
		weaponTypes["Dual_Photon_Blasters"] = &WeaponTypes::Dual_Photon_Blasters;
		weaponTypes["Dual_Photon_Blasters_Mojo"] = &WeaponTypes::Dual_Photon_Blasters_Mojo;
		weaponTypes["Dual_Photon_Blasters_Artanis"] = &WeaponTypes::Dual_Photon_Blasters_Artanis;
		weaponTypes["Anti_Matter_Missiles"] = &WeaponTypes::Anti_Matter_Missiles;
		weaponTypes["Anti_Matter_Missiles_Mojo"] = &WeaponTypes::Anti_Matter_Missiles_Mojo;
		weaponTypes["Anti_Matter_Missiles_Artanis"] = &WeaponTypes::Anti_Matter_Missiles_Artanis;
		weaponTypes["Phase_Disruptor_Cannon"] = &WeaponTypes::Phase_Disruptor_Cannon;
		weaponTypes["Phase_Disruptor_Cannon_Danimoth"] = &WeaponTypes::Phase_Disruptor_Cannon_Danimoth;
		weaponTypes["Pulse_Cannon"] = &WeaponTypes::Pulse_Cannon;
		weaponTypes["STS_Photon_Cannon"] = &WeaponTypes::STS_Photon_Cannon;
		weaponTypes["STA_Photon_Cannon"] = &WeaponTypes::STA_Photon_Cannon;
		weaponTypes["Scarab"] = &WeaponTypes::Scarab;
		weaponTypes["Neutron_Flare"] = &WeaponTypes::Neutron_Flare;
		weaponTypes["Halo_Rockets"] = &WeaponTypes::Halo_Rockets;
		weaponTypes["Corrosive_Acid"] = &WeaponTypes::Corrosive_Acid;
		weaponTypes["Subterranean_Spines"] = &WeaponTypes::Subterranean_Spines;
		weaponTypes["Warp_Blades"] = &WeaponTypes::Warp_Blades;
		weaponTypes["Warp_Blades_Hero"] = &WeaponTypes::Warp_Blades_Hero;
		weaponTypes["Warp_Blades_Zeratul"] = &WeaponTypes::Warp_Blades_Zeratul;
		weaponTypes["Independant_Laser_Battery"] = &WeaponTypes::Independant_Laser_Battery;
		weaponTypes["Twin_Autocannons_Floor_Trap"] = &WeaponTypes::Twin_Autocannons_Floor_Trap;
		weaponTypes["Hellfire_Missile_Pack_Wall_Trap"] = &WeaponTypes::Hellfire_Missile_Pack_Wall_Trap;
		weaponTypes["Flame_Thrower_Wall_Trap"] = &WeaponTypes::Flame_Thrower_Wall_Trap;
		weaponTypes["Hellfire_Missile_Pack_Floor_Trap"] = &WeaponTypes::Hellfire_Missile_Pack_Floor_Trap;
		weaponTypes["Yamato_Gun"] = &WeaponTypes::Yamato_Gun;
		weaponTypes["Nuclear_Strike"] = &WeaponTypes::Nuclear_Strike;
		weaponTypes["Lockdown"] = &WeaponTypes::Lockdown;
		weaponTypes["EMP_Shockwave"] = &WeaponTypes::EMP_Shockwave;
		weaponTypes["Irradiate"] = &WeaponTypes::Irradiate;
		weaponTypes["Parasite"] = &WeaponTypes::Parasite;
		weaponTypes["Spawn_Broodlings"] = &WeaponTypes::Spawn_Broodlings;
		weaponTypes["Ensnare"] = &WeaponTypes::Ensnare;
		weaponTypes["Dark_Swarm"] = &WeaponTypes::Dark_Swarm;
		weaponTypes["Plague"] = &WeaponTypes::Plague;
		weaponTypes["Consume"] = &WeaponTypes::Consume;
		weaponTypes["Stasis_Field"] = &WeaponTypes::Stasis_Field;
		weaponTypes["Psionic_Storm"] = &WeaponTypes::Psionic_Storm;
		weaponTypes["Disruption_Web"] = &WeaponTypes::Disruption_Web;
		weaponTypes["Restoration"] = &WeaponTypes::Restoration;
		weaponTypes["Mind_Control"] = &WeaponTypes::Mind_Control;
		weaponTypes["Feedback"] = &WeaponTypes::Feedback;
		weaponTypes["Optical_Flare"] = &WeaponTypes::Optical_Flare;
		weaponTypes["Maelstrom"] = &WeaponTypes::Maelstrom;
		weaponTypes["None"] = &WeaponTypes::None;
		weaponTypes["Unknown"] = &WeaponTypes::Unknown;

		auto weaponTypesEnum = weaponTypes.create_named("Enum");
		weaponTypesEnum["Gauss_Rifle"] = WeaponTypes::Enum::Gauss_Rifle;
		weaponTypesEnum["Gauss_Rifle_Jim_Raynor"] = WeaponTypes::Enum::Gauss_Rifle_Jim_Raynor;
		weaponTypesEnum["C_10_Canister_Rifle"] = WeaponTypes::Enum::C_10_Canister_Rifle;
		weaponTypesEnum["C_10_Canister_Rifle_Sarah_Kerrigan"] = WeaponTypes::Enum::C_10_Canister_Rifle_Sarah_Kerrigan;
		weaponTypesEnum["Fragmentation_Grenade"] = WeaponTypes::Enum::Fragmentation_Grenade;
		weaponTypesEnum["Fragmentation_Grenade_Jim_Raynor"] = WeaponTypes::Enum::Fragmentation_Grenade_Jim_Raynor;
		weaponTypesEnum["Spider_Mines"] = WeaponTypes::Enum::Spider_Mines;
		weaponTypesEnum["Twin_Autocannons"] = WeaponTypes::Enum::Twin_Autocannons;
		weaponTypesEnum["Hellfire_Missile_Pack"] = WeaponTypes::Enum::Hellfire_Missile_Pack;
		weaponTypesEnum["Twin_Autocannons_Alan_Schezar"] = WeaponTypes::Enum::Twin_Autocannons_Alan_Schezar;
		weaponTypesEnum["Hellfire_Missile_Pack_Alan_Schezar"] = WeaponTypes::Enum::Hellfire_Missile_Pack_Alan_Schezar;
		weaponTypesEnum["Arclite_Cannon"] = WeaponTypes::Enum::Arclite_Cannon;
		weaponTypesEnum["Arclite_Cannon_Edmund_Duke"] = WeaponTypes::Enum::Arclite_Cannon_Edmund_Duke;
		weaponTypesEnum["Fusion_Cutter"] = WeaponTypes::Enum::Fusion_Cutter;
		weaponTypesEnum["Gemini_Missiles"] = WeaponTypes::Enum::Gemini_Missiles;
		weaponTypesEnum["Burst_Lasers"] = WeaponTypes::Enum::Burst_Lasers;
		weaponTypesEnum["Gemini_Missiles_Tom_Kazansky"] = WeaponTypes::Enum::Gemini_Missiles_Tom_Kazansky;
		weaponTypesEnum["Burst_Lasers_Tom_Kazansky"] = WeaponTypes::Enum::Burst_Lasers_Tom_Kazansky;
		weaponTypesEnum["ATS_Laser_Battery"] = WeaponTypes::Enum::ATS_Laser_Battery;
		weaponTypesEnum["ATA_Laser_Battery"] = WeaponTypes::Enum::ATA_Laser_Battery;
		weaponTypesEnum["ATS_Laser_Battery_Hero"] = WeaponTypes::Enum::ATS_Laser_Battery_Hero;
		weaponTypesEnum["ATA_Laser_Battery_Hero"] = WeaponTypes::Enum::ATA_Laser_Battery_Hero;
		weaponTypesEnum["ATS_Laser_Battery_Hyperion"] = WeaponTypes::Enum::ATS_Laser_Battery_Hyperion;
		weaponTypesEnum["ATA_Laser_Battery_Hyperion"] = WeaponTypes::Enum::ATA_Laser_Battery_Hyperion;
		weaponTypesEnum["Flame_Thrower"] = WeaponTypes::Enum::Flame_Thrower;
		weaponTypesEnum["Flame_Thrower_Gui_Montag"] = WeaponTypes::Enum::Flame_Thrower_Gui_Montag;
		weaponTypesEnum["Arclite_Shock_Cannon"] = WeaponTypes::Enum::Arclite_Shock_Cannon;
		weaponTypesEnum["Arclite_Shock_Cannon_Edmund_Duke"] = WeaponTypes::Enum::Arclite_Shock_Cannon_Edmund_Duke;
		weaponTypesEnum["Longbolt_Missile"] = WeaponTypes::Enum::Longbolt_Missile;
		weaponTypesEnum["Yamato_Gun"] = WeaponTypes::Enum::Yamato_Gun;
		weaponTypesEnum["Nuclear_Strike"] = WeaponTypes::Enum::Nuclear_Strike;
		weaponTypesEnum["Lockdown"] = WeaponTypes::Enum::Lockdown;
		weaponTypesEnum["EMP_Shockwave"] = WeaponTypes::Enum::EMP_Shockwave;
		weaponTypesEnum["Irradiate"] = WeaponTypes::Enum::Irradiate;
		weaponTypesEnum["Claws"] = WeaponTypes::Enum::Claws;
		weaponTypesEnum["Claws_Devouring_One"] = WeaponTypes::Enum::Claws_Devouring_One;
		weaponTypesEnum["Claws_Infested_Kerrigan"] = WeaponTypes::Enum::Claws_Infested_Kerrigan;
		weaponTypesEnum["Needle_Spines"] = WeaponTypes::Enum::Needle_Spines;
		weaponTypesEnum["Needle_Spines_Hunter_Killer"] = WeaponTypes::Enum::Needle_Spines_Hunter_Killer;
		weaponTypesEnum["Kaiser_Blades"] = WeaponTypes::Enum::Kaiser_Blades;
		weaponTypesEnum["Kaiser_Blades_Torrasque"] = WeaponTypes::Enum::Kaiser_Blades_Torrasque;
		weaponTypesEnum["Toxic_Spores"] = WeaponTypes::Enum::Toxic_Spores;
		weaponTypesEnum["Spines"] = WeaponTypes::Enum::Spines;
		weaponTypesEnum["Acid_Spore"] = WeaponTypes::Enum::Acid_Spore;
		weaponTypesEnum["Acid_Spore_Kukulza"] = WeaponTypes::Enum::Acid_Spore_Kukulza;
		weaponTypesEnum["Glave_Wurm"] = WeaponTypes::Enum::Glave_Wurm;
		weaponTypesEnum["Glave_Wurm_Kukulza"] = WeaponTypes::Enum::Glave_Wurm_Kukulza;
		weaponTypesEnum["Seeker_Spores"] = WeaponTypes::Enum::Seeker_Spores;
		weaponTypesEnum["Subterranean_Tentacle"] = WeaponTypes::Enum::Subterranean_Tentacle;
		weaponTypesEnum["Suicide_Infested_Terran"] = WeaponTypes::Enum::Suicide_Infested_Terran;
		weaponTypesEnum["Suicide_Scourge"] = WeaponTypes::Enum::Suicide_Scourge;
		weaponTypesEnum["Parasite"] = WeaponTypes::Enum::Parasite;
		weaponTypesEnum["Spawn_Broodlings"] = WeaponTypes::Enum::Spawn_Broodlings;
		weaponTypesEnum["Ensnare"] = WeaponTypes::Enum::Ensnare;
		weaponTypesEnum["Dark_Swarm"] = WeaponTypes::Enum::Dark_Swarm;
		weaponTypesEnum["Plague"] = WeaponTypes::Enum::Plague;
		weaponTypesEnum["Consume"] = WeaponTypes::Enum::Consume;
		weaponTypesEnum["Particle_Beam"] = WeaponTypes::Enum::Particle_Beam;
		weaponTypesEnum["Psi_Blades"] = WeaponTypes::Enum::Psi_Blades;
		weaponTypesEnum["Psi_Blades_Fenix"] = WeaponTypes::Enum::Psi_Blades_Fenix;
		weaponTypesEnum["Phase_Disruptor"] = WeaponTypes::Enum::Phase_Disruptor;
		weaponTypesEnum["Phase_Disruptor_Fenix"] = WeaponTypes::Enum::Phase_Disruptor_Fenix;
		weaponTypesEnum["Psi_Assault"] = WeaponTypes::Enum::Psi_Assault;
		weaponTypesEnum["Psionic_Shockwave"] = WeaponTypes::Enum::Psionic_Shockwave;
		weaponTypesEnum["Psionic_Shockwave_TZ_Archon"] = WeaponTypes::Enum::Psionic_Shockwave_TZ_Archon;
		weaponTypesEnum["Dual_Photon_Blasters"] = WeaponTypes::Enum::Dual_Photon_Blasters;
		weaponTypesEnum["Anti_Matter_Missiles"] = WeaponTypes::Enum::Anti_Matter_Missiles;
		weaponTypesEnum["Dual_Photon_Blasters_Mojo"] = WeaponTypes::Enum::Dual_Photon_Blasters_Mojo;
		weaponTypesEnum["Anti_Matter_Missiles_Mojo"] = WeaponTypes::Enum::Anti_Matter_Missiles_Mojo;
		weaponTypesEnum["Phase_Disruptor_Cannon"] = WeaponTypes::Enum::Phase_Disruptor_Cannon;
		weaponTypesEnum["Phase_Disruptor_Cannon_Danimoth"] = WeaponTypes::Enum::Phase_Disruptor_Cannon_Danimoth;
		weaponTypesEnum["Pulse_Cannon"] = WeaponTypes::Enum::Pulse_Cannon;
		weaponTypesEnum["STS_Photon_Cannon"] = WeaponTypes::Enum::STS_Photon_Cannon;
		weaponTypesEnum["STA_Photon_Cannon"] = WeaponTypes::Enum::STA_Photon_Cannon;
		weaponTypesEnum["Scarab"] = WeaponTypes::Enum::Scarab;
		weaponTypesEnum["Stasis_Field"] = WeaponTypes::Enum::Stasis_Field;
		weaponTypesEnum["Psionic_Storm"] = WeaponTypes::Enum::Psionic_Storm;
		weaponTypesEnum["Warp_Blades_Zeratul"] = WeaponTypes::Enum::Warp_Blades_Zeratul;
		weaponTypesEnum["Warp_Blades_Hero"] = WeaponTypes::Enum::Warp_Blades_Hero;
		weaponTypesEnum["Platform_Laser_Battery"] = WeaponTypes::Enum::Platform_Laser_Battery;
		weaponTypesEnum["Independant_Laser_Battery"] = WeaponTypes::Enum::Independant_Laser_Battery;
		weaponTypesEnum["Twin_Autocannons_Floor_Trap"] = WeaponTypes::Enum::Twin_Autocannons_Floor_Trap;
		weaponTypesEnum["Hellfire_Missile_Pack_Wall_Trap"] = WeaponTypes::Enum::Hellfire_Missile_Pack_Wall_Trap;
		weaponTypesEnum["Flame_Thrower_Wall_Trap"] = WeaponTypes::Enum::Flame_Thrower_Wall_Trap;
		weaponTypesEnum["Hellfire_Missile_Pack_Floor_Trap"] = WeaponTypes::Enum::Hellfire_Missile_Pack_Floor_Trap;
		weaponTypesEnum["Neutron_Flare"] = WeaponTypes::Enum::Neutron_Flare;
		weaponTypesEnum["Disruption_Web"] = WeaponTypes::Enum::Disruption_Web;
		weaponTypesEnum["Restoration"] = WeaponTypes::Enum::Restoration;
		weaponTypesEnum["Halo_Rockets"] = WeaponTypes::Enum::Halo_Rockets;
		weaponTypesEnum["Corrosive_Acid"] = WeaponTypes::Enum::Corrosive_Acid;
		weaponTypesEnum["Mind_Control"] = WeaponTypes::Enum::Mind_Control;
		weaponTypesEnum["Feedback"] = WeaponTypes::Enum::Feedback;
		weaponTypesEnum["Optical_Flare"] = WeaponTypes::Enum::Optical_Flare;
		weaponTypesEnum["Maelstrom"] = WeaponTypes::Enum::Maelstrom;
		weaponTypesEnum["Subterranean_Spines"] = WeaponTypes::Enum::Subterranean_Spines;
		weaponTypesEnum["Warp_Blades"] = WeaponTypes::Enum::Warp_Blades;
		weaponTypesEnum["C_10_Canister_Rifle_Samir_Duran"] = WeaponTypes::Enum::C_10_Canister_Rifle_Samir_Duran;
		weaponTypesEnum["C_10_Canister_Rifle_Infested_Duran"] = WeaponTypes::Enum::C_10_Canister_Rifle_Infested_Duran;
		weaponTypesEnum["Dual_Photon_Blasters_Artanis"] = WeaponTypes::Enum::Dual_Photon_Blasters_Artanis;
		weaponTypesEnum["Anti_Matter_Missiles_Artanis"] = WeaponTypes::Enum::Anti_Matter_Missiles_Artanis;
		weaponTypesEnum["C_10_Canister_Rifle_Alexei_Stukov"] = WeaponTypes::Enum::C_10_Canister_Rifle_Alexei_Stukov;
		weaponTypesEnum["None"] = WeaponTypes::Enum::None;
		weaponTypesEnum["Unknown"] = WeaponTypes::Enum::Unknown;
		weaponTypesEnum["MAX"] = WeaponTypes::Enum::MAX;
	}
}