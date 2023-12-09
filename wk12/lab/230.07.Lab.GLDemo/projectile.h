#pragma once

#include "direction.h"
#include "position.h"
#include <vector>
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
    void     advance(double timeInterval);
    void     draw(ogstream& gout);
    bool     flying();

    // Getters
    double   getAltitude();
    Position getPosition();
    double   getFlightTime();
    double   getFlightDistance();
    double   getSpeed();
    double   getCurrentTime();

    // Setters
    void     setMass(double mass);
    void     setRadius(double radius);


private:

    // Struct to hold position, velocity, time in flght path array
    struct PositionVelocityTime {
        Position pt;
        Velocity v;
        double   t;
    } pvt;

    // Attrubutes
    double mass;
    double radius;
    vector<PositionVelocityTime> flightPath;
};