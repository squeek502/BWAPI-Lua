.. currentmodule:: BWAPI

WeaponTypes
===========

.. module:: BWAPI.WeaponTypes

Module containing weapon types.

.. seealso::
   :class:`BWAPI.WeaponType`

Functions
---------

.. staticmethod:: allWeaponTypes() -> set

   Retrieves a set of all WeaponTypes.

   :return: Set of all WeaponTypes.
   :rtype: :class:`~BWAPI.WeaponTypeset`

.. staticmethod:: normalWeaponTypes() -> set

   Retrieves a set of all defined normal WeaponTypes. This set contains all weapons that are not used for abilities.

   :return: Set of normal WeaponTypes.
   :rtype: :class:`~BWAPI.WeaponTypeset`

.. staticmethod:: specialWeaponTypes() -> set

   Retrieves a set of all defined special WeaponTypes. This set contains all weapons that are used exclusively for special unit abilities.

   :return: Set of special WeaponTypes.
   :rtype: :class:`~BWAPI.WeaponTypeset`

Constants
---------

All constants are instances of the :class:`~BWAPI.WeaponType` class

.. rubric:: Normal Weapons

.. data:: Gauss_Rifle
.. data:: Gauss_Rifle_Jim_Raynor
.. data:: C_10_Canister_Rifle
.. data:: C_10_Canister_Rifle_Sarah_Kerrigan
.. data:: C_10_Canister_Rifle_Samir_Duran
.. data:: C_10_Canister_Rifle_Infested_Duran
.. data:: C_10_Canister_Rifle_Alexei_Stukov
.. data:: Fragmentation_Grenade
.. data:: Fragmentation_Grenade_Jim_Raynor
.. data:: Spider_Mines
.. data:: Twin_Autocannons
.. data:: Twin_Autocannons_Alan_Schezar
.. data:: Hellfire_Missile_Pack
.. data:: Hellfire_Missile_Pack_Alan_Schezar
.. data:: Arclite_Cannon
.. data:: Arclite_Cannon_Edmund_Duke
.. data:: Fusion_Cutter
.. data:: Gemini_Missiles
.. data:: Gemini_Missiles_Tom_Kazansky
.. data:: Burst_Lasers
.. data:: Burst_Lasers_Tom_Kazansky
.. data:: ATS_Laser_Battery
.. data:: ATS_Laser_Battery_Hero
.. data:: ATS_Laser_Battery_Hyperion
.. data:: ATA_Laser_Battery
.. data:: ATA_Laser_Battery_Hero
.. data:: ATA_Laser_Battery_Hyperion
.. data:: Flame_Thrower
.. data:: Flame_Thrower_Gui_Montag
.. data:: Arclite_Shock_Cannon
.. data:: Arclite_Shock_Cannon_Edmund_Duke
.. data:: Longbolt_Missile
.. data:: Claws
.. data:: Claws_Devouring_One
.. data:: Claws_Infested_Kerrigan
.. data:: Needle_Spines
.. data:: Needle_Spines_Hunter_Killer
.. data:: Kaiser_Blades
.. data:: Kaiser_Blades_Torrasque
.. data:: Toxic_Spores
.. data:: Spines
.. data:: Acid_Spore
.. data:: Acid_Spore_Kukulza
.. data:: Glave_Wurm
.. data:: Glave_Wurm_Kukulza
.. data:: Seeker_Spores
.. data:: Subterranean_Tentacle
.. data:: Suicide_Infested_Terran
.. data:: Suicide_Scourge
.. data:: Particle_Beam
.. data:: Psi_Blades
.. data:: Psi_Blades_Fenix
.. data:: Phase_Disruptor
.. data:: Phase_Disruptor_Fenix
.. data:: Psi_Assault
.. data:: Psionic_Shockwave
.. data:: Psionic_Shockwave_TZ_Archon
.. data:: Dual_Photon_Blasters
.. data:: Dual_Photon_Blasters_Mojo
.. data:: Dual_Photon_Blasters_Artanis
.. data:: Anti_Matter_Missiles
.. data:: Anti_Matter_Missiles_Mojo
.. data:: Anti_Matter_Missiles_Artanis
.. data:: Phase_Disruptor_Cannon
.. data:: Phase_Disruptor_Cannon_Danimoth
.. data:: Pulse_Cannon
.. data:: STS_Photon_Cannon
.. data:: STA_Photon_Cannon
.. data:: Scarab
.. data:: Neutron_Flare
.. data:: Halo_Rockets
.. data:: Corrosive_Acid
.. data:: Subterranean_Spines
.. data:: Warp_Blades
.. data:: Warp_Blades_Hero
.. data:: Warp_Blades_Zeratul
.. data:: Independant_Laser_Battery
.. data:: Twin_Autocannons_Floor_Trap
.. data:: Hellfire_Missile_Pack_Wall_Trap
.. data:: Flame_Thrower_Wall_Trap
.. data:: Hellfire_Missile_Pack_Floor_Trap

.. rubric:: Special Weapons

.. data:: Yamato_Gun
.. data:: Nuclear_Strike
.. data:: Lockdown
.. data:: EMP_Shockwave
.. data:: Irradiate
.. data:: Parasite
.. data:: Spawn_Broodlings
.. data:: Ensnare
.. data:: Dark_Swarm
.. data:: Plague
.. data:: Consume
.. data:: Stasis_Field
.. data:: Psionic_Storm
.. data:: Disruption_Web
.. data:: Restoration
.. data:: Mind_Control
.. data:: Feedback
.. data:: Optical_Flare
.. data:: Maelstrom

.. rubric:: Misc

.. data:: None
.. data:: Unknown

Enum
----

.. module:: BWAPI.WeaponTypes.Enum

Enumeration of weapon types.

.. include:: /_include/api-enum.rst

.. data:: Gauss_Rifle

   Value of 0.

.. data:: Gauss_Rifle_Jim_Raynor

   Value of 1.

.. data:: C_10_Canister_Rifle

   Value of 2.

.. data:: C_10_Canister_Rifle_Sarah_Kerrigan

   Value of 3.

.. data:: Fragmentation_Grenade

   Value of 4.

.. data:: Fragmentation_Grenade_Jim_Raynor

   Value of 5.

.. data:: Spider_Mines

   Value of 6.

.. data:: Twin_Autocannons

   Value of 7.

.. data:: Hellfire_Missile_Pack

   Value of 8.

.. data:: Twin_Autocannons_Alan_Schezar

   Value of 9.

.. data:: Hellfire_Missile_Pack_Alan_Schezar

   Value of 10.

.. data:: Arclite_Cannon

   Value of 11.

.. data:: Arclite_Cannon_Edmund_Duke

   Value of 12.

.. data:: Fusion_Cutter

   Value of 13.

.. data:: Gemini_Missiles

   Value of 15.

.. data:: Burst_Lasers

   Value of 16.

.. data:: Gemini_Missiles_Tom_Kazansky

   Value of 17.

.. data:: Burst_Lasers_Tom_Kazansky

   Value of 18.

.. data:: ATS_Laser_Battery

   Value of 19.

.. data:: ATA_Laser_Battery

   Value of 20.

.. data:: ATS_Laser_Battery_Hero

   Value of 21.

.. data:: ATA_Laser_Battery_Hero

   Value of 22.

.. data:: ATS_Laser_Battery_Hyperion

   Value of 23.

.. data:: ATA_Laser_Battery_Hyperion

   Value of 24.

.. data:: Flame_Thrower

   Value of 25.

.. data:: Flame_Thrower_Gui_Montag

   Value of 26.

.. data:: Arclite_Shock_Cannon

   Value of 27.

.. data:: Arclite_Shock_Cannon_Edmund_Duke

   Value of 28.

.. data:: Longbolt_Missile

   Value of 29.

.. data:: Yamato_Gun

   Value of 30.

.. data:: Nuclear_Strike

   Value of 31.

.. data:: Lockdown

   Value of 32.

.. data:: EMP_Shockwave

   Value of 33.

.. data:: Irradiate

   Value of 34.

.. data:: Claws

   Value of 35.

.. data:: Claws_Devouring_One

   Value of 36.

.. data:: Claws_Infested_Kerrigan

   Value of 37.

