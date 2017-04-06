.. attribute:: clientInfo

   A Lua table that can be used to store arbitrary data associated with the current object.

   .. code-block:: lua
      :caption: Example usage

      obj.clientInfo["test"] = 5
      print(obj.clientInfo["test"]) -- prints "5"

   .. seealso::
      :ref:`The differences between the C++ and Lua implementations <differences-clientInfo>`
