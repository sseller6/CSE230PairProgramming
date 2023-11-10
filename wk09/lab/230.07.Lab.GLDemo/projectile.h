#pragma once

#include <vector>
#include "position.h"
#include "velocity.h"

using namespace std;

class Projectile
{
private:

    // Struct to hold position, velocity, time in flght path array
    struct PositionVelocityTime {
        Position position;
        Velocity velocity;
        double   time;
    };

    // Attrubutes
    double mass;
    double radius;
    vector<PositionVelocityTime> flightPath;

public:
    Projectile();
    void reset();
    void fire();
    void advance(double time);
    void draw();
    bool flying();

    // Getters
    double getAltitude();
    Position getPosition();
    double getFlightTime();
    double getFlightDistance();
    double getSpeed();
    double getCurrentTime();

    // Setters
    void setMass();
    void setRadius();
};