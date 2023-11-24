#include "obstacle.h"
#include "bird.h"
#include <cmath>

// get the position of the obstacle in the x direction
double obstacle::getx() {
    return x;
}

// get the position of the hole
double obstacle::gethole() {
    return hole;
}

// get the pass value
bool obstacle::getpass() {
    return pass;
}

// to set the x coordinate
void obstacle::setx(double input_x){
    x = input_x;
}

// to set the hole position
void obstacle::sethole(double y){
    hole = y;
}

// to set the pass value
void obstacle::setpass(bool p){
    pass = p;
}

// update the position of the obstacle in the x direction
void obstacle::next() {
    x = x - o_velocity;
}

// set the parameters for the obstacle
void obstacle::set_position(double s, double hole_y, double hole_height_y) {
    x = s;
    hole = hole_y;
}

// get the discriminant of whether the bird touches the obstacle
bool obstacle::istouch(Bird B, int screen_N) {
    for (int i=0; i<=1; i++){
        for (int j=-5; j<=6; j++){
            for (int k=0; k<=hole-1; k++){
                if (((ceil(B.getx())+i) == (x+j)) and ((ceil(B.gety())-1) == k)){
                    return true;
                }
            }
            for (int k=hole+9; k<=screen_N; k++){
                if (((ceil(B.getx())+i) == (x+j)) and ((ceil(B.gety())+1) == k)){
                    return true;
                }
            }
        }
    }
    for (int i=-3; i<=3; i++){
        if ((i != 0) and (i != 1)){
            for (int j=-5; j<=6; j++){
                for (int k=0; k<=hole-1; k++){
                    if (((ceil(B.getx())+i) == x+j) and (ceil(B.gety()) == k)){
                        return true;
                    }
                }
                for (int k=hole+9; k<screen_N; k++){
                    if (((ceil(B.getx())+i) == x+j) and (ceil(B.gety()) == k)){
                        return true;
                    }
                }
            }
        }
    }
    return false;

}

// get the discriminant of whether the bird passed the obstacle
bool obstacle::ispassed(Bird B){
    if (ceil(B.getx()) >= ceil(x)-5){
        return true;
    }
    return false;
}