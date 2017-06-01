Changes to the Global Environment
=================================

.. method:: print(...)

:meth:`print` has been overriden to act similarly to the normal Lua print, but redirect its output to the client chat window via :meth:`BWAPI.print`.

It will take all arguments, call ``tostring`` on them, concatenate them together using ``\t`` as the separator, append a newline to the end of the string, and then pass that to :meth:`BWAPI.print`.

.. attribute:: package.path

The directory of the loaded LuaAIModule .dll gets appended to the front of :attr:`package.path` (using both the ``/?.lua`` and ``/?/init.lua`` variants).

.. attribute:: package.cpath

The directory of the loaded LuaAIModule .dll gets appended to the front of :attr:`package.cpath` (using the ``/?.dll`` variant)

.. attribute:: BWAPI
   :noindex:

See :mod:`BWAPI`
