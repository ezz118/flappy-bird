#include <iostream>
#include <cstdio>
#include <list>
#include <cmath>
#include <random>
#include "interactive.h"
#include "bird.h"
#include "obstacle.h"
#include "startgame.h"

using namespace std;

char ob_left[]="\u2590";
char ob_right[]="\u258C";
char ob[]="\u2588";
char ground[]="\u2582";
int flap=0;//to record how long the bird has kept one gesture
int flaptime=3;//the time that the bird keep one gesture
int add_ob_time=screen_M/2; //set the initial time for adding an obstacle
double Left=(double)screen_M*4.0/10.0; //set the left boundary of the obstacle
double Right=(double)screen_M*6.5/10.0; //set the right boundary of the obstacle

char screen[screen_N][screen_M];
list <obstacle> O; //to define the a list of obstacle


int startgame(){//will be renamed startgame
    Bird* B = init_game();
    int score=0;
    print_screen();
    printf("\n Your score: %d\nPress space to start the game.\n", score);
    
    while (1){
        if (keyboard_hit()==' '){
            break;
        }
        wait_to_next();
    }
    
    int t=0;
    while (1){
        move_bird(*B);
        move_obstacles();

        if (check_new_ob(t)){
            add_ob();
            t=0;
        }
        
        init_screen();
        add_ob_to_screen();
        add_bird_to_screen(*B);
        print_screen();
        printf("\n Your score: %d\nPress q to pause the game.\n", score);

        if (check_fail(*B,score)){
            break;
        }

        char tmpc=keyboard_hit();
        if (tmpc==' '){
            B->jump();
        }
        else if (tmpc=='q' || tmpc=='Q'){
            game_pause();
        }

        wait_to_next();
        t+=1;
    }
    bird_fall(*B);
    delete B;
    printf("You fail! Your score is %d\n",score);
    return score;
}

void move_bird(Bird &B){
    B.next();
}

void move_obstacles(){
    for (int i=0; i < O.size(); i++){
        O.front().next();
        O.push_back(O.front());
        O.pop_front();
    }
}

void print_screen(void){
    clear_screen();
    for (int i=0; i < screen_N; i++){
        for (int j=0; j < screen_M; j++){
            if (screen[i][j]=='l'){
                printf("\033[1;32m%s\033[0m", ob_left);
            }
            else if (screen[i][j]=='r'){
                printf("\033[1;32m%s\033[0m", ob_right);
            }
            else if (screen[i][j]=='m'){
                printf("\033[1;32m%s\033[0m", ob);
            }
            else if (screen[i][j]=='g'){
                printf("%s", ground);
            }
            else if (screen[i][j]==' '){
                putchar(' ');
            }
            else{
                char tmp[2];
                tmp[0]=screen[i][j], tmp[1]='\0';
                printf("\033[1;33m%s\033[0m",tmp);
            }
        }
        putchar('\n');
    }
}

void add_bird_to_screen(Bird B){
    char up_wing, down_wing;
    if (flap < flaptime){
        up_wing = '\\';
        down_wing = '/';
        flap+=1;
    }
    else{
        up_wing = '/';
        down_wing = '\\';
        flap+=1;
        if (flap == 2*flaptime - 1){
            flap = 0;
        }
    }
    int x=ceil(B.getx());
    int y=ceil(B.gety());
    if ((y-1)>=0 and (y-1)<screen_N){
        if ((x+1)>=0 and (x+1)<screen_M){
            screen[y-1][x+1]=up_wing;
        }
        if (x>=0 and x<screen_M){
            screen[y-1][x]=up_wing;
        }
    }
    if (y>=0 and y<screen_N){
        for (int i=x-3; i <=x+1; i+=2){
            if (i>=0 and i<screen_M){
                screen[y][i]='[';
            }
        }
        for (int i=x-2; i<=x+2; i+=2){
            if (i>=0 and i<screen_M){
                screen[y][i]=']';
            }
        }
        if ((x+3)>=0 and (x+3)<screen_M){
            screen[y][x+3]='>';
        }
    }
    if ((y+1)>=0 and (y+1)<screen_N){
        if ((x+1)>=0 and (x+1)<screen_M){
            screen[y+1][x+1]=down_wing;
        }
        if (x>=0 and x<screen_M){
            screen[y+1][x]=down_wing;
        }
    }

}

void add_ob_to_screen(void){
    for (int i=0; i<O.size(); i++){
        int x=ceil(O.front().getx());
        int y_lower=ceil(O.front().gethole_lower());
        int y_upper=ceil(O.front().gethole_upper());
        for (int i=x-5; i<=x+6; i++){
            for (int j=0; j<screen_N; j++){
                if ((i>=0 and i<screen_M) and (j<=y_lower or j>=y_upper)){
                    if (i == x-5){
                        screen[j][i]='l';
                    }
                    if (i == x+6){
                        screen[j][i]='r';
                    }
                    else{
                        screen[j][i]='m';
                    }
                }
            }
        }
        O.push_back(O.front());
        O.pop_front();
    }
}

void add_ob(void){
    //std::random_device rd;
    //std::mt19937 gen(rd());
    //std::uniform_real_distribution<double> dis2(4.0, double(screen_N-15));
   // double ran_hole=dis2(gen);
    int ran_hole = rand()%(screen_N-15-4)+4;

    obstacle new_o;
    new_o.setx(screen_M);
    new_o.sethole(ran_hole);
    new_o.setpass(false);
    O.push_back(new_o);
}


bool check_new_ob(int t){
    if (t==0) {
        int L=int(Left);
        int R=int(Right);
        add_ob_time = rand()%(R-L+1)+L;
        return false;
    }

    else {
        if (t == add_ob_time){
            return true;
        }
        else{
            return false;
        }
    }

}

bool check_fail(Bird B, int &score){
    for (int i=0; i<O.size(); ++i){
        if (O.front().istouch(B, screen_N)){
            return true;
        }
        if (O.front().getpass()== false and O.front().ispassed(B)){
            O.front().setpass(true);
            score+=1;
        }
        O.push_back(O.front());
        O.pop_front();
    }
    if (B.gety() >= screen_N){
        return true;
    }
    return false;
}

void bird_fall(Bird B){
    for (int i=1;i<=10;i++){
        wait_to_next();
    }
    B.setv(-jump_velocity);
    while ((ceil(B.gety()) + 2) <  screen_N){
        //B.sety(B.gety() - B.getv());
        B.next();
        init_screen();
        add_ob_to_screen();
        add_bird_to_screen(B);
        print_screen();
        wait_to_next();
    }
    B.sety(double(screen_N-2));
    init_screen();
    add_ob_to_screen();
    add_bird_to_screen(B);
    print_screen();
    for (int i=0;i<=4;i++){
        for (int j=0;j<=screen_M;j++){
            putchar(' ');
        }
        putchar('\n');
    }
    print_screen();
    return;
}

void init_screen(){
    for (int i=0; i<screen_M; ++i){
        for (int j=0; j<screen_N-1; ++j){
            screen[j][i] = ' ';
        }
        screen[screen_N-1][i]='g';
    }
}

Bird* init_game(){
    O.clear();
    init_screen();

    Bird* B = new Bird;
    B->sety(screen_N/2);
    B->setv(0);
    add_ob();
    add_bird_to_screen(*B);
    add_ob_to_screen();

    return B;
}

void game_pause(){
    printf("\n Game paused. Press SPACE to resume the game.\n");
    while (1){
        if (keyboard_hit()==' '){
            break;
        }
        wait_to_next();
    }
    return;
}