#ifndef OBSTACKLE_H
#define OBSTACKLE_H
#include "bird.h"
// a class for the parameters of an obstacle

//fix the velocity of the obstacle
#ifdef __linux__ 
const double o_velocity = 0.5;
#elif _WIN32
const double o_velocity = 1;
#endif


class obstacle {
public:
    // get the position of the obstacle in the x direction
    double getx();
    //get the position of the hole
    double gethole();
    //to know whether the obstacle has been passed
    double gethole_lower();
    double gethole_upper();
    bool getpass();
    // get the discriminant of whether the bird touches the obstacle
    bool istouch(Bird B, int screen_N);
    // set the parameters for the obstacle
    void set_position(double x, double hole, double hole_height);
    //set the x coordinate of the obstacle
    void setx(double x);
    //set the hole position
    void sethole(double y);
    //set the pass value 
    void setpass(bool p);
    // update the position of the obstacle in the x direction
    void next();
    // get the discriminant of whether the bird passed the obstacle
    bool ispassed(Bird B);

private:
    // position of the obstacle in the x direction
    double x;
    // position of the hole in the y direction
    double hole, upper, lower;
    // record whether the bird has passed the obstacle
    bool pass;
};
#endif
