.. currentmodule:: BWAPI

UnitTypes
=========

.. module:: BWAPI.UnitTypes

Module containing unit types.

.. seealso::
   :class:`BWAPI.UnitType`

Functions
---------

.. staticmethod:: allUnitTypes() -> set

   Retrieves a set of all UnitTypes.

   :return: Set of all UnitTypes.
   :rtype: :class:`~BWAPI.UnitTypeset`

.. staticmethod:: allMacroTypes() -> set

   Retrieves the set of all macro unit types.

   A macro type is a fake unit type, used by some functions. These include :attr:`AllUnits`, :attr:`Men`, :attr:`Buildings`, and :attr:`Factories`. The purpose of these types are to match the same ones used in Broodwar, also seen in the StarEdit map editor.

   :return: Set of all macro UnitTypes.
   :rtype: :class:`~BWAPI.UnitTypeset`

Constants
---------

All constants are instances of the :class:`~BWAPI.UnitType` class

.. rubric:: Terran Ground Units

.. data:: Terran_Firebat
.. data:: Terran_Ghost
.. data:: Terran_Goliath
.. data:: Terran_Marine
.. data:: Terran_Medic
.. data:: Terran_SCV
.. data:: Terran_Siege_Tank_Siege_Mode
.. data:: Terran_Siege_Tank_Tank_Mode
.. data:: Terran_Vulture
.. data:: Terran_Vulture_Spider_Mine

.. rubric:: Terran Air Units

.. data:: Terran_Battlecruiser
.. data:: Terran_Dropship
.. data:: Terran_Nuclear_Missile
.. data:: Terran_Science_Vessel
.. data:: Terran_Valkyrie
.. data:: Terran_Wraith

.. rubric:: Terran Heroes

.. data:: Hero_Alan_Schezar
.. data:: Hero_Alexei_Stukov
.. data:: Hero_Arcturus_Mengsk
.. data:: Hero_Edmund_Duke_Tank_Mode
.. data:: Hero_Edmund_Duke_Siege_Mode
.. data:: Hero_Gerard_DuGalle
.. data:: Hero_Gui_Montag
.. data:: Hero_Hyperion
.. data:: Hero_Jim_Raynor_Marine
.. data:: Hero_Jim_Raynor_Vulture
.. data:: Hero_Magellan
.. data:: Hero_Norad_II
.. data:: Hero_Samir_Duran
.. data:: Hero_Sarah_Kerrigan
.. data:: Hero_Tom_Kazansky
.. data:: Terran_Civilian

.. rubric:: Terran Buildings

.. data:: Terran_Academy
.. data:: Terran_Armory
.. data:: Terran_Barracks
.. data:: Terran_Bunker
.. data:: Terran_Command_Center
.. data:: Terran_Engineering_Bay
.. data:: Terran_Factory
.. data:: Terran_Missile_Turret
.. data:: Terran_Refinery
.. data:: Terran_Science_Facility
.. data:: Terran_Starport
.. data:: Terran_Supply_Depot

.. rubric:: Terran Addons

.. data:: Terran_Comsat_Station
.. data:: Terran_Control_Tower
.. data:: Terran_Covert_Ops
.. data:: Terran_Machine_Shop
.. data:: Terran_Nuclear_Silo
.. data:: Terran_Physics_Lab

.. rubric:: Terran Special Buildings

.. data:: Special_Crashed_Norad_II
.. data:: Special_Ion_Cannon
.. data:: Special_Power_Generator
.. data:: Special_Psi_Disrupter

.. rubric:: Protoss Ground Units

.. data:: Protoss_Archon
.. data:: Protoss_Dark_Archon
.. data:: Protoss_Dark_Templar
.. data:: Protoss_Dragoon
.. data:: Protoss_High_Templar
.. data:: Protoss_Probe
.. data:: Protoss_Reaver
.. data:: Protoss_Scarab
.. data:: Protoss_Zealot

.. rubric:: Protoss Air Units

.. data:: Protoss_Arbiter
.. data:: Protoss_Carrier
.. data:: Protoss_Corsair
.. data:: Protoss_Interceptor
.. data:: Protoss_Observer
.. data:: Protoss_Scout
.. data:: Protoss_Shuttle

.. rubric:: Protoss Heroes

