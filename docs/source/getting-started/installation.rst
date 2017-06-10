Installation
============

.. rubric:: Starcraft and BWAPI

1. Install and update Starcraft to patch 1.16.1 (not 1.18). The 1.16.1 patch `can be downloaded here <http://ftp.blizzard.com/pub/starcraft/patches/PC/SC-1161.exe>`__, and a guide for setting up simultateous 1.16.1 and 1.18 installs `can be found here <https://iccup.com/en/starcraft/sc_start.html>`__.
2. Download and install `BWAPI 4.1.2 <https://github.com/bwapi/bwapi/releases/tag/v4.1.2>`__

.. rubric:: BWAPI-Lua

3. Download the `BWAPI-Lua .dll for the version of Lua you want to use <https://github.com/squeek502/BWAPI-Lua/releases>`__ and move it to ``Starcraft/bwapi-data/AI`` (e.g. ``C:\Program Files (x86)\StarCraft\bwapi-data\AI``).
4. You will also need to make sure that you have a compatible Lua .dll in your Starcraft folder or somewhere in your ``PATH`` (for Lua 5.1, it should be named ``lua51.dll``). If you are unsure if you have this, you should download it from `here <https://github.com/squeek502/BWAPI-Lua/releases>`__ and put it in your Starcraft folder (e.g. ``C:\Program Files (x86)\StarCraft``).
5. Edit ``Starcraft/bwapi-data/bwapi.ini`` and change the line ``ai = bwapi-data/AI/ExampleAIModule.dll`` to point to the BWAPI-Lua dll you just installed (e.g. ``ai = bwapi-data/AI/Lua51AIModule.dll``)

.. admonition:: Next

   :doc:`Your first Lua AI <your-first-ai>`
