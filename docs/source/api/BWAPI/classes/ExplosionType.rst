ExplosionType
*************

.. currentmodule:: BWAPI

.. class:: ExplosionType

   A representation of a weapon's explosion type.

   This indicates how the weapon behaves, such as if it deals splash damage or causes an effect to occur.

   .. seealso::
      :mod:`~BWAPI.ExplosionTypes`

   .. rubric:: Constructors

   .. method:: ExplosionType([id = ExplosionTypes.Enum.None])

      Expected type constructor.

      If the type is an invalid type, then it becomes ``Unknown``. A type is invalid if its value is less than 0 or greater than ``Unknown``.

      :param int id: The id that corresponds to this type. It is typically an integer value that corresponds to an internal Broodwar type. If the given id is invalid, then it becomes ``Unknown``.

   .. rubric:: Member Functions

   .. include:: /_include/type-functions.rst

ExplosionTypeset
****************

.. class:: ExplosionTypeset

   A container for a set of :class:`ExplosionType` objects.

   .. rubric:: Constructors

   .. method:: ExplosionTypeset()

      Default constructor.

   .. method:: ExplosionTypeset(set)

      Copy constructor.

      :param BWAPI.ExplosionTypeset set: The ExplosionTypeset to copy.

   .. method:: ExplosionTypeset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`ExplosionType` are added to the set.

      :param table tbl: A table containing :class:`ExplosionType` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