.. data:: Hero_Aldaris
.. data:: Hero_Artanis
.. data:: Hero_Danimoth
.. data:: Hero_Dark_Templar
.. data:: Hero_Fenix_Dragoon
.. data:: Hero_Fenix_Zealot
.. data:: Hero_Gantrithor
.. data:: Hero_Mojo
.. data:: Hero_Raszagal
.. data:: Hero_Tassadar
.. data:: Hero_Tassadar_Zeratul_Archon
.. data:: Hero_Warbringer
.. data:: Hero_Zeratul

.. rubric:: Protoss Buildings

.. data:: Protoss_Arbiter_Tribunal
.. data:: Protoss_Assimilator
.. data:: Protoss_Citadel_of_Adun
.. data:: Protoss_Cybernetics_Core
.. data:: Protoss_Fleet_Beacon
.. data:: Protoss_Forge
.. data:: Protoss_Gateway
.. data:: Protoss_Nexus
.. data:: Protoss_Observatory
.. data:: Protoss_Photon_Cannon
.. data:: Protoss_Pylon
.. data:: Protoss_Robotics_Facility
.. data:: Protoss_Robotics_Support_Bay
.. data:: Protoss_Shield_Battery
.. data:: Protoss_Stargate
.. data:: Protoss_Templar_Archives

.. rubric:: Protoss Special Buildings

.. data:: Special_Khaydarin_Crystal_Form
.. data:: Special_Protoss_Temple
.. data:: Special_Stasis_Cell_Prison
.. data:: Special_Warp_Gate
.. data:: Special_XelNaga_Temple

.. rubric:: Zerg Ground Units

.. data:: Zerg_Broodling
.. data:: Zerg_Defiler
.. data:: Zerg_Drone
.. data:: Zerg_Egg
.. data:: Zerg_Hydralisk
.. data:: Zerg_Infested_Terran
.. data:: Zerg_Larva
.. data:: Zerg_Lurker
.. data:: Zerg_Lurker_Egg
.. data:: Zerg_Ultralisk
.. data:: Zerg_Zergling

.. rubric:: Zerg Air Units

.. data:: Zerg_Cocoon
.. data:: Zerg_Devourer
.. data:: Zerg_Guardian
.. data:: Zerg_Mutalisk
.. data:: Zerg_Overlord
.. data:: Zerg_Queen
.. data:: Zerg_Scourge

.. rubric:: Zerg Heroes

.. data:: Hero_Devouring_One
.. data:: Hero_Hunter_Killer
.. data:: Hero_Infested_Duran
.. data:: Hero_Infested_Kerrigan
.. data:: Hero_Kukulza_Guardian
.. data:: Hero_Kukulza_Mutalisk
.. data:: Hero_Matriarch
.. data:: Hero_Torrasque
.. data:: Hero_Unclean_One
.. data:: Hero_Yggdrasill

.. rubric:: Zerg Buildings

.. data:: Zerg_Creep_Colony
.. data:: Zerg_Defiler_Mound
.. data:: Zerg_Evolution_Chamber
.. data:: Zerg_Extractor
.. data:: Zerg_Greater_Spire
.. data:: Zerg_Hatchery
.. data:: Zerg_Hive
.. data:: Zerg_Hydralisk_Den
.. data:: Zerg_Infested_Command_Center
.. data:: Zerg_Lair
.. data:: Zerg_Nydus_Canal
.. data:: Zerg_Queens_Nest
.. data:: Zerg_Spawning_Pool
.. data:: Zerg_Spire
.. data:: Zerg_Spore_Colony
.. data:: Zerg_Sunken_Colony
.. data:: Zerg_Ultralisk_Cavern

.. rubric:: Zerg Special Buildings

.. data:: Special_Cerebrate
.. data:: Special_Cerebrate_Daggoth
.. data:: Special_Mature_Chrysalis
.. data:: Special_Overmind
.. data:: Special_Overmind_Cocoon
.. data:: Special_Overmind_With_Shell

.. rubric:: Critters

.. data:: Critter_Bengalaas
.. data:: Critter_Kakaru
.. data:: Critter_Ragnasaur
.. data:: Critter_Rhynadon
.. data:: Critter_Scantid
.. data:: Critter_Ursadon

.. rubric:: Resources

.. data:: Resource_Mineral_Field
.. data:: Resource_Mineral_Field_Type_2
.. data:: Resource_Mineral_Field_Type_3
.. data:: Resource_Vespene_Geyser

.. rubric:: Spells

.. data:: Spell_Dark_Swarm
.. data:: Spell_Disruption_Web
.. data:: Spell_Scanner_Sweep

.. rubric:: Beacons

.. data:: Special_Protoss_Beacon
.. data:: Special_Protoss_Flag_Beacon
.. data:: Special_Terran_Beacon
.. data:: Special_Terran_Flag_Beacon
.. data:: Special_Zerg_Beacon
.. data:: Special_Zerg_Flag_Beacon

.. rubric:: Powerups

.. data:: Powerup_Data_Disk
.. data:: Powerup_Flag
.. data:: Powerup_Khalis_Crystal
.. data:: Powerup_Khaydarin_Crystal
.. data:: Powerup_Mineral_Cluster_Type_1
.. data:: Powerup_Mineral_Cluster_Type_2
.. data:: Powerup_Protoss_Gas_Orb_Type_1
.. data:: Powerup_Protoss_Gas_Orb_Type_2
.. data:: Powerup_Psi_Emitter
.. data:: Powerup_Terran_Gas_Tank_Type_1
.. data:: Powerup_Terran_Gas_Tank_Type_2
.. data:: Powerup_Uraj_Crystal
.. data:: Powerup_Young_Chrysalis
.. data:: Powerup_Zerg_Gas_Sac_Type_1
.. data:: Powerup_Zerg_Gas_Sac_Type_2

.. rubric:: Traps

.. data:: Special_Floor_Gun_Trap
.. data:: Special_Floor_Missile_Trap
.. data:: Special_Right_Wall_Flame_Trap
.. data:: Special_Right_Wall_Missile_Trap
.. data:: Special_Wall_Flame_Trap
.. data:: Special_Wall_Missile_Trap

.. rubric:: Doors

.. data:: Special_Pit_Door
.. data:: Special_Right_Pit_Door
.. data:: Special_Right_Upper_Level_Door
.. data:: Special_Upper_Level_Door

.. rubric:: Special

.. data:: Special_Cargo_Ship
.. data:: Special_Floor_Hatch
.. data:: Special_Independant_Starport
.. data:: Special_Map_Revealer
.. data:: Special_Mercenary_Gunship
.. data:: Special_Start_Location

.. rubric:: Macros

.. data:: None
.. data:: AllUnits
.. data:: Men
.. data:: Buildings
.. data:: Factories
.. data:: Unknown


Enum
----

.. module:: BWAPI.UnitTypes.Enum

Enumeration of unit types.

.. include:: /_include/api-enum.rst

.. data:: Terran_Marine

   Value of 0.

.. data:: Terran_Ghost

   Value of 1.

.. data:: Terran_Vulture

   Value of 2.

.. data:: Terran_Goliath

   Value of 3.

.. data:: Terran_Goliath_Turret

   Value of 4.

.. data:: Terran_Siege_Tank_Tank_Mode

   Value of 5.

.. data:: Terran_Siege_Tank_Tank_Mode_Turret

   Value of 6.

.. data:: Terran_SCV

   Value of 7.

.. data:: Terran_Wraith

   Value of 8.

.. data:: Terran_Science_Vessel

   Value of 9.

.. data:: Hero_Gui_Montag

   Value of 10.

.. data:: Terran_Dropship

   Value of 11.

.. data:: Terran_Battlecruiser

   Value of 12.

.. data:: Terran_Vulture_Spider_Mine

   Value of 13.

.. data:: Terran_Nuclear_Missile

   Value of 14.

.. data:: Terran_Civilian

   Value of 15.

.. data:: Hero_Sarah_Kerrigan

   Value of 16.

.. data:: Hero_Alan_Schezar

   Value of 17.

.. data:: Hero_Alan_Schezar_Turret

   Value of 18.

.. data:: Hero_Jim_Raynor_Vulture

   Value of 19.

.. data:: Hero_Jim_Raynor_Marine

   Value of 20.

.. data:: Hero_Tom_Kazansky

   Value of 21.

.. data:: Hero_Magellan

   Value of 22.

.. data:: Hero_Edmund_Duke_Tank_Mode

   Value of 23.

.. data:: Hero_Edmund_Duke_Tank_Mode_Turret

   Value of 24.

.. data:: Hero_Edmund_Duke_Siege_Mode

   Value of 25.

.. data:: Hero_Edmund_Duke_Siege_Mode_Turret

   Value of 26.

.. data:: Hero_Arcturus_Mengsk

   Value of 27.

