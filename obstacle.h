#ifndef OBSTACKLE_H
#define OBSTACKLE_H

// a class for the parameters of an obstacle

//fix the velocity of the obstacle
const double o_velocity = 1;

class obstacle {
public:
    // get the position of the obstacle in the x direction
    double getx() { return x; }
    // get the position of the hole in the y direction
    double gethole() { return hole; }
    // get the discriminant of whether the bird touches the obstacle
    bool touch() { return touch; }
    // update the position of the obstacle in the x direction
    double next() {x -= o_velocity; return x; }

private:
    // position of the obstacle in the x direction
    double x;
    // position of the hole in the y direction
    double hole;
    // discriminant of whether the bird touches the obstacle
    bool touch;
};
#endif
