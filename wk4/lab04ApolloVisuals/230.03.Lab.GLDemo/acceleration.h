/***********************************************************************
 * Header File:
 *     Acceleration 
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object containing the physics for acceleration of the lunar module.
 ************************************************************************/

#pragma once

class Acceleration

{
	// Methods
public:
	Acceleration();
	Acceleration(double ddx, double ddy);
	// Getters
	double getDDX() const;
	double getDDY() const;
	// Setters
	void setDDX(double ddx);
	void setDDY(double ddy);
private:
	// Attributes
	double ddx;
	double ddy;
};