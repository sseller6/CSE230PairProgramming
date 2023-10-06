/***********************************************************************
 * Header File:
 *     Acceleration 
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object containing the physics for acceleration of the lunar module.
 ************************************************************************/

#pragma once

#include <math.h>    // for math
#include <iostream>  // for cout

class Acceleration

{
	// Methods
public:
	Acceleration();
	Acceleration(double ddx, double ddy);
	double getDDX() const;
	double getDDY() const;
	void setDDX(double ddx);
	void setDDY(double ddy);
private:
	// Attributes
	double ddx;
	double ddy;
};