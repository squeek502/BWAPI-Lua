.. currentmodule:: BWAPI

DamageTypes
===========

.. module:: BWAPI.DamageTypes

Module containing damage types.

* `View on Liquipedia <http://wiki.teamliquid.net/starcraft/Damage_Type>`_
* `View on Starcraft Campendium (Official Website) <http://classic.battle.net/scc/gs/damage.shtml>`_
* `View on Starcraft Wikia <http://starcraft.wikia.com/wiki/Damage_types>`_

.. seealso::
   :class:`BWAPI.DamageType`

Functions
---------

.. staticmethod:: allDamageTypes() -> set

   Retrieves a set of all DamageTypes.

   :return: Set of all DamageTypes.
   :rtype: :class:`~BWAPI.DamageTypeset`

Constants
---------

All constants are instances of the :class:`~BWAPI.DamageType` class

.. data:: Independent
.. data:: Explosive
.. data:: Concussive
.. data:: Normal
.. data:: Ignore_Armor
.. data:: None
.. data:: Unknown

Enum
----

.. module:: BWAPI.DamageTypes.Enum

Enumeration of damage types.

.. include:: /_include/api-enum.rst

.. data:: Independent

   Value of 0.

.. data:: Explosive

   Value of 1.

.. data:: Concussive

   Value of 2.

.. data:: Normal

   Value of 3.

.. data:: Ignore_Armor

   Value of 4.

.. data:: None

   Value of 5.

.. data:: Unknown

   Value of 6.

.. data:: MAX

   Value of 7.
