The BWAPI Module
================

.. module:: BWAPI

The BWAPI bindings are all loaded into the :mod:`BWAPI` module, which is loaded as ``BWAPI`` into the global environment and can also be found in the ``"BWAPI"`` key in ``package.loaded`` (retrieved by doing ``require('BWAPI')``)

.. contents::

Classes
-------

.. toctree::
   :maxdepth: 2
   :glob:

   classes/*

Data
----

.. toctree::
   :maxdepth: 1
   :glob:

   data/*

Constants
---------

.. data:: Broodwar

   The currently running :class:`Game` instance

Functions
---------

.. staticmethod:: print(text)

   Prints the text to the client chat window, with no owner

   :param string text: The text to be printed

   .. note:: This function does not automatically append a newline to the output

Callbacks
---------

.. note::
   Replays are considered games and call all of the same callbacks as a standard game would.

.. method:: onStart()

   Called only once at the beginning of a game.

   It is intended that the AI module do any data initialization in this function.

   .. note:: ``init.lua`` is loaded with the same environment that :meth:`BWAPI.onStart` is called with, so the use of this callback is optional

.. method:: onFrame()

   Called once for every execution of a logical frame in Broodwar.

   Users will generally put most of their code in this function.

.. method:: onEnd(isWinner)

   Called once at the end of a game.

   :param boolean isWinner: A boolean value to determine if the current player has won the match. This value will be true if the current player has won, and false if either the player has lost or the game is actually a replay.

.. method:: onError(msg)

   If defined, then all Lua error messages will be redirected to this function (instead of the default functionality of the error message being printed to the screen). Can be used for custom error handling/logging errors to file/etc.

   :param string msg: The error message.

   .. literalinclude:: ../../../../examples/LogErrorsToFile/init.lua
      :language: lua
      :caption: `examples/LoggingErrorsToFile/init.lua <https://github.com/squeek502/BWAPI-Lua/blob/master/examples/LoggingErrorsToFile/init.lua>`_


.. method:: onNukeDetect(target)

   Called when a :attr:`Nuke <BWAPI.UnitTypes.Terran_Nuclear_Missile>` has been launched somewhere on the map.

   :param BWAPI.Position target: A :class:`~BWAPI.Position` containing the target location of the :attr:`Nuke <BWAPI.UnitTypes.Terran_Nuclear_Missile>`. If the target location is not visible and :attr:`BWAPI.Flag.CompleteMapInformation` is disabled, then target will be :attr:`BWAPI.Positions.Unknown`.

.. method:: onPlayerLeft(player)

   Called when a Player leaves the game.

   All of their units are automatically given to the neutral player with their colour and alliance parameters preserved.

   :param BWAPI.Player player: The :class:`Player` that has left the game.

.. method:: onReceiveText(player, text)

   Called when the client receives a message from another Player.

   This function can be used to retrieve information from allies in team games, or just to respond to other players.

   :param BWAPI.Player player: The :class:`Player` that sent the message.
   :param string text: The text message that the ``player`` sent.

.. method:: onSaveGame(gameName)

   Called when the state of the Broodwar game is saved to file.

   :param string gameName: The file name that the game was saved as

.. method:: onSendText(text)

   Called when the user attempts to send a text message.

   This function can be used to make the bot execute text commands entered by the user for debugging purposes.

   :param string text: The exact text message that was sent by the user.

   .. note:: If :attr:`BWAPI.Flag.UserInput` is disabled, then this function is not called.

.. method:: onUnitComplete(unit)

   Called when the state of a unit changes from incomplete to complete.

   :param BWAPI.Unit unit: The :class:`Unit` that has been completed.

.. method:: onUnitCreate(unit)

   Called when any unit is created.

   :param BWAPI.Unit unit: The :class:`Unit` that has just been created.

   .. note:: Due to the internal workings of Broodwar, this function excludes Zerg morphing and the construction of structures over a :attr:`Vespene Geyser <BWAPI.UnitTypes.Resource_Vespene_Geyser>`.
   .. seealso:: :meth:`BWAPI.onUnitMorph`

.. method:: onUnitDestroy(unit)

   Called when a unit is removed from the game either through death or other means.

   :param BWAPI.Unit unit: The :class:`Unit` that has just been destroyed or otherwise completely removed from the game.

   .. note:: When a :attr:`Drone <BWAPI.UnitTypes.Zerg_Drone>` morphs into an :attr:`Extractor <BWAPI.UnitTypes.Zerg_Extractor>`, the :attr:`Drone <BWAPI.UnitTypes.Zerg_Drone>` is removed from the game and the :attr:`Vespene Geyser <BWAPI.UnitTypes.Resource_Vespene_Geyser>` morphs into an :attr:`Extractor <BWAPI.UnitTypes.Zerg_Extractor>`.
   .. note:: If a unit is visible and destroyed, then :meth:`BWAPI.onUnitHide` is called just before this.

.. method:: onUnitDiscover(unit)

   Called when a Unit becomes accessible.

   :param BWAPI.Unit unit: The :class:`Unit` that has just become accessible.

   .. note:: This function INCLUDES the state of `BWAPI.Flag.CompleteMapInformation`.
   .. seealso:: :meth:`BWAPI.onUnitShow`

.. method:: onUnitEvade(unit)

   Called when a Unit becomes inaccessible.

   :param BWAPI.Unit unit: The :class:`Unit` that has just become inaccessible.

   .. note:: This function INCLUDES the state of `BWAPI.Flag.CompleteMapInformation`.
   .. seealso:: :meth:`BWAPI.onUnitHide`

.. method:: onUnitHide(unit)

   Called just as a visible unit is becoming invisible.

   :param BWAPI.Unit unit: The :class:`Unit` that is about to go out of scope.

   .. note:: This function EXCLUDES the state of `BWAPI.Flag.CompleteMapInformation`.
   .. seealso:: :meth:`BWAPI.onUnitEvade`

.. method:: onUnitMorph(unit)

   Called when a unit changes its :class:`~BWAPI.UnitType`.

   For example, when a :attr:`Drone <BWAPI.UnitTypes.Zerg_Drone>` transforms into a :attr:`Hatchery <BWAPI.UnitTypes.Zerg_Hatchery>`, a :attr:`Siege Tank <BWAPI.UnitTypes.Terran_Siege_Tank>` uses :attr:`Siege Mode <BWAPI.TechTypes.Tank_Siege_Mode>`, or a :attr:`Vespene Geyser <BWAPI.UnitTypes.Resource_Vespene_Geyser>` receives a :attr:`Refinery <BWAPI.UnitTypes.Terran_Refinery>`.

   :param BWAPI.Unit unit: The :class:`Unit` that just had its :class:`UnitType` change.

   .. note:: This is NOT called if the unit type changes to or from :attr:`~BWAPI.UnitTypes.Unknown`.
