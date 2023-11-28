#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"
#include "interactive.h"
#include "startgame.h"

using namespace std;


//make a struct
struct Rank{
        string name;
        int scorenum;
};

void upd_ranking( int newscore, string newname){
        ifstream fin;
        fin.open("ranking.txt");
        Rank scorelist[11];
        string score;
        int count=0;
        bool flag=0;
        while (fin >> score){
                int pos=0;
                pos = score.find("&");
                string scorenum;
                scorenum = score.substr(pos+1);
                int scoreNum = stoi(scorenum);
                string name;
                name = score.substr(0,pos);
                if (newscore>scoreNum){
                        scorelist[count].scorenum=newscore;
                        scorelist[count].name=newname;
                        count+=1;
                        if (count==10){
                                break;
                        }
                        newscore=-1;
                        flag=1;
                }
                scorelist[count].scorenum=scoreNum;
                scorelist[count].name=name;
                count++;
                if (count==10){
                        break;
                }
        }
        if (count<9){
                scorelist[count].scorenum=newscore;
                scorelist[count].name=newname;
                count+=1;
                newscore=-1;
                flag=1;
        }
        ofstream fout;
        fout.open("ranking.txt");
        if (fout.fail()){
                cout<<"Error in file opening!!"<<endl;
                exit(1);
        }
        for (int i=0;i<(count<10?count:10);i++){
                fout<<scorelist[i].name<<"&"<<scorelist[i].scorenum<<endl;
        }
        fout.close();
        if (flag){
                cout<<"Congratulation, you enter the leaderboard!\n";
                showranking();
                return;
        }
        cout<<"The latest score has been recorded!"<<endl;
        wait_to_enter();
}

void showranking(){
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
        if (count==0){
                printf("\nThe list is empty.\n\n");
                wait_to_enter();
                return;
        }
        struct Rank * scorelist = new Rank[count]; //Dynamic memory management
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
        cout<<endl;
        cout<<"\n Leaderboard:"<<endl;
        for (int index=0; index<count && index<10; index++){
                cout<<index+1<<"  "<<scorelist[index].name<<": "<<scorelist[index].scorenum<<endl;
        }
        delete [] scorelist;
        wait_to_enter();
}

void print_menu(){
        clear_screen();
        for (int i=0;i<=screen_N+4;i++){
                for (int j=0;j<=screen_M;j++){
                        putchar(' ');
                }
                putchar('\n');
        }
        clear_screen();
        cout<<"       PLAY FLAPPY BIRD!!!  "<<endl;
        cout<<"  Press 1 to start the game!"<<endl;
        cout<<"Press 2 to show the leaderboard!"<<endl;
        cout<<"        Press 3 to quit"<<endl;
}

void wait_to_enter(){
        for (int i=1;i<=15;i++){
                wait_to_next();
        }
        cout<<"\nPress SPACE to go to the main menu or Q to quit the game\n";
        char ch=keyboard_hit();
        while (ch!=' ' && ch!='q' && ch!='Q'){
                wait_to_next();
                ch=keyboard_hit();
        }
        if (ch==' '){
                return;
        }
        else{
                game_end();
        }
}

void game_end(){
        cout<<endl;
        cout<<"\nGame ended!"<<endl;
        for (int i=1;i<=15;i++){
                wait_to_next();
        }
        exit(0);
}
