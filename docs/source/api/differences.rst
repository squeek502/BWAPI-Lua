Differences Between the C++ and Lua API
=======================================

Most of the API follows the conventions of the C++ API and can be used in exactly the same ways, although there are exceptions in cases where either:

- The Lua programming language does not have the same capabilities as C++, so things must be done a different way
- It makes more sense to do something in a "Lua way" rather than the "C++ way"

This page documents all such differences.


Interface derived classes (Game, Player, Unit, etc)
---------------------------------------------------

:meth:`~BWAPI.Interface.registerEvent`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Takes Lua functions for its ``action`` and ``condition`` parameters (note: ``condition`` can be ``nil``)

.. code-block:: lua
   :caption: Example usage

   local Broodwar = BWAPI.Broodwar
   local pos = u:getPosition()
   local lastErr = Broodwar:getLastError()
   local action = function()
      Broodwar:drawTextMap(pos, string.format("%c%s", BWAPI.Text.White, tostring(lastErr)))
   end
   Broodwar:registerEvent(action, nil, Broodwar:getLatencyFrames())

:meth:`~BWAPI.Interface.getClientInfo` and :meth:`~BWAPI.Interface.setClientInfo`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

``getClientInfo``/``setClientInfo`` have been removed in favor of a ``clientInfo`` property that is a Lua table. This allows for storing arbitrary data in a more user-friendly way.

.. code-block:: lua
   :caption: Example usage

   unit.clientInfo["test"] = 5
   print(unit.clientInfo["test"])


Functions that take a variable amount of string parameters in C++
-----------------------------------------------------------------

All C++ functions that take variable amounts of strings now expect only a single string.

.. note::
   Any formatting must be done in Lua first (``string.format``), and then the formatted string can be passed into the function like normal.

:meth:`Game::sendTextEx`
^^^^^^^^^^^^^^^^^^^^^^^^

A new convenience function has been added to send text to allies: :meth:`~BWAPI.Game.sendTextToAllies`, which fowards the method to :meth:`~BWAPI.Game.sendTextEx` with ``true`` as the first parameter. The following two snippets are exactly equivalent:
- ``BWAPI.Broodwar:sendTextEx(true, "your message")``
- ``BWAPI.Broodwar:sendTextToAllies("your message")``

Unit
----

.. _differences-unit-train:

:meth:`~BWAPI.Unit.cancelTrain` and :meth:`~BWAPI.Unit.getTrainingQueue`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

:meth:`~BWAPI.Unit.cancelTrain`'s slot parameter has been changed to be one-indexed (like Lua), rather than zero-indexed (like C++). For example, to cancel the first unit being trained, you would now pass a slot of ``1``, whereas in C++ you'd pass a slot of ``0``

Similarly, :meth:`~BWAPI.Unit.getTrainingQueue` returns a Lua array-like table (which is one-indexed) instead of a ``std::list`` (which is zero-indexed). This allows for the following:

.. code-block:: lua

   -- cancel the first dragoon found in the queue
   local queue = building:getTrainingQueue()
   for slot, unitType in ipairs(queue) do
     if unitType == BWAPI.UnitTypes.Protoss_Dragoon then
      building:cancelTrain(slot)
      break
     end
   end

.. warning::
   Iterating a training queue and canceling multiple slots while in the loop will result in unexpected behavior, as the slots will shift as things are canceled. For example, if you cancel slot 1 and then iterate to slot 2 and also cancel it, then you'll actually be canceling what was originally in slot 3.


UnitType
--------

:meth:`~BWAPI.UnitType.whatBuilds`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Returns two values instead of a ``std::pair``

.. code-block:: lua
   :caption: Example usage

   local unitType, howMany = ut:whatBuilds()

:meth:`~BWAPI.UnitType.requiredUnits`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Returns a Lua table of the format ``{ [<unitTypeID>] = <howMany> }``, where ``<unitTypeID>`` is the integer ID/Enum of a required UnitType (equal to ``UnitType:getID()``) and ``<howMany>`` is the required number of that unit.

.. code-block:: lua
   :caption: Example usage

   local scv = BWAPI.UnitTypes.SCV
   local requiredUnits = scv:requiredUnits()
   for unitTypeID, howMany in pairs(requiredUnits) do
     local requiredUnitType = BWAPI.UnitType(unitTypeID)
     local str = string.format("%s requires %d %s",
       tostring(scv),
       howMany,
       tostring(requiredUnitType)
     )
     print(str)
   end


SetContainer implemenations (Unitset, Playerset, etc)
-----------------------------------------------------

The set can be iterated one of two ways:

- ``for x in set:iterator() do``
- ``for i, x in ipairs(set:asTable()) do``


.. _differences-unitfilter:

All lists (std::list, Position::list, UnitType::list, etc)
----------------------------------------------------------

All C++ functions that return lists now return array-like Lua tables.

.. code-block:: lua
   :caption: Example

   local nukeDots = BWAPI.Broodwar:getNukeDots()
   for i, pos in ipairs(nukeDots) do
      print(string.format("There's a nuke at %s", tostring(pos)))
   end

UnitFilter
----------

All functions that take a UnitFilter parameter now expect either:
- A Lua function that takes a unit and returns a boolean.
- A UnitFilter instance from :mod:`BWAPI.Filter`

.. note::

   :mod:`BWAPI.Filter` :class:`UnitFilter` instances can be still used by calling them with a :class:`Unit` as the parameter (e.g. ``BWAPI.Filter.CanAttack(unit)``)

   These filters can also be combined by using the normal Lua boolean operators and wrapping/returning the result in a function. The function can then be passed as an argument to functions that would normally take a :class:`UnitFilter` in C++, like so:

   .. code-block:: lua

      local myFilter = function(unit)
        return BWAPI.Filter.CanAttack(unit) and not BWAPI.Filter.IsOrganic(unit)
      end
      local closest = unit:getClosestUnit(myFilter)

BestUnitFilter
--------------

All functions that take a BestUnitFIlter parameter now expect a Lua function that takes two parameters: the current best unit, and the unit to compare to, and returns the best unit out of the two.

.. code-block:: lua
   :caption: Example

   local bestFilter = function(a, b)
     if b:getHitPoints() > a:getHitPoints() then
       return b
     end
     return a
   end
   local best = BWAPI.Broodwar:getBestUnit(bestFilter, BWAPI.Filter.IsOrganic)
