#include "obstacle.h"
#include "bird.h"
#include <cmath>
#include <cstdio>

double obstacle::getx() {
    return x;
}

double obstacle::gethole() {
    return hole;
}

double obstacle::gethole_lower() {
    return lower;
}

double obstacle::gethole_upper() {
    return upper;
}

bool obstacle::getpass() {
    return pass;
}

void obstacle::setx(double input_x){
    x = input_x;
}

void obstacle::sethole(double y){
    hole = y;
    upper = y+11;
    lower = y-3;
}

void obstacle::setpass(bool p){
    pass = p;
}

void obstacle::next() {
    x = x - o_velocity;
}


void obstacle::set_position(double s, double hole_y, double hole_height_y) {
    x = s;
    hole = hole_y;
}

bool obstacle::istouch(Bird B, int screen_N) {
    printf("checking\n");
    for (int i=0; i<=1; i++){
        for (int j=-5; j<=6; j++){
            for (int k=0; k<=lower; k++){
                if (((ceil(B.getx())+i) == (x+j)) and ((ceil(B.gety())-1) == k)){
                    //printf("1): %d %d %d up\n",i,j,k);
                    return true;
                }
            }
            for (int k=upper; k<screen_N; k++){
                if (((ceil(B.getx())+i) == (x+j)) and ((ceil(B.gety())+1) == k)){
                    //printf("1): %d %d %d down\n",i,j,k);
                    return true;
                }
            }
        }
    }
    for (int i=-3; i<=3; i++){
        if ((i != 0) and (i != 1)){
            for (int j=-5; j<=6; j++){
                for (int k=0; k<=lower+1; k++){
                    if (((ceil(B.getx())+i) == x+j) and (ceil(B.gety()) == k)){
                        //printf("2): %d %d %d up\n",i,j,k);
                        return true;
                    }
                }
                for (int k=upper; k<screen_N; k++){
                    if (((ceil(B.getx())+i) == x+j) and (ceil(B.gety()) == k)){
                        //printf("2): %d %d %d down\n",i,j,k);
                        return true;
                    }
                }
            }
        }
    }
    if (B.gety()<0 and ceil(B.getx())+3 == x-5){
        return true;
    }
    printf("checked, false");
    return false;
}

bool obstacle::ispassed(Bird B){
    if (ceil(B.getx()) >= ceil(x)){
        return true;
    }
    return false;
}
