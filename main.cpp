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
        cout<<"PLAY FLAPPY BIRD!!!"<<endl;
        cout<<"Welcome to flappy bird, this game is made by"<<endl;
        cout<<"How to play: (to be edited)"<<endl;
        cout<<"\nIMPORTANT: please fullscreen your console\n\n";
        wait_to_enter();
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
