#include <sol.hpp>
#include <BWAPI.h>
#include "CommonBindings.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindColor(sol::table module)
	{
		auto color = module.create_simple_usertype<Color>();
		bindType(color);
		module.set_usertype("Color", color);

		auto colors = module.create_named("Colors",
			"Red", &Colors::Red,
			"Blue", &Colors::Blue,
			"Teal", &Colors::Teal,
			"Purple", &Colors::Purple,
			"Orange", &Colors::Orange,
			"Brown", &Colors::Brown,
			"White", &Colors::White,
			"Yellow", &Colors::Yellow,
			"Green", &Colors::Green,
			"Cyan", &Colors::Cyan,
			"Black", &Colors::Black,
			"Grey", &Colors::Grey
		);
		auto text = module.new_enum("Text",
			"Previous", Text::Previous,
			"Default", Text::Default,
			"Yellow", Text::Yellow,
			"White", Text::White,
			"Grey", Text::Grey,
			"Red", Text::Red,
			"Green", Text::Green,
			"BrightRed", Text::BrightRed,
			"Invisible", Text::Invisible,
			"Blue", Text::Blue,
			"Teal", Text::Teal,
			"Purple", Text::Purple,
			"Orange", Text::Orange,
			"Align_Right", Text::Align_Right,
			"Align_Center", Text::Align_Center,
			"Invisible2", Text::Invisible2,
			"Brown", Text::Brown,
			"PlayerWhite", Text::PlayerWhite,
			"PlayerYellow", Text::PlayerYellow,
			"DarkGreen", Text::DarkGreen,
			"LightYellow", Text::LightYellow,
			"Cyan", Text::Cyan,
			"Tan", Text::Tan,
			"GreyBlue", Text::GreyBlue,
			"GreyGreen", Text::GreyGreen,
			"GreyCyan", Text::GreyCyan,
			"Turquoise", Text::Turquoise
		);
		text.new_enum("Size",
			"Small", Text::Size::Small,
			"Default", Text::Size::Default,
			"Large", Text::Size::Large,
			"Huge", Text::Size::Huge
		);
	}
}