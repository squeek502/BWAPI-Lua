#include <sol.hpp>
#include <BWAPI.h>
#include "Interface.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindBullet(sol::table module)
	{
		sol::simple_usertype<BulletInterface> bullet = module.create_simple_usertype<BulletInterface>(
			sol::meta_function::construct, sol::no_constructor,
			"getID", &BulletInterface::getID,
			"exists", &BulletInterface::exists,
			"getPlayer", &BulletInterface::getPlayer,
			"getType", &BulletInterface::getType,
			"getSource", &BulletInterface::getSource,
			"getPosition", &BulletInterface::getPosition,
			"getAngle", &BulletInterface::getAngle,
			"getVelocityX", &BulletInterface::getVelocityX,
			"getVelocityY", &BulletInterface::getVelocityY,
			"getTarget", &BulletInterface::getTarget,
			"getTargetPosition", &BulletInterface::getTargetPosition,
			"getRemoveTimer", &BulletInterface::getRemoveTimer,
			"isVisible", sol::overload(
				[](BulletInterface* bullet) { return bullet->isVisible(); },
				&BulletInterface::isVisible
			)
		);
		bindInterface(bullet);
		module.set_usertype("Bullet", bullet);
	}
}