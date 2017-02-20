#include <sol.hpp>
#include <BWAPI.h>
#include "Interface.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindGame(sol::table module)
	{
		sol::simple_usertype<Game> game = module.create_simple_usertype<Game>(
			sol::meta_function::construct, sol::nil,
			"getForces", &Game::getForces,
			"setCommandOptimizationLevel", &Game::setCommandOptimizationLevel,
			"enableFlag", &Game::enableFlag,
			"isReplay", &Game::isReplay,
			"isPaused", &Game::isPaused,
			"getPlayers", &Game::getPlayers,
			"enemy", &Game::enemy,
			"self", &Game::self,
			"getFPS", &Game::getFPS,
			"getAverageFPS", &Game::getAverageFPS,
			"mapName", &Game::mapName,
			"getLastError", &Game::getLastError,
			"getFrameCount", &Game::getFrameCount,
			"getLatencyFrames", &Game::getLatencyFrames,
			"getBuildLocation", sol::overload(
				[](Game *game, UnitType type, TilePosition desiredPosition)
				{
					return game->getBuildLocation(type, desiredPosition);
				},
				[](Game *game, UnitType type, TilePosition desiredPosition, int maxRange)
				{
					return game->getBuildLocation(type, desiredPosition, maxRange);
				},
				&Game::getBuildLocation
			),
			"drawTextScreen", [](Game* game, int x, int y, const char *text) { game->drawTextScreen(x, y, "%s", text); },
			"drawTextMap", sol::overload(
				[](Game* game, int x, int y, const char* text)
				{
					return game->drawTextMap(x, y, "%s", text);
				},
				[](Game* game, Position pos, const char* text)
				{
					return game->drawTextMap(pos, "%s", text);
				}
			),
			"drawBoxMap", sol::overload(
				[](Game* game, int left, int top, int right, int bottom, Color color)
				{
					return game->drawBoxMap(left, top, right, bottom, color);
				},
				[](Game* game, int left, int top, int right, int bottom, Color color, bool isSolid)
				{
					return game->drawBoxMap(left, top, right, bottom, color, isSolid);
				},
				[](Game* game, Position leftTop, Position rightBottom, Color color)
				{
					return game->drawBoxMap(leftTop, rightBottom, color);
				},
				[](Game* game, Position leftTop, Position rightBottom, Color color, bool isSolid)
				{
					return game->drawBoxMap(leftTop, rightBottom, color, isSolid);
				}
			),
			"sendText", [](Game* game, const char *msg) { game->sendText("%s", msg); }
		);
		bindInterface(game);
		module.set_usertype("Game", game);
	}
}