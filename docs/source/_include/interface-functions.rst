.. method:: registerEvent(action, [condition = nil], [timesToRun = -1], [framesToCheck = 0])

   Registers an event and associates it with the current object.

   Events can be used to automate tasks (like train X Marines until Y of them have been created by the given Barracks) or to create user-defined callbacks.

   :param function action: The callback to be executed when the event conditions are true.
   :param function condition: (optional) The condition callback which will return true if the action is intended to be executed. The condition will always be true if omitted.
   :param int timesToRun: (optional) The number of times to execute the action before the event is removed. If the value is negative, then the event will never be removed. The value will be -1 if omitted, causing the event to execute until the game ends.
   :param int framesToCheck: (optional) The number of frames to skip between checks. If this value is 0, then a condition check is made once per frame. If this value is 1, then the condition for this event is only checked every other frame. This value is 0 by default, meaning the event's condition is checked every frame.
