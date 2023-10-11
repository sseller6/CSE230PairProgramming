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

double Acceleration::getDDX() const
{
	return 0.0;
}

double Acceleration::getDDY() const
{
	return 0.0;
}

void Acceleration::setDDX(double ddx)
{
}

void Acceleration::setDDY(double ddy)
{
}
