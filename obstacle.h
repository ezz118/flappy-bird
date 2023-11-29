#ifndef OBSTACKLE_H
#define OBSTACKLE_H
#include "bird.h"
// a class for the parameters of an obstacle

//fix the velocity of the obstacle
#ifdef __linux__ 
const double o_velocity = 1;
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
    double gethole_lower();//get the y-position of the lower bound of the hole
    double gethole_upper();//get the y-position of the upper bound of the hole
    bool getpass();

    // get the discriminant of whether the bird touches the obstacle.
    // input the bird object and the screen size (width), output a boolean 
    // value to determine whether the bird touches the obstacle
    bool istouch(Bird B, int screen_N);

    // set the parameters for the obstacle
    // input the x-position of the obstacle, y-position of the hole and its height.
    void set_position(double x, double hole, double hole_height);

    //set the x coordinate of the obstacle
    void setx(double x);

    //set the hole position
    void sethole(double y);

    //set the pass value 
    void setpass(bool p);

    // update the position of the obstacle in the x direction
    void next(void);

    // get the discriminant of whether the bird passed the obstacle
    // input the Bird type parameters
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
