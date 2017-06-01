Installing and Using Modules
============================

Modules can be loaded and used as in normal Lua. Note that BWAPI-Lua adds the directory of the loaded BWAPI-Lua dll to ``package.path`` and ``package.cpath`` (see :attr:`package.cpath`/:attr:`package.path`).

.. note::
   When loading binary modules using ``require``, you should not use any paths in the module name passed to ``require``, as binary modules rely on the module name to call the initialization function.

   For example, a module like ``example.dll`` should be loaded by doing ``require('example')`` rather than ``require('sub.dir.example')``, even if the path to ``example.dll`` is ``sub/dir/example.dll``. If you want to put the ``.dll`` outside the default search paths (for example, in a directory specific to your AI), then you'll need to alter ``package.cpath`` accordingly (e.g. ``package.cpath = "C:/path/to/dir/?.dll;" .. package.cpath``).
