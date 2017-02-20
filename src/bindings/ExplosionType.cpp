#include <sol.hpp>
#include <BWAPI.h>
#include "Type.h"
#include "SetContainer.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindExplosionType(sol::table module)
	{
		auto explosionType = module.create_simple_usertype<ExplosionType>();
		bindType(explosionType);
		module.set_usertype("ExplosionType", explosionType);

		auto explosionTypeSet = module.create_simple_usertype<ExplosionType::set>();
		bindSetContainer<ExplosionType::set, ExplosionType>(explosionTypeSet);
		module.set_usertype("ExplosionTypeset", explosionTypeSet);

		auto explosionTypes = module.create_named("ExplosionTypes");
		explosionTypes["None"] = &ExplosionTypes::None;
		explosionTypes["Normal"] = &ExplosionTypes::Normal;
		explosionTypes["Radial_Splash"] = &ExplosionTypes::Radial_Splash;
		explosionTypes["Enemy_Splash"] = &ExplosionTypes::Enemy_Splash;
		explosionTypes["Lockdown"] = &ExplosionTypes::Lockdown;
		explosionTypes["Nuclear_Missile"] = &ExplosionTypes::Nuclear_Missile;
		explosionTypes["Parasite"] = &ExplosionTypes::Parasite;
		explosionTypes["Broodlings"] = &ExplosionTypes::Broodlings;
		explosionTypes["EMP_Shockwave"] = &ExplosionTypes::EMP_Shockwave;
		explosionTypes["Irradiate"] = &ExplosionTypes::Irradiate;
		explosionTypes["Ensnare"] = &ExplosionTypes::Ensnare;
		explosionTypes["Plague"] = &ExplosionTypes::Plague;
		explosionTypes["Stasis_Field"] = &ExplosionTypes::Stasis_Field;
		explosionTypes["Dark_Swarm"] = &ExplosionTypes::Dark_Swarm;
		explosionTypes["Consume"] = &ExplosionTypes::Consume;
		explosionTypes["Yamato_Gun"] = &ExplosionTypes::Yamato_Gun;
		explosionTypes["Restoration"] = &ExplosionTypes::Restoration;
		explosionTypes["Disruption_Web"] = &ExplosionTypes::Disruption_Web;
		explosionTypes["Corrosive_Acid"] = &ExplosionTypes::Corrosive_Acid;
		explosionTypes["Mind_Control"] = &ExplosionTypes::Mind_Control;
		explosionTypes["Feedback"] = &ExplosionTypes::Feedback;
		explosionTypes["Optical_Flare"] = &ExplosionTypes::Optical_Flare;
		explosionTypes["Maelstrom"] = &ExplosionTypes::Maelstrom;
		explosionTypes["Air_Splash"] = &ExplosionTypes::Air_Splash;
		explosionTypes["Unknown"] = &ExplosionTypes::Unknown;

		auto explosionTypesEnum = explosionTypes.create_named("Enum");
		explosionTypesEnum["None"] = ExplosionTypes::Enum::None;
		explosionTypesEnum["Normal"] = ExplosionTypes::Enum::Normal;
		explosionTypesEnum["Radial_Splash"] = ExplosionTypes::Enum::Radial_Splash;
		explosionTypesEnum["Enemy_Splash"] = ExplosionTypes::Enum::Enemy_Splash;
		explosionTypesEnum["Lockdown"] = ExplosionTypes::Enum::Lockdown;
		explosionTypesEnum["Nuclear_Missile"] = ExplosionTypes::Enum::Nuclear_Missile;
		explosionTypesEnum["Parasite"] = ExplosionTypes::Enum::Parasite;
		explosionTypesEnum["Broodlings"] = ExplosionTypes::Enum::Broodlings;
		explosionTypesEnum["EMP_Shockwave"] = ExplosionTypes::Enum::EMP_Shockwave;
		explosionTypesEnum["Irradiate"] = ExplosionTypes::Enum::Irradiate;
		explosionTypesEnum["Ensnare"] = ExplosionTypes::Enum::Ensnare;
		explosionTypesEnum["Plague"] = ExplosionTypes::Enum::Plague;
		explosionTypesEnum["Stasis_Field"] = ExplosionTypes::Enum::Stasis_Field;
		explosionTypesEnum["Dark_Swarm"] = ExplosionTypes::Enum::Dark_Swarm;
		explosionTypesEnum["Consume"] = ExplosionTypes::Enum::Consume;
		explosionTypesEnum["Yamato_Gun"] = ExplosionTypes::Enum::Yamato_Gun;
		explosionTypesEnum["Restoration"] = ExplosionTypes::Enum::Restoration;
		explosionTypesEnum["Disruption_Web"] = ExplosionTypes::Enum::Disruption_Web;
		explosionTypesEnum["Corrosive_Acid"] = ExplosionTypes::Enum::Corrosive_Acid;
		explosionTypesEnum["Mind_Control"] = ExplosionTypes::Enum::Mind_Control;
		explosionTypesEnum["Feedback"] = ExplosionTypes::Enum::Feedback;
		explosionTypesEnum["Optical_Flare"] = ExplosionTypes::Enum::Optical_Flare;
		explosionTypesEnum["Maelstrom"] = ExplosionTypes::Enum::Maelstrom;
		explosionTypesEnum["Unused"] = ExplosionTypes::Enum::Unused;
		explosionTypesEnum["Air_Splash"] = ExplosionTypes::Enum::Air_Splash;
		explosionTypesEnum["Unknown"] = ExplosionTypes::Enum::Unknown;
		explosionTypesEnum["MAX"] = ExplosionTypes::Enum::MAX;
	}
}