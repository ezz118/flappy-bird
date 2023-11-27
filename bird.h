#ifndef BIRD_H
#define BIRD_H

// a class for the parameters of a bird

#ifdef __linux__ 
const double x_position = 40;
const double acceleration = 0.12;
const double jump_velocity = 1;
#elif _WIN32
const double x_position = 40;
const double acceleration = 0.6;
const double jump_velocity = 3;
#endif

class Bird {
public:
    // get the position of the bird in the x direction
    double getx();

    // get the position of the bird in the y direction
    double gety();

    // get the velocity of the bird in the y direction
    double getv();

    // update the velocity of the bird after every jump
    void jump();

    // update the position and the velocity of the bird after every time step
    void next();

    // set the value of y coordinate of the bird
    void sety(double h);
    // input a constant as the desired coordinate parameter

    // set the value of velocity of the bird
    void setv(double velo);
    // input a constant as the desired velocity parameter

private:
    // position of the bird in the x direction
    const double x = x_position;

    // position of the bird in the y direction
    double y;

    // velocity of the bird in the y direction, we set positive direction to be upward
    double v;

    // acceleration of the bird in the y direction
    const double a = acceleration;

    // velocity of the bird's jump
    const double init_v = jump_velocity;

};

#endif
