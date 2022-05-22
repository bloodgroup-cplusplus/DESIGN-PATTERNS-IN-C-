/* dependency inversion principle is split into two differnt ideas
 * high level modules shouldn't depend on the low level modules 
 * instead both should depend on abstractions
 * Abstractions shouldn't depend on details rather details should depend on abstractions
 * You don't want to depend on the concrete type more than you need to 
 * We have abstractions in the first place so that we can chnage the underlying principle 
 * Never depend on anything concrete, only depend on abstractions
 * High level modules should not depend on low level modules. They should depend on abstractions. 
 * Able to change an implementation easily without altering the high level code 
 */

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<fstream>
#include<tuple>


/* A. High -level modules should not depend on low-level modules. 
 * Both should depend on abstractions. 
 
 * B. Abstractions should not depend on details Details should depend on abstractions
 */

enum class Relationship
{
    parent, 
    child, 
    sibling
};



struct Person 
{
    string name; 
};

// how to fix the situation of some chnanges by low-level 
// is by introducing an interface 

// moving something into a low-level module and moving it into abstraction module 

struct RelationshipBrowser
{
    virtual std::vector<Person> find_all_children_of(const string &name) = 0;
};

struct Relationships  // low-level 
{
    // we have a vector of tuples and inside the tuple we have two people and 
    // relationships 

    std::vector<tuple<Person, Relationship, Person >> relations;


    void add_parent_and_child( const Person & parent, const Person & child)
    {
        relations.push_back({parent, Relationships::parent, child});
        relations.push_back({child, Relationships::child, parent});


    }

    std::vector<Person> find_all_children_of(const string & name) override
    {
        std::vector<Person> result;
        for(auto && [first, rel,second]: relations)
        {
            if(first.name == "John" && rel == Relationship ::parent)
            {
               // std::cout<< "John has a child called " <<second.name <<std::endl;
               result.push_back(second);
            }
        }
    }
    return result;
};


// you want to have dependency on interfaces and don't start depnding on their details
//

struct Research // high-level 
// the worst thing to do here is to direct take dependency on a low level module 
// we have a high-level module that is going to depend on low level module 
// we should avoid doing 
// we see it on the definition of the principle 
{
   /* Research( Relationships & relationships)
    {
        auto & relations = relationships.relations;
        for( auto && [ first, rel, second]: relations)
        {
            if (first.name == "John" && rel == Relationship::parent)
            {
                std::cout<<"John has a child called " << second.name <<std::endl;
            }
        }
    }*/

    Research (RelationshipBrowser & browser)
    {
        for (auto & child :browser.find_all_children_of("John"))
        {
            std::cout<<"John has a child called "<<child.name<<std::endl;
        }
    }
};

int main()
{
    Person parent {"John"};
    Person child1 {"Chris"}, child2{"Matt"};
    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent,child2);

    Research _( relationships);
    
    //all good till here 
    //but what if the low level module decides to change the 
    //visibility of the member variable
