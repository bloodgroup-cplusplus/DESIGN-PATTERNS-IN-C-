#include<iostream>

/* Let's learn about the important concepts of the C++ world that are going to
 * be refrenced in this book.
 * the first pattern in Curiously Recuring Template Pattern
 * the idea is simple. an inheritor passes itself as a template argument to its base class:
 */


//struct Foo: SomeBase<Foo> 2
//{
 //   ....
//}




/* why one would ever do that? one reason is to be able to access a typed 
 * this pointer inside a base class implementation.
 * for example suppose every single inheritor of SomeBase implements a 
 * being()/end() pair required for iteration 
 */


template<typename T>

class Base
{


    ....
};


class Derived : public Base<Derived>
{

    ....
};


/* the purpose of doing this is using the derived class in the base class .
 * From the perspective of the base object, the derived object is itself, but downcasted
 * Therefore the base class can acess the derived class by static_casting itself into the derived class.
 */

template<typename T>
class Base
{
    public:
        void doSomething()
        {
            T &derived = std::static_cast<T&>(*this);
            use derived;
        }
};
//Note that contrary to typical casts to derived class, we don't use dynamic_cat here.
/*A dynamic_cast is used when you want to make sure at run-time that the derived class you are
 * casting into is the correct one.
 * But here we don't need this guarantee:
 * The base class is designed to be inherited from by its template parameter,
 * and by nothing else.
 */

/* what could go wrong 
 * if two classes happen to derive from the same CRTP base class we likely get 
 * to undefined behaviour when the CRTP will try to use the wrong class
 */

class Derived1 : public Base<Derived1>
{
    ...
};


class Derived2: public Base<Derived> // we have a bug in this line of code 
{
    ...
};

//How to solve this solution . 
//There is a solution to prevent this, propsed by Marek Kurdej
//
