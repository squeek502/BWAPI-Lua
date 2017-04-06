Bullet
******

.. currentmodule:: BWAPI

.. class:: Bullet

   An object representing a bullet or missile spawned from an attack.

   Bullet allows you to detect bullets, missiles, and other types of non-melee attacks or special abilities that would normally be visible through human eyes (A lurker spike or a Queen's flying parasite), allowing quicker reaction to unavoidable consequences.

   For example, ordering medics to restore units that are about to receive a lockdown to compensate for latency and minimize its effects. You can't know entirely which unit will be receiving a lockdown unless you can detect the lockdown missile using the Bullet class.

   Bullet objects are re-used after they are destroyed, however their ID is updated when it represents a new Bullet.

   If :attr:`BWAPI.Flag.CompleteMapInformation` is disabled, then a Bullet is accessible if and only if it is visible. Otherwise if :attr:`BWAPI.Flag.CompleteMapInformation` is enabled, then all Bullets in the game are accessible.

   .. seealso::
      :meth:`Game.getBullets`, :meth:`Bullet.exists`

   .. rubric:: Constructors

   This class is not constructable through Lua.

   .. rubric:: Member Variables

   .. include:: /_include/interface-clientinfo.rst

   .. rubric:: Member Functions

   .. method:: exists() -> boolean

      Checks if the Bullet exists in the view of the :mod:`BWAPI` player.

       If :attr:`BWAPI.Flag.CompleteMapInformation` is disabled, and a Bullet is not visible, then the return value will be false regardless of the Bullet's true existence. This is because absolutely no state information on invisible enemy bullets is made available to the AI.

      :return: Returns ``true`` if the bullet exists or is visible, or ``false`` if the bullet was destroyed or has gone out of scope
      :rtype: boolean

      .. seealso::
         isVisible, :meth:`Unit.exists`

   .. method:: getAngle() -> double

      Retrieve's the direction the Bullet is facing.

      If the angle is 0, then the Bullet is facing right.

      :return: A double representing the direction the Bullet is facing. Returns ``0.0`` if the bullet is inaccessible.
      :rtype: double

   .. method:: getID() -> int

      Retrieves a unique identifier for the current Bullet.

      :return: An integer value containing the identifier.
      :rtype: int

   .. method:: getPlayer() -> Player

      Retrieves the Player interface that owns the Bullet.

      :return: The owning Player interface object. Returns ``nil`` if the Player object for this Bullet is inaccessible.
      :rtype: :class:`BWAPI.Player`

   .. method:: getPosition() -> Position

      Retrieves the Bullet's current position.

      :return: A Position containing the Bullet's current coordinates. Returns ``Positions.Unknown`` if the Bullet is inaccessible.
      :rtype: :class:`BWAPI.Position`

      .. seealso::
         :meth:`getTargetPosition`

   .. method:: getRemoveTimer() -> int

      Retrieves the timer that indicates the Bullet's life span.

      Bullets are not permanent objects, so they will often have a limited life span. This life span is measured in frames. Normally a Bullet will reach its target before being removed.

      :return: An integer representing the remaining number of frames until the Bullet self-destructs. Returns ``0`` if the Bullet is inaccessible.
      :rtype: int

   .. method:: getSource() -> Unit

      Retrieves the Unit interface that the Bullet spawned from.

      :return: The owning Unit interface object. Returns ``nil`` if the source can not be identified or is inaccessible.
      :rtype: :class:`BWAPI.Unit`

      .. seealso::
         :meth:`getTarget`

   .. method:: getTarget() -> Unit

      Retrieves the Unit interface that the Bullet is heading to.

      :return: The target Unit interface object, if one exists. Returns ``nil`` if the Bullet's target Unit is inaccessible, the Bullet is targetting the ground, or if the Bullet itself is inaccessible.
      :rtype: :class:`BWAPI.Unit`

      .. seealso::
         :meth:`getTargetPosition`, :meth:`getSource`

   .. method:: getTargetPosition() -> Position

      Retrieves the target position that the Bullet is heading to.

      :return: A Position indicating where the Bullet is headed. Returns ``Positions.Unknown`` if the bullet is inaccessible.
      :rtype: :class:`BWAPI.Position`

      .. seealso::
         :meth:`getTarget`, :meth:`getPosition`

   .. method:: getType() -> BulletType

      Retrieves the type of this Bullet.

      :return: A :class:`BulletType` representing the Bullet's type. Returns ``BulletTypes.Unknown`` if the Bullet is inaccessible.
      :rtype: :class:`BWAPI.BulletType`

   .. method:: getVelocityX() -> double

      Retrieves the X component of the Bullet's velocity, measured in pixels per frame.

      :return: A double representing the number of pixels moved on the X axis per frame. Returns ``0.0`` if the Bullet is inaccessible.
      :rtype: double

      .. seealso::
         :meth:`getVelocityY`, :meth:`getAngle`

   .. method:: getVelocityY() -> double

      Retrieves the Y component of the Bullet's velocity, measured in pixels per frame.

      :return: A double representing the number of pixels moved on the Y axis per frame. Returns ``0.0`` if the Bullet is inaccessible.
      :rtype: double

      .. seealso::
         :meth:`getVelocityX`, :meth:`getAngle`

   .. method:: isVisible([player = nil]) -> boolean

      Retrieves the visibility state of the Bullet.

      :param BWAPI.Player player: (optional) If this parameter is specified, then the Bullet's visibility to the given player is checked. If this parameter is omitted, then a default value of nil is used, which will check if the :mod:`BWAPI` player has vision of the Bullet.

      :return: Returns ``true`` if the Bullet is visible to the specified player, or ``false`` if the Bullet is not visible to the specified player
      :rtype: boolean

      .. note::
         If ``player`` is nil and Broodwar->self() is also nil, then the visibility of the Bullet is determined by checking if at least one other player has vision of the Bullet.

   .. include:: /_include/interface-functions.rst
