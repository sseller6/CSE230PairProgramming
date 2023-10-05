/***********************************************************************
 * Header File:
 *     Lander : Represents the lander in the lunar lander simulator
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object contianing all of the properties of the lander.
 ************************************************************************/

#pragma once

#include "point.h"   // for Point
#include "uiDraw.h"  // for ogstream

/************************
 * LANDER
 * The lander class
 * *********************/
class Lander
{
public: 
	Lander(ptUpperRight);
	void reset();
	bool isDead();
	bool isLanded();
	bool isFlying();
	Point getPosition;
	int getFuel() const;
	void draw(thrust, gout) const;
	void input(thrust);
	void coast();
	void land();
	void crash();
private:
	Status status;
	Point pt;
	Velocity v;
	Angle angle;
	double fuel;
}
