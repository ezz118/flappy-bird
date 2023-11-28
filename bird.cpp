#include "bird.h"
#include <cmath>

double Bird::gety() {
    return y;
}

double Bird::getx() {
    return x;
}

double Bird::getv() {
    return v;
}

void Bird::jump() {
    v = init_v;
}

// positive velocity means upward, positive acceleration means downward
void Bird::next() {
    if (v>v_cap){
        v = v - a;
    }
    y = y - v;
}

void Bird::sety(double h) {
    y = h;
}

void Bird::setv(double velo) {
    v = velo;
}
