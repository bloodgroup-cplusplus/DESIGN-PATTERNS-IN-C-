#include<ApplicationServices/ApplicationServices.h>
#include<unistd.h>
#include<string>
vo

int main()
{
    CGEventSourceRef source = CGEventSourceCreate(kCGEventSourceStateCombinedSessionState);
    CGEventRef mouse = CGEventCreateMouseEvent (NULL, kCGEventMouseMoved, CGPointMake( 100,200), 0);
	kCGEventMouseMoved(



}

