#ifndef STARTGAME_H
#define STARTGAME_H
#include "bird.h"

const int screen_N=35;//size of the screen
const int screen_M=100;

Bird* init_game(void);//for initializing the game, e.g. new a bird

void print_screen(void);//to print the screen

void move_bird(Bird &B);//to move a bird

void move_obstacles(void);//to move all the obstacles, which are store in STL_list, also delete the obstacles that are out

bool check_fail(Bird B, int &score);//to check if the bird hit an obstacle; and check if the bird pass an obstacle

double normal_distribution(int a, int b, double mean, double std);//to generate a random number from normal distribution

bool check_new_ob(int t);//check if an obstacle will be added now

void add_ob(void);//make an ob and push_back into the list

void add_bird_to_screen(Bird B);//add the bird to screen

void add_ob_to_screen(void);//add the obstacles to screen

int startgame();//to start the game

void bird_fall(Bird B);//to show the bird falling when it hits the obstacle

void init_screen(void);//to initialize all the entries in screen to be ' '

bool check_new_ob(int t);//judge whether to add a new obstacle

void game_pause(void);//to pause the game

#endif
