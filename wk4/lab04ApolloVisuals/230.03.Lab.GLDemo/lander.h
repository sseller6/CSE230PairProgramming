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
#include "uiInteract.h" // for controls
#include "uiDraw.h"   // for ogstream
#include "status.h"   // for status


// The lander class
class Lander
{
public:
	Lander(Point ptUpperRight);
	void reset();

	Point getPosition() const;
	int getFuel() const;
	void useFuel(double ammount);
	bool getStatus() const;
	void setStatus(bool status);
	void draw(ogstream &gout, const Interface* pUI) const;
	void move(const Interface* pUI, double time);
	void coast();
	void land();
	void crash();
private:
	bool status; // 1 for thruster engaged 0 for thruster disengaged
	Point position;
	Velocity velocity;
	Angle angle;
	double fuel;
};