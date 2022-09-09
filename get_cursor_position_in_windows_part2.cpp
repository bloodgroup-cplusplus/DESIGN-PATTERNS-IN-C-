#include<windows.h>

int main()
{
	HANDLE hStdout;
	COORD destCoord;
	hStdout= GetStdHandle(STD_OUTPUT_HANDLE);

	// position cursor at start of window
	
	destCoord.X=0;
	destCoord.Y=0;
	SetConsoleCursorPosition(hStdout,destCoord);
}


