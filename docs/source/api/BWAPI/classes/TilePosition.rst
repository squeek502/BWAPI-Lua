TilePosition
************

.. currentmodule:: BWAPI

.. class:: TilePosition

   Indicates a position that is 32x32 pixels in size. Typically used for building placement.

   .. seealso::
      :mod:`BWAPI.TilePositions`, :data:`BWAPI.TILEPOSITION_SCALE`

   .. rubric:: Constructors

   .. method:: TilePosition()

      Default constructor.

   .. method:: TilePosition(x, y)

      :param int x: The x coordinate.
      :param int y: The y coordinate.

   .. method:: TilePosition(walkPos)

      A constructor to convert a :class:`WalkPosition` to a :class:`TilePosition`.

      :param BWAPI.WalkPosition walkPos: The position to be converted.

   .. method:: TilePosition(pos)

      A constructor to convert a :class:`Position` to a :class:`TilePosition`.

      :param BWAPI.Position pos: The position to be converted.

   .. rubric:: Member Variables

   .. attribute:: x

      (integer) The x coordinate.

   .. attribute:: y

      (integer) The y coordinate.

   .. rubric:: Member Functions

   .. method:: isValid() -> boolean

      Checks if this point is within the game's map bounds.

      :return: true If it is a valid position and on the map/playing field, or false If this is not a valid position.
      :rtype: boolean

      .. note::
         If the Broodwar pointer is not initialized, this function will check validity against the largest (256x256) map size.

   .. method:: makeValid() -> TilePosition

      Checks if this point is within the game's map bounds, if not, then it will set the x and y values to be within map bounds. For example, if x is less than 0, then x is set to 0.

      :return: Itself
      :rtype: BWAPI.TilePosition

      .. note::
         If the Broodwar pointer is not initialized, this function will check validity against the largest (256x256) map size.

      .. seealso::
         :meth:`isValid`

   .. method:: getDistance(pos) -> double

      Gets an accurate distance measurement from this point to the given position.

      .. note::
         This is a direct distance calculation that ignores all collision.

      .. note::
         This function impedes performance. In most cases you should use :meth:`getApproxDistance`.

      :param BWAPI.TilePosition pos: The target position to get the distance to.
      :return: A double representing the distance between this point and ``position``.
      :rtype: double

      .. seealso::
         :meth:`getApproxDistance`

   .. method:: getLength() -> double

      Gets the length of this point from the top left corner of the map.

      .. note::
         This function impedes performance. In most cases you should use :meth:`getApproxDistance`.

      :return: A double representing the length of this point from (0,0).
      :rtype: double

      .. seealso::
         :meth:`getApproxDistance`

   .. method:: getApproxDistance(pos) -> int

      Retrieves the approximate distance using an algorithm from Starcraft: Broodwar.

      .. note::
         This is a direct distance calculation that ignores all collision.

      .. note::
         This function is desired because it uses the same "imperfect" algorithm used in Broodwar, so that calculations will be consistent with the game. It is also optimized for performance.

      :param BWAPI.TilePosition pos: The target position to get the distance to.
      :return: A integer representing the distance between this point and ``position``.
      :rtype: int

      .. seealso::
         :meth:`getDistance`

   .. method:: setMax(max_x, max_y) -> TilePosition

      Sets the maximum x and y values.

      If the current x or y values exceed the given maximum, then values are set to the maximum.

      :param int max_x: Maximum x value.
      :param int max_y: Maximum y value.
      :return: Itself.
      :rtype: BWAPI.TilePosition

      .. seealso::
         :meth:`setMin`

   .. method:: setMax(max) -> TilePosition

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.TilePosition max: Point containing the maximum x and y values.
      :return: Itself.
      :rtype: BWAPI.TilePosition

   .. method:: setMin(max_x, max_y) -> TilePosition

      Sets the minimum x and y values.

      If the current x or y values are below the given minimum, then values are set to the minimum.

      :param int max_x: Minimum x value.
      :param int max_y: Minimum y value.
      :return: Itself.
      :rtype: BWAPI.TilePosition

      .. seealso::
         :meth:`setMax`

   .. method:: setMin(max) -> TilePosition

      This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.

      :param BWAPI.TilePosition max: Point containing the minimum x and y values.
      :return: Itself.
      :rtype: BWAPI.TilePosition
