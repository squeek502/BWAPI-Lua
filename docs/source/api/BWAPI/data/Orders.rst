.. currentmodule:: BWAPI

Orders
======

.. module:: BWAPI.Orders

Module containing unit orders.

.. seealso::
   :class:`BWAPI.Order`

Functions
---------

.. staticmethod:: allOrders() -> set

   Retrieves a set of all Orders.

   :return: Set of all Orders.
   :rtype: :class:`~BWAPI.Orderset`

Constants
---------

All constants are instances of the :class:`~BWAPI.Order` class

.. data:: Die
.. data:: Stop
.. data:: Guard
.. data:: PlayerGuard
.. data:: TurretGuard
.. data:: BunkerGuard
.. data:: Move
.. data:: AttackUnit
.. data:: AttackTile
.. data:: Hover
.. data:: AttackMove
.. data:: InfestedCommandCenter
.. data:: UnusedNothing
.. data:: UnusedPowerup
.. data:: TowerGuard
.. data:: VultureMine
.. data:: Nothing
.. data:: CastInfestation
.. data:: InfestingCommandCenter
.. data:: PlaceBuilding
.. data:: CreateProtossBuilding
.. data:: ConstructingBuilding
.. data:: Repair
.. data:: PlaceAddon
.. data:: BuildAddon
.. data:: Train
.. data:: RallyPointUnit
.. data:: RallyPointTile
.. data:: ZergBirth
.. data:: ZergUnitMorph
.. data:: ZergBuildingMorph
.. data:: IncompleteBuilding
.. data:: BuildNydusExit
.. data:: EnterNydusCanal
.. data:: Follow
.. data:: Carrier
.. data:: ReaverCarrierMove
.. data:: CarrierIgnore2
.. data:: Reaver
.. data:: TrainFighter
.. data:: InterceptorAttack
.. data:: ScarabAttack
.. data:: RechargeShieldsUnit
.. data:: RechargeShieldsBattery
.. data:: ShieldBattery
.. data:: InterceptorReturn
.. data:: BuildingLand
.. data:: BuildingLiftOff
.. data:: DroneLiftOff
.. data:: LiftingOff
.. data:: ResearchTech
.. data:: Upgrade
.. data:: Larva
.. data:: SpawningLarva
.. data:: Harvest1
.. data:: Harvest2
.. data:: MoveToGas
.. data:: WaitForGas
.. data:: HarvestGas
.. data:: ReturnGas
.. data:: MoveToMinerals
.. data:: WaitForMinerals
.. data:: MiningMinerals
.. data:: Harvest3
.. data:: Harvest4
.. data:: ReturnMinerals
.. data:: Interrupted
.. data:: EnterTransport
.. data:: PickupIdle
.. data:: PickupTransport
.. data:: PickupBunker
.. data:: Pickup4
.. data:: PowerupIdle
.. data:: Sieging
.. data:: Unsieging
.. data:: InitCreepGrowth
.. data:: SpreadCreep
.. data:: StoppingCreepGrowth
.. data:: GuardianAspect
.. data:: ArchonWarp
.. data:: CompletingArchonSummon
.. data:: HoldPosition
.. data:: Cloak
.. data:: Decloak
.. data:: Unload
.. data:: MoveUnload
.. data:: FireYamatoGun
.. data:: CastLockdown
.. data:: Burrowing
.. data:: Burrowed
.. data:: Unburrowing
.. data:: CastDarkSwarm
.. data:: CastParasite
.. data:: CastSpawnBroodlings
.. data:: CastEMPShockwave
.. data:: NukeWait
.. data:: NukeTrain
.. data:: NukeLaunch
.. data:: NukePaint
.. data:: NukeUnit
.. data:: CastNuclearStrike
.. data:: NukeTrack
.. data:: CloakNearbyUnits
.. data:: PlaceMine
.. data:: RightClickAction
.. data:: CastRecall
.. data:: Teleport
.. data:: CastScannerSweep
.. data:: Scanner
.. data:: CastDefensiveMatrix
.. data:: CastPsionicStorm
.. data:: CastIrradiate
.. data:: CastPlague
.. data:: CastConsume
.. data:: CastEnsnare
.. data:: CastStasisField
.. data:: CastHallucination
.. data:: Hallucination2
.. data:: ResetCollision
.. data:: Patrol
.. data:: CTFCOPInit
.. data:: CTFCOPStarted
.. data:: CTFCOP2
.. data:: ComputerAI
.. data:: AtkMoveEP
.. data:: HarassMove
.. data:: AIPatrol
.. data:: GuardPost
.. data:: RescuePassive
.. data:: Neutral
.. data:: ComputerReturn
.. data:: SelfDestructing
.. data:: Critter
.. data:: HiddenGun
.. data:: OpenDoor
.. data:: CloseDoor
.. data:: HideTrap
.. data:: RevealTrap
.. data:: EnableDoodad
.. data:: DisableDoodad
.. data:: WarpIn
.. data:: Medic
.. data:: MedicHeal
.. data:: HealMove
.. data:: MedicHealToIdle
.. data:: CastRestoration
.. data:: CastDisruptionWeb
.. data:: CastMindControl
.. data:: DarkArchonMeld
.. data:: CastFeedback
.. data:: CastOpticalFlare
.. data:: CastMaelstrom
.. data:: JunkYardDog
.. data:: Fatal
.. data:: None
.. data:: Unknown

Enum
----

.. module:: BWAPI.Orders.Enum

Enumeration of unit orders.

.. include:: /_include/api-enum.rst

.. data:: Die

   Value of 0.

.. data:: Stop

   Value of 1.

.. data:: Guard

   Value of 2.

.. data:: PlayerGuard

   Value of 3.

.. data:: TurretGuard

   Value of 4.

.. data:: BunkerGuard

   Value of 5.

.. data:: Move

   Value of 6.

.. data:: ReaverStop

   Value of 7.

.. data:: Attack1

   Value of 8.

.. data:: Attack2

   Value of 9.

.. data:: AttackUnit

   Value of 10.

.. data:: AttackFixedRange

   Value of 11.

.. data:: AttackTile

   Value of 12.

.. data:: Hover

   Value of 13.

.. data:: AttackMove

   Value of 14.

.. data:: InfestedCommandCenter

   Value of 15.

.. data:: UnusedNothing

   Value of 16.

.. data:: UnusedPowerup

   Value of 17.

.. data:: TowerGuard

   Value of 18.

.. data:: TowerAttack

   Value of 19.

.. data:: VultureMine

   Value of 20.

.. data:: StayInRange

   Value of 21.

.. data:: TurretAttack

   Value of 22.

.. data:: Nothing

   Value of 23.

.. data:: Unused_24

   Value of 24.

.. data:: DroneStartBuild

   Value of 25.

.. data:: DroneBuild

   Value of 26.

.. data:: CastInfestation

   Value of 27.

.. data:: MoveToInfest

   Value of 28.

.. data:: InfestingCommandCenter

   Value of 29.

.. data:: PlaceBuilding

   Value of 30.

.. data:: PlaceProtossBuilding

   Value of 31.

.. data:: CreateProtossBuilding

   Value of 32.

.. data:: ConstructingBuilding

   Value of 33.

.. data:: Repair

   Value of 34.

.. data:: MoveToRepair

   Value of 35.

.. data:: PlaceAddon

   Value of 36.

.. data:: BuildAddon

   Value of 37.

.. data:: Train

   Value of 38.

.. data:: RallyPointUnit

   Value of 39.

.. data:: RallyPointTile

   Value of 40.

.. data:: ZergBirth

   Value of 41.

.. data:: ZergUnitMorph

   Value of 42.

