#include <iostream>
#include <cstdio>
#include <list>
#include <cmath>
#include <random>
#include "interactive.h"
//include "screen.h"
#include "bird.h"
#include "obstacle.h"

const int screen_N=40;//size of the screen
const int screen_M=80;
const int sleep_time=50000;
bool flapped=true;


char screen[screen_N][screen_M];
list<obstacle> O; //to define the a list of obstacle


int startgame(){//will be renamed startgame
    bird B = init();
    print_screen();
    while (1){
        if (keyboard_hit()){
            break;
        }
        usleep(sleep_time);
    }
    int t=0;
    int score=0;
    while (1){
        move_bird(B);
        move_obstacles();

        if (check_fail(B,score)){
            break;
        }

        if (check_new_ob(t)){
            add_ob();
            t=0;
        }

        add_bird_to_screen(B);
        add_ob_to_screen();
        print_screen();

        if (keyboard_hit()){
            //B.jump();
        }
        
        usleep(sleep_time);
        t+=1;
    }
    return score;
}

void move_bird(bird &B){
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
    for (int i=0; i < screen_N; i++){
        for (int j=0; j < screen_M; j++){
            putchar(screen[i][j]);
        }
        putchar('\n');
    }
}

void add_bird_to_screen(bird B){
    char up_wing, down_wing;
    if (flapped == true){
        up_wing = '\\';
        down_wing = '/';
        flapped = false;
    }
    else{
        up_wing = '/';
        down_wing = '\\';
        flapped = true;
    }
    int x=ceil(B.x);
    int y=ceil(B.y);
    if ((y-1)>=0 and (y-1)<screen_N){
        if ((x+1)>=0 and (x+1)<screen_M){
            screen[y+1][x+1]=up_wing;
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
        int x=ceil(O.front().x);
        int y=ceil(O.front().hole);
        for (int i=x-5; i<=x+6; i++){
            for (int j=0; j<screen_N; j++){
                if ((i>=0 and i<screen_M) and (j<y or j>=y+9)){
                    screen[j][i]=char(219);
                }
            }
        }
        O.push_back(O.front());
        O.pop_front();
    }
}

void add_ob(void){
    double max=O.front().x;
    for (int i=0; i<O.size(); i++){
        if (O.front().x > max){
            max=O.front().x;
        }
        O.push_back(O.front());
        O.pop_front();
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis1(max+26.0, double(screen_M+4));
    double ran_x=dis1(gen);
    std::uniform_real_distribution<double> dis2(4.0, double(screen_N-15));
    double ran_hole=dis2(gen);
    obstacle new_o;
    new_o.x=ran_x;
    new_o.hole=ran_hole;
    O.push_back(new_o);
}

bool check_fail(bird B, int &score){
    for (int i=0; i<O.size(); ++i){
        if (O.front().istouch()){
            return true;
        }
        if (O.front().pass == false and O.ispassed()){
            O.front().pass = true;
            score+=1;
        }
        O.push_back(O.front());
        O.pop_front();
    }
    if (B.y >= screen_N){
        return true;
    }
}
