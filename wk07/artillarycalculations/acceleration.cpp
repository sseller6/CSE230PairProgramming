/***********************************************************************
 * Source File:
 *     Acceleration
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of the physics for acceleration of the M777 Howitzer.
 ************************************************************************/

#include "acceleration.h"

 /*************************************************************************
 * Default Acceleration Constructor
 *************************************************************************/
Acceleration::Acceleration() 
    : ddx(0.00),
      ddy(0.00)
{}

/*************************************************************************
* UPDATE ACCELERATION   
* Update the change in the x and y component of acceleration.
*************************************************************************/
void Acceleration::updateAcceleration(Force& force, double mass)
{
    // Update x
    ddx = computeAcceleration(force.getForceX(), mass);
    // Update y
    ddy = computeAcceleration(force.getForceY(), mass);
}
/*************************************************************************
* COMPUTE ACCELERATION
* Compute the new acceleration.
*************************************************************************/
double Acceleration::computeAcceleration(double force, double mass)
{
    return force /  mass;
}

/*************************************************************************
* GET DDX
* Returns x componenet of acceleration
*************************************************************************/
double Acceleration::getDDX()
{
    return ddx;
}

/*************************************************************************
* GET DDY
* Returns y component of acceleration
*************************************************************************/
double Acceleration::getDDY()
{
    return ddy;
}
