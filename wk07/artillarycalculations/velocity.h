/***********************************************************************
 * Header File:
 *     Velocity :
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object of the physics for the velocity of the M777 Howitzer.
 ************************************************************************/
#pragma once

#include "xyComponents.h"

// Forward Declarations

 /************************************
  * ACCELERATION class
  ************************************/
class Acceleration;


/************************************
 * VELOCITY class
 ************************************/
 class Velocity
{
	// Methods
public:
	// Constructors
	Velocity();
	Velocity(double dx, double dy);
	// Methods
	void   addX(double accel, double time);
	void   addY(double accel, double time);
	double computeVelocity(double velocity, double acceleration, double timeInterval);
	void   updateVelocity(Acceleration &acceleration, double timeInterval);
	// Getters
	double getDX() const;
	double getDY() const;
	double getVelocity();
	// Setters
	void   setDX(double dx);
	void   setDY(double dy);


private:
    // Attributes
	double dx;
	double dy;
};