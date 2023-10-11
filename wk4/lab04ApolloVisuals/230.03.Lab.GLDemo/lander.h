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
#include "force.h"   // for thrust
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
	Angle getAngle() const;
	Velocity getSpeed() const;
	double getFuel() const;
	void useFuel(double ammount);
	int getStatus() const;
	void setStatus(int status);
	void draw(ogstream &gout, const Interface* pUI) const;
	void move(const Interface* pUI, double time);
	void coast();
	void fly();
	void land();
	void crash();
private:
	int status; // 0 for coast, 1 for land, 2 for crash
	Point position;
	Velocity velocity;
	Angle angle;
	double fuel;
	Force thrust;
};