#include "force.h"
#include "acceleration.h"
#include "velocity.h"

// Default Constructor
Force::Force()
{
    forceX = 0.00;
    forceY = 0.00;
}

// Non Default Constructor
Force::Force(double aRadians, double force)
{
    setForce(aRadians, force);
}

// Basic compute force method
double Force::computeForce(double mass, double acceleration)
{
    return mass * acceleration;
}

// Basic update force method
void Force::updateForce(double mass, Acceleration &acceleration)
{
    // Set x
    forceX = computeForce(mass, acceleration.getDDX());
    // Set y
    forceY = computeForce(mass, acceleration.getDDY());
}


// GETTERS

double Force::getForceX()
{
    return forceX;
}

double Force::getForceY()
{
    return forceY;
}

double Force::getForce()
{
    return computeTotalComponent(getForceX(), getForceY());
}

// SETTERS

void Force::setForceX(double value)
{
    forceX = value;
}

void Force::setForceY(double value)
{
    forceY = value;
}

void Force::setForce(double aRadians, double totalForce)
{
    forceX = computeHorizontalComponent(aRadians, totalForce);
    forceY = computeVerticalComponent(aRadians, totalForce);
}


// Drag Force Constructor

DragForce::DragForce()
    :dragCoefficient(0.00),
     mediumDensity(0.00)
{
}

// Non Default Constructor
DragForce::DragForce(double dragCoefficient, double mediumDensity)
{
    this->dragCoefficient = dragCoefficient;
    this->mediumDensity = mediumDensity;
}

// Override function for computing drag force
// Formula: d = ( c * ρ * v^2 * a) / 2
// Where d = DragForce
//       c = dragCoeficient
//       p = meduimDensity
//       v = velocity
//       a = surfaceArea
double DragForce::computeForce(double surfaceArea, double velocity)
{
   return (dragCoefficient * mediumDensity * (velocity * velocity) * surfaceArea) / 2;
}

// Overrride function for updating drag force
void DragForce::updateForce(double surfaceArea, Velocity &velocity)
{
    setForceX(computeForce(surfaceArea, velocity.getDX()));
    setForceY(computeForce(surfaceArea, velocity.getDY()));
}

// Default Constructor
Gravity::Gravity()
    : acceleration(0.0)
{}

// Non Default Constructor
Gravity::Gravity(double accelerationGravity)
    : acceleration(accelerationGravity)
{}

double Gravity::computeForce(double mass, double altitude)
{
    return mass * getAcceleration(altitude);
}

void Gravity::updateForce(double mass, double altitude)
{
    setForceY(computeForce(mass, altitude));
}

double Gravity::getAcceleration(double altitude)
{
    return -9.8; // Stub function
}