.. data:: ZergBuildingMorph

   Value of 43.

.. data:: IncompleteBuilding

   Value of 44.

.. data:: IncompleteMorphing

   Value of 45.

.. data:: BuildNydusExit

   Value of 46.

.. data:: EnterNydusCanal

   Value of 47.

.. data:: IncompleteWarping

   Value of 48.

.. data:: Follow

   Value of 49.

.. data:: Carrier

   Value of 50.

.. data:: ReaverCarrierMove

   Value of 51.

.. data:: CarrierStop

   Value of 52.

.. data:: CarrierAttack

   Value of 53.

.. data:: CarrierMoveToAttack

   Value of 54.

.. data:: CarrierIgnore2

   Value of 55.

.. data:: CarrierFight

   Value of 56.

.. data:: CarrierHoldPosition

   Value of 57.

.. data:: Reaver

   Value of 58.

.. data:: ReaverAttack

   Value of 59.

.. data:: ReaverMoveToAttack

   Value of 60.

.. data:: ReaverFight

   Value of 61.

.. data:: ReaverHoldPosition

   Value of 62.

.. data:: TrainFighter

   Value of 63.

.. data:: InterceptorAttack

   Value of 64.

.. data:: ScarabAttack

   Value of 65.

.. data:: RechargeShieldsUnit

   Value of 66.

.. data:: RechargeShieldsBattery

   Value of 67.

.. data:: ShieldBattery

   Value of 68.

.. data:: InterceptorReturn

   Value of 69.

.. data:: DroneLand

   Value of 70.

.. data:: BuildingLand

   Value of 71.

.. data:: BuildingLiftOff

   Value of 72.

.. data:: DroneLiftOff

   Value of 73.

.. data:: LiftingOff

   Value of 74.

.. data:: ResearchTech

   Value of 75.

.. data:: Upgrade

   Value of 76.

.. data:: Larva

   Value of 77.

.. data:: SpawningLarva

   Value of 78.

.. data:: Harvest1

   Value of 79.

.. data:: Harvest2

   Value of 80.

.. data:: MoveToGas

   Value of 81.

.. data:: WaitForGas

   Value of 82.

.. data:: HarvestGas

   Value of 83.

.. data:: ReturnGas

   Value of 84.

.. data:: MoveToMinerals

   Value of 85.

.. data:: WaitForMinerals

   Value of 86.

.. data:: MiningMinerals

   Value of 87.

.. data:: Harvest3

   Value of 88.

.. data:: Harvest4

   Value of 89.

.. data:: ReturnMinerals

   Value of 90.

.. data:: Interrupted

   Value of 91.

.. data:: EnterTransport

   Value of 92.

.. data:: PickupIdle

   Value of 93.

.. data:: PickupTransport

   Value of 94.

.. data:: PickupBunker

   Value of 95.

.. data:: Pickup4

   Value of 96.

.. data:: PowerupIdle

   Value of 97.

.. data:: Sieging

   Value of 98.

.. data:: Unsieging

   Value of 99.

.. data:: WatchTarget

   Value of 100.

.. data:: InitCreepGrowth

   Value of 101.

.. data:: SpreadCreep

   Value of 102.

.. data:: StoppingCreepGrowth

   Value of 103.

.. data:: GuardianAspect

   Value of 104.

.. data:: ArchonWarp

   Value of 105.

.. data:: CompletingArchonSummon

   Value of 106.

.. data:: HoldPosition

   Value of 107.

.. data:: QueenHoldPosition

   Value of 108.

.. data:: Cloak

   Value of 109.

.. data:: Decloak

   Value of 110.

.. data:: Unload

   Value of 111.

.. data:: MoveUnload

   Value of 112.

.. data:: FireYamatoGun

   Value of 113.

.. data:: MoveToFireYamatoGun

   Value of 114.

.. data:: CastLockdown

   Value of 115.

.. data:: Burrowing

   Value of 116.

