#include <iostream>
#include <fstream>
#include "menu.h"
using namespace std;
void upd_ranking( int score){
        ofstream fout;
        fout.open("ranking.txt", ios::app);
        if (fout.fail()){
                cout<<"Error in file opening!!"<<endl;
                exit(1);
                }
        fout<<score<<endl;
        fout.close();
        }

void showranking(){
        ifstream fin;
        fin.open("ranking.txt");
        if (fin.fail()){
                cout<<"Error in file opening or ranking.txt does not exist!"<<endl;
                exit(1);
                }
        int score, count=0;
        while (fin >> score){
                count++;
                }
        fin.close();
        int * scorelist = new int[count];
        count=0;
        fin.open("ranking.txt");
        while (fin >> score){
                scorelist[count]=score;
                count++;
                }
        fin.close();
        //reraning the list
        int i, j, idx;
        int max;
        for ( i=0; i<count; i++){
                max=scorelist[i];
                idx=i;
                for (j=i+1;j<count; j++){
                        if (scorelist[j] >max){
                                max= scorelist[j];
                                idx = j;
                                }
                }
                if (idx != i)
                        swap( scorelist[i], scorelist[idx]);
        }
        cout<<"Leaderboard:"<<endl;
        for (int index=0; index<count && index<10; index++){
                cout<<index+1<<": "<<scorelist[index]<<endl;
                }
        delete [] scorelist;
        }
void print_caidan(){
        cout<<"       PLAY FLAPPY BIRD!!!  "<<endl;
        cout<<"Enter 1 to record your latest score!"<<endl;
        cout<<"Enter 2 to show the leaderborad!"<<endl;
        cout<<"Enter 3 to reset the leaderborad!"<<endl;
        cout<<"Enter 4 to START THE GAME!!!!"<<endl;
        }
