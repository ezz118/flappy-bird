#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <ctime>
#include "menu.h"
#include "startgame.h"
using namespace std;

int main(){
        srand(time(0));
        int option=0;
        string name;
        while (option != 4){
                print_menu();
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
                        case 2: 
                                showranking(); break;
                        default: 
                                cout<<"Invalid input."<<endl;
                }
        }
        return 0;
}
