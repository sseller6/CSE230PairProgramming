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
#include "velocity.h"      // for Velocity
#include "uiInteract.h"    // for controls
#include "uiDraw.h"        // for ogstream


// The lander class
class Lander
{
public:
	Lander(Point ptUpperRight);
	void reset();
	// Getters
	Point getPosition() const;
	int getWidth() const;
	Angle getAngle() const;
	Velocity getSpeed() const; // Cannot be const?
	double getFuel() const;
	// Setters
	void setIsFlying(bool value);
	void useFuel(double ammount);
	void draw(ogstream &gout, const Interface* pUI) const;
	// Movements
	void move();
	void stop();
	void rotateLeft(double radians);
	void rotateRight(double radians);
private:
	bool isFlying;
	Point position;
	Velocity velocity;
	Acceleration acceleration;
	Angle angle;
	double fuel;
	Force thrust;
	double gravity;
	double width;
	double mass;
	double time;

	// Physics
	double computeVerticalComponent(double total);
	double computeHorizontalComponent(double total);
	double computeNewPosition(double position0, double v, double a, double t);

};