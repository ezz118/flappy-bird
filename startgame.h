#ifndef STARTGAME_H
#define STARTGAME_H
#include "bird.h"

const int screen_N=35;//size of the screen
const int screen_M=100;

//for initializing the setting game, e.g. new a bird 
Bird* init_game(void);

//to print the screen
void print_screen(void);

//to move a bird；
//input the user-defined type Bird
void move_bird(Bird &B);

//to move all the obstacles, which are store in STL_list
void move_obstacles(void);

//to check if the bird hit an obstacle; and check if the bird pass an obstacle; also delete the obstacles that are out
//input bird type parameters and the current score
//output a bool type, true for hitting the obstacle;
bool check_fail(Bird B, int &score);

//check if an obstacle will be added now
//input t is the time (or the distance from the right-most edge of the screen) that the previous obsatcle appears
//output a bool type, true for adding an obstacle
bool check_new_ob(int t);

//make an ob and push_back into the list
void add_ob(void);

//add the bird to the array screen
//input the bird type parameters
void add_bird_to_screen(Bird B);

//add the obstacles to the array screen
void add_ob_to_screen(void);

//to start the game
int startgame(void);

//to indicate the bird falling when it hits the obstacle
//input the bird type parameters
void bird_fall(Bird B);

//to initialize all the entries in the array screen
void init_screen(void);

//to pause the game, return true if the user command to return to the main menu
bool game_pause(void);

#endif
