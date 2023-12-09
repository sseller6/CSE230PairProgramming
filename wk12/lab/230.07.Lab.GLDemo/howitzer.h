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
class Simulation;

class Howitzer
{
	friend TestHowitzer;
	friend Simulation;
public:
	// Constructors
	Howitzer();

	// Methods
	void draw(ogstream& gout, double flightTime); // figure out gout.
    void generatePosition(double size);
    void rotateRight();
	void rotateLeft();
    void raiseUp();
	void raiseDown();

	// Getters
	Position  getPosition();
    double    getMuzzleVelocity();
	double    getMuzzleAngle();

    // Setters
    void setMuzzleVelocity(Velocity velocity);

private:
    // Attributes
    Position position;
    double muzzleVelocity;
    Direction elevation; // This is our angle.
};