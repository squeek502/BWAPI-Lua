#include <sol.hpp>
#include <BWAPI.h>
#include "Interface.h"
#include "IsInstance.h"

using namespace BWAPI;

namespace BWAPI_Lua
{
	void bindGame(sol::table module)
	{
		sol::simple_usertype<Game> game = module.create_simple_usertype<Game>(
			sol::meta_function::construct, sol::no_constructor
		);
		game.set("getForces", &Game::getForces);
		game.set("getPlayers", &Game::getPlayers);
		game.set("getAllUnits", &Game::getAllUnits);
		game.set("getMinerals", &Game::getMinerals);
		game.set("getGeysers", &Game::getGeysers);
		game.set("getNeutralUnits", &Game::getNeutralUnits);
		game.set("getStaticMinerals", &Game::getStaticMinerals);
		game.set("getStaticGeysers", &Game::getStaticGeysers);
		game.set("getStaticNeutralUnits", &Game::getStaticNeutralUnits);
		game.set("getBullets", &Game::getBullets);
		game.set("getNukeDots", 
			[](Game* game)
			{
				return sol::as_table(game->getNukeDots());
			}
		);
		/* Binding removed because I'm not sure of it's applicability
		game.set("getEvents",
			[](Game* game)
			{
				return sol::as_table(game->getEvents());
			}
		);
		*/
		game.set("getForce", &Game::getForce);
		game.set("getPlayer", &Game::getPlayer);
		game.set("getUnit", &Game::getUnit);
		game.set("indexToUnit", &Game::indexToUnit);
		game.set("getRegion", &Game::getRegion);
		game.set("getGameType", &Game::getGameType);
		game.set("getLatency", &Game::getLatency);
		game.set("getFrameCount", &Game::getFrameCount);
		game.set("getReplayFrameCount", &Game::getReplayFrameCount);
		game.set("getFPS", &Game::getFPS);
		game.set("getAverageFPS", &Game::getAverageFPS);
		game.set("getMousePosition", &Game::getMousePosition);
		game.set("getMouseState", &Game::getMouseState);
		game.set("getKeyState", &Game::getKeyState);
		game.set("getScreenPosition", &Game::getScreenPosition);
		game.set("setScreenPosition", sol::overload(
			static_cast<void (Game::*)(int, int)>(&Game::setScreenPosition), 
			static_cast<void (Game::*)(Position)>(&Game::setScreenPosition)
		));
		game.set("pingMinimap", sol::overload(
			static_cast<void (Game::*)(int, int)>(&Game::pingMinimap),
			static_cast<void (Game::*)(Position)>(&Game::pingMinimap)
		));
		game.set("isFlagEnabled", &Game::isFlagEnabled);
		game.set("enableFlag", &Game::enableFlag);
		game.set("getUnitsOnTile", sol::overload(
			[](Game* game, int tileX, int tileY)
			{
				return game->getUnitsOnTile(tileX, tileY);
			},
			[](Game* game, int tileX, int tileY, const sol::function& pred)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getUnitsOnTile(tileX, tileY, pred);
			},
			[](Game* game, int tileX, int tileY, const UnitFilter& pred)
			{
				return game->getUnitsOnTile(tileX, tileY, pred);
			},
			[](Game* game, const TilePosition& pos)
			{
				return game->getUnitsOnTile(pos);
			},
			[](Game* game, const TilePosition& pos, const sol::function& pred)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getUnitsOnTile(pos, pred);
			},
			[](Game* game, const TilePosition& pos, const UnitFilter& pred)
			{
				return game->getUnitsOnTile(pos, pred);
			}
		));
		game.set("getUnitsInRectangle", sol::overload(
			[](Game* game, int left, int top, int right, int bottom)
			{
				return game->getUnitsInRectangle(left, top, right, bottom);
			},
			[](Game* game, int left, int top, int right, int bottom, const sol::function& pred)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getUnitsInRectangle(left, top, right, bottom, pred);
			},
			[](Game* game, int left, int top, int right, int bottom, const UnitFilter& pred)
			{
				return game->getUnitsInRectangle(left, top, right, bottom, pred);
			},
			[](Game* game, const Position& topLeft, const Position& bottomRight)
			{
				return game->getUnitsInRectangle(topLeft, bottomRight);
			},
			[](Game* game, const Position& topLeft, const Position& bottomRight, const sol::function& pred)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getUnitsInRectangle(topLeft, bottomRight, pred);
			},
			[](Game* game, const Position& topLeft, const Position& bottomRight, const UnitFilter& pred)
			{
				return game->getUnitsInRectangle(topLeft, bottomRight, pred);
			}
		));
		game.set("getUnitsInRadius", sol::overload(
			[](Game* game, int x, int y, int radius)
			{
				return game->getUnitsInRadius(x, y, radius);
			},
			[](Game* game, int x, int y, int radius, const sol::function& pred)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getUnitsInRadius(x, y, radius, pred);
			},
			[](Game* game, int x, int y, int radius, const UnitFilter& pred)
			{
				return game->getUnitsInRadius(x, y, radius, pred);
			},
			[](Game* game, const Position& center, int radius)
			{
				return game->getUnitsInRadius(center, radius);
			},
			[](Game* game, const Position& center, int radius, const sol::function& pred)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getUnitsInRadius(center, radius, pred);
			},
			[](Game* game, const Position& center, int radius, const UnitFilter& pred)
			{
				return game->getUnitsInRadius(center, radius, pred);
			}
		));
		game.set("getClosestUnit", sol::overload(
			[](Game* game, const Position& center)
			{
				return game->getClosestUnit(center);
			},
			[](Game* game, const Position& center, const sol::function& pred)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getClosestUnit(center, pred);
			},
			[](Game* game, const Position& center, const UnitFilter& pred)
			{
				return game->getClosestUnit(center, pred);
			},
			&Game::getClosestUnit
		));
		game.set("getClosestUnitInRectangle", sol::overload(
			[](Game* game, const Position& center)
			{
				return game->getClosestUnitInRectangle(center);
			},
			[](Game* game, const Position& center, const sol::function& pred)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getClosestUnitInRectangle(center, pred);
			},
			[](Game* game, const Position& center, const sol::function& pred, int left)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getClosestUnitInRectangle(center, pred, left);
			},
			[](Game* game, const Position& center, const sol::function& pred, int left, int top)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getClosestUnitInRectangle(center, pred, left, top);
			},
			[](Game* game, const Position& center, const sol::function& pred, int left, int top, int right)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getClosestUnitInRectangle(center, pred, left, top, right);
			},
			[](Game* game, const Position& center, const sol::function& pred, int left, int top, int right, int bottom)
			{
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getClosestUnitInRectangle(center, pred, left, top, right, bottom);
			},
			[](Game* game, const Position& center, const UnitFilter& pred)
			{
				return game->getClosestUnitInRectangle(center, pred);
			},
			[](Game* game, const Position& center, const UnitFilter& pred, int left)
			{
				return game->getClosestUnitInRectangle(center, pred, left);
			},
			[](Game* game, const Position& center, const UnitFilter& pred, int left, int top)
			{
				return game->getClosestUnitInRectangle(center, pred, left, top);
			},
			[](Game* game, const Position& center, const UnitFilter& pred, int left, int top, int right)
			{
				return game->getClosestUnitInRectangle(center, pred, left, top, right);
			},
			[](Game* game, const Position& center, const UnitFilter& pred, int left, int top, int right, int bottom)
			{
				return game->getClosestUnitInRectangle(center, pred, left, top, right, bottom);
			}
		));
		game.set("getBestUnit", sol::overload(
			[](Game* game, const sol::function& best, const sol::function& pred)
			{
				BestUnitFilter bestFilter(nullptr);
				if (best.valid())
					bestFilter = BestUnitFilter(sol::protected_function(best));
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getBestUnit(bestFilter, filter);
			},
			[](Game* game, const sol::function& best, const sol::function& pred, const Position& center)
			{
				BestUnitFilter bestFilter(nullptr);
				if (best.valid())
					bestFilter = BestUnitFilter(sol::protected_function(best));
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getBestUnit(bestFilter, filter, center);
			},
			[](Game* game, const sol::function& best, const sol::function& pred, const Position& center, int radius)
			{
				BestUnitFilter bestFilter(nullptr);
				if (best.valid())
					bestFilter = BestUnitFilter(sol::protected_function(best));
				UnitFilter filter(nullptr);
				if (pred.valid())
					filter = UnitFilter(sol::protected_function(pred));
				return game->getBestUnit(bestFilter, filter, center, radius);
			},
			[](Game* game, const sol::function& best, const UnitFilter& filter, const Position& center)
			{
				BestUnitFilter bestFilter(nullptr);
				if (best.valid())
					bestFilter = BestUnitFilter(sol::protected_function(best));
				return game->getBestUnit(bestFilter, filter, center);
			},
			[](Game* game, const sol::function& best, const UnitFilter& filter, const Position& center, int radius)
			{
				BestUnitFilter bestFilter(nullptr);
				if (best.valid())
					bestFilter = BestUnitFilter(sol::protected_function(best));
				return game->getBestUnit(bestFilter, filter, center, radius);
			}
		));
		game.set("getLastError", &Game::getLastError);
		game.set("setLastError", sol::overload(
			[](Game* game) { return game->setLastError(); },
			&Game::setLastError
		));
		game.set("mapWidth", &Game::mapWidth);
		game.set("mapHeight", &Game::mapHeight);
		game.set("mapFileName", &Game::mapFileName);
		game.set("mapPathName", &Game::mapPathName);
		game.set("mapName", &Game::mapName);
		game.set("mapHash", &Game::mapHash);
		game.set("isWalkable", sol::overload(
			static_cast<bool (Game::*)(int, int) const>(&Game::isWalkable),
			static_cast<bool (Game::*)(WalkPosition) const>(&Game::isWalkable)
		));
		game.set("getGroundHeight", sol::overload(
			static_cast<int (Game::*)(int, int) const>(&Game::getGroundHeight),
			static_cast<int (Game::*)(TilePosition) const>(&Game::getGroundHeight)
		));
		game.set("isBuildable", sol::overload(
			[](Game* game, int x, int y) { return game->isBuildable(x, y); },
			static_cast<bool (Game::*)(int, int, bool) const>(&Game::isBuildable),
			[](Game* game, TilePosition pos) { return game->isBuildable(pos); },
			static_cast<bool (Game::*)(TilePosition, bool) const>(&Game::isBuildable)
		));
		game.set("isVisible", sol::overload(
			static_cast<bool (Game::*)(int, int) const>(&Game::isVisible),
			static_cast<bool (Game::*)(TilePosition) const>(&Game::isVisible)
		));
		game.set("isExplored", sol::overload(
			static_cast<bool (Game::*)(int, int) const>(&Game::isExplored),
			static_cast<bool (Game::*)(TilePosition) const>(&Game::isExplored)
		));
		game.set("hasCreep", sol::overload(
			static_cast<bool (Game::*)(int, int) const>(&Game::hasCreep),
			static_cast<bool (Game::*)(TilePosition) const>(&Game::hasCreep)
		));
		game.set("hasPowerPrecise", sol::overload(
			[](Game* game, int x, int y) { return game->hasPowerPrecise(x, y); },
			static_cast<bool (Game::*)(int, int, UnitType) const>(&Game::hasPowerPrecise),
			[](Game* game, Position pos) { return game->hasPowerPrecise(pos); },
			static_cast<bool (Game::*)(Position, UnitType) const>(&Game::hasPowerPrecise)
		));
		game.set("hasPower", sol::overload(
			[](Game* game, int x, int y) { return game->hasPower(x, y); },
			static_cast<bool (Game::*)(int, int, UnitType) const>(&Game::hasPower),
			[](Game* game, TilePosition pos) { return game->hasPower(pos); },
			static_cast<bool (Game::*)(TilePosition, UnitType) const>(&Game::hasPower),

			[](Game* game, int x, int y, int w, int h) { return game->hasPower(x, y, w, h); },
			static_cast<bool (Game::*)(int, int, int, int, UnitType) const>(&Game::hasPower),
			[](Game* game, TilePosition pos, int w, int h) { return game->hasPower(pos, w, h); },
			static_cast<bool (Game::*)(TilePosition, int, int, UnitType) const>(&Game::hasPower)
		));
		game.set("canBuildHere", sol::overload(
			[](Game* game, TilePosition pos, UnitType type) { return game->canBuildHere(pos, type); },
			[](Game* game, TilePosition pos, UnitType type, Unit unit) { return game->canBuildHere(pos, type, unit); },
			&Game::canBuildHere
		));
		game.set("canMake", sol::overload(
			[](Game* game, UnitType type) { return game->canMake(type); },
			&Game::canMake
		));
		game.set("canResearch", sol::overload(
			[](Game* game, TechType type) { return game->canResearch(type); },
			[](Game* game, TechType type, Unit unit) { return game->canResearch(type, unit); },
			&Game::canResearch
		));
		game.set("canUpgrade", sol::overload(
			[](Game* game, UpgradeType type) { return game->canUpgrade(type); },
			[](Game* game, UpgradeType type, Unit unit) { return game->canUpgrade(type, unit); },
			&Game::canUpgrade
		));
		game.set("getStartLocations", [](Game* game) { return sol::as_table(game->getStartLocations()); });
		game.set("printf", [](Game* game, const char* msg) { return game->printf("%s", msg); });
		game.set("sendText", [](Game* game, const char *msg) { game->sendText("%s", msg); });
		game.set("sendTextEx", [](Game* game, bool toAllies, const char *msg) { game->sendTextEx(toAllies, "%s", msg); });
		game.set("sendTextToAllies", [](Game* game, const char *msg) { game->sendTextEx(true, "%s", msg); }); // BWAPI-Lua specific
		game.set("isInGame", &Game::isInGame);
		game.set("isMultiplayer", &Game::isMultiplayer);
		game.set("isBattleNet", &Game::isBattleNet);
		game.set("isPaused", &Game::isPaused);
		game.set("isReplay", &Game::isReplay);
		game.set("pauseGame", &Game::pauseGame);
		game.set("resumeGame", &Game::resumeGame);
		game.set("leaveGame", &Game::leaveGame);
		game.set("restartGame", &Game::restartGame);
		game.set("setLocalSpeed", &Game::setLocalSpeed);
		game.set("issueCommand", &Game::issueCommand);
		game.set("getSelectedUnits", &Game::getSelectedUnits);
		game.set("self", &Game::self);
		game.set("enemy", &Game::enemy);
		game.set("neutral", &Game::neutral);
		game.set("allies", &Game::allies);
		game.set("enemies", &Game::enemies);
		game.set("observers", &Game::observers);
		game.set("setTextSize", sol::overload(
			[](Game* game) { return game->setTextSize(); },
			&Game::setTextSize
		));
		game.set("drawText", [](Game* game, CoordinateType::Enum ctype, int x, int y, const char *str) { return game->drawText(ctype, x, y, "%s", str); });
		game.set("drawTextMap", sol::overload(
			[](Game* game, int x, int y, const char *str) { return game->drawTextMap(x, y, "%s", str); },
			[](Game* game, Position pos, const char *str) { return game->drawTextMap(pos, "%s", str); }
		));
		game.set("drawTextMouse", sol::overload(
			[](Game* game, int x, int y, const char *str) { return game->drawTextMouse(x, y, "%s", str); },
			[](Game* game, Position pos, const char *str) { return game->drawTextMouse(pos, "%s", str); }
		));
		game.set("drawTextScreen", sol::overload(
			[](Game* game, int x, int y, const char *str) { return game->drawTextScreen(x, y, "%s", str); },
			[](Game* game, Position pos, const char *str) { return game->drawTextScreen(pos, "%s", str); }
		));
		game.set("drawBox", sol::overload(
			[](Game* game, CoordinateType::Enum ctype, int left, int top, int right, int bottom, Color color) { return game->drawBox(ctype, left, top, right, bottom, color); },
			&Game::drawBox
		));
		game.set("drawBoxMap", sol::overload(
			[](Game* game, int left, int top, int right, int bottom, Color color)
			{
				return game->drawBoxMap(left, top, right, bottom, color);
			},
			static_cast<void (Game::*)(int, int, int, int, Color, bool)>(&Game::drawBoxMap),
			[](Game* game, Position leftTop, Position rightBottom, Color color)
			{
				return game->drawBoxMap(leftTop, rightBottom, color);
			},
			static_cast<void (Game::*)(Position, Position, Color, bool)>(&Game::drawBoxMap)
		));
		game.set("drawBoxMouse", sol::overload(
			[](Game* game, int left, int top, int right, int bottom, Color color)
			{
				return game->drawBoxMouse(left, top, right, bottom, color);
			},
			static_cast<void (Game::*)(int, int, int, int, Color, bool)>(&Game::drawBoxMouse),
			[](Game* game, Position leftTop, Position rightBottom, Color color)
			{
				return game->drawBoxMouse(leftTop, rightBottom, color);
			},
			static_cast<void (Game::*)(Position, Position, Color, bool)>(&Game::drawBoxMouse)
		));
		game.set("drawBoxScreen", sol::overload(
			[](Game* game, int left, int top, int right, int bottom, Color color)
			{
				return game->drawBoxScreen(left, top, right, bottom, color);
			},
			static_cast<void (Game::*)(int, int, int, int, Color, bool)>(&Game::drawBoxScreen),
			[](Game* game, Position leftTop, Position rightBottom, Color color)
			{
				return game->drawBoxScreen(leftTop, rightBottom, color);
			},
			static_cast<void (Game::*)(Position, Position, Color, bool)>(&Game::drawBoxScreen)
		));
		game.set("drawTriangle", sol::overload(
			[](Game* game, CoordinateType::Enum ctype, int ax, int ay, int bx, int by, int cx, int cy, Color color) { return game->drawTriangle(ctype, ax, ay, bx, by, cx, cy, color); },
			&Game::drawTriangle
		));
		game.set("drawTriangleMap", sol::overload(
			[](Game* game, int ax, int ay, int bx, int by, int cx, int cy, Color color)
			{
				return game->drawTriangleMap(ax, ay, bx, by, cx, cy, color);
			},
			static_cast<void (Game::*)(int, int, int, int, int, int, Color, bool)>(&Game::drawTriangleMap),
			[](Game* game, Position a, Position b, Position c, Color color)
			{
				return game->drawTriangleMap(a, b, c, color);
			},
			static_cast<void (Game::*)(Position, Position, Position, Color, bool)>(&Game::drawTriangleMap)
		));
		game.set("drawTriangleMouse", sol::overload(
			[](Game* game, int ax, int ay, int bx, int by, int cx, int cy, Color color)
			{
				return game->drawTriangleMouse(ax, ay, bx, by, cx, cy, color);
			},
			static_cast<void (Game::*)(int, int, int, int, int, int, Color, bool)>(&Game::drawTriangleMouse),
			[](Game* game, Position a, Position b, Position c, Color color)
			{
				return game->drawTriangleMouse(a, b, c, color);
			},
			static_cast<void (Game::*)(Position, Position, Position, Color, bool)>(&Game::drawTriangleMouse)
		));
		game.set("drawTriangleScreen", sol::overload(
			[](Game* game, int ax, int ay, int bx, int by, int cx, int cy, Color color)
			{
				return game->drawTriangleScreen(ax, ay, bx, by, cx, cy, color);
			},
			static_cast<void (Game::*)(int, int, int, int, int, int, Color, bool)>(&Game::drawTriangleScreen),
			[](Game* game, Position a, Position b, Position c, Color color)
			{
				return game->drawTriangleScreen(a, b, c, color);
			},
			static_cast<void (Game::*)(Position, Position, Position, Color, bool)>(&Game::drawTriangleScreen)
		));
		game.set("drawCircle", sol::overload(
			[](Game* game, CoordinateType::Enum ctype, int x, int y, int radius, Color color) { return game->drawCircle(ctype, x, y, radius, color); },
			&Game::drawCircle
		));
		game.set("drawCircleMap", sol::overload(
			[](Game* game, int x, int y, int radius, Color color)
			{
				return game->drawCircleMap(x, y, radius, color);
			},
			static_cast<void (Game::*)(int, int, int, Color, bool)>(&Game::drawCircleMap),
			[](Game* game, Position p, int radius, Color color)
			{
				return game->drawCircleMap(p, radius, color);
			},
			static_cast<void (Game::*)(Position, int, Color, bool)>(&Game::drawCircleMap)
		));
		game.set("drawCircleMouse", sol::overload(
			[](Game* game, int x, int y, int radius, Color color)
			{
				return game->drawCircleMouse(x, y, radius, color);
			},
			static_cast<void (Game::*)(int, int, int, Color, bool)>(&Game::drawCircleMouse),
			[](Game* game, Position p, int radius, Color color)
			{
				return game->drawCircleMouse(p, radius, color);
			},
			static_cast<void (Game::*)(Position, int, Color, bool)>(&Game::drawCircleMouse)
		));
		game.set("drawCircleScreen", sol::overload(
			[](Game* game, int x, int y, int radius, Color color)
			{
				return game->drawCircleScreen(x, y, radius, color);
			},
			static_cast<void (Game::*)(int, int, int, Color, bool)>(&Game::drawCircleScreen),
			[](Game* game, Position p, int radius, Color color)
			{
				return game->drawCircleScreen(p, radius, color);
			},
			static_cast<void (Game::*)(Position, int, Color, bool)>(&Game::drawCircleScreen)
		));
		game.set("drawEllipse", sol::overload(
			[](Game* game, CoordinateType::Enum ctype, int x, int y, int xrad, int yrad, Color color) { return game->drawEllipse(ctype, x, y, xrad, yrad, color); },
			&Game::drawEllipse
		));
		game.set("drawEllipseMap", sol::overload(
			[](Game* game, int x, int y, int xrad, int yrad, Color color)
			{
				return game->drawEllipseMap(x, y, xrad, yrad, color);
			},
			static_cast<void (Game::*)(int, int, int, int, Color, bool)>(&Game::drawEllipseMap),
			[](Game* game, Position p, int xrad, int yrad, Color color)
			{
				return game->drawEllipseMap(p, xrad, yrad, color);
			},
			static_cast<void (Game::*)(Position, int, int, Color, bool)>(&Game::drawEllipseMap)
		));
		game.set("drawEllipseMouse", sol::overload(
			[](Game* game, int x, int y, int xrad, int yrad, Color color)
			{
				return game->drawEllipseMouse(x, y, xrad, yrad, color);
			},
			static_cast<void (Game::*)(int, int, int, int, Color, bool)>(&Game::drawEllipseMouse),
			[](Game* game, Position p, int xrad, int yrad, Color color)
			{
				return game->drawEllipseMouse(p, xrad, yrad, color);
			},
			static_cast<void (Game::*)(Position, int, int, Color, bool)>(&Game::drawEllipseMouse)
		));
		game.set("drawEllipseScreen", sol::overload(
			[](Game* game, int x, int y, int xrad, int yrad, Color color)
			{
				return game->drawEllipseScreen(x, y, xrad, yrad, color);
			},
			static_cast<void (Game::*)(int, int, int, int, Color, bool)>(&Game::drawEllipseScreen),
			[](Game* game, Position p, int xrad, int yrad, Color color)
			{
				return game->drawEllipseScreen(p, xrad, yrad, color);
			},
			static_cast<void (Game::*)(Position, int, int, Color, bool)>(&Game::drawEllipseScreen)
		));
		game.set("drawDot", &Game::drawDot);
		game.set("drawDotMap", sol::overload(
			static_cast<void (Game::*)(int, int, Color)>(&Game::drawDotMap),
			static_cast<void (Game::*)(Position, Color)>(&Game::drawDotMap)
		));
		game.set("drawDotMouse", sol::overload(
			static_cast<void (Game::*)(int, int, Color)>(&Game::drawDotMouse),
			static_cast<void (Game::*)(Position, Color)>(&Game::drawDotMouse)
		));
		game.set("drawDotScreen", sol::overload(
			static_cast<void (Game::*)(int, int, Color)>(&Game::drawDotScreen),
			static_cast<void (Game::*)(Position, Color)>(&Game::drawDotScreen)
		));
		game.set("drawLine", &Game::drawLine);
		game.set("drawLineMap", sol::overload(
			static_cast<void (Game::*)(int, int, int, int, Color)>(&Game::drawLineMap),
			static_cast<void (Game::*)(Position, Position, Color)>(&Game::drawLineMap)
		));
		game.set("drawLineMouse", sol::overload(
			static_cast<void (Game::*)(int, int, int, int, Color)>(&Game::drawLineMouse),
			static_cast<void (Game::*)(Position, Position, Color)>(&Game::drawLineMouse)
		));
		game.set("drawLineScreen", sol::overload(
			static_cast<void (Game::*)(int, int, int, int, Color)>(&Game::drawLineScreen),
			static_cast<void (Game::*)(Position, Position, Color)>(&Game::drawLineScreen)
		));
		game.set("getLatencyFrames", &Game::getLatencyFrames);
		game.set("getLatencyTime", &Game::getLatencyTime);
		game.set("getRemainingLatencyFrames", &Game::getRemainingLatencyFrames);
		game.set("getRemainingLatencyTime", &Game::getRemainingLatencyTime);
		game.set("getRevision", &Game::getRevision);
		game.set("isDebug", &Game::isDebug);
		game.set("isLatComEnabled", &Game::isLatComEnabled);
		game.set("setLatCom", &Game::setLatCom);
		game.set("isGUIEnabled", &Game::isGUIEnabled);
		game.set("setGUI", &Game::setGUI);
		game.set("setGUIEnabled", &Game::setGUI); // BWAPI-Lua specific
		game.set("getInstanceNumber", &Game::getInstanceNumber);
		game.set("getAPM", sol::overload(
			[](Game* game) { return game->getAPM(); },
			&Game::getAPM
		));
		game.set("setMap", static_cast<bool (Game::*)(const char*)>(&Game::setMap));
		game.set("setFrameSkip", &Game::setFrameSkip);
		game.set("hasPath", &Game::hasPath);
		game.set("setAlliance", sol::overload(
			[](Game* game, Player player) { return game->setAlliance(player); },
			[](Game* game, Player player, bool allied) { return game->setAlliance(player, allied); },
			&Game::setAlliance
		));
		game.set("setVision", sol::overload(
			[](Game* game, Player player) { return game->setVision(player); },
			&Game::setVision
		));
		game.set("elapsedTime", &Game::elapsedTime);
		game.set("setCommandOptimizationLevel", &Game::setCommandOptimizationLevel);
		game.set("countdownTimer", &Game::countdownTimer);
		game.set("getAllRegions", &Game::getAllRegions);
		game.set("getRegionAt", sol::overload(
			static_cast<Region (Game::*)(int, int) const>(&Game::getRegionAt),
			static_cast<Region(Game::*)(Position) const>(&Game::getRegionAt)
		));
		game.set("getLastEventTime", &Game::getLastEventTime);
		game.set("setRevealAll", sol::overload(
			[](Game* game) { return game->setRevealAll(); },
			&Game::setRevealAll
		));
		game.set("getBuildLocation", sol::overload(
			[](Game *game, UnitType type, TilePosition desiredPosition)
			{
				return game->getBuildLocation(type, desiredPosition);
			},
			[](Game *game, UnitType type, TilePosition desiredPosition, int maxRange)
			{
				return game->getBuildLocation(type, desiredPosition, maxRange);
			},
			&Game::getBuildLocation
		));
		game.set("getDamageFrom", sol::overload(
			[](Game *game, UnitType fromType, UnitType toType)
			{
				return game->getDamageFrom(fromType, toType);
			},
			[](Game *game, UnitType fromType, UnitType toType, Player fromPlayer)
			{
				return game->getDamageFrom(fromType, toType, fromPlayer);
			},
			&Game::getDamageFrom
		));
		game.set("getDamageTo", sol::overload(
			[](Game *game, UnitType toType, UnitType fromType)
			{
				return game->getDamageTo(toType, fromType);
			},
			[](Game *game, UnitType toType, UnitType fromType, Player toPlayer)
			{
				return game->getDamageTo(toType, fromType, toPlayer);
			},
			&Game::getDamageTo
		));
		game.set("getRandomSeed", &Game::getRandomSeed);
		bindInterface(game);
		bindIsInstance(game);
		module.set_usertype("Game", game);
	}
}