#include "acceleration.h"

// Default Constructor
Acceleration::Acceleration() 
    : ddx(0.00),
      ddy(0.00)
{}



void Acceleration::updateAcceleration(Force& force, double mass)
{
    // Update x
    ddx = computeAcceleration(force.getForceX(), mass);
    // Update y
    ddy = computeAcceleration(force.getForceY(), mass);
}

double Acceleration::computeAcceleration(double force, double mass)
{
    return force /  mass;
}

// GETTERS
// Returns x componenet of acceleration
double Acceleration::getDDX()
{
    return ddx;
}

// SETTERS
// Returns y component of acceleration
double Acceleration::getDDY()
{
    return ddy;
}