.. data:: Needle_Spines

   Value of 38.

.. data:: Needle_Spines_Hunter_Killer

   Value of 39.

.. data:: Kaiser_Blades

   Value of 40.

.. data:: Kaiser_Blades_Torrasque

   Value of 41.

.. data:: Toxic_Spores

   Value of 42.

.. data:: Spines

   Value of 43.

.. data:: Acid_Spore

   Value of 46.

.. data:: Acid_Spore_Kukulza

   Value of 47.

.. data:: Glave_Wurm

   Value of 48.

.. data:: Glave_Wurm_Kukulza

   Value of 49.

.. data:: Seeker_Spores

   Value of 52.

.. data:: Subterranean_Tentacle

   Value of 53.

.. data:: Suicide_Infested_Terran

   Value of 54.

.. data:: Suicide_Scourge

   Value of 55.

.. data:: Parasite

   Value of 56.

.. data:: Spawn_Broodlings

   Value of 57.

.. data:: Ensnare

   Value of 58.

.. data:: Dark_Swarm

   Value of 59.

.. data:: Plague

   Value of 60.

.. data:: Consume

   Value of 61.

.. data:: Particle_Beam

   Value of 62.

.. data:: Psi_Blades

   Value of 64.

.. data:: Psi_Blades_Fenix

   Value of 65.

.. data:: Phase_Disruptor

   Value of 66.

.. data:: Phase_Disruptor_Fenix

   Value of 67.

.. data:: Psi_Assault

   Value of 69.

.. data:: Psionic_Shockwave

   Value of 70.

.. data:: Psionic_Shockwave_TZ_Archon

   Value of 71.

.. data:: Dual_Photon_Blasters

   Value of 73.

.. data:: Anti_Matter_Missiles

   Value of 74.

.. data:: Dual_Photon_Blasters_Mojo

   Value of 75.

.. data:: Anti_Matter_Missiles_Mojo

   Value of 76.

.. data:: Phase_Disruptor_Cannon

   Value of 77.

.. data:: Phase_Disruptor_Cannon_Danimoth

   Value of 78.

.. data:: Pulse_Cannon

   Value of 79.

.. data:: STS_Photon_Cannon

   Value of 80.

.. data:: STA_Photon_Cannon

   Value of 81.

.. data:: Scarab

   Value of 82.

.. data:: Stasis_Field

   Value of 83.

.. data:: Psionic_Storm

   Value of 84.

.. data:: Warp_Blades_Zeratul

   Value of 85.

.. data:: Warp_Blades_Hero

   Value of 86.

.. data:: Platform_Laser_Battery

   Value of 92.

.. data:: Independant_Laser_Battery

   Value of 93.

.. data:: Twin_Autocannons_Floor_Trap

   Value of 96.

.. data:: Hellfire_Missile_Pack_Wall_Trap

   Value of 97.

.. data:: Flame_Thrower_Wall_Trap

   Value of 98.

.. data:: Hellfire_Missile_Pack_Floor_Trap

   Value of 99.

.. data:: Neutron_Flare

   Value of 100.

.. data:: Disruption_Web

   Value of 101.

.. data:: Restoration

   Value of 102.

.. data:: Halo_Rockets

   Value of 103.

.. data:: Corrosive_Acid

   Value of 104.

.. data:: Mind_Control

   Value of 105.

.. data:: Feedback

   Value of 106.

.. data:: Optical_Flare

   Value of 107.

.. data:: Maelstrom

   Value of 108.

.. data:: Subterranean_Spines

   Value of 109.

.. data:: Warp_Blades

   Value of 111.

.. data:: C_10_Canister_Rifle_Samir_Duran

   Value of 112.

.. data:: C_10_Canister_Rifle_Infested_Duran

   Value of 113.

.. data:: Dual_Photon_Blasters_Artanis

   Value of 114.

.. data:: Anti_Matter_Missiles_Artanis

   Value of 115.

.. data:: C_10_Canister_Rifle_Alexei_Stukov

   Value of 116.

.. data:: None

   Value of 130.

.. data:: Unknown

   Value of 131.

.. data:: MAX

   Value of 132.