.. data:: Burrowed

   Value of 117.

.. data:: Unburrowing

   Value of 118.

.. data:: CastDarkSwarm

   Value of 119.

.. data:: CastParasite

   Value of 120.

.. data:: CastSpawnBroodlings

   Value of 121.

.. data:: CastEMPShockwave

   Value of 122.

.. data:: NukeWait

   Value of 123.

.. data:: NukeTrain

   Value of 124.

.. data:: NukeLaunch

   Value of 125.

.. data:: NukePaint

   Value of 126.

.. data:: NukeUnit

   Value of 127.

.. data:: CastNuclearStrike

   Value of 128.

.. data:: NukeTrack

   Value of 129.

.. data:: InitializeArbiter

   Value of 130.

.. data:: CloakNearbyUnits

   Value of 131.

.. data:: PlaceMine

   Value of 132.

.. data:: RightClickAction

   Value of 133.

.. data:: SuicideUnit

   Value of 134.

.. data:: SuicideLocation

   Value of 135.

.. data:: SuicideHoldPosition

   Value of 136.

.. data:: CastRecall

   Value of 137.

.. data:: Teleport

   Value of 138.

.. data:: CastScannerSweep

   Value of 139.

.. data:: Scanner

   Value of 140.

.. data:: CastDefensiveMatrix

   Value of 141.

.. data:: CastPsionicStorm

   Value of 142.

.. data:: CastIrradiate

   Value of 143.

.. data:: CastPlague

   Value of 144.

.. data:: CastConsume

   Value of 145.

.. data:: CastEnsnare

   Value of 146.

.. data:: CastStasisField

   Value of 147.

.. data:: CastHallucination

   Value of 148.

.. data:: Hallucination2

   Value of 149.

.. data:: ResetCollision

   Value of 150.

.. data:: ResetHarvestCollision

   Value of 151.

.. data:: Patrol

   Value of 152.

.. data:: CTFCOPInit

   Value of 153.

.. data:: CTFCOPStarted

   Value of 154.

.. data:: CTFCOP2

   Value of 155.

.. data:: ComputerAI

   Value of 156.

.. data:: AtkMoveEP

   Value of 157.

.. data:: HarassMove

   Value of 158.

.. data:: AIPatrol

   Value of 159.

.. data:: GuardPost

   Value of 160.

.. data:: RescuePassive

   Value of 161.

.. data:: Neutral

   Value of 162.

.. data:: ComputerReturn

   Value of 163.

.. data:: InitializePsiProvider

   Value of 164.

.. data:: SelfDestructing

   Value of 165.

.. data:: Critter

   Value of 166.

.. data:: HiddenGun

   Value of 167.

.. data:: OpenDoor

   Value of 168.

.. data:: CloseDoor

   Value of 169.

.. data:: HideTrap

   Value of 170.

.. data:: RevealTrap

   Value of 171.

.. data:: EnableDoodad

   Value of 172.

.. data:: DisableDoodad

   Value of 173.

.. data:: WarpIn

   Value of 174.

.. data:: Medic

   Value of 175.

.. data:: MedicHeal

   Value of 176.

.. data:: HealMove

   Value of 177.

.. data:: MedicHoldPosition

   Value of 178.

.. data:: MedicHealToIdle

   Value of 179.

.. data:: CastRestoration

   Value of 180.

.. data:: CastDisruptionWeb

   Value of 181.

.. data:: CastMindControl

   Value of 182.

.. data:: DarkArchonMeld

   Value of 183.

.. data:: CastFeedback

   Value of 184.

.. data:: CastOpticalFlare

   Value of 185.

.. data:: CastMaelstrom

   Value of 186.

.. data:: JunkYardDog

   Value of 187.

.. data:: Fatal

   Value of 188.

.. data:: None

   Value of 189.

.. data:: Unknown

   Value of 190.

.. data:: MAX

   Value of 191.
