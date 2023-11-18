#include "interactive.h"

#ifdef __linux__ 

bool keyboard_hit(){
    return 0;
}

#elif _WIN32

#include<conio.h> 
#include<cstring>
#include<windows.h>

void clear_screen(){
	COORD CursorPosition;
	CursorPosition.X = 0; 
	CursorPosition.Y = 0; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition); 
}

bool keyboard_hit(){
    if (kbhit()){
        char key=getch();
        if (key==' '){
            return 1;
        }
    }
    return 0;
}

#endif