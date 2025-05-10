### Singleton

Command is a behavioral design pattern that allows you to encapsulate an action into a command object, so it can be executed later, stored, undone, or queued.

## Key Concepts:

* Encapsulation of actions → wraps an action (a function responsible for performing a task) into a separate object (a command – an instance of a Command class).

* Decoupling sender and receiver → the object that invokes the command doesn’t know how the action is implemented.

* Flexibility → makes it easy to implement action history, undo/redo functionality, and command queues.

Command increases the structural complexity of the code, but significantly improves the flexibility and scalability of the system.
