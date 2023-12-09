/***********************************************************************
 * Source File:
 *    Projectile : The representation of the projectile on screen.
 * Author:
 *    Jarom & Steven
 * Summary:
 *    Everything we need to know about the projectile.
 ************************************************************************/

#pragma once

#include "physics.h"
#include "projectile.h"
#include "uiDraw.h"

using namespace std;

// Constructors

/***************************************
 * Default Constructor
 ***************************************/
Projectile::Projectile()
	: mass(0.00),
	  radius(0.00),
      flightPath()
{
}

/***************************************
 * NON-Default Constructor
 ***************************************/
Projectile::Projectile(double mass, double radius)
	: mass(mass),
	  radius(radius),
	  flightPath()
{
}

/***************************************
 * RESET
 * Resets all attributes
 ***************************************/
void Projectile::reset()
{

}

/***************************************
 * FIRE
 * Used for initial variables for pvt
 ***************************************/
void Projectile::fire(Position position, double time,
	                  double angle, double velocity)
{
	pvt.pt = position;
	pvt.v.setDX(computeHorizontalComponent(angle, velocity));
	pvt.v.setDY(computeVerticalComponent(angle,velocity));
	pvt.t = time;
	flightPath.push_back(pvt);
}

/***************************************
 * ADVANCE
 * Advance the projectile farther along.
 ***************************************/
void Projectile::advance(double timeInterval)
{   
	double angle = angleFromComponents(pvt.v.getDX(), pvt.v.getDY());
	double speed = computeTotalComponent(pvt.v.getDX(), pvt.v.getDY());
	double altitude = pvt.pt.getMetersY();

	// Compute Drag
	double dragForce = forceFromDrag(densityFromAltitude(altitude),
									 dragFromMach(computeMach(speed, speedOfSoundFromAltitude(altitude))),
								     radius,
								     speed);

	// Compute Gravity
	double gravityForce = gravityFromAltitude(altitude);
	
	// Sum Forces
	double netXForce = computeHorizontalComponent(angle, dragForce);
	double netYForce = computeVerticalComponent(angle, dragForce) + gravityForce;

	// Compute Change in acceleration
	double ddx = computeAcceleration(netXForce, mass);
	double ddy = computeAcceleration(netYForce, mass);

	// Compute change in velocity
	double dx = computeVelocity(speed, ddx, timeInterval);
	double dy = computeVelocity(speed, ddy, timeInterval);

	// Update position
	pvt.pt.setMeters(computeNewPosition(pvt.pt.getMetersX(), dx, ddx, timeInterval),
		             computeNewPosition(pvt.pt.getMetersY(), dy, ddy, timeInterval));

	// update Velocity
	pvt.v.addDX(dx);
	pvt.v.addDY(dy);

	// update time
	pvt.t += timeInterval;

	// Add to flight path
	flightPath.push_back(pvt);
}

/***************************************
 * DRAW
 ***************************************/
void Projectile::draw(ogstream& gout)
{
	gout.drawProjectile(pvt.pt);
}

/***************************************
 * FLYING
 ***************************************/
bool Projectile::flying()
{
	return false;
}

/***************************************
 * GET ALTITUDE
 ***************************************/
double Projectile::getAltitude()
{
	return 0.0;
}

/***************************************
 * GET POSITION
 ***************************************/
Position Projectile::getPosition()
{
	return Position();
}

/***************************************
 * GET FLIGHT TIME
 ***************************************/
double Projectile::getFlightTime()
{
	return 0.0;
}

/***************************************
 * GET FLIGHT DISTANCE
 ***************************************/
double Projectile::getFlightDistance()
{
	return 0.0;
}

/***************************************
 * GET SPEED
 ***************************************/
double Projectile::getSpeed()
{
	return 0.0;
}

/***************************************
 * GET CURRENT TIME
 ***************************************/
double Projectile::getCurrentTime()
{
	return 0.0;
}

/***************************************
 * SET MASS
 ***************************************/
void Projectile::setMass(double mass)
{
	this->mass = mass;
}

/***************************************
 * SET RADIUS
 ***************************************/
void Projectile::setRadius(double radius)
{
	this->radius = radius;
}
