/* The factory methods an interface for creating an object, but
 * let subclasses decide which class to instatntiate.
 * Factory methods lets class defer instantiation to subclasses.
 * 
 * if oyu have a class that has a method and that needs instance of another 
 * this is a mechansims by which we create instance of other classes
 * whenever you want to create instance of differnt class/
 *
 *
 */

/* IMPLEMENTATION 
 * Different ways to implement
 * An overridable method is provided that returns instance of a class
 * This method can be overridden to return instance of subclass
 * Behaves like a constructor
 * However, a constructor always returns the same instance;
 * factory method can return instance of any sub-type
 * consequently, facotry method is also called .0
 */


class Product
{
    public:
        virtual void Operation () =0;
        virtual ~Product() = default;
};


void ConcreteProduct::Operation()
{
    std::cout << __FUNCSIG__<<std::cout;
    erturn 
