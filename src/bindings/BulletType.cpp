#include <sol.hpp>
#include <BWAPI.h>
#include "Type.h"
#include "SetContainer.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindBulletType(sol::table module)
	{
		auto bulletType = module.create_simple_usertype<BulletType>();
		bindType(bulletType);
		bindIsInstance(bulletType);
		module.set_usertype("BulletType", bulletType);

		auto bulletTypeSet = module.create_simple_usertype<BulletType::set>();
		bindSetContainer<BulletType::set, BulletType>(bulletTypeSet);
		bindIsInstance(bulletTypeSet);
		module.set_usertype("BulletTypeset", bulletTypeSet);

		auto bulletTypes = module.create_named("BulletTypes");
		bulletTypes["Melee"] = &BulletTypes::Melee;
		bulletTypes["Fusion_Cutter_Hit"] = &BulletTypes::Fusion_Cutter_Hit;
		bulletTypes["Gauss_Rifle_Hit"] = &BulletTypes::Gauss_Rifle_Hit;
		bulletTypes["C_10_Canister_Rifle_Hit"] = &BulletTypes::C_10_Canister_Rifle_Hit;
		bulletTypes["Gemini_Missiles"] = &BulletTypes::Gemini_Missiles;
		bulletTypes["Fragmentation_Grenade"] = &BulletTypes::Fragmentation_Grenade;
		bulletTypes["Longbolt_Missile"] = &BulletTypes::Longbolt_Missile;
		bulletTypes["ATS_ATA_Laser_Battery"] = &BulletTypes::ATS_ATA_Laser_Battery;
		bulletTypes["Burst_Lasers"] = &BulletTypes::Burst_Lasers;
		bulletTypes["Arclite_Shock_Cannon_Hit"] = &BulletTypes::Arclite_Shock_Cannon_Hit;
		bulletTypes["EMP_Missile"] = &BulletTypes::EMP_Missile;
		bulletTypes["Dual_Photon_Blasters_Hit"] = &BulletTypes::Dual_Photon_Blasters_Hit;
		bulletTypes["Particle_Beam_Hit"] = &BulletTypes::Particle_Beam_Hit;
		bulletTypes["Anti_Matter_Missile"] = &BulletTypes::Anti_Matter_Missile;
		bulletTypes["Pulse_Cannon"] = &BulletTypes::Pulse_Cannon;
		bulletTypes["Psionic_Shockwave_Hit"] = &BulletTypes::Psionic_Shockwave_Hit;
		bulletTypes["Psionic_Storm"] = &BulletTypes::Psionic_Storm;
		bulletTypes["Yamato_Gun"] = &BulletTypes::Yamato_Gun;
		bulletTypes["Phase_Disruptor"] = &BulletTypes::Phase_Disruptor;
		bulletTypes["STA_STS_Cannon_Overlay"] = &BulletTypes::STA_STS_Cannon_Overlay;
		bulletTypes["Sunken_Colony_Tentacle"] = &BulletTypes::Sunken_Colony_Tentacle;
		bulletTypes["Acid_Spore"] = &BulletTypes::Acid_Spore;
		bulletTypes["Glave_Wurm"] = &BulletTypes::Glave_Wurm;
		bulletTypes["Seeker_Spores"] = &BulletTypes::Seeker_Spores;
		bulletTypes["Queen_Spell_Carrier"] = &BulletTypes::Queen_Spell_Carrier;
		bulletTypes["Plague_Cloud"] = &BulletTypes::Plague_Cloud;
		bulletTypes["Consume"] = &BulletTypes::Consume;
		bulletTypes["Ensnare"] = &BulletTypes::Ensnare;
		bulletTypes["Needle_Spine_Hit"] = &BulletTypes::Needle_Spine_Hit;
		bulletTypes["Invisible"] = &BulletTypes::Invisible;
		bulletTypes["Optical_Flare_Grenade"] = &BulletTypes::Optical_Flare_Grenade;
		bulletTypes["Halo_Rockets"] = &BulletTypes::Halo_Rockets;
		bulletTypes["Subterranean_Spines"] = &BulletTypes::Subterranean_Spines;
		bulletTypes["Corrosive_Acid_Shot"] = &BulletTypes::Corrosive_Acid_Shot;
		bulletTypes["Neutron_Flare"] = &BulletTypes::Neutron_Flare;
		bulletTypes["None"] = &BulletTypes::None;
		bulletTypes["Unknown"] = &BulletTypes::Unknown;

		auto bulletTypesEnum = bulletTypes.create_named("Enum");
		bulletTypesEnum["Melee"] = BulletTypes::Enum::Melee;

		bulletTypesEnum["Fusion_Cutter_Hit"] = BulletTypes::Enum::Fusion_Cutter_Hit;
		bulletTypesEnum["Gauss_Rifle_Hit"] = BulletTypes::Enum::Gauss_Rifle_Hit;
		bulletTypesEnum["C_10_Canister_Rifle_Hit"] = BulletTypes::Enum::C_10_Canister_Rifle_Hit;
		bulletTypesEnum["Gemini_Missiles"] = BulletTypes::Enum::Gemini_Missiles;
		bulletTypesEnum["Fragmentation_Grenade"] = BulletTypes::Enum::Fragmentation_Grenade;
		bulletTypesEnum["Longbolt_Missile"] = BulletTypes::Enum::Longbolt_Missile;
		bulletTypesEnum["Unused_Lockdown"] = BulletTypes::Enum::Unused_Lockdown;
		bulletTypesEnum["ATS_ATA_Laser_Battery"] = BulletTypes::Enum::ATS_ATA_Laser_Battery;
		bulletTypesEnum["Burst_Lasers"] = BulletTypes::Enum::Burst_Lasers;
		bulletTypesEnum["Arclite_Shock_Cannon_Hit"] = BulletTypes::Enum::Arclite_Shock_Cannon_Hit;
		bulletTypesEnum["EMP_Missile"] = BulletTypes::Enum::EMP_Missile;
		bulletTypesEnum["Dual_Photon_Blasters_Hit"] = BulletTypes::Enum::Dual_Photon_Blasters_Hit;
		bulletTypesEnum["Particle_Beam_Hit"] = BulletTypes::Enum::Particle_Beam_Hit;
		bulletTypesEnum["Anti_Matter_Missile"] = BulletTypes::Enum::Anti_Matter_Missile;
		bulletTypesEnum["Pulse_Cannon"] = BulletTypes::Enum::Pulse_Cannon;
		bulletTypesEnum["Psionic_Shockwave_Hit"] = BulletTypes::Enum::Psionic_Shockwave_Hit;
		bulletTypesEnum["Psionic_Storm"] = BulletTypes::Enum::Psionic_Storm;
		bulletTypesEnum["Yamato_Gun"] = BulletTypes::Enum::Yamato_Gun;
		bulletTypesEnum["Phase_Disruptor"] = BulletTypes::Enum::Phase_Disruptor;
		bulletTypesEnum["STA_STS_Cannon_Overlay"] = BulletTypes::Enum::STA_STS_Cannon_Overlay;
		bulletTypesEnum["Sunken_Colony_Tentacle"] = BulletTypes::Enum::Sunken_Colony_Tentacle;
		bulletTypesEnum["Venom_Unused"] = BulletTypes::Enum::Venom_Unused;
		bulletTypesEnum["Acid_Spore"] = BulletTypes::Enum::Acid_Spore;
		bulletTypesEnum["Plasma_Drip_Unused"] = BulletTypes::Enum::Plasma_Drip_Unused;
		bulletTypesEnum["Glave_Wurm"] = BulletTypes::Enum::Glave_Wurm;
		bulletTypesEnum["Seeker_Spores"] = BulletTypes::Enum::Seeker_Spores;
		bulletTypesEnum["Queen_Spell_Carrier"] = BulletTypes::Enum::Queen_Spell_Carrier;
		bulletTypesEnum["Plague_Cloud"] = BulletTypes::Enum::Plague_Cloud;
		bulletTypesEnum["Consume"] = BulletTypes::Enum::Consume;
		bulletTypesEnum["Ensnare"] = BulletTypes::Enum::Ensnare;
		bulletTypesEnum["Needle_Spine_Hit"] = BulletTypes::Enum::Needle_Spine_Hit;
		bulletTypesEnum["Invisible"] = BulletTypes::Enum::Invisible;

		bulletTypesEnum["Optical_Flare_Grenade"] = BulletTypes::Enum::Optical_Flare_Grenade;
		bulletTypesEnum["Halo_Rockets"] = BulletTypes::Enum::Halo_Rockets;
		bulletTypesEnum["Subterranean_Spines"] = BulletTypes::Enum::Subterranean_Spines;
		bulletTypesEnum["Corrosive_Acid_Shot"] = BulletTypes::Enum::Corrosive_Acid_Shot;
		bulletTypesEnum["Corrosive_Acid_Hit"] = BulletTypes::Enum::Corrosive_Acid_Hit;
		bulletTypesEnum["Neutron_Flare"] = BulletTypes::Enum::Neutron_Flare;

		bulletTypesEnum["None"] = BulletTypes::Enum::None;
		bulletTypesEnum["Unknown"] = BulletTypes::Enum::Unknown;
		bulletTypesEnum["MAX"] = BulletTypes::Enum::MAX;
	}
}