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
    hole_height = hole_height_y;
}

// get the discriminant of whether the bird touches the obstacle
bool obstacle::istouch(Bird bird) {
    //need to fill in
}
