/***********************************************************************
 * Header File:
 *     Lander : Represents the lander in the lunar lander simulator
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object contianing all of the properties of the lander.
 ************************************************************************/

#pragma once

#include "angle.h"    // for Angle
#include "point.h"    // for Point
#include "thrust.h"   // for thrust
#include "velocity.h" // for Velocity
#include "uiDraw.h"   // for ogstream
#include "status.h"   // for status
#include <ogstream>

/************************
 * LANDER
 * The lander class
 * *********************/
class Lander
{
public:
	Lander(Point ptUpperRight);
	void reset();

	Point getPosition();
	int getFuel() const;
	void draw(Thrust thrust, gout) const;
	void input(Thrust thrust);
	void coast();
	void land();
	void crash();
private:
	Status Status(); // Gotta figure this out later.
	Point pt;
	Velocity v;
	Angle angle;
	double fuel;
};