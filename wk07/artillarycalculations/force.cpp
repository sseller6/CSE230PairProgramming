#include "force.h"
#include "acceleration.h"
#include "velocity.h"
#include <unordered_map>
using namespace std;

/*****************************************************************
* Default Constructor
*****************************************************************/
Force::Force()
{
    forceX = 0.00;
    forceY = 0.00;
}

/*****************************************************************
* Non Default Constructor
*****************************************************************/
Force::Force(double aRadians, double force)
{
    setForce(aRadians, force);
}

/*****************************************************************
* FORCE COMPUTE FORCE
* Basic compute force method.
*****************************************************************/
double Force::computeForce(double mass, double acceleration)
{
    return mass * acceleration;
}

/*****************************************************************
* FORCE UPDATE FORCE
* Basic update force method.
*****************************************************************/
void Force::updateForce(double mass, Acceleration &acceleration)
{
    // Set x
    forceX = computeForce(mass, acceleration.getDDX());
    // Set y
    forceY = computeForce(mass, acceleration.getDDY());
}

/*****************************************************************
* FORCE GET FORCE X
* Get the force of the X value.
*****************************************************************/
double Force::getForceX()
{
    return forceX;
}

/*****************************************************************
* FORCE GET FORCE Y
* Get the force of the Y value.
*****************************************************************/
double Force::getForceY()
{
    return forceY;
}

/*****************************************************************
* FORCE GET FORCE 
* Get the force.
*****************************************************************/
double Force::getForce()
{
    return computeTotalComponent(getForceX(), getForceY());
}

/*****************************************************************
* FORCE SET FORCE X
* Set the force of X.
*****************************************************************/
void Force::setForceX(double value)
{
    forceX = value;
}
/*****************************************************************
* FORCE SET FORCE Y
* Set the force of Y.
*****************************************************************/
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
    :dragCoefficient(0.30), // Defined constants
     mediumDensity(0.60)
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
    // Linear Interpolation Table
    double altitudes[] = {0000, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000};
    double accelerations[] = {9.087, 9.804, 9.801, 9.797, 9.794, 9.791, 9.788, 9.785, 9.782, 9.779, 9.776, 9.761, 9.745, 9.730};
    unordered_map<double, double> altitudeAcceleration =
    {
        {0000, 9.087},
        {1000, 9.804},
        {2000, 9.801},
        {3000, 9.797},
        {4000, 9.794},
        {5000, 9.791},
        {6000, 9.788},
        {7000, 9.785},
        {8000, 9.782},
        {9000, 9.779},
        {10000, 9.776},
        {15000, 9.761},
        {20000, 9.745},
        {25000, 9.730},
    };

    int index = 0;
    // Iterate through list. i 0 = index 0. Compare value to altitude. If the value of index is greater than altitude, stop and set index to i-1.
    // Then set 
    for (double value : altitudes)
    {
        if (value < altitude)
        {
            index = value
        }
    }

    // Initialize linear interpolation variables
    double d = altitude;  //Altitude
    double r;  //Solve for R (just initialize)
    double d0 = altitudes[index]; //Key1 iterate thorugh keys 
    double r0 = accelerations[index]; //Value1
    double d1 = altitudes[index + 1]; //Key2
    double r1 = accelerations[index + 1]; //Value2


    
    // Steven's attempt at coding the equation
    r = (((r1 - r0) * (d * d0)) / (d1 - d0)) + r0;


    
    return -9.8;
}
