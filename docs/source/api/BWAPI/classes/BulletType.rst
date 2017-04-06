BulletType
**********

.. currentmodule:: BWAPI

.. class:: BulletType

   This class represents a type of bullet.

   .. note::
      Internally, these are the same IDs as flingy types in Broodwar.

   .. seealso::
      :mod:`~BWAPI.BulletTypes`

   .. rubric:: Constructors

   .. method:: BulletType([id = BulletTypes.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes :attr:`BulletTypes.Unknown`. A type is invalid if its value is less than 0 or greater than :attr:`BulletTypes.Unknown`.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes :attr:`BulletTypes.Unknown`.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

BulletTypeset
*************

.. class:: BulletTypeset

   A container for a set of :class:`BulletType` objects.

   .. rubric:: Constructors

   .. method:: BulletTypeset()

      Default constructor.

   .. method:: BulletTypeset(set)

      Copy constructor.

      :param BWAPI.BulletTypeset set: The BulletTypeset to copy.

   .. method:: BulletTypeset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`BulletType` are added to the set.

      :param table tbl: A table containing :class:`BulletType` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
