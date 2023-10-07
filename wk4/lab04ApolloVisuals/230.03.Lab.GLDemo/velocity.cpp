/***********************************************************************
 * Source File:
 *     Velocity :
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of the physics for acceleration of the lunar module.
 ************************************************************************/

#include "velocity.h"

// Default Constructor
Velocity :: Velocity() : dx(0.0), dy (0.0)
{
}

// Non-default Constructor

Velocity :: Velocity(double dx, double dy)
{
	this->dx = dx;
	this->dy = dy;
}

// Get DX
double Velocity :: getDX() const
{
	return dx;
}

// Get DY
double Velocity :: getDY() const
{
	return dy;
}

double Velocity::getVelocity()
{
	return computeTotal();
}


// Set DX
void Velocity :: setDX(double dx)
{
}

// Set DY
void Velocity :: setDY(double dy)
{
}

// Add
void Velocity :: add(double accel, double time)
{
}

// Calculates total velocity
double Velocity::computeTotal()
{
	return sqrt((dx * dx) + (dy * dy));
}

