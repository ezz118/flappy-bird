#include <cstdio>
#include "interactive.h"

#ifdef __linux__ 

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

bool keyboard_hit(){
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF && ch==" "){
    	ungetc(ch, stdin);
    	return 1;
    }
    return 0;
}

void clear_screen(){
    printf("\x1B[2J\x1B[H");
    return;
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
