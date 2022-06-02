#include<iostream>

class Foo
{};


class Bar
{
    private:
        Foo *m_foo;


    public:
        Bar()
        {
            m_foo = new Foo();
            std::cout<<"Creating Bar at"<<this<<std::endl;
        }

        ~Bar()
        {
            delete m_foo;
            std::cout<<"Destructing Bar at"<<this<<std::endl;
        }

};


int main(int argc, const char * argv[])
{
    Bar original;

    Bar copy = original; 
    // the original contains the pointer 
    // the copy contains the same pointer 
    // when the function ends the copy is going to go out of stop
    // when the function ends the copy is going to go out of scope 
    // It is going to delete the foo pointer
    // the original is going to go out of scope
    // we call delete twice on the same memory
    // we have violated the rule of three
    // if you need to implemented a destructor
    // then you also have to implement a copy constructor and copy assignment operator 
    // in the following section we are going to see classes which manages 

    return 0;
}


