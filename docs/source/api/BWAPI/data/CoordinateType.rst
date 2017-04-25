.. currentmodule:: BWAPI

CoordinateType
==============

.. module:: BWAPI.CoordinateType

Module containing coordinate types.

Constants
---------

.. data:: None

   A default value for uninitialized coordinate types.

   Equal to :data:`BWAPI.CoordinateType.Enum.None`

.. data:: Screen

   :data:`~BWAPI.Positions.Origin` (0,0) corresponds to the top left corner of the screen.

   Equal to :data:`BWAPI.CoordinateType.Enum.Screen`

.. data:: Map

   :data:`~BWAPI.Positions.Origin` (0,0) corresponds to the top left corner of the map.

   Equal to :data:`BWAPI.CoordinateType.Enum.Map`

.. data:: Mouse

   :data:`~BWAPI.Positions.Origin` (0,0) corresponds to the location of the mouse cursor.

   Equal to :data:`BWAPI.CoordinateType.Enum.Mouse`

Enum
----

.. module:: BWAPI.CoordinateType.Enum

Enumeration of coordinate types.

.. data:: None

   Value of 0.

.. data:: Screen

   Value of 1.

.. data:: Map

   Value of 2.

.. data:: Mouse

   Value of 3.
