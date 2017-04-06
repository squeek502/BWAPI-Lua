Bulletset
*********

.. currentmodule:: BWAPI

.. class:: Bulletset

   A container for a set of :class:`Bullet` objects.

   .. rubric:: Constructors

   .. method:: Bulletset()

      Default constructor.

   .. method:: Bulletset(set)

      Copy constructor.

      :param BWAPI.Bulletset set: The Bulletset to copy.

   .. method:: Bulletset(tbl)

      Constructor to convert a Lua table to a set. Any values in the table that are of type :class:`Bullet` are added to the set.

      :param table tbl: A table containing :class:`Bullet` objects.

   .. rubric:: Member Functions

   .. include:: /_include/set-container-functions.rst
