/***********************************************************************
 * Header File:
 *    Howitzer : The representation of the howitzer on the screen.
 * Author:
 *    Jarom & Steven
 * Summary:
 *    Everything we need to know about the howitzer.
 ***********************************************************************/

#pragma once

#include "direction.h"
#include "uiDraw.h"

using namespace std;

class TestHowitzer;

class Howitzer
{
	friend TestHowitzer;
public:
	// Constructors
	Howitzer();
	Howitzer(double position); // should the non-defualt constuctor have position as a parameter?

	// Methods
	void draw(ogstream& gout, double flightTime); // figure out gout.
    void generatePosition(double size);
    void rotate(double radians);
    void raise(double radians);

	// Getters
	double getPosition();
    Velocity getMuzzleVelocity();

    // Setters
    void setMuzzleVelocity(Velocity velocity);

private:
    // Attributes
    Position position;
    double muzzleVelocity;
    Direction elevation;
};