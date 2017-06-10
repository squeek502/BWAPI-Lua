Your First Lua AI
=================

The entry point to Lua is ``init.lua`` in the same directory as the loaded BWAPI-Lua AI module .dll (e.g. ``C:\Program Files (x86)\StarCraft\bwapi-data\AI``). Once ``init.lua`` is executed, the  :ref:`BWAPI callbacks <bwapi-callbacks>` will be begin to be called (if they are defined in the global ``BWAPI`` table).

The most basic AI--one that simply sends a string to the chat at the start of a game--would look like this:

.. code-block:: lua
   :caption: init.lua

   function BWAPI.onStart()
     BWAPI.Broodwar:sendText("Hello world!")
   end

The :meth:`BWAPI.onStart` callback gets called immediately after ``init.lua`` is loaded.
