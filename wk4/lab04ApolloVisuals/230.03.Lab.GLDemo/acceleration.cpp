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
* Default Acceleration Constructor
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
	setDDX(ddx);
	setDDY(ddy);
}

/*************************************************************************
* GET DDX
* Get the change in the x component of acceleration.
*************************************************************************/
double Acceleration::getDDX() const
{
	return ddx;
}

/*************************************************************************
* GET DDY
* Get the change in the y component of acceleration.
*************************************************************************/
double Acceleration::getDDY() const
{
	return ddy;
}

/*************************************************************************
* SET DDX
* Set the change in the x component of acceleration.
*************************************************************************/
void Acceleration::setDDX(double ddx)
{
	this->ddx = ddx;
}

/*************************************************************************
 * SET DDY
 * Set the change in the y component of acceleration.
 ************************************************************************/
void Acceleration::setDDY(double ddy)
{
	this->ddy = ddy;
}
