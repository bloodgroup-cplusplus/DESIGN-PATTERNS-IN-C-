#include<iostream>
#include<windows.h>


void set_cursor(int, int)
{
	HANDLE handle;
	COORD coordinates;
	handle=GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X=x;
	coordinates.Y=y;
	SetConsoleCursorPosition(handle,coordinates);
}


int main()
{
	int x=0,y=0;
	set_cursor(x,y);
	return 0;
}



