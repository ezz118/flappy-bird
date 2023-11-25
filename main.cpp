#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "menu.h"
#include "startgame.h"
using namespace std;
int main(){
        srand(time(0));
        print_menu();
        int option=0;
        string name;
        while (option != 4){
                cin>>option;
                switch (option){
                        case 1:
                                int score;
                                score=startgame();
                                cout<<"Enter your username:"<<endl;
                                cin>>name;
                                upd_ranking(score, name);
                                cout<<"The latest score has been recorded!"<<endl;
                                break;
                        case 2: showranking(); break;
                        case 3:
                                remove("ranking.txt");
                                cout<<"The leaderboard has been reseted!"<<endl;
                                break;
                        case 4: break;
                        default: cout<<"Invalid input."<<endl;
                }
        }
        return 0;
}
