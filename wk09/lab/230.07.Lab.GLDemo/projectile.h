#pragma once

#include <vector>
#include "position.h"
#include "velocity.h"

using namespace std;

// Forward declaration for projectile unit tests
class TestProjecitile;

class Projectile
{
public:
    

    // Methods
             Projectile();
             Projectile(double mass, double radius);
    void     reset();
    void     fire();
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

    // Unit Test Access
    friend TestProjectile;

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