### Singleton

Singleton is a creational pattern that ensures a class has only one instance and provides a global point of access to it.

## Key Concepts:

* Restricts object creation → Prevents multiple instances of the class.

* Global access → Other parts of the code can access it via getInstance().

* Lazy initialization → The instance is created only when first needed.

Singleton is often criticized for introducing hidden global state, which can make testing more difficult.
