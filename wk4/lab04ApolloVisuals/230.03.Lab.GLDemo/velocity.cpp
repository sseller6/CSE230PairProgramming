/*************************************************************************
 * Source File:
 *     Velocity :
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of the physics for acceleration of the lunar module.
 ************************************************************************/

#include "velocity.h"

/*************************************************************************
 * velocity : CONSTRUCTOR
 * Default constructor.
 ************************************************************************/
Velocity :: Velocity() : dx(0.0), dy (0.0)
{
}

/*************************************************************************
 * VELOCITY : CONSTRUCTOR
 * Non-default Constructor
 ************************************************************************/
Velocity :: Velocity(double dx, double dy)
{
	this->dx = dx;
	this->dy = dy;
}

/*************************************************************************
 * GET DX
 * Get the change in velocity for the x component.
 ************************************************************************/
double Velocity :: getDX() const
{
	return dx;
}

/*************************************************************************
 * GET DY
 * Get the change in velocity for the y component.
 ************************************************************************/
double Velocity :: getDY() const
{
	return dy;
}

/*************************************************************************
 * GET VELOCITY
 * Get the current velocity.
 ************************************************************************/
double Velocity::getVelocity()
{
	return computeTotal();
}


/*************************************************************************
 * SET DX
 * Set the change in velocity for the x component.
 ************************************************************************/
void Velocity :: setDX(double dx)
{
}

/*************************************************************************
 * SET DY
 * Set the change in velocity for the y component.
 ************************************************************************/
void Velocity :: setDY(double dy)
{
}

/*************************************************************************
 * ADD
 * Add velocity.
 ************************************************************************/
void Velocity :: add(double accel, double time)
{
}

/*************************************************************************
 * COMPUTE TOTAL
 * Compute the total velocity.
 ************************************************************************/
double Velocity::computeTotal()
{
	return sqrt((dx * dx) + (dy * dy));
}

