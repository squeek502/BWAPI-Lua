.. currentmodule:: BWAPI

Filter
======

.. module:: BWAPI.Filter

Unary Filters
-------------

Unary filters are predicate functions that return boolean values.

These functions can be used as predicates for functions that take a unit predicate/filter parameter (e.g. :meth:`BWAPI.Unit.getClosestUnit`, :meth:`BWAPI.Game.getUnitsInRadius`). They can also be used as convenience functions to access values that may usually take multiple function calls to access.

.. seealso::
   :ref:`The differences between the C++ and Lua implementations of UnitFilter <differences-unitfilter>`

.. rubric:: UnitType delegate boolean filters

.. staticmethod:: IsTransport(unit) -> bool

   Equivalent to ``unit:getType():spaceProvided() > 0 and u:getType() ~= BWAPI.UnitTypes.Terran_Bunker``

.. staticmethod:: CanProduce(unit) -> bool

   Equivalent to ``unit:getType():canProduce()``

.. staticmethod:: CanAttack(unit) -> bool

   Equivalent to ``unit:getType():canAttack()``

.. staticmethod:: CanMove(unit) -> bool

   Equivalent to ``unit:getType():canMove()``

.. staticmethod:: IsFlyer(unit) -> bool

   Equivalent to ``unit:getType():isFlyer()``

.. staticmethod:: RegeneratesHP(unit) -> bool

   Equivalent to ``unit:getType():regeneratesHP()``

.. staticmethod:: IsSpellcaster(unit) -> bool

   Equivalent to ``unit:getType():isSpellcaster()``

.. staticmethod:: HasPermanentCloak(unit) -> bool

   Equivalent to ``unit:getType():hasPermanentCloak()``

.. staticmethod:: IsOrganic(unit) -> bool

   Equivalent to ``unit:getType():isOrganic()``

.. staticmethod:: IsMechanical(unit) -> bool

   Equivalent to ``unit:getType():isMechanical()``

.. staticmethod:: IsRobotic(unit) -> bool

   Equivalent to ``unit:getType():isRobotic()``

.. staticmethod:: IsDetector(unit) -> bool

   Equivalent to ``unit:getType():isDetector()``

.. staticmethod:: IsResourceContainer(unit) -> bool

   Equivalent to ``unit:getType():isResourceContainer()``

.. staticmethod:: IsResourceDepot(unit) -> bool

   Equivalent to ``unit:getType():isResourceDepot()``

.. staticmethod:: IsRefinery(unit) -> bool

   Equivalent to ``unit:getType():isRefinery()``

.. staticmethod:: IsWorker(unit) -> bool

   Equivalent to ``unit:getType():isWorker()``

.. staticmethod:: RequiresPsi(unit) -> bool

   Equivalent to ``unit:getType():requiresPsi()``

.. staticmethod:: RequiresCreep(unit) -> bool

   Equivalent to ``unit:getType():requiresCreep()``

.. staticmethod:: IsBurrowable(unit) -> bool

   Equivalent to ``unit:getType():isBurrowable()``

.. staticmethod:: IsCloakable(unit) -> bool

   Equivalent to ``unit:getType():isCloakable()``

.. staticmethod:: IsBuilding(unit) -> bool

   Equivalent to ``unit:getType():isBuilding()``

.. staticmethod:: IsAddon(unit) -> bool

   Equivalent to ``unit:getType():isAddon()``

.. staticmethod:: IsFlyingBuilding(unit) -> bool

   Equivalent to ``unit:getType():isFlyingBuilding()``

.. staticmethod:: IsNeutral(unit) -> bool

   Equivalent to ``unit:getType():isNeutral()``

.. staticmethod:: IsHero(unit) -> bool

   Equivalent to ``unit:getType():isHero()``

.. staticmethod:: IsPowerup(unit) -> bool

   Equivalent to ``unit:getType():isPowerup()``

.. staticmethod:: IsBeacon(unit) -> bool

   Equivalent to ``unit:getType():isBeacon()``

.. staticmethod:: IsFlagBeacon(unit) -> bool

   Equivalent to ``unit:getType():isFlagBeacon()``

.. staticmethod:: IsSpecialBuilding(unit) -> bool

   Equivalent to ``unit:getType():isSpecialBuilding()``

.. staticmethod:: IsSpell(unit) -> bool

   Equivalent to ``unit:getType():isSpell()``

.. staticmethod:: ProducesLarva(unit) -> bool

   Equivalent to ``unit:getType():producesLarva()``

.. staticmethod:: IsMineralField(unit) -> bool

   Equivalent to ``unit:getType():isMineralField()``

.. staticmethod:: IsCritter(unit) -> bool

   Equivalent to ``unit:getType():isCritter()``

