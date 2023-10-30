/***********************************************************************
 * Source File:
 *     Velocity :
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of the physics for the velocity of the M777 Howitzer.
 ************************************************************************/

#include "velocity.h"
#include "acceleration.h"

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
	return computeTotalComponent(dx, dy);
}


/*************************************************************************
 * SET DX
 * Set the change in velocity for the x component.
 ************************************************************************/
void Velocity :: setDX(double dx)
{
	this->dx = dx;
}

/*************************************************************************
 * SET DY
 * Set the change in velocity for the y component.
 ************************************************************************/
void Velocity :: setDY(double dy)
{
	this->dy = dy;
}

/*************************************************************************
 * ADD X
 * Add velocity to the X component.
 ************************************************************************/
void Velocity :: addX(double accel, double time)
{
	dx += accel * time;
}

/*************************************************************************
 * ADD Y
 * Add velocity to the Y component.
 ************************************************************************/
void Velocity::addY(double accel, double time)
{
	dy += accel * time;
}

/***********************************************
 * COMPUTE VELOCITY
 * Starting with a given velocity, find the new
 * velocity once acceleration is applied. This is
 * called the Kinematics equation. The
 * equation is:
 *     v = v + a t
 * INPUT
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     v : new velocity, in meters/second
 ***********************************************/
double Velocity::computeVelocity(double velocity, double acceleration, double timeInterval)
{
	// Find the new velocity.
	double newV;
	newV = velocity + (acceleration * timeInterval);
	return newV;
}

/*************************************************************************
 * UPDATE VELOCITY 
 * Update the x and y component of velocity.
 ************************************************************************/
void Velocity::updateVelocity(Acceleration &acceleration, double timeInterval)
{
	// Update X
	dx = computeVelocity(getDX(), acceleration.getDDX(), timeInterval);
	// Update Y
	dy = computeVelocity(getDY(), acceleration.getDDY(), timeInterval);
}