.. data:: Hero_Hyperion

   Value of 28.

.. data:: Hero_Norad_II

   Value of 29.

.. data:: Terran_Siege_Tank_Siege_Mode

   Value of 30.

.. data:: Terran_Siege_Tank_Siege_Mode_Turret

   Value of 31.

.. data:: Terran_Firebat

   Value of 32.

.. data:: Spell_Scanner_Sweep

   Value of 33.

.. data:: Terran_Medic

   Value of 34.

.. data:: Zerg_Larva

   Value of 35.

.. data:: Zerg_Egg

   Value of 36.

.. data:: Zerg_Zergling

   Value of 37.

.. data:: Zerg_Hydralisk

   Value of 38.

.. data:: Zerg_Ultralisk

   Value of 39.

.. data:: Zerg_Broodling

   Value of 40.

.. data:: Zerg_Drone

   Value of 41.

.. data:: Zerg_Overlord

   Value of 42.

.. data:: Zerg_Mutalisk

   Value of 43.

.. data:: Zerg_Guardian

   Value of 44.

.. data:: Zerg_Queen

   Value of 45.

.. data:: Zerg_Defiler

   Value of 46.

.. data:: Zerg_Scourge

   Value of 47.

.. data:: Hero_Torrasque

   Value of 48.

.. data:: Hero_Matriarch

   Value of 49.

.. data:: Zerg_Infested_Terran

   Value of 50.

.. data:: Hero_Infested_Kerrigan

   Value of 51.

.. data:: Hero_Unclean_One

   Value of 52.

.. data:: Hero_Hunter_Killer

   Value of 53.

.. data:: Hero_Devouring_One

   Value of 54.

.. data:: Hero_Kukulza_Mutalisk

   Value of 55.

.. data:: Hero_Kukulza_Guardian

   Value of 56.

.. data:: Hero_Yggdrasill

   Value of 57.

.. data:: Terran_Valkyrie

   Value of 58.

.. data:: Zerg_Cocoon

   Value of 59.

.. data:: Protoss_Corsair

   Value of 60.

.. data:: Protoss_Dark_Templar

   Value of 61.

.. data:: Zerg_Devourer

   Value of 62.

.. data:: Protoss_Dark_Archon

   Value of 63.

.. data:: Protoss_Probe

   Value of 64.

.. data:: Protoss_Zealot

   Value of 65.

.. data:: Protoss_Dragoon

   Value of 66.

.. data:: Protoss_High_Templar

   Value of 67.

.. data:: Protoss_Archon

   Value of 68.

.. data:: Protoss_Shuttle

   Value of 69.

.. data:: Protoss_Scout

   Value of 70.

.. data:: Protoss_Arbiter

   Value of 71.

.. data:: Protoss_Carrier

   Value of 72.

.. data:: Protoss_Interceptor

   Value of 73.

.. data:: Hero_Dark_Templar

   Value of 74.

.. data:: Hero_Zeratul

   Value of 75.

.. data:: Hero_Tassadar_Zeratul_Archon

   Value of 76.

.. data:: Hero_Fenix_Zealot

   Value of 77.

.. data:: Hero_Fenix_Dragoon

   Value of 78.

.. data:: Hero_Tassadar

   Value of 79.

.. data:: Hero_Mojo

   Value of 80.

.. data:: Hero_Warbringer

   Value of 81.

.. data:: Hero_Gantrithor

   Value of 82.

.. data:: Protoss_Reaver

   Value of 83.

.. data:: Protoss_Observer

   Value of 84.

.. data:: Protoss_Scarab

   Value of 85.

.. data:: Hero_Danimoth

   Value of 86.

.. data:: Hero_Aldaris

   Value of 87.

.. data:: Hero_Artanis

   Value of 88.

.. data:: Critter_Rhynadon

   Value of 89.

.. data:: Critter_Bengalaas

   Value of 90.

.. data:: Special_Cargo_Ship

   Value of 91.

.. data:: Special_Mercenary_Gunship

   Value of 92.

.. data:: Critter_Scantid

   Value of 93.

.. data:: Critter_Kakaru

   Value of 94.

.. data:: Critter_Ragnasaur

   Value of 95.

.. data:: Critter_Ursadon

   Value of 96.

.. data:: Zerg_Lurker_Egg

   Value of 97.

.. data:: Hero_Raszagal

   Value of 98.

.. data:: Hero_Samir_Duran

   Value of 99.

.. data:: Hero_Alexei_Stukov

   Value of 100.

.. data:: Special_Map_Revealer

   Value of 101.

.. data:: Hero_Gerard_DuGalle

   Value of 102.

.. data:: Zerg_Lurker

   Value of 103.

.. data:: Hero_Infested_Duran

   Value of 104.

.. data:: Spell_Disruption_Web

   Value of 105.

.. data:: Terran_Command_Center

   Value of 106.

.. data:: Terran_Comsat_Station

   Value of 107.

.. data:: Terran_Nuclear_Silo

   Value of 108.

.. data:: Terran_Supply_Depot

   Value of 109.

.. data:: Terran_Refinery

   Value of 110.

.. data:: Terran_Barracks

   Value of 111.

.. data:: Terran_Academy

   Value of 112.

.. data:: Terran_Factory

   Value of 113.

.. data:: Terran_Starport

   Value of 114.

.. data:: Terran_Control_Tower

   Value of 115.

.. data:: Terran_Science_Facility

   Value of 116.

.. data:: Terran_Covert_Ops

   Value of 117.

.. data:: Terran_Physics_Lab

   Value of 118.

.. data:: Unused_Terran1

   Value of 119.

.. data:: Terran_Machine_Shop

   Value of 120.

.. data:: Unused_Terran2

   Value of 121.

.. data:: Terran_Engineering_Bay

   Value of 122.

.. data:: Terran_Armory

   Value of 123.

.. data:: Terran_Missile_Turret

   Value of 124.

.. data:: Terran_Bunker

   Value of 125.

.. data:: Special_Crashed_Norad_II

   Value of 126.

.. data:: Special_Ion_Cannon

   Value of 127.

.. data:: Powerup_Uraj_Crystal

   Value of 128.

.. data:: Powerup_Khalis_Crystal

   Value of 129.

.. data:: Zerg_Infested_Command_Center

   Value of 130.

.. data:: Zerg_Hatchery

   Value of 131.

.. data:: Zerg_Lair

   Value of 132.

.. data:: Zerg_Hive

   Value of 133.

.. data:: Zerg_Nydus_Canal

   Value of 134.

.. data:: Zerg_Hydralisk_Den

   Value of 135.

.. data:: Zerg_Defiler_Mound

   Value of 136.

.. data:: Zerg_Greater_Spire

   Value of 137.

.. data:: Zerg_Queens_Nest

   Value of 138.

.. data:: Zerg_Evolution_Chamber

   Value of 139.

.. data:: Zerg_Ultralisk_Cavern

   Value of 140.

.. data:: Zerg_Spire

   Value of 141.

.. data:: Zerg_Spawning_Pool

   Value of 142.

.. data:: Zerg_Creep_Colony

   Value of 143.

.. data:: Zerg_Spore_Colony

   Value of 144.

.. data:: Unused_Zerg1

   Value of 145.

.. data:: Zerg_Sunken_Colony

   Value of 146.

.. data:: Special_Overmind_With_Shell

   Value of 147.

.. data:: Special_Overmind

   Value of 148.

.. data:: Zerg_Extractor

   Value of 149.

.. data:: Special_Mature_Chrysalis

   Value of 150.

.. data:: Special_Cerebrate

   Value of 151.

.. data:: Special_Cerebrate_Daggoth

   Value of 152.

.. data:: Unused_Zerg2

   Value of 153.

.. data:: Protoss_Nexus

   Value of 154.

.. data:: Protoss_Robotics_Facility

   Value of 155.

.. data:: Protoss_Pylon

   Value of 156.

.. data:: Protoss_Assimilator

   Value of 157.

.. data:: Unused_Protoss1

   Value of 158.

.. data:: Protoss_Observatory

   Value of 159.

.. data:: Protoss_Gateway

   Value of 160.

.. data:: Unused_Protoss2

.. data:: Protoss_Photon_Cannon

   Value of 162.

.. data:: Protoss_Citadel_of_Adun

   Value of 163.

.. data:: Protoss_Cybernetics_Core

   Value of 164.

.. data:: Protoss_Templar_Archives

   Value of 165.

.. data:: Protoss_Forge

   Value of 166.

.. data:: Protoss_Stargate

   Value of 167.

.. data:: Special_Stasis_Cell_Prison

   Value of 168.

.. data:: Protoss_Fleet_Beacon

   Value of 169.

