#ifndef OBSTACKLE_H
#define OBSTACKLE_H

// a class for the parameters of an obstacle

//fix the velocity of the obstacle
const double o_velocity = 1;
class obstacle {
public:
    // get the position of the obstacle in the x direction
    double getx();
    // get the discriminant of whether the bird touches the obstacle
    bool istouch(Bird bird);
    // set the parameters for the obstacle
    void set_position(double x, double hole, double hole_height);
    // update the position of the obstacle in the x direction
    void next();

private:
    // position of the obstacle in the x direction
    double x;
    // position of the hole in the y direction
    double hole;
    // the height of the hole
    double hole_height;
};
#endif
