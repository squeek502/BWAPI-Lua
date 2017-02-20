#pragma once

#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	namespace TestBindings
	{
		class MockGameImpl : public Game
		{
			Forceset forceSet;
			Playerset playerSet;
			Unitset unitSet;
			Bulletset bulletSet;
			Position::list positionList;
			std::list<Event> events;
			Regionset regionSet;
			TilePosition::list tilePosList;

			virtual const Forceset & getForces() const override
			{
				return forceSet;
			}
			virtual const Playerset & getPlayers() const override
			{
				return playerSet;
			}
			virtual const Unitset & getAllUnits() const override
			{
				return unitSet;
			}
			virtual const Unitset & getMinerals() const override
			{
				return unitSet;
			}
			virtual const Unitset & getGeysers() const override
			{
				return unitSet;
			}
			virtual const Unitset & getNeutralUnits() const override
			{
				return unitSet;
			}
			virtual const Unitset & getStaticMinerals() const override
			{
				return unitSet;
			}
			virtual const Unitset & getStaticGeysers() const override
			{
				return unitSet;
			}
			virtual const Unitset & getStaticNeutralUnits() const override
			{
				return unitSet;
			}
			virtual const Bulletset & getBullets() const override
			{
				return bulletSet;
			}
			virtual const Position::list & getNukeDots() const override
			{
				return positionList;
			}
			virtual const std::list<Event>& getEvents() const override
			{
				return events;
			}
			virtual Force getForce(int forceID) const override
			{
				return Force();
			}
			virtual Player getPlayer(int playerID) const override
			{
				return Player();
			}
			virtual Unit getUnit(int unitID) const override
			{
				return Unit();
			}
			virtual Unit indexToUnit(int unitIndex) const override
			{
				return Unit();
			}
			virtual Region getRegion(int regionID) const override
			{
				return Region();
			}
			virtual GameType getGameType() const override
			{
				return GameType();
			}
			virtual int getLatency() const override
			{
				return 0;
			}
			virtual int getFrameCount() const override
			{
				return 0;
			}
			virtual int getReplayFrameCount() const override
			{
				return 0;
			}
			virtual int getFPS() const override
			{
				return 0;
			}
			virtual double getAverageFPS() const override
			{
				return 0.0;
			}
			virtual Position getMousePosition() const override
			{
				return Position();
			}
			virtual bool getMouseState(MouseButton button) const override
			{
				return false;
			}
			virtual bool getKeyState(Key key) const override
			{
				return false;
			}
			virtual BWAPI::Position getScreenPosition() const override
			{
				return BWAPI::Position();
			}
			virtual void setScreenPosition(int x, int y) override
			{
			}
			virtual void pingMinimap(int x, int y) override
			{
			}
			virtual bool isFlagEnabled(int flag) const override
			{
				return false;
			}
			virtual void enableFlag(int flag) override
			{
			}
			virtual Unitset getUnitsInRectangle(int left, int top, int right, int bottom, const UnitFilter & pred = nullptr) const override
			{
				return Unitset();
			}
			virtual Unit getClosestUnitInRectangle(Position center, const UnitFilter & pred = nullptr, int left = 0, int top = 0, int right = 999999, int bottom = 999999) const override
			{
				return Unit();
			}
			virtual Unit getBestUnit(const BestUnitFilter & best, const UnitFilter & pred, Position center = Positions::Origin, int radius = 999999) const override
			{
				return Unit();
			}
			virtual Error getLastError() const override
			{
				return Error();
			}
			virtual bool setLastError(BWAPI::Error e = Errors::None) const override
			{
				return false;
			}
			virtual int mapWidth() const override
			{
				return 0;
			}
			virtual int mapHeight() const override
			{
				return 0;
			}
			virtual std::string mapFileName() const override
			{
				return std::string();
			}
			virtual std::string mapPathName() const override
			{
				return std::string();
			}
			virtual std::string mapName() const override
			{
				return std::string();
			}
			virtual std::string mapHash() const override
			{
				return std::string();
			}
			virtual bool isWalkable(int walkX, int walkY) const override
			{
				return false;
			}
			virtual int getGroundHeight(int tileX, int tileY) const override
			{
				return 0;
			}
			virtual bool isBuildable(int tileX, int tileY, bool includeBuildings = false) const override
			{
				return false;
			}
			virtual bool isVisible(int tileX, int tileY) const override
			{
				return false;
			}
			virtual bool isExplored(int tileX, int tileY) const override
			{
				return false;
			}
			virtual bool hasCreep(int tileX, int tileY) const override
			{
				return false;
			}
			virtual bool hasPowerPrecise(int x, int y, UnitType unitType = UnitTypes::None) const override
			{
				return false;
			}
			virtual bool canBuildHere(TilePosition position, UnitType type, Unit builder = nullptr, bool checkExplored = false) override
			{
				return false;
			}
			virtual bool canMake(UnitType type, Unit builder = nullptr) const override
			{
				return false;
			}
			virtual bool canResearch(TechType type, Unit unit = nullptr, bool checkCanIssueCommandType = true) override
			{
				return false;
			}
			virtual bool canUpgrade(UpgradeType type, Unit unit = nullptr, bool checkCanIssueCommandType = true) override
			{
				return false;
			}
			virtual const TilePosition::list & getStartLocations() const override
			{
				return tilePosList;
			}
			virtual void vPrintf(const char * format, va_list args) override
			{
			}
			virtual void vSendTextEx(bool toAllies, const char * format, va_list args) override
			{
			}
			virtual bool isInGame() const override
			{
				return false;
			}
			virtual bool isMultiplayer() const override
			{
				return false;
			}
			virtual bool isBattleNet() const override
			{
				return false;
			}
			virtual bool isPaused() const override
			{
				return false;
			}
			virtual bool isReplay() const override
			{
				return false;
			}
			virtual void pauseGame() override
			{
			}
			virtual void resumeGame() override
			{
			}
			virtual void leaveGame() override
			{
			}
			virtual void restartGame() override
			{
			}
			virtual void setLocalSpeed(int speed) override
			{
			}
			virtual bool issueCommand(const Unitset & units, UnitCommand command) override
			{
				return false;
			}
			virtual const Unitset & getSelectedUnits() const override
			{
				return unitSet;
			}
			virtual Player self() const override
			{
				return Player();
			}
			virtual Player enemy() const override
			{
				return Player();
			}
			virtual Player neutral() const override
			{
				return Player();
			}
			virtual Playerset & allies() override
			{
				return playerSet;
			}
			virtual Playerset & enemies() override
			{
				return playerSet;
			}
			virtual Playerset & observers() override
			{
				return playerSet;
			}
			virtual void setTextSize(Text::Size::Enum size = Text::Size::Default) override
			{
			}
			virtual void vDrawText(CoordinateType::Enum ctype, int x, int y, const char * format, va_list arg) override
			{
			}
			virtual void drawBox(CoordinateType::Enum ctype, int left, int top, int right, int bottom, Color color, bool isSolid = false) override
			{
			}
			virtual void drawTriangle(CoordinateType::Enum ctype, int ax, int ay, int bx, int by, int cx, int cy, Color color, bool isSolid = false) override
			{
			}
			virtual void drawCircle(CoordinateType::Enum ctype, int x, int y, int radius, Color color, bool isSolid = false) override
			{
			}
			virtual void drawEllipse(CoordinateType::Enum ctype, int x, int y, int xrad, int yrad, Color color, bool isSolid = false) override
			{
			}
			virtual void drawDot(CoordinateType::Enum ctype, int x, int y, Color color) override
			{
			}
			virtual void drawLine(CoordinateType::Enum ctype, int x1, int y1, int x2, int y2, Color color) override
			{
			}
			virtual int getLatencyFrames() const override
			{
				return 0;
			}
			virtual int getLatencyTime() const override
			{
				return 0;
			}
			virtual int getRemainingLatencyFrames() const override
			{
				return 0;
			}
			virtual int getRemainingLatencyTime() const override
			{
				return 0;
			}
			virtual int getRevision() const override
			{
				return 0;
			}
			virtual bool isDebug() const override
			{
				return false;
			}
			virtual bool isLatComEnabled() const override
			{
				return false;
			}
			virtual void setLatCom(bool isEnabled) override
			{
			}
			virtual bool isGUIEnabled() const override
			{
				return false;
			}
			virtual void setGUI(bool enabled) override
			{
			}
			virtual int getInstanceNumber() const override
			{
				return 0;
			}
			virtual int getAPM(bool includeSelects = false) const override
			{
				return 0;
			}
			virtual bool setMap(const char * mapFileName) override
			{
				return false;
			}
			virtual void setFrameSkip(int frameSkip) override
			{
			}
			virtual bool setAlliance(BWAPI::Player player, bool allied = true, bool alliedVictory = true) override
			{
				return false;
			}
			virtual bool setVision(BWAPI::Player player, bool enabled = true) override
			{
				return false;
			}
			virtual int elapsedTime() const override
			{
				return 0;
			}
			virtual void setCommandOptimizationLevel(int level) override
			{
			}
			virtual int countdownTimer() const override
			{
				return 0;
			}
			virtual const Regionset & getAllRegions() const override
			{
				return regionSet;
			}
			virtual BWAPI::Region getRegionAt(int x, int y) const override
			{
				return BWAPI::Region();
			}
			virtual int getLastEventTime() const override
			{
				return 0;
			}
			virtual bool setRevealAll(bool reveal = true) override
			{
				return false;
			}
		};

		inline void bindMockGameImpl(sol::table module)
		{
			module.new_usertype<MockGameImpl>("MockGame", sol::default_constructor, sol::base_classes, sol::bases<Game>());
		}
	}
}