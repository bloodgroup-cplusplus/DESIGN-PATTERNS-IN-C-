#include<iostream>
#include<ApplicationServices/ApplicationServices.h>
#include<iostream>


int main()
{
	CGPoint myPoint = CGPointMake(34,342);
    typedef uint32_t CGDirectDisplayID;
    CGDirectDisplayID display_id=CGMainDisplayID();
	std::cout<<display_id<<std::endl;
    CGDisplayMoveCursorToPoint(display_id,myPoint);
	return 0;
}


