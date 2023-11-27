///menu.h
#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;

// a function to update the ranking list;
// input the score and the name of the player
void upd_ranking(int score, string name);

// a function to display the ranking list
void showranking(void);

// a function to print out the menu page
void print_menu(void);

// a function to pause and enter the next phase
void wait_to_enter(void);

// a function to end the game
void game_end(void);

#endif
