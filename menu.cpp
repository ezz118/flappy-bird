#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"
#include "interactive.h"

using namespace std;

void upd_ranking( int score, string name){
        ofstream fout;
        fout.open("ranking.txt", ios::app);
        if (fout.fail()){
                cout<<"Error in file opening!!"<<endl;
                exit(1);
        }
        fout<<name<<"&"<<score<<endl;
        fout.close();
}

void showranking(){   //待改
        ifstream fin;
        fin.open("ranking.txt"); // File input/output
        if (fin.fail()){
                cout<<"Error in file opening or there is no ranking!"<<endl;
                exit(1);
        }
        int count=0;
        string score;
        while (fin >> score){
                count++;
        }
        fin.close();
        //make a struct
        struct rank{
                string name;
                int scorenum;
        };
        rank * scorelist = new rank[count]; //Dynamic memory management
        count=0;
        fin.open("ranking.txt");
        while (fin >> score){
                int pos=0;
                pos = score.find("&");
                string scorenum;
                scorenum = score.substr(pos+1);
                int scoreNum = stoi(scorenum);
                scorelist[count].scorenum= scoreNum;
                string name;
                name = score.substr(0,pos);
                scorelist[count].name=name;
                count++;
        }
        fin.close();
        //rearranging the list
        int i, j, idx;
        int max;
        for ( i=0; i<count; i++){
                max=scorelist[i].scorenum;
                idx=i;
                for (j=i+1;j<count; j++){
                        if (scorelist[j].scorenum >max){
                                max= scorelist[j].scorenum;
                                idx = j;
                        }
                }
                if (idx != i)
                        swap( scorelist[i], scorelist[idx]);
        }
        cout<<"Leaderboard:"<<endl;
        for (int index=0; index<count && index<10; index++){
                cout<<index+1<<"、"<<scorelist[index].name<<": "<<scorelist[index].scorenum<<endl;
        }
        delete [] scorelist;
}

void print_menu(){
        //待改
        clear_screen();
        cout<<"       PLAY FLAPPY BIRD!!!  "<<endl;
        cout<<"Enter 1 to record your latest score!"<<endl;
        cout<<"Enter 2 to show the leaderborad!"<<endl;
        cout<<"Enter 3 to reset the leaderborad!"<<endl;
        cout<<"Enter 4 to START THE GAME!!!!"<<endl;
}
