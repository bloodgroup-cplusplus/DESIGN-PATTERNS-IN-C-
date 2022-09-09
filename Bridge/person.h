#ifndef PERSON_H
#define PERSON_H
#include<string>


class Person
{
public:
    Person();
    ~Person();
    std::string name ;
    class PersonImpl;
    PersonImpl *impl;

    void greet();
    // the idea of pimpl idom is that implementation details are relayed, bridged into a
    // seperate class
    // we have inner class
};

#endif // PERSON_H