.. staticmethod:: CanBuildAddon(unit) -> bool

   Equivalent to ``unit:getType():canBuildAddon()``

.. rubric:: Unit boolean filters

.. staticmethod:: IsFlying(unit) -> bool

   Equivalent to ``unit:isFlying()``

.. staticmethod:: Exists(unit) -> bool

   Equivalent to ``unit:exists()``

.. staticmethod:: IsAttacking(unit) -> bool

   Equivalent to ``unit:isAttacking()``

.. staticmethod:: IsBeingConstructed(unit) -> bool

   Equivalent to ``unit:isBeingConstructed()``

.. staticmethod:: IsBeingGathered(unit) -> bool

   Equivalent to ``unit:isBeingGathered()``

.. staticmethod:: IsBeingHealed(unit) -> bool

   Equivalent to ``unit:isBeingHealed()``

.. staticmethod:: IsBlind(unit) -> bool

   Equivalent to ``unit:isBlind()``

.. staticmethod:: IsBraking(unit) -> bool

   Equivalent to ``unit:isBraking()``

.. staticmethod:: IsBurrowed(unit) -> bool

   Equivalent to ``unit:isBurrowed()``

.. staticmethod:: IsCarryingGas(unit) -> bool

   Equivalent to ``unit:isCarryingGas()``

.. staticmethod:: IsCarryingMinerals(unit) -> bool

   Equivalent to ``unit:isCarryingMinerals()``

.. staticmethod:: IsCarryingSomething(unit) -> bool

   Equivalent to ``unit:isCarryingMinerals() or unit:isCarryingGas()``

.. staticmethod:: IsCloaked(unit) -> bool

   Equivalent to ``unit:isCloaked()``

.. staticmethod:: IsCompleted(unit) -> bool

   Equivalent to ``unit:isCompleted()``

.. staticmethod:: IsConstructing(unit) -> bool

   Equivalent to ``unit:isConstructing()``

.. staticmethod:: IsDefenseMatrixed(unit) -> bool

   Equivalent to ``unit:isDefenseMatrixed()``

.. staticmethod:: IsDetected(unit) -> bool

   Equivalent to ``unit:isDetected()``

.. staticmethod:: IsEnsnared(unit) -> bool

   Equivalent to ``unit:isEnsnared()``

.. staticmethod:: IsFollowing(unit) -> bool

   Equivalent to ``unit:isFollowing()``

.. staticmethod:: IsGatheringGas(unit) -> bool

   Equivalent to ``unit:isGatheringGas()``

.. staticmethod:: IsGatheringMinerals(unit) -> bool

   Equivalent to ``unit:isGatheringMinerals()``

.. staticmethod:: IsHallucination(unit) -> bool

   Equivalent to ``unit:isHallucination()``

.. staticmethod:: IsHoldingPosition(unit) -> bool

   Equivalent to ``unit:isHoldingPosition()``

.. staticmethod:: IsIdle(unit) -> bool

   Equivalent to ``unit:isIdle()``

.. staticmethod:: IsInterruptible(unit) -> bool

   Equivalent to ``unit:isInterruptible()``

.. staticmethod:: IsInvincible(unit) -> bool

   Equivalent to ``unit:isInvincible()``

.. staticmethod:: IsIrradiated(unit) -> bool

   Equivalent to ``unit:isIrradiated()``

.. staticmethod:: IsLifted(unit) -> bool

   Equivalent to ``unit:isLifted()``

.. staticmethod:: IsLoaded(unit) -> bool

   Equivalent to ``unit:isLoaded()``

.. staticmethod:: IsLockedDown(unit) -> bool

   Equivalent to ``unit:isLockedDown()``

.. staticmethod:: IsMaelstrommed(unit) -> bool

   Equivalent to ``unit:isMaelstrommed()``

.. staticmethod:: IsMorphing(unit) -> bool

   Equivalent to ``unit:isMorphing()``

.. staticmethod:: IsMoving(unit) -> bool

   Equivalent to ``unit:isMoving()``

.. staticmethod:: IsParasited(unit) -> bool

   Equivalent to ``unit:isParasited()``

.. staticmethod:: IsPatrolling(unit) -> bool

   Equivalent to ``unit:isPatrolling()``

.. staticmethod:: IsPlagued(unit) -> bool

   Equivalent to ``unit:isPlagued()``

.. staticmethod:: IsRepairing(unit) -> bool

   Equivalent to ``unit:isRepairing()``

.. staticmethod:: IsResearching(unit) -> bool

   Equivalent to ``unit:isResearching()``

.. staticmethod:: IsSieged(unit) -> bool

   Equivalent to ``unit:isSieged()``

