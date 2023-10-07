/***********************************************************************
 * Source File:
 *     Velocity :
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object of the physics for the velocity of the lunar module.
 ************************************************************************/
#pragma once

#include <math.h>    // for math
#include <iostream>  // for cout

class Velocity

{
	// Methods
public:
	Velocity();
	Velocity(double dx, double dy);
	double getDX() const;
	double getDY() const;
	double getVelocity() const;
	void setDX(double dx);
	void setDY(double dy);
	void add(double accel, double time);
private:
    // Attributes
	double dx;
	double dy;
};