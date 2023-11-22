#ifndef OBSTACKLE_H
#define OBSTACKLE_H
#include "bird.h"
// a class for the parameters of an obstacle

//fix the velocity of the obstacle
const double o_velocity = 1;
class obstacle {
public:
    // get the position of the obstacle in the x direction
    double getx();
    // get the discriminant of whether the bird touches the obstacle
    bool istouch(Bird B);
    // set the parameters for the obstacle
    void set_position(double x, double hole, double hole_height);
    // update the position of the obstacle in the x direction
    void next();
    // get the discriminant of whether the bird passed the obstacle
    bool ispassed(Bird B);

private:
    // position of the obstacle in the x direction
    double x;
    // position of the hole in the y direction
    double hole;
    // record whether the bird has passed the obstacle
    bool pass;
};
#endif
