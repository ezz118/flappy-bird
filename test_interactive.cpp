/*

This file is useless, just for testing the functions in interactive.cpp

*/


#include "interactive.h"
#include <cstdio>
#include <windows.h>

int main(){
    int a=0;
    while (1){
        printf("%d",a);
        Sleep(100);
	    if (keyboard_hit()){
            clear_screen();
            a+=1;
        }
    }
    return 0;
}