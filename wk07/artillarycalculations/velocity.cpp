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
#include <iostream>

using namespace std;

/*************************************************************************
 * velocity : CONSTRUCTOR
 * Default constructor.
 ************************************************************************/
Velocity :: Velocity() : dx(0.0), dy (0.0), mach(0.0)
{
}

/*************************************************************************
 * VELOCITY : CONSTRUCTOR
 * Non-default Constructor
 ************************************************************************/
Velocity :: Velocity(double dx, double dy)
	: mach(0)
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

double Velocity::getMach() const
{
	return mach;
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
void Velocity::updateVelocity(Acceleration &acceleration, double timeInterval, double altitude)
{
	// Update X
	dx = computeVelocity(getDX(), acceleration.getDDX(), timeInterval);
	// Update Y
	dy = computeVelocity(getDY(), acceleration.getDDY(), timeInterval);

	// Update Mach
	mach = computeMach(altitude);
}

// Computes current mach
double Velocity::computeMach(double altitude)
{
	double totalVelocity = computeTotalComponent(dx, dy);

	// Linear Interpolation Table
	double altitudes[] = { 0000, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 40000 };
	double speeds[] = { 340, 336, 328, 324, 320, 316, 312, 308, 303, 299, 295, 295, 295, 305, 324 };

	double speed; // Value to hold the speed
	bool altitudeFound = false;
	int index = -1;
	while (!altitudeFound)
	{
		// Increment index.
		index++;

		// value lower than table
		if (altitude < altitudes[0])
		{
			// Use minimum value
			return speeds[0];
		}

		// Base Case: Altitude already in table.
		if (altitudes[index] == altitude)
		{
			return totalVelocity / speeds[index];
		}

		// Keep searching until altitude is found.
		else if (altitudes[index] < altitude && altitude < altitudes[index + 1])
		{
			altitudeFound = true;
		}

		// If altitude is larger than the table.
		else if (index >= 15)
		{
			return totalVelocity / speeds[14];
		}
	}


	// Initialize linear interpolation variables
	double d = altitude;                  //Altitude
	double r;                             //Solve for R (just initialize)
	double d0 = altitudes[index];         //Key1 iterate thorugh keys 
	double r0 = speeds[index];             //Value1
	double d1 = altitudes[index + 1];     //Key2
	double r1 = speeds[index + 1];         //Value2



	// Steven's attempt at coding the equation
	r = (((r1 - r0) * (d - d0)) / (d1 - d0)) + r0;

	return totalVelocity / r;
}