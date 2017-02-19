#include <sol.hpp>
#include <BWAPI.h>
#include "BWAPI_Lua.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindTechType(sol::table module)
	{
		auto techType = module.create_simple_usertype<TechType>(
			"getRace", &TechType::getRace
		);
		bindType<TechType>(techType);
		module.set_usertype("TechType", techType);

		auto techTypeSet = module.create_simple_usertype<TechType::set>();
		bindSetContainer<TechType::set, TechType>(techTypeSet);
		module.set_usertype("TechTypeset", techTypeSet);

		auto techTypes = module.create_named("TechTypes");
		techTypes["Stim_Packs"] = &TechTypes::Stim_Packs;
		techTypes["Lockdown"] = &TechTypes::Lockdown;
		techTypes["EMP_Shockwave"] = &TechTypes::EMP_Shockwave;
		techTypes["Spider_Mines"] = &TechTypes::Spider_Mines;
		techTypes["Scanner_Sweep"] = &TechTypes::Scanner_Sweep;
		techTypes["Tank_Siege_Mode"] = &TechTypes::Tank_Siege_Mode;
		techTypes["Defensive_Matrix"] = &TechTypes::Defensive_Matrix;
		techTypes["Irradiate"] = &TechTypes::Irradiate;
		techTypes["Yamato_Gun"] = &TechTypes::Yamato_Gun;
		techTypes["Cloaking_Field"] = &TechTypes::Cloaking_Field;
		techTypes["Personnel_Cloaking"] = &TechTypes::Personnel_Cloaking;
		techTypes["Restoration"] = &TechTypes::Restoration;
		techTypes["Optical_Flare"] = &TechTypes::Optical_Flare;
		techTypes["Healing"] = &TechTypes::Healing;
		techTypes["Nuclear_Strike"] = &TechTypes::Nuclear_Strike;
		techTypes["Burrowing"] = &TechTypes::Burrowing;
		techTypes["Infestation"] = &TechTypes::Infestation;
		techTypes["Spawn_Broodlings"] = &TechTypes::Spawn_Broodlings;
		techTypes["Dark_Swarm"] = &TechTypes::Dark_Swarm;
		techTypes["Plague"] = &TechTypes::Plague;
		techTypes["Consume"] = &TechTypes::Consume;
		techTypes["Ensnare"] = &TechTypes::Ensnare;
		techTypes["Parasite"] = &TechTypes::Parasite;
		techTypes["Lurker_Aspect"] = &TechTypes::Lurker_Aspect;
		techTypes["Psionic_Storm"] = &TechTypes::Psionic_Storm;
		techTypes["Hallucination"] = &TechTypes::Hallucination;
		techTypes["Recall"] = &TechTypes::Recall;
		techTypes["Stasis_Field"] = &TechTypes::Stasis_Field;
		techTypes["Archon_Warp"] = &TechTypes::Archon_Warp;
		techTypes["Disruption_Web"] = &TechTypes::Disruption_Web;
		techTypes["Mind_Control"] = &TechTypes::Mind_Control;
		techTypes["Dark_Archon_Meld"] = &TechTypes::Dark_Archon_Meld;
		techTypes["Feedback"] = &TechTypes::Feedback;
		techTypes["Maelstrom"] = &TechTypes::Maelstrom;

		techTypes["None"] = &TechTypes::None;
		techTypes["Unknown"] = &TechTypes::Unknown;

		auto techTypesEnum = techTypes.create_named("Enum");
		techTypesEnum["Stim_Packs"] = TechTypes::Enum::Stim_Packs;
		techTypesEnum["Lockdown"] = TechTypes::Enum::Lockdown;
		techTypesEnum["EMP_Shockwave"] = TechTypes::Enum::EMP_Shockwave;
		techTypesEnum["Spider_Mines"] = TechTypes::Enum::Spider_Mines;
		techTypesEnum["Scanner_Sweep"] = TechTypes::Enum::Scanner_Sweep;
		techTypesEnum["Tank_Siege_Mode"] = TechTypes::Enum::Tank_Siege_Mode;
		techTypesEnum["Defensive_Matrix"] = TechTypes::Enum::Defensive_Matrix;
		techTypesEnum["Irradiate"] = TechTypes::Enum::Irradiate;
		techTypesEnum["Yamato_Gun"] = TechTypes::Enum::Yamato_Gun;
		techTypesEnum["Cloaking_Field"] = TechTypes::Enum::Cloaking_Field;
		techTypesEnum["Personnel_Cloaking"] = TechTypes::Enum::Personnel_Cloaking;
		techTypesEnum["Burrowing"] = TechTypes::Enum::Burrowing;
		techTypesEnum["Infestation"] = TechTypes::Enum::Infestation;
		techTypesEnum["Spawn_Broodlings"] = TechTypes::Enum::Spawn_Broodlings;
		techTypesEnum["Dark_Swarm"] = TechTypes::Enum::Dark_Swarm;
		techTypesEnum["Plague"] = TechTypes::Enum::Plague;
		techTypesEnum["Consume"] = TechTypes::Enum::Consume;
		techTypesEnum["Ensnare"] = TechTypes::Enum::Ensnare;
		techTypesEnum["Parasite"] = TechTypes::Enum::Parasite;
		techTypesEnum["Psionic_Storm"] = TechTypes::Enum::Psionic_Storm;
		techTypesEnum["Hallucination"] = TechTypes::Enum::Hallucination;
		techTypesEnum["Recall"] = TechTypes::Enum::Recall;
		techTypesEnum["Stasis_Field"] = TechTypes::Enum::Stasis_Field;
		techTypesEnum["Archon_Warp"] = TechTypes::Enum::Archon_Warp;
		techTypesEnum["Restoration"] = TechTypes::Enum::Restoration;
		techTypesEnum["Disruption_Web"] = TechTypes::Enum::Disruption_Web;
		techTypesEnum["Unused_26"] = TechTypes::Enum::Unused_26;
		techTypesEnum["Mind_Control"] = TechTypes::Enum::Mind_Control;
		techTypesEnum["Dark_Archon_Meld"] = TechTypes::Enum::Dark_Archon_Meld;
		techTypesEnum["Feedback"] = TechTypes::Enum::Feedback;
		techTypesEnum["Optical_Flare"] = TechTypes::Enum::Optical_Flare;
		techTypesEnum["Maelstrom"] = TechTypes::Enum::Maelstrom;
		techTypesEnum["Lurker_Aspect"] = TechTypes::Enum::Lurker_Aspect;
		techTypesEnum["Unused_33"] = TechTypes::Enum::Unused_33;
		techTypesEnum["Healing"] = TechTypes::Enum::Healing;
		techTypesEnum["Nuclear_Strike"] = TechTypes::Enum::Nuclear_Strike;

		techTypesEnum["None"] = TechTypes::Enum::None;
		techTypesEnum["Unknown"] = TechTypes::Enum::Unknown;
		techTypesEnum["MAX"] = TechTypes::Enum::MAX;
	}
}