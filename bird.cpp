#include "bird.h"
#include <cmath>

// get the position of the bird in the y direction
double Bird::gety() {
    return y;
}

double Bird::getx() {
    return x;
}

// update the velocity of the bird after every jump
void Bird::jump() {
    v = init_v;
}

// update the position and the velocity of the bird after every time step
// positive velocity means upward, positive acceleration means downward
void Bird::next() {
    v = v - a;
    y = y - v;
}

// set the y coordinate of the bird
void Bird::sety(double h) {
    y = h;
}

