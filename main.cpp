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
        clear_screen();
        for (int i=0;i<=screen_N+4;i++){
                for (int j=0;j<=screen_M;j++){
                        putchar(' ');
                }
                putchar('\n');
        }
        clear_screen();
        cout<<"PLAY FLAPPY BIRD!!!"<<endl;
        cout<<"Welcome to flappy bird, this game is made by Jason Mak, (to be filled)"<<endl;
        cout<<"How to play: (to be edited)"<<endl;
        cout<<"\nIMPORTANT: please fullscreen your console";
        wait_to_enter();
        srand(time(0));
        char option = '0';
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
                                if (score==-1){
                                        break;
                                }
                                else if (score==0){
                                        wait_to_enter();
                                        break;
                                }
                                cout<<"\nPlease enter your username (do NOT include space):";
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
