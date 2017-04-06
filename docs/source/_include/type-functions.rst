.. method:: getID() -> int

   Retrieves this type's identifier as an integer.

   :return: An integer representation of this type.
   :rtype: int

.. method:: isValid() -> boolean

   Checks if the current type has a valid identifier. The purpose of this function is to prevent buffer overflows if a type has been handled improperly.

   A type is valid if it is between 0 and Unknown (inclusive).

   :return: ``true`` if this type is valid and ``false`` otherwise.
   :rtype: boolean

.. method:: getName() -> string

   :return: The variable name of the type.
   :rtype: string
