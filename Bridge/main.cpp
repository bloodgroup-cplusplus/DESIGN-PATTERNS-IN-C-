#include <iostream>
// connecting components together thorugh Abstractions
/* MOTIVATION
 * Bridge prevents a 'Cartesian product' complexity explosion
 * Base class Thread Scheduler
 * Can be prremptive or cooperative
 * Can run on Window or unix
 * End up with a 2*2 scenario: Windows PTS, UNix PTS, WindowsCTS, Unix CTS
 * Bridge pattern avoids this entity explosion
 * A mechanism that decouples an interface(hierarchy) from an implemenation (hierarchy)
* pimpl idiom is a bridge
* /


int main()
{
   std:: cout << "Hello World!" << std::endl;
    return 0;
}
