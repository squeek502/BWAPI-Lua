.. method:: iterator() -> iteratorFunction

   Returns `an iterator function <https://www.lua.org/pil/7.1.html>`_ intended to be used in ``for`` loops (e.g. ``for item in set:iterator() do``).

   :return: `An iterator function <https://www.lua.org/pil/7.1.html>`_ that will return the next value in the set with each successive call.
   :rtype: function

.. method:: asTable() -> table

   Returns the values of the set as an array-like Lua table.

   .. note::
      The ordering of the returned table is arbitrary (due to sets being unordered in the C++ implementation).

   :return: An array-like Lua table containing each value in the set.
   :rtype: table

.. method:: count(val) -> int

   Searches the set for elements with a value of ``val`` and returns the number of elements found. Because sets do not allow for duplicate values, this means that the function will return either ``1`` or ``0``. Because of this, it's recommended to use :meth:`contains` instead.

   .. seealso::
      :meth:`contains`, `std::unordered_set::count <http://www.cplusplus.com/reference/unordered_set/unordered_set/count/>`_

.. method:: contains(val) -> boolean

   Checks if this set contains a specific value.

   :return: ``true`` if the set contains the specified value, or ``false`` otherwise.
   :rtype: boolean

.. method:: size() -> int

   :return: The number of values in the set.
   :rtype: int

   .. note::
      ``set:size()`` is exactly equivalent to ``#set``

.. method:: empty() -> boolean

   :return: ``true`` if the set is empty (``size() == 0``), or ``false`` otherwise.
   :rtype: boolean

.. method:: insert(val)

   Inserts the value into the set.

   .. note::
      Sets cannot contain duplicate values. If the value already exists in the set, the set will not be modified.

.. method:: erase(val) -> numElementsErased

   Removes ``val`` from the set if it exists.

   :return: The number of elements removed. Because sets do not allow for duplicate values, this means that the function will return either ``1`` or ``0``.
   :rtype: int

.. method:: clear()

   Removes all elements from the set, leaving it with a size of 0.

.. method:: eraseIf(pred)

   Iterates the set and erases each element x where pred(x) returns true. The set is modified in place.

   :param function pred: A predicate function that takes a value and returns ``true`` for values that should be erased and ``false`` otherwise.

.. method:: erase_if(pred)

   Alias of :meth:`eraseIf`

.. method:: filter(pred)

   Iterates the set and erases each element x where pred(x) returns false. The set is modified in place.

   :param function pred: A predicate function that takes a value and returns ``true`` for values that should be kept and ``false`` for elements that should be erased.

.. method:: keepIf(pred)

   Alias of :meth:`filter`/:meth:`keep_if`

.. method:: keep_if(pred)

   Alias of :meth:`filter`/:meth:`keepIf`
