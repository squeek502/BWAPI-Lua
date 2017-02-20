#pragma once

#include <sol.hpp>
#include <BWAPI.h>

using namespace BWAPI;

namespace BWAPI_Lua
{
	namespace TestBindings
	{
		class MockUnitImpl : public UnitInterface {
		public:
			virtual int getID() const override
			{
				return 0;
			}
			virtual bool exists() const override
			{
				return false;
			}
			virtual int getReplayID() const override
			{
				return 0;
			}
			virtual Player getPlayer() const override
			{
				return Player();
			}
			virtual UnitType getType() const override
			{
				return UnitType();
			}
			virtual Position getPosition() const override
			{
				return Position();
			}
			virtual double getAngle() const override
			{
				return 0.0;
			}
			virtual double getVelocityX() const override
			{
				return 0.0;
			}
			virtual double getVelocityY() const override
			{
				return 0.0;
			}
			virtual int getHitPoints() const override
			{
				return 0;
			}
			virtual int getShields() const override
			{
				return 0;
			}
			virtual int getEnergy() const override
			{
				return 0;
			}
			virtual int getResources() const override
			{
				return 0;
			}
			virtual int getResourceGroup() const override
			{
				return 0;
			}
			virtual int getLastCommandFrame() const override
			{
				return 0;
			}
			virtual UnitCommand getLastCommand() const override
			{
				return UnitCommand();
			}
			virtual BWAPI::Player getLastAttackingPlayer() const override
			{
				return BWAPI::Player();
			}
			virtual UnitType getInitialType() const override
			{
				return UnitType();
			}
			virtual Position getInitialPosition() const override
			{
				return Position();
			}
			virtual TilePosition getInitialTilePosition() const override
			{
				return TilePosition();
			}
			virtual int getInitialHitPoints() const override
			{
				return 0;
			}
			virtual int getInitialResources() const override
			{
				return 0;
			}
			virtual int getKillCount() const override
			{
				return 0;
			}
			virtual int getAcidSporeCount() const override
			{
				return 0;
			}
			virtual int getInterceptorCount() const override
			{
				return 0;
			}
			virtual int getScarabCount() const override
			{
				return 0;
			}
			virtual int getSpiderMineCount() const override
			{
				return 0;
			}
			virtual int getGroundWeaponCooldown() const override
			{
				return 0;
			}
			virtual int getAirWeaponCooldown() const override
			{
				return 0;
			}
			virtual int getSpellCooldown() const override
			{
				return 0;
			}
			virtual int getDefenseMatrixPoints() const override
			{
				return 0;
			}
			virtual int getDefenseMatrixTimer() const override
			{
				return 0;
			}
			virtual int getEnsnareTimer() const override
			{
				return 0;
			}
			virtual int getIrradiateTimer() const override
			{
				return 0;
			}
			virtual int getLockdownTimer() const override
			{
				return 0;
			}
			virtual int getMaelstromTimer() const override
			{
				return 0;
			}
			virtual int getOrderTimer() const override
			{
				return 0;
			}
			virtual int getPlagueTimer() const override
			{
				return 0;
			}
			virtual int getRemoveTimer() const override
			{
				return 0;
			}
			virtual int getStasisTimer() const override
			{
				return 0;
			}
			virtual int getStimTimer() const override
			{
				return 0;
			}
			virtual UnitType getBuildType() const override
			{
				return UnitType();
			}
			virtual UnitType::list getTrainingQueue() const override
			{
				return UnitType::list();
			}
			virtual TechType getTech() const override
			{
				return TechType();
			}
			virtual UpgradeType getUpgrade() const override
			{
				return UpgradeType();
			}
			virtual int getRemainingBuildTime() const override
			{
				return 0;
			}
			virtual int getRemainingTrainTime() const override
			{
				return 0;
			}
			virtual int getRemainingResearchTime() const override
			{
				return 0;
			}
			virtual int getRemainingUpgradeTime() const override
			{
				return 0;
			}
			virtual Unit getBuildUnit() const override
			{
				return Unit();
			}
			virtual Unit getTarget() const override
			{
				return Unit();
			}
			virtual Position getTargetPosition() const override
			{
				return Position();
			}
			virtual Order getOrder() const override
			{
				return Order();
			}
			virtual Order getSecondaryOrder() const override
			{
				return Order();
			}
			virtual Unit getOrderTarget() const override
			{
				return Unit();
			}
			virtual Position getOrderTargetPosition() const override
			{
				return Position();
			}
			virtual Position getRallyPosition() const override
			{
				return Position();
			}
			virtual Unit getRallyUnit() const override
			{
				return Unit();
			}
			virtual Unit getAddon() const override
			{
				return Unit();
			}
			virtual Unit getNydusExit() const override
			{
				return Unit();
			}
			virtual Unit getPowerUp() const override
			{
				return Unit();
			}
			virtual Unit getTransport() const override
			{
				return Unit();
			}
			virtual Unitset getLoadedUnits() const override
			{
				return Unitset();
			}
			virtual Unit getCarrier() const override
			{
				return Unit();
			}
			virtual Unitset getInterceptors() const override
			{
				return Unitset();
			}
			virtual Unit getHatchery() const override
			{
				return Unit();
			}
			virtual Unitset getLarva() const override
			{
				return Unitset();
			}
			virtual bool hasNuke() const override
			{
				return false;
			}
			virtual bool isAccelerating() const override
			{
				return false;
			}
			virtual bool isAttacking() const override
			{
				return false;
			}
			virtual bool isAttackFrame() const override
			{
				return false;
			}
			virtual bool isBeingGathered() const override
			{
				return false;
			}
			virtual bool isBeingHealed() const override
			{
				return false;
			}
			virtual bool isBlind() const override
			{
				return false;
			}
			virtual bool isBraking() const override
			{
				return false;
			}
			virtual bool isBurrowed() const override
			{
				return false;
			}
			virtual bool isCarryingGas() const override
			{
				return false;
			}
			virtual bool isCarryingMinerals() const override
			{
				return false;
			}
			virtual bool isCloaked() const override
			{
				return false;
			}
			virtual bool isCompleted() const override
			{
				return false;
			}
			virtual bool isConstructing() const override
			{
				return false;
			}
			virtual bool isDetected() const override
			{
				return false;
			}
			virtual bool isGatheringGas() const override
			{
				return false;
			}
			virtual bool isGatheringMinerals() const override
			{
				return false;
			}
			virtual bool isHallucination() const override
			{
				return false;
			}
			virtual bool isIdle() const override
			{
				return false;
			}
			virtual bool isInterruptible() const override
			{
				return false;
			}
			virtual bool isInvincible() const override
			{
				return false;
			}
			virtual bool isLifted() const override
			{
				return false;
			}
			virtual bool isMorphing() const override
			{
				return false;
			}
			virtual bool isMoving() const override
			{
				return false;
			}
			virtual bool isParasited() const override
			{
				return false;
			}
			virtual bool isSelected() const override
			{
				return false;
			}
			virtual bool isStartingAttack() const override
			{
				return false;
			}
			virtual bool isStuck() const override
			{
				return false;
			}
			virtual bool isTraining() const override
			{
				return false;
			}
			virtual bool isUnderAttack() const override
			{
				return false;
			}
			virtual bool isUnderDarkSwarm() const override
			{
				return false;
			}
			virtual bool isUnderDisruptionWeb() const override
			{
				return false;
			}
			virtual bool isUnderStorm() const override
			{
				return false;
			}
			virtual bool isPowered() const override
			{
				return false;
			}
			virtual bool isVisible(Player player = nullptr) const override
			{
				return false;
			}
			virtual bool isTargetable() const override
			{
				return false;
			}
			virtual bool issueCommand(UnitCommand command) override
			{
				return false;
			}
			virtual bool canIssueCommand(UnitCommand command, bool checkCanUseTechPositionOnPositions = true, bool checkCanUseTechUnitOnUnits = true, bool checkCanBuildUnitType = true, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canIssueCommandGrouped(UnitCommand command, bool checkCanUseTechPositionOnPositions = true, bool checkCanUseTechUnitOnUnits = true, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canCommand() const override
			{
				return false;
			}
			virtual bool canCommandGrouped(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canIssueCommandType(UnitCommandType ct, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canIssueCommandTypeGrouped(UnitCommandType ct, bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canTargetUnit(Unit targetUnit, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canAttack(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canAttack(PositionOrUnit target, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canAttackGrouped(bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canAttackGrouped(PositionOrUnit target, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canAttackMove(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canAttackMoveGrouped(bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canAttackUnit(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canAttackUnit(Unit targetUnit, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canAttackUnitGrouped(bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canAttackUnitGrouped(Unit targetUnit, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canBuild(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canBuild(UnitType uType, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canBuild(UnitType uType, BWAPI::TilePosition tilePos, bool checkTargetUnitType = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canBuildAddon(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canBuildAddon(UnitType uType, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canTrain(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canTrain(UnitType uType, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canMorph(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canMorph(UnitType uType, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canResearch(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canResearch(TechType type, bool checkCanIssueCommandType = true) const override
			{
				return false;
			}
			virtual bool canUpgrade(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUpgrade(UpgradeType type, bool checkCanIssueCommandType = true) const override
			{
				return false;
			}
			virtual bool canSetRallyPoint(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canSetRallyPoint(PositionOrUnit target, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canSetRallyPosition(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canSetRallyUnit(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canSetRallyUnit(Unit targetUnit, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canMove(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canMoveGrouped(bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canPatrol(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canPatrolGrouped(bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canFollow(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canFollow(Unit targetUnit, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canGather(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canGather(Unit targetUnit, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canReturnCargo(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canHoldPosition(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canStop(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRepair(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRepair(Unit targetUnit, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canBurrow(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUnburrow(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canCloak(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canDecloak(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canSiege(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUnsiege(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canLift(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canLand(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canLand(TilePosition target, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canLoad(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canLoad(Unit targetUnit, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUnloadWithOrWithoutTarget(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUnloadAtPosition(Position targDropPos, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUnload(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUnload(Unit targetUnit, bool checkCanTargetUnit = true, bool checkPosition = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUnloadAll(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUnloadAllPosition(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUnloadAllPosition(Position targDropPos, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRightClick(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRightClick(PositionOrUnit target, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRightClickGrouped(bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRightClickGrouped(PositionOrUnit target, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRightClickPosition(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRightClickPositionGrouped(bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRightClickUnit(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRightClickUnit(Unit targetUnit, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRightClickUnitGrouped(bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canRightClickUnitGrouped(Unit targetUnit, bool checkCanTargetUnit = true, bool checkCanIssueCommandType = true, bool checkCommandibilityGrouped = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canHaltConstruction(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canCancelConstruction(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canCancelAddon(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canCancelTrain(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canCancelTrainSlot(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canCancelTrainSlot(int slot, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canCancelMorph(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canCancelResearch(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canCancelUpgrade(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUseTechWithOrWithoutTarget(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUseTechWithOrWithoutTarget(BWAPI::TechType tech, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUseTech(BWAPI::TechType tech, PositionOrUnit target = nullptr, bool checkCanTargetUnit = true, bool checkTargetsType = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUseTechWithoutTarget(BWAPI::TechType tech, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUseTechUnit(BWAPI::TechType tech, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUseTechUnit(BWAPI::TechType tech, Unit targetUnit, bool checkCanTargetUnit = true, bool checkTargetsUnits = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUseTechPosition(BWAPI::TechType tech, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canUseTechPosition(BWAPI::TechType tech, Position target, bool checkTargetsPositions = true, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canPlaceCOP(bool checkCommandibility = true) const override
			{
				return false;
			}
			virtual bool canPlaceCOP(TilePosition target, bool checkCanIssueCommandType = true, bool checkCommandibility = true) const override
			{
				return false;
			}
		};

		inline void bindMockUnitImpl(sol::table module)
		{
			module.new_usertype<MockUnitImpl>("MockUnit", sol::default_constructor, sol::base_classes, sol::bases<UnitInterface>());
		}
	}
}