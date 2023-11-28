#include <cstdio>
#include "interactive.h"

#ifdef __linux__ 

const int sleep_time=60000;

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

typedef struct termios T;

char keyboard_hit(){
    T oldt, newt;
    int c, oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    c = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(c != EOF){
        return c;
    }
    return '\0';
}

void clear_screen(){
    printf("\x1B[2J\x1B[H");
    return;
}

void wait_to_next(){
    usleep(sleep_time);
}

#elif _WIN32

const int sleep_time=40;

#include<conio.h> 
#include<cstring>
#include<windows.h>

void clear_screen(){
	COORD CursorPosition;
	CursorPosition.X = 0; 
	CursorPosition.Y = 0; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition); 
}

char keyboard_hit(){
    if (kbhit()){
        char key=getch();
        return key;
    }
    return '\0';
}

void wait_to_next(){
    Sleep(sleep_time);
}

#endif
