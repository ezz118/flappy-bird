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
        cout<<"Welcome to Flappy Bird, this game is made by Jason Mak, Dacian Deng, Maggie Ke and Ruize Lai."<<endl;
        cout<<"How to play: Just press SPACE to make the descending bird fly upwards and fly between columns of green obstacles without hitting them!"<<endl;
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
                switch (option){   //different options in menu
                        case '1':
                                int score;
                                score=startgame();  //start the game and the startgame() function returns a score
                                if (score==-1){
                                        break;
                                }
                                else if (score==0){  //Not entering leaderboard
                                        wait_to_enter();
                                        break;
                                }
                                upd_ranking(score);  //update ranking
                                break;
                        case '2': 
                                showranking(); 
                                break;
                        case '3':
                                game_end();
                                break;
                        default:    //If the input is invalid, players need to input again.
                                break;
                }
        }
        return 0;
}
