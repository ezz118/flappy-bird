#include <iostream>
#include <cstdio>
#include <list>
//include "screen.h"
//include "bird.h"
//include "obstacle.h"

const int screen_N=40;//size of the screen
const int screen_M=80;
const int sleep_time=50000;

void clear_screen();//to clear screen

int kbhit();//to check if the keyboard is hit

class bird{};//for compilation, will delete this line when bird.h is done
class obstacle{};//the same

char screen[screen_N][screen_M];
list<obstacle> O; //to define the a list of obstacle

bird init(void);//for initializing the game, e.g. new a bird
void print_screen(void);//to print the screen

void move_bird(bird &B);//to move a bird

void move_obstacles(void);//to move all the obstacles, which are store in STL_list, also delete the obstacles that are out

bool check_fail(bird B, int &score);//to check if the bird hit an obstacle; and check if the bird pass an obstacle

bool check_new_ob(int t);//check if an obstacle will be added now

void add_ob(void);//make an ob and push_back into the list

void add_bird_to_screen(bird B);//add the bird to screen

void add_ob_to_screen(void);//add the obstacles to screen

void move_bird(bird &B){
    //bird.next();
    return;
}

int startgame(){//will be renamed startgame
    bird B = init();
    print_screen();
    while (1){
        if (kbhit()){
            break;
        }
        usleep(sleep_time);
    }
    int t=0;
    int score=0;
    while (1){
        move_bird(B);
        move_obstacles();

        if (check_fail(B,score)){
            break;
        }

        if (check_new_ob(t)){
            add_ob();
            t=0;
        }

        add_bird_to_screen(B);
        add_ob_to_screen();
        print_screen();

        if (kbhit()){
            //B.jump();
        }
        
        usleep(sleep_time);
        t+=1;
    }
    return score;
}
