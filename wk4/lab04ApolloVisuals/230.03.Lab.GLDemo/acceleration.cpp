/***********************************************************************
 * Source File:
 *     Acceleration :
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of the physics for acceleration of the lunar module.
 ************************************************************************/

#include "acceleration.h"

/*************************************************************************
* Default Constructor
*************************************************************************/
Acceleration::Acceleration()
	: ddx(0.0), ddy(0.0)
{
}

/*************************************************************************
* Non-Default Constructor
*************************************************************************/
Acceleration::Acceleration(double ddx, double ddy)
{
}

/*************************************************************************
* Get the change in the x component of acceleration.
*************************************************************************/
double Acceleration::getDDX() const
{
	return 0.0;
}

/*************************************************************************
* Get the change in the y component of acceleration.
*************************************************************************/
double Acceleration::getDDY() const
{
	return 0.0;
}

/*************************************************************************
* Set the change in the x component of acceleration.
*************************************************************************/
void Acceleration::setDDX(double ddx)
{
}

/*************************************************************************
* Set the change in the y component of acceleration.
*************************************************************************/
void Acceleration::setDDY(double ddy)
{
}
