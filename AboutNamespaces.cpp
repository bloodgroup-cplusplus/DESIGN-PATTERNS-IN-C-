// A namespace is a declarative region that provides a scope to the identifiers
// Namespaces are used to organize code into logical groups
// and to prevent name collisons that can occur especially when your code  base
// includes multiple libraries. 
//  All identifiers are namespace scope are visible to one another without qualification
//  Identifiers outside the namespace can access the members by using the fully qualified name for each identifier
//  the following example shows a namespace declaration and three ways that code outside the namespace can accesses their names


namespace ContosoData
{
    class ObjectManager
    {
        public:
            void DoSomething () {}
    };

    void Func( ObjectManager) {}
}


// use the fully qualified name 
//

ContosoData::ObjectManager mgr;
mgr.DoSomething();
ContosoData::Func(mgr);

// use a using declaration to bring one identifier into scope:

using ContosoData::ObjectManager;
ObjectManager mgr;
mgr.DoSomething();

// use a using directive to bring everything in the namespace into scope.

using namespace ContosoData;
ObjectManager mgr;
mgr.DoSomething();
Func(mgr);


