#include "obstacle.h"
#include "bird.h"
#include <cmath>

// get the position of the obstacle in the x direction
double obstacle::getx() {
    return x;
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
                if (((ceil(B.x)+i) == (x+j)) and ((ceil(B.y)-1) == k)){
                    return true;
                }
            }
            for (int k=hole+9; k<=screen_N; k++){
                if (((ceil(B.x)+i) == (x+j)) and ((ceil(B.y)+1) == k)){
                    return true;
                }
            }
        }
    }
    for (int i=-3; i<=3; i++){
        if ((i != 0) and (i != 1)){
            for (int j=-5; j<=6; j++){
                for (int k=0; k<=hole-1; k++){
                    if (((ceil(B.x)+i) == x+j) and (ceil(B.y) == k)){
                        return true;
                    }
                }
                for (int k=hole+9; k<screen_N; k++){
                    if (((ceil(B.x)+i) == x+j) and (ceil(B.y) == k)){
                        return true;
                    }
                }
            }
        }
    }

}

// get the discriminant of whether the bird passed the obstacle
bool obstacle::ispassed(Bird B){
    if (ceil(B.x) >= ceil(x)-5)
       return true;
}