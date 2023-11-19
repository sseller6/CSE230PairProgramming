/***********************************************************************
 * Source File:
 *     Velocity :
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object of the physics for the velocity of the lunar module.
 ************************************************************************/
#pragma once

#include <cmath> // for sqrt()

 class Velocity
{
	// Methods
public:
	Velocity();
	Velocity(double dx, double dy);
	double getDX() const;
	double getDY() const;
	double getVelocity();
	void setDX(double dx);
	void setDY(double dy);
	void addX(double accel, double time);
	void addY(double accel, double time);
	double computeTotal();
private:
    // Attributes
	double dx;
	double dy;
};