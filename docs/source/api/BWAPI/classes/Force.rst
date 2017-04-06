Force
*****

.. currentmodule:: BWAPI

.. class:: Force

   The Force class is used to get information about each force in a match.

   Normally this is considered a team.

   .. note::
      It is not called a team because players on the same force do not necessarily need to be allied at the beginning of a match.

   .. rubric:: Constructors

   This class is not constructable through Lua.

   .. rubric:: Member Variables

   .. include:: /_include/interface-clientinfo.rst

   .. rubric:: Member Functions

   .. method:: getID() -> int

      Retrieves the unique ID that represents this Force.

      :return: An integer containing the ID for the Force.
      :rtype: int

   .. method:: getName() -> string

      Retrieves the name of the Force.

      :return: A string containing the name of the force.
      :rtype: string

      .. code-block:: lua
         :caption: Example usage

         local myForce = BWAPI.Broodwar:self():getForce()
         if myForce:getName() == "Observers" then
           print("Looks like we're observing a match")
         end

   .. method:: getPlayers() -> set

      Retrieves the set of players that belong to this Force.

      :return: A :class:`~BWAPI.Playerset` object containing the players that are part of this Force.
      :rtype: :class:`BWAPI.Playerset`

      .. code-block:: lua
         :caption: Example usage

         -- Get the enemy force, but make sure we have an enemy
         if BWAPI.Broodwar:enemy() then
           local myEnemyForce = BWAPI.Broodwar:enemy():getForce()
           print("The allies of my enemy are...")
           for ally in myEnemyForce:iterator() do
             print("  - " .. ally:getName())
           end
         end

   .. include:: /_include/interface-functions.rst
