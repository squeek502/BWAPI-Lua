.. currentmodule:: BWAPI

Text
====

.. module:: BWAPI.Text

Contains enumeration of text formatting codes.

Such codes are used in calls to :meth:`BWAPI.Game.drawText`, :meth:`BWAPI.Game.printf`, and ``print``

.. important::
   Although the values are stored as a ``number`` type, they are most useful when printed as a character (which Lua does not have a type for; it only has ``string``). The necessary ``int`` to ``char`` conversion can be done using ``string.format`` or ``string.char`` like so:

   .. code-block:: lua

      local text = "Your string"
      -- using string.format
      local formatted1 = string.format("%c%s", BWAPI.Text.White, text)
      -- using string.char
      local formatted2 = string.char(BWAPI.Text.White) .. text
      -- these two techniques will result in exactly the same result
      assert(formatted1 == formatted2)

.. seealso::
   :meth:`BWAPI.Game.drawText`

Functions
---------

.. staticmethod:: isColor(c) -> bool

   Checks if the given character is a color-changing control code.

   :param number c: The ``BWAPI.Text`` constant to check
   :return: ``true`` if ``c`` is a regular color (not ``Previous``, ``Invisible*``, or ``Align*``)
   :rtype: boolean

Enum
----

.. data:: Previous

   Value of 1.

   Uses the previous color that was specified before the current one.

.. data:: Default

   Value of 2.

   Uses the default blueish color. This color is used in standard game messages.

.. data:: Yellow

   Value of 3.

   A solid yellow.

   This yellow is used in notifications and is also the default color when printing text to Broodwar.

.. data:: White

   Value of 4.

   A bright white. This is used for timers.

.. data:: Grey

   Value of 5.

   A dark grey. This color code will override all color formatting that follows.

.. data:: Red

   Value of 6.

   A deep red. This color code is used for error messages.

.. data:: Green

   Value of 7.

   A solid green. This color is used for sent messages and resource counters.

.. data:: BrightRed

   Value of 8.

   A type of red. This color is used to color the name of the red player.

.. data:: Invisible

   Value of 11.

   This code hides all text and formatting that follows.

.. data:: Blue

   Value of 14.

   A deep blue. This color is used to color the name of the blue player.

.. data:: Teal

   Value of 15.

   A teal color. This color is used to color the name of the teal player.

.. data:: Purple

   Value of 16.

   A deep purple. This color is used to color the name of the purple player.

.. data:: Orange

   Value of 17.

   A solid orange. This color is used to color the name of the orange player.

.. data:: Align_Right

   Value of 18.

   An alignment directive that aligns the text to the right side of the screen.

.. data:: Align_Center

   Value of 19.

   An alignment directive that aligns the text to the center of the screen.

.. data:: Invisible2

   Value of 20.

   This code hides all text and formatting that follows.

.. data:: Brown

   Value of 21.

   A dark brown. This color is used to color the name of the brown player.

.. data:: PlayerWhite

   Value of 22.

   A dirty white. This color is used to color the name of the white player.

.. data:: PlayerYellow

   Value of 23.

   A deep yellow. This color is used to color the name of the yellow player.

.. data:: DarkGreen

   Value of 24.

   A dark green. This color is used to color the name of the green player.

.. data:: LightYellow

   Value of 25.

   A bright yellow.

.. data:: Cyan

   Value of 26.

   A cyan color. Similar to Default.

.. data:: Tan

   Value of 27.

   A tan color.

.. data:: GreyBlue

   Value of 28.

   A dark blueish color.

.. data:: GreyGreen

   Value of 29.

   A type of Green.

.. data:: GreyCyan

   Value of 30.

   A different type of Cyan.

.. data:: Turquoise

   Value of 31.

   A bright blue color.


Text.Size
=========

.. module:: BWAPI.Text.Size

Enumeration of available text sizes.

.. seealso::
   :meth:`Game.setTextSize`

Enum
----

.. data:: Small

   Value of 0. The smallest text size in the game.

.. data:: Default

   Value of 1. The standard text size, used for most things in the game such as chat messages.

.. data:: Large

   Value of 2. A larger text size. This size is used for the in-game countdown timer seen in :attr:`Capture The Flag <BWAPI.GameTypes.Capture_The_Flag>` or :attr:`Use Map Settings <BWAPI.GameTypes.Use_Map_Settings>` game types.

.. data:: Huge

   Value of 3. The largest text size in the game.
