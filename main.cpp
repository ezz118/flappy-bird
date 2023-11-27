#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <ctime>
#include "menu.h"
#include "startgame.h"
#include "interactive.h"
using namespace std;

int main(){
        srand(time(0));
        char option;
        string name;
        while (option != 4){
                print_menu();
                option=keyboard_hit();
                while (option=='\0'){
                        wait_to_next();
                        option=keyboard_hit();
                }
                switch (option){
                        case '1':
                                int score;
                                score=startgame();
                                cout<<"\nPlease enter your username:";
                                cin>>name;
                                upd_ranking(score, name);
                                break;
                        case '2': 
                                showranking(); 
                                break;
                        case '3':
                                game_end();
                                break;
                        default: 
                                break;
                }
        }
        return 0;
}
