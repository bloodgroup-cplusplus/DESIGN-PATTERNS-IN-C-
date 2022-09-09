#include "person.h"
class Person::PersonImpl
{



Person::Person() : impl(new PersonImpl)
{
}

Person :: ~Person()
{
    delete impl;
}
