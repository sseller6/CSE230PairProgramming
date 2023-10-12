/***********************************************************************
 * Header File:
 *     Lander : Represents the lander in the lunar lander simulator
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object contianing all of the properties of the lander.
 ************************************************************************/

#pragma once

#include "angle.h"         // for Angle
#include "acceleration.h"  // for acceleration
#include "point.h"         // for Point
#include "force.h"         // for thrust
#include "game.h"          // for time
#include "velocity.h"      // for Velocity
#include "uiInteract.h"    // for controls
#include "uiDraw.h"        // for ogstream
#include "status.h"        // for status


// The lander class
class Lander
{
public:
	Lander(Point ptUpperRight);
	void reset();
	// Getters
	Point getPosition() const;
	Angle getAngle() const;
	Velocity getSpeed() const;
	double getFuel() const;
	// Setters
	void useFuel(double ammount);
	int getStatus() const;
	void setStatus(int status);
	void draw(ogstream &gout, const Interface* pUI) const;
	// Movements
	void move();
	void rotateLeft(double radians);
	void rotateRight(double radians);
    // Status modifiers
	void coast();
	void fly();
	void land();
	void crash();
private:
	int status; // 0 for coast, 1 for fly, 2 for land, 3 for crash
	Point position;
	Velocity velocity;
	Acceleration acceleration;
	Angle angle;
	double fuel;
	Force thrust;

	// Physics
	double computeNewPosition(double position0, double v, double a, double t);

};