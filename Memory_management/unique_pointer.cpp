/* No copy
 * Automatically deletes free store memory
 * put on the local stack 
 *
 * Data structure stored on stack
 *  OUt of scope ->delete pointer
 *  Moveable -> can create and return unique_ptr
 *  Not copyable -> wee need to deep copy
 *  Clear ownership -> Clear code
 *  Very small overhead -> Fast
 *  creating a unique pointer 
 *  std::make_unique<T>
 *  Constructor 
 *  .reset(T*ptr)
 *
 *
 *  Creating a Unique Pointer 
 *      std::make_unique
 *      Bset wy to create unique pointe r
 *      std::unique_ptr<foo> a = std::make_unique<foo>();
 *      Creates object of type foo( default constructor) on free store and stores in 
 *      unique pointer
 *
 *  std::unique_ptr<foo> a = std::unique_ptr<foo> (3.141,bar);
 *      Creates object of type foo on free store, passing in 3.141 and bar
 *      to constructor, and stores in unique pointer 
 *
 *  Only available since C++14, compiler may not support it yet
 *
