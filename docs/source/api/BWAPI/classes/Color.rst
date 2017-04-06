Color
*****

.. currentmodule:: BWAPI

.. class:: Color

   The :class:`Color` object is used in drawing routines to specify the color to use.

   .. note::
      Starcraft uses a 256 color palette for rendering. Thus, the colors available are limited to this palette.

   .. seealso::
      :mod:`~BWAPI.Colors`

   .. rubric:: Constructors

   .. method:: Color([id = 0])

      A constructor that uses the color at the specified palette index.

      :param int id: The index of the color in the 256-color palette.

   .. method:: Color(red, green, blue)

      A constructor that uses the color index in the palette that is closest to the given rgb values.

      On its first call, the colors in the palette will be sorted for fast indexing.

      :param int red: The amount of red.
      :param int green: The amount of green.
      :param int blue: The amount of blue.

      .. note::
         This function computes the distance of the RGB values and may not be accurate.

   .. rubric:: Member Functions

   .. method:: blue() -> int

      Retrieves the blue component of the color.

      :return: integer containing the value of the blue component.
      :rtype: int

   .. method:: green() -> int

      Retrieves the green component of the color.

      :return: integer containing the value of the green component.
      :rtype: int

   .. method:: red() -> int

      Retrieves the red component of the color.

      :return: integer containing the value of the red component.
      :rtype: int

   .. include:: /_include/type-functions.rst