.. staticmethod:: IsStartingAttack(unit) -> bool

   Equivalent to ``unit:isStartingAttack()``

.. staticmethod:: IsStasised(unit) -> bool

   Equivalent to ``unit:isStasised()``

.. staticmethod:: IsStimmed(unit) -> bool

   Equivalent to ``unit:isStimmed()``

.. staticmethod:: IsStuck(unit) -> bool

   Equivalent to ``unit:isStuck()``

.. staticmethod:: IsTraining(unit) -> bool

   Equivalent to ``unit:isTraining()``

.. staticmethod:: IsUnderAttack(unit) -> bool

   Equivalent to ``unit:isUnderAttack()``

.. staticmethod:: IsUnderDarkSwarm(unit) -> bool

   Equivalent to ``unit:isUnderDarkSwarm()``

.. staticmethod:: IsUnderDisruptionWeb(unit) -> bool

   Equivalent to ``unit:isUnderDisruptionWeb()``

.. staticmethod:: IsUnderStorm(unit) -> bool

   Equivalent to ``unit:isUnderStorm()``

.. staticmethod:: IsPowered(unit) -> bool

   Equivalent to ``unit:isPowered()``

.. staticmethod:: IsVisible(unit) -> bool

   Equivalent to ``unit:isVisible()``

Comparison Filters
------------------

Comparison filters are functions that return a value.

These can either be used as convenience functions to access values that usually take multiple function calls to get, or can be used with :meth:`BWAPI.Lowest`/:meth:`BWAPI.Highest` to create a 'best' function to be used with :meth:`BWAPI.Game.getBestUnit` (as long as the returned value from the comparison filter can be compared using less than/greater than).

.. seealso::
   :ref:`The differences between the C++ and Lua implementations of BestFilter <differences-bestfilter>`

.. staticmethod:: HP(unit) -> int

   Equivalent to ``unit:getHitPoints()``

.. staticmethod:: MaxHP(unit) -> int

   Equivalent to ``unit:getType():maxHitPoints()``

.. staticmethod:: HP_Percent(unit) -> int

   Equivalent to ``math.floor(unit:getHitPoints() / unit:getType():maxHitPoints() * 100)`` if ``unit:getType():maxHitPoints() ~= 0``, or ``0`` otherwise.

.. staticmethod:: Shields(unit) -> int

   Equivalent to ``unit:getShields()``

.. staticmethod:: MaxShields(unit) -> int

   Equivalent to ``unit:getType():maxShields()``

.. staticmethod:: Shields_Percent(unit) -> int

   Equivalent to ``math.floor(unit:getShields() / unit:getType():maxShields() * 100)`` if ``unit:getType():maxShields() ~= 0``, or ``0`` otherwise.

.. staticmethod:: Energy(unit) -> int

   Equivalent to ``unit:getEnergy()``

.. staticmethod:: MaxEnergy(unit) -> int

   Equivalent to ``unit:getPlayer():maxEnergy(unit:getType())``

.. staticmethod:: Energy_Percent(unit) -> int

   Equivalent to ``math.floor(unit:getEnergy() / unit:getPlayer():maxEnergy(unit:getType()) * 100)`` if ``unit:getPlayer():maxEnergy(unit:getType()) ~= 0``, or ``0`` otherwise.

.. staticmethod:: Armor(unit) -> int

   Equivalent to ``unit:getPlayer():armor(unit:getType())``

.. staticmethod:: ArmorUpgrade(unit) -> UpgradeType

   Equivalent to ``unit:getType():armorUpgrade()``

.. staticmethod:: MineralPrice(unit) -> int

   Equivalent to ``unit:getType():mineralPrice()``

.. staticmethod:: GasPrice(unit) -> int

   Equivalent to ``unit:getType():gasPrice()``

.. staticmethod:: BuildTime(unit) -> int

   Equivalent to ``unit:getType():buildTime()``

.. staticmethod:: SupplyRequired(unit) -> int

   Equivalent to ``unit:getType():supplyRequired()``

.. staticmethod:: SupplyProvided(unit) -> int

   Equivalent to ``unit:getType():supplyProvided()``

.. staticmethod:: SpaceRequired(unit) -> int

   Equivalent to ``unit:getType():spaceRequired()``

.. staticmethod:: SpaceRemaining(unit) -> int

   Equivalent to ``unit:spaceRemaining()``

.. staticmethod:: SpaceProvided(unit) -> int

   Equivalent to ``unit:getType():spaceProvided()``

.. staticmethod:: BuildScore(unit) -> int

   Equivalent to ``unit:getType():buildScore()``

