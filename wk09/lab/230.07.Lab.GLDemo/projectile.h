#pragma once

#include <vector>
#include "position.h"
#include "velocity.h"

using namespace std;

// Forward declaration for projectile unit tests
class TestProjectile;

class Projectile
{
    // Unit Test Access
    friend TestProjectile;

public:
    

    // Methods
             Projectile();
             Projectile(double mass, double radius);
    void     reset();
    void     fire(Position position, double time,
                  double angle, double velocity);
    void     advance(double time);
    void     draw();
    bool     flying();

    // Getters
    double   getAltitude();
    Position getPosition();
    double   getFlightTime();
    double   getFlightDistance();
    double   getSpeed();
    double   getCurrentTime();

    // Setters
    void     setMass();
    void     setRadius();


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
};