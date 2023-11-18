#include <iostream>
#include <cstdio>
#include <fstream>
#include "menu.h"
using namespace std;
int main(){
        print_caidan();
        int option=0;
        while (option != 4){
        cin>>option;
        switch (option){
                case 1:
                        int score; cin>>score; //现在没有score，所以测试时要手动输入score
                        upd_ranking(score);
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