.. data:: Protoss_Arbiter_Tribunal

   Value of 170.

.. data:: Protoss_Robotics_Support_Bay

   Value of 171.

.. data:: Protoss_Shield_Battery

   Value of 172.

.. data:: Special_Khaydarin_Crystal_Form

   Value of 173.

.. data:: Special_Protoss_Temple

   Value of 174.

.. data:: Special_XelNaga_Temple

   Value of 175.

.. data:: Resource_Mineral_Field

   Value of 176.

.. data:: Resource_Mineral_Field_Type_2

   Value of 177.

.. data:: Resource_Mineral_Field_Type_3

   Value of 178.

.. data:: Unused_Cave

   Value of 179.

.. data:: Unused_Cave_In

   Value of 180.

.. data:: Unused_Cantina

   Value of 181.

.. data:: Unused_Mining_Platform

   Value of 182.

.. data:: Unused_Independant_Command_Center

   Value of 183.

.. data:: Special_Independant_Starport

   Value of 184.

.. data:: Unused_Independant_Jump_Gate

   Value of 185.

.. data:: Unused_Ruins

   Value of 186.

.. data:: Unused_Khaydarin_Crystal_Formation

   Value of 187.

.. data:: Resource_Vespene_Geyser

   Value of 188.

.. data:: Special_Warp_Gate

   Value of 189.

.. data:: Special_Psi_Disrupter

   Value of 190.

.. data:: Unused_Zerg_Marker

   Value of 191.

.. data:: Unused_Terran_Marker

   Value of 192.

.. data:: Unused_Protoss_Marker

   Value of 193.

.. data:: Special_Zerg_Beacon

   Value of 194.

.. data:: Special_Terran_Beacon

   Value of 195.

.. data:: Special_Protoss_Beacon

   Value of 196.

.. data:: Special_Zerg_Flag_Beacon

   Value of 197.

.. data:: Special_Terran_Flag_Beacon

   Value of 198.

.. data:: Special_Protoss_Flag_Beacon

   Value of 199.

.. data:: Special_Power_Generator

   Value of 200.

.. data:: Special_Overmind_Cocoon

   Value of 201.

.. data:: Spell_Dark_Swarm

   Value of 202.

.. data:: Special_Floor_Missile_Trap

   Value of 203.

.. data:: Special_Floor_Hatch

   Value of 204.

.. data:: Special_Upper_Level_Door

   Value of 205.

.. data:: Special_Right_Upper_Level_Door

   Value of 206.

.. data:: Special_Pit_Door

   Value of 207.

.. data:: Special_Right_Pit_Door

   Value of 208.

.. data:: Special_Floor_Gun_Trap

   Value of 209.

.. data:: Special_Wall_Missile_Trap

   Value of 210.

.. data:: Special_Wall_Flame_Trap

   Value of 211.

.. data:: Special_Right_Wall_Missile_Trap

   Value of 212.

.. data:: Special_Right_Wall_Flame_Trap

   Value of 213.

.. data:: Special_Start_Location

   Value of 214.

.. data:: Powerup_Flag

   Value of 215.

.. data:: Powerup_Young_Chrysalis

   Value of 216.

.. data:: Powerup_Psi_Emitter

   Value of 217.

.. data:: Powerup_Data_Disk

   Value of 218.

.. data:: Powerup_Khaydarin_Crystal

   Value of 219.

.. data:: Powerup_Mineral_Cluster_Type_1

   Value of 220.

.. data:: Powerup_Mineral_Cluster_Type_2

   Value of 221.

.. data:: Powerup_Protoss_Gas_Orb_Type_1

   Value of 222.

.. data:: Powerup_Protoss_Gas_Orb_Type_2

   Value of 223.

.. data:: Powerup_Zerg_Gas_Sac_Type_1

   Value of 224.

.. data:: Powerup_Zerg_Gas_Sac_Type_2

   Value of 225.

.. data:: Powerup_Terran_Gas_Tank_Type_1

   Value of 226.

.. data:: Powerup_Terran_Gas_Tank_Type_2

   Value of 227.

.. data:: None

   Value of 228.

.. data:: AllUnits

   Value of 229.

.. data:: Men

   Value of 230.

.. data:: Buildings

   Value of 231.

.. data:: Factories

   Value of 232.

.. data:: Unknown

   Value of 233.

.. data:: MAX

   Value of 234.
