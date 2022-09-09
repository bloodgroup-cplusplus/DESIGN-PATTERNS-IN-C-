#include<ApplicationServices/ApplicationServices.h>
#include<unistd.h>
#include<iostream>
int main()
{
	NXPoint mouseWarpLocation= CGEventSourceCreate(100,100);
	CGEventSourceRef evscr= CGEventSourceCreate(kCGEventSourceStateCombinedSessionState);
	CGEventSourceSetLocalEventsSuppressionInterval(evsrc,0.0);
	CGWarpMouseCursorPosition(mouseWarpLocation);
	CGAssociateMouseAndMouseCursorPosition(1);
	CFRelease(evsrc);
}
