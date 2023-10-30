/***********************************************************************
 * Source File:
 *     Force
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of the physics for the force of the M777 Howitzer.
 ************************************************************************/

#include "force.h"
#include "acceleration.h"
#include "velocity.h"
#include <unordered_map>
#include <iostream>
using namespace std;

/*****************************************************************
* FORCE : Default Constructor
*****************************************************************/
Force::Force()
{
    forceX = 0.00;
    forceY = 0.00;
}

/*****************************************************************
* FORCE : Non Default Constructor
*****************************************************************/
Force::Force(double aRadians, double force)
{
    setForce(aRadians, force);
}

/*****************************************************************
* FORCE : COMPUTE FORCE
* Basic compute force method.
*****************************************************************/
double Force::computeForce(double mass, double acceleration)
{
    return mass * acceleration;
}

/*****************************************************************
* FORCE : UPDATE FORCE
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
* FORCE : GET FORCE X
* Get the force of the X value.
*****************************************************************/
double Force::getForceX()
{
    return forceX;
}

/*****************************************************************
* FORCE : GET FORCE Y
* Get the force of the Y value.
*****************************************************************/
double Force::getForceY()
{
    return forceY;
}

/*****************************************************************
* FORCE : GET FORCE 
* Get the force.
*****************************************************************/
double Force::getForce()
{
    return computeTotalComponent(getForceX(), getForceY());
}

/*****************************************************************
* FORCE : SET FORCE X
* Set the force of X.
*****************************************************************/
void Force::setForceX(double value)
{
    forceX = value;
}
/*****************************************************************
* FORCE : SET FORCE Y
* Set the force of Y.
*****************************************************************/
void Force::setForceY(double value)
{
    forceY = value;
}
/*****************************************************************
* FORCE : SET FORCE 
* Set the force of Y.
*****************************************************************/
void Force::setForce(double aRadians, double totalForce)
{
    forceX = computeHorizontalComponent(aRadians, totalForce);
    forceY = computeVerticalComponent(aRadians, totalForce);
}

/*****************************************************************
* Drag Force Constructor
*****************************************************************/
DragForce::DragForce()
    :dragCoefficient(0.30), // Defined constants
     mediumDensity(0.60)
{
}

/*****************************************************************
* Drag Force Non Default Constructor
*****************************************************************/
DragForce::DragForce(double dragCoefficient, double mediumDensity)
{
    this->dragCoefficient = dragCoefficient;
    this->mediumDensity = mediumDensity;
}

/*****************************************************************
* DRAG FORCE : COMPUTE FORCE
* Override function for computing drag force
* Formula: d = ( c * ρ * v^2 * a) / 2
* Where d = DragForce
*       c = dragCoeficient
*       p = meduimDensity
*       v = velocity
*       a = surfaceArea
*****************************************************************/
double DragForce::computeForce(double surfaceArea, double velocity)
{
   return -(dragCoefficient * mediumDensity * (velocity * velocity) * surfaceArea) / 2;
}

/*****************************************************************
* DRAG FORCE : UPDATE FORCE
* Not to be confused with FORCE: UPDATE FORCE.
* Overrride function for updating drag force
*****************************************************************/
void DragForce::updateForce(double surfaceArea, Velocity &velocity, double altitude)
{
    // Update Air Density
    dragCoefficient = computeDragCoefficient(velocity);
    // Update Drag Coefficient
    mediumDensity = computeMediumDensity(altitude);
    // Compute Foces
    setForceX(computeForce(surfaceArea, velocity.getDX()));
    setForceY(computeForce(surfaceArea, velocity.getDY()));
}

double DragForce::computeDragCoefficient(Velocity& velocity)
{
    double mach = velocity.getMach();

    // Linear Interpolation Table
    double machs[] = { 0.300, 0.500, 0.700, 0.890, 0.920, 0.960, 0.980, 1.000, 1.020, 1.060, 1.240, 1.530, 1.990, 2.870, 2.890, 5.000 };
    double coefficients[] = { 0.1629, 0.1659, 0.2031, 0.2597, 0.3010, 0.3287, 0.4002, 0.4258, 0.4335, 0.4483, 0.4064, 0.3663, 0.2897, 0.2306, 0.2656 };
    
    bool machFound = false;
    int index = -1;
    while (!machFound)
    {
        // Increment index.
        index++;

        // Base Case: Altitude already in table.
        if (machs[index] == mach)
            return coefficients[index];

        // Keep searching until altitude is found.
        else if (machs[index] < mach && mach < machs[index + 1])
        {
            machFound = true;
        }

        // If altitude isn't on table, print error and use default 9.087 m/s.
        else if (index >= 15)
        {
            cout << "ERROR: Mach Not Found in table default value used" << endl;
            return 0.3;
        }
    }


    // Initialize linear interpolation variables
    double d = mach;                  //Altitude
    double r;                             //Solve for R (just initialize)
    double d0 = machs[index];         //Key1 iterate thorugh keys 
    double r0 = coefficients[index];     //Value1
    double d1 = machs[index + 1];     //Key2
    double r1 = coefficients[index + 1]; //Value2



    // Steven's attempt at coding the equation
    r = (((r1 - r0) * (d - d0)) / (d1 - d0)) + r0;



    return r;
}

double DragForce::computeMediumDensity(double altitude)
{
    // Hard Code Table
    double altitudes[] = { 0000, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 40000, 50000, 60000, 70000, 80000 };
    double densities[] = { 1.2250000, 1.1120000, 1.0070000, 0.9092000, 0.8194000, 0.7364000, 0.6601000, 0.5900000, 0.5258000, 0.4671000, 0.4135000, 0.1948000, 0.0889100, 0.0400800, 0.0184100, 0.0039960, 0.0010270, 0.0003097, 0.0000828, 0.0000185 };
    
    // Linear Interpolation
    bool altitudeFound = false;
    int index = -1;
    while (!altitudeFound)
    {
        // Increment index.
        index++;

        // Base Case: Altitude already in table.
        if (altitudes[index] == altitude)
            return densities[index];

        // Keep searching until altitude is found.
        else if (altitudes[index] < altitude && altitude < altitudes[index + 1])
        {
            altitudeFound = true;
        }

        // If altitude isn't on table, print error and use default 9.087 m/s.
        else if (index >= 19)
        {
            cout << "ERROR: Altittude Not Found in table default value used" << endl;
            return 0.6;
        }
    }


    // Initialize linear interpolation variables
    double d = altitude;                  //Altitude
    double r;                             //Solve for R (just initialize)
    double d0 = altitudes[index];         //Key1 iterate thorugh keys 
    double r0 = densities[index];         //Value1
    double d1 = altitudes[index + 1];     //Key2
    double r1 = densities[index + 1];     //Value2



    // Steven's attempt at coding the equation
    r = (((r1 - r0) * (d - d0)) / (d1 - d0)) + r0;

    return r;
}

/*****************************************************************
* GRAVITY : Default Constructor
*****************************************************************/
Gravity::Gravity()
    : acceleration(0.0)
{}

/*****************************************************************
* GRAVITY : Non Default Constructor
*****************************************************************/
Gravity::Gravity(double accelerationGravity)
    : acceleration(accelerationGravity)
{}

/*****************************************************************
* GRAVITY : COMPUTE FORCE
* Basic compute force method.
*****************************************************************/
double Gravity::computeForce(double mass, double altitude)
{
    return mass * getAcceleration(altitude);
}

/*****************************************************************
* GRAVITY : UPDATE FORCE
* Updates the force of gravity.
*****************************************************************/
void Gravity::updateForce(double mass, double altitude)
{
    setForceY(computeForce(mass, altitude));
}

/*****************************************************************
* GRAVITY : GET ACCELERATION
* Returns the new acceleration of gravity.
*****************************************************************/
double Gravity::getAcceleration(double altitude)
{
    // Linear Interpolation Table
    double altitudes[] = {0000, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000};
    double accelerations[] = {-9.807, -9.804, -9.801, -9.797, -9.794, -9.791, -9.788, -9.785, -9.782, -9.779, -9.776, -9.761, -9.745, -9.730};

    bool altitudeFound = false;
    int index = -1;
    while (!altitudeFound)
    {
		// Increment index.
		index++;

		// Base Case: Altitude already in table.
		if (altitudes[index] == altitude)
			return accelerations[index];

        // Keep searching until altitude is found.
        else if (altitudes[index] < altitude && altitude < altitudes[index + 1])
        {
            altitudeFound = true;
        }
        
        // If altitude isn't on table, print error and use default 9.087 m/s.
         else if (index >= 13)
        {
            cout << "ERROR: Altittude Not Found in table default value used" << endl;
            return 9.08;
        }
    }


    // Initialize linear interpolation variables
    double d = altitude;                  //Altitude
    double r;                             //Solve for R (just initialize)
    double d0 = altitudes[index];         //Key1 iterate thorugh keys 
    double r0 = accelerations[index];     //Value1
    double d1 = altitudes[index + 1];     //Key2
    double r1 = accelerations[index + 1]; //Value2


    
    // Steven's attempt at coding the equation
    r = (((r1 - r0) * (d - d0)) / (d1 - d0)) + r0;


    
    return r;
}
