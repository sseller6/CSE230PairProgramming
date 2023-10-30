/***********************************************************************
 * Header File:
 *     Force
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object containing the physics for the force of the M777 Howitzer.
 ************************************************************************/

#pragma once
#include "xyComponents.h"

// Forward declarations
class Acceleration;
class Velocity;

/************************************
 * FORCE class
 ************************************/
class Force
{
private:
	double forceX;
	double forceY;

public:
	Force();
	Force(double aRadians, double force);
	double computeForce(double mass, double acceleration);
	void   updateForce(double mass, Acceleration &acceleration);
	
	// GETTERS
	double getForceX();
	double getForceY();
	double getForce();

	// SETTERS
	void setForceX(double value);
	void setForceY(double value);
	void setForce(double aRadians, double totalForce);
};

/************************************
 * GRAVITY class
 ************************************/
class Gravity : public Force
{
private:
	double acceleration;
public:
	Gravity();
	Gravity(double force);
	double computeForce(double mass, double altitude);
	void   updateForce(double mass, double altitude);
	double getAcceleration(double altitude);
};

/************************************
 * DRAGFORCE class
 ************************************/
class DragForce : public Force
{
private:
	double dragCoefficient;
	double mediumDensity;
public:
	DragForce();
	DragForce(double dragCoefficient, double mediumDensity);
	double computeForce(double surfaceArea, double velocity);
	void   updateForce(double surfaceArea, Velocity &velocity);
};
