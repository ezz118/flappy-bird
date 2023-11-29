#ifndef STARTGAME_H
#define STARTGAME_H
#include "bird.h"

const int screen_N=35;//size of the screen
const int screen_M=100;

//for initializing the game, e.g. new a bird
Bird* init_game(void);

// print the screen
void print_screen(void);

//to move a bird；
//input the user-defined type Bird
void move_bird(Bird &B);

//to move all the obstacles, which are store in STL_list, also delete the obstacles that are out
void move_obstacles(void);

//to check if the bird hit an obstacle; and check if the bird pass an obstacle
//input bird type parameters and the current score
bool check_fail(Bird B, int &score);

//check if an obstacle will be added now
//input t is the time (or the distance from the right-most edge of the screen) that the previous obsatcle appears
bool check_new_ob(int t);

//make an ob and push_back into the list
void add_ob(void);

//add the bird to screen
//input the bird type parameters
void add_bird_to_screen(Bird B);

//add the obstacles to screen
void add_ob_to_screen(void);

//to start the game
int startgame(void);

//to indicate the bird falling when it hits the obstacle
//input the bird type parameters
void bird_fall(Bird B);

//to initialize all the entries in screen to be ' '
void init_screen(void);

//to pause the game
bool game_pause(void);

#endif
