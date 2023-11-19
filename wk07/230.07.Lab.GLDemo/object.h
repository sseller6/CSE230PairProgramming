/***********************************************************************
 * Header File:
 *    Inertia : Represents the inertia of an object
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Everything about inertia
 ************************************************************************/

#pragma once

#include <vector>

class Object
{
private:
	// Attributes
	double mass;
	XYVector positon;
	XYVector velocity;
	XYVector acceleration;
	vector<Force> forces;

public:
	// Methods

	// Physics
	void updateAcceleration();
	void updateVelocity();
	void updatePosition();
};

