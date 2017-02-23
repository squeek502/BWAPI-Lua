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

getClientInfo and setClientInfo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

``getClientInfo``/``setClientInfo`` have been removed in favor of a ``clientInfo`` property that is a Lua table.

.. code-block:: lua
   :caption: Example usage

   unit.clientInfo["test"] = 5
   print(unit.clientInfo["test"])


Functions that take a variable amount of string parameters in C++
-----------------------------------------------------------------

All C++ functions that take variable amounts of strings now expect only a single string.

.. note::
   All formatting now needs to be done in Lua first (``string.format``), and then the formatted string can be passed into the function like normal.


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


UnitFilter
----------

All functions that take a UnitFilter parameter now expect a Lua function that takes a unit and returns a boolean

.. note::

   :mod:`BWAPI.Filter` :class:`UnitFilter` instances can be still used by calling them with a :class:`Unit` as the parameter (e.g. ``BWAPI.Filter.CanAttack(unit)``)

   These filters can also be combined by using the normal Lua boolean operators and wrapping/returning the result in a function. The function can then be passed as an argument to functions that would normally take a :class:`UnitFilter` in C++, like so:

   .. code-block:: lua

      local myFilter = function(unit)
        return BWAPI.Filter.CanAttack(unit) and not BWAPI.Filter.IsOrganic(unit)
      end
      local closest = unit:getClosestUnit(myFilter)
