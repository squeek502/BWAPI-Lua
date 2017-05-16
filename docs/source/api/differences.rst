Differences Between the C++ and Lua API
=======================================

Most of the API follows the conventions of the C++ API and can be used in exactly the same ways, although there are exceptions in cases where either:

- The Lua programming language does not have the same capabilities as C++, so things must be done a different way
- It makes more sense to do something in a "Lua way" rather than the "C++ way"

This page documents all such differences.

All classes
-----------

Every bound class has a static member function ``isInstance`` which can be used to determine if a ``userdata`` value (an instance of a C++ class) is an instance of that class.

.. code-block:: lua
   :caption: Example

   function determineType(unknown)
     if BWAPI.Position.isInstance(unknown) then
       print("It's a Position")
     elseif BWAPI.TilePosition.isInstance(unknown) then
       print("It's a TilePosition")
     elseif BWAPI.Unit.isInstance(unknown) then
       print("It's a Unit")
     else
       print("It's something else")
     end
   end

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

.. _differences-clientInfo:

:meth:`~BWAPI.Interface.getClientInfo` and :meth:`~BWAPI.Interface.setClientInfo`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

``getClientInfo``/``setClientInfo`` have been removed in favor of a ``clientInfo`` property that is a Lua table. This allows for storing arbitrary data in a more user-friendly way.

.. code-block:: lua
   :caption: Example usage

   unit.clientInfo["test"] = 5
   print(unit.clientInfo["test"])

.. important::

   ``setClientInfo`` has also been removed from :class:`~BWAPI.Unitset`. Instead, you should simply iterate the ``Unitset`` and operate on the clientInfo of each unit as needed.

   .. code-block:: lua
      :caption: Example

      local value = 5
      for unit in set:iterator() do
        unit.clientInfo["key"] = value
      end

.. _differences-string-format:

Functions that take a variable amount of string parameters in C++
-----------------------------------------------------------------

All C++ functions that take variable amounts of strings now expect only a single string.

.. note::
   Any formatting must be done in Lua first (``string.format``), and then the formatted string can be passed into the function like normal.

.. _differences-sendTextEx:

:meth:`Game.sendTextEx`
^^^^^^^^^^^^^^^^^^^^^^^

A new convenience function has been added to send text to allies: :meth:`~BWAPI.Game.sendTextToAllies`, which fowards the method to :meth:`~BWAPI.Game.sendTextEx` with ``true`` as the first parameter. The following two snippets are exactly equivalent:
- ``BWAPI.Broodwar:sendTextEx(true, "your message")``
- ``BWAPI.Broodwar:sendTextToAllies("your message")``

Unit
----

.. _differences-unit-train:

:meth:`~BWAPI.Unit.cancelTrain` and :meth:`~BWAPI.Unit.getTrainingQueue`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

All methods that deal with training slots have been changed to be one-indexed (like Lua), rather than zero-indexed (like C++). For example, to cancel the first unit being trained, you would now pass a slot of ``1``, whereas in C++ you'd pass a slot of ``0``. List of affected methods:

* :meth:`BWAPI.Unit.canCancelTrainSlot`
* :meth:`BWAPI.Unit.cancelTrain`
* :meth:`BWAPI.Unit.getTrainingQueue`
* :meth:`BWAPI.UnitCommand.getSlot`
* :meth:`BWAPI.UnitCommand.cancelTrain`
* :meth:`BWAPI.Unitset.cancelTrain`

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

.. _differences-whatBuilds:

:meth:`~BWAPI.UnitType.whatBuilds`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Returns two values instead of a ``std::pair``

.. code-block:: lua
   :caption: Example usage

   local unitType, howMany = ut:whatBuilds()

.. _differences-requiredUnits:

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

.. _differences-sets:

SetContainer implementations (Unitset, Playerset, etc)
------------------------------------------------------

The set can be iterated one of two ways:

- ``for x in set:iterator() do``
- ``for i, x in ipairs(set:asTable()) do``

Also, any SetContainer types of the format ``ClassName::set`` are bound as ``ClassNameset``, to match the naming convention of the other SetContainer types (``Playerset``, ``Unitset``, etc). For example, ``UnitType::set`` is bound as :class:`BWAPI.UnitTypeset`.


All lists (std::list, Position::list, UnitType::list, etc)
----------------------------------------------------------

All C++ functions that return lists now return array-like Lua tables.

.. code-block:: lua
   :caption: Example

   local nukeDots = BWAPI.Broodwar:getNukeDots()
   for i, pos in ipairs(nukeDots) do
      print(string.format("There's a nuke at %s", tostring(pos)))
   end

.. _differences-unitfilter:

UnitFilter
----------

All functions that take a UnitFilter parameter now expect a Lua function that takes a unit and returns a boolean.

.. note::

   :mod:`BWAPI.Filter` functions can be used by calling them with a :class:`Unit` as the parameter (e.g. ``BWAPI.Filter.CanAttack(unit)``)

   These filters can also be combined by using the normal Lua boolean operators and wrapping/returning the result in a function. The function can then be passed as an argument to functions that would normally take a ``UnitFilter`` in C++, like so:

   .. code-block:: lua

      local myFilter = function(unit)
        return BWAPI.Filter.CanAttack(unit) and not BWAPI.Filter.IsOrganic(unit)
      end
      local closest = unit:getClosestUnit(myFilter)

.. _differences-bestfilter:

BestFilter
----------

All functions that take a ``BestUnitFilter`` parameter now expect a Lua function that takes two parameters: the current best unit, and the unit to compare to, and returns the best unit out of the two.

.. code-block:: lua
   :caption: Example

   local bestFilter = function(a, b)
     if b:getHitPoints() > a:getHitPoints() then
       return b
     end
     return a
   end
   local best = BWAPI.Broodwar:getBestUnit(bestFilter, BWAPI.Filter.IsOrganic)

.. seealso::
   :meth:`BWAPI.Game.getBestUnit`

Event and Game::getEvents
-------------------------

For now, the ``getEvents`` function of :class:`BWAPI.Game` has been removed, and there are no bindings for the ``BWAPI.Event`` class. This is subject to change if it's shown to be necessary.