.. staticmethod:: DestroyScore(unit) -> int

   Equivalent to ``unit:getType():destroyScore()``

.. staticmethod:: TopSpeed(unit) -> double

   Equivalent to ``unit:getPlayer():topSpeed(unit:getType())``

.. staticmethod:: SightRange(unit) -> int

   Equivalent to ``unit:getPlayer():sightRange(unit:getType())``

.. staticmethod:: MaxWeaponCooldown(unit) -> int

   Equivalent to ``unit:getPlayer():weaponDamageCooldown(unit:getType())``

.. staticmethod:: SizeType(unit) -> UnitSizeType

   Equivalent to ``unit:getType():size()``

.. staticmethod:: GroundWeapon(unit) -> WeaponType

   Equivalent to ``unit:getType():groundWeapon()``

.. staticmethod:: AirWeapon(unit) -> WeaponType

   Equivalent to ``unit:getType():airWeapon()``

.. staticmethod:: GetType(unit) -> UnitType

   Equivalent to ``unit:getType()``

.. staticmethod:: GetRace(unit) -> Race

   Equivalent to ``unit:getType():getRace()``

.. staticmethod:: GetPlayer(unit) -> Player

   Equivalent to ``unit:getPlayer()``

.. staticmethod:: Resources(unit) -> int

   Equivalent to ``unit:getResources()``

.. staticmethod:: ResourceGroup(unit) -> int

   Equivalent to ``unit:getResourceGroup()``

.. staticmethod:: AcidSporeCount(unit) -> int

   Equivalent to ``unit:getAcidSporeCount()``

.. staticmethod:: InterceptorCount(unit) -> int

   Equivalent to ``unit:getInterceptorCount()``

.. staticmethod:: ScarabCount(unit) -> int

   Equivalent to ``unit:getScarabCount()``

.. staticmethod:: SpiderMineCount(unit) -> int

   Equivalent to ``unit:getSpiderMineCount()``

.. staticmethod:: WeaponCooldown(unit) -> int

   Equivalent to ``unit:getGroundWeaponCooldown()``

.. staticmethod:: SpellCooldown(unit) -> int

   Equivalent to ``unit:getSpellCooldown()``

.. staticmethod:: DefenseMatrixPoints(unit) -> int

   Equivalent to ``unit:getDefenseMatrixPoints()``

.. staticmethod:: DefenseMatrixTime(unit) -> int

   Equivalent to ``unit:getDefenseMatrixTimer()``

.. staticmethod:: EnsnareTime(unit) -> int

   Equivalent to ``unit:getEnsnareTimer()``

.. staticmethod:: IrradiateTime(unit) -> int

   Equivalent to ``unit:getIrradiateTimer()``

.. staticmethod:: LockdownTime(unit) -> int

   Equivalent to ``unit:getLockdownTimer()``

.. staticmethod:: MaelstromTime(unit) -> int

   Equivalent to ``unit:getMaelstromTimer()``

.. staticmethod:: OrderTime(unit) -> int

   Equivalent to ``unit:getOrderTimer()``

.. staticmethod:: PlagueTimer(unit) -> int

   Equivalent to ``unit:getPlagueTimer()``

.. staticmethod:: RemoveTime(unit) -> int

   Equivalent to ``unit:getRemoveTimer()``

.. staticmethod:: StasisTime(unit) -> int

   Equivalent to ``unit:getStasisTimer()``

.. staticmethod:: StimTime(unit) -> int

   Equivalent to ``unit:getStimTimer()``

.. staticmethod:: BuildType(unit) -> UnitType

   Equivalent to ``unit:getBuildType()``

.. staticmethod:: RemainingBuildTime(unit) -> int

   Equivalent to ``unit:getRemainingBuildTime()``

.. staticmethod:: RemainingTrainTime(unit) -> int

   Equivalent to ``unit:getRemainingTrainTime()``

.. staticmethod:: Target(unit) -> Unit

   Equivalent to ``unit:getTarget()``

.. staticmethod:: CurrentOrder(unit) -> Order

   Equivalent to ``unit:getOrder()``

.. staticmethod:: SecondaryOrder(unit) -> Order

   Equivalent to ``unit:getSecondaryOrder()``

.. staticmethod:: OrderTarget(unit) -> Unit

   Equivalent to ``unit:getOrderTarget()``

.. staticmethod:: GetLeft(unit) -> int

   Equivalent to ``unit:getLeft()``

.. staticmethod:: GetTop(unit) -> int

   Equivalent to ``unit:getTop()``

.. staticmethod:: GetRight(unit) -> int

   Equivalent to ``unit:getRight()``

.. staticmethod:: GetBottom(unit) -> int

   Equivalent to ``unit:getBottom()``
