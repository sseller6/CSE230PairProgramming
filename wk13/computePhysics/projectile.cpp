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
	cout << "Projectile Fired" << endl;
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
	cout << "PVT before: p: " << pvt.pt << ", v: " << pvt.v.getDX() << "x " << pvt.v.getDY() << "y, t: " << pvt.t << endl;
	
	// update time
	pvt.t += timeInterval;

	double angle = angleFromComponents(pvt.v.getDX(), pvt.v.getDY());
	double speed = computeTotalComponent(pvt.v.getDX(), pvt.v.getDY());
	double altitude = pvt.pt.getMetersY();

	// Compute Drag
	double dragForce = forceFromDrag(densityFromAltitude(altitude),
									 dragFromMach(computeMach(speed, speedOfSoundFromAltitude(altitude))),
								     radius,
								     speed);
	cout << "drag: " << dragForce << endl;

	// Compute Gravity
	double gravityForce = gravityFromAltitude(altitude);
	cout << "gravity: " << gravityForce << endl;
	
	// Sum Forces
	double netXForce = computeHorizontalComponent(angle, dragForce);
	double netYForce = computeVerticalComponent(angle, dragForce);
	cout << "netXForce: " << netXForce << ", netYForce: " << netYForce << endl;

	// Compute Acceleration
	double ddx = -computeAcceleration(netXForce, mass);
	double ddy = -computeAcceleration(netYForce, mass) - gravityForce;
	cout << "accX: " << ddx << ", accY: " << ddy << endl;

	// Compute change in velocity 
	double velX = ddx * timeInterval;
	double velY = ddy * timeInterval;
	cout << "velX: " << velX << ", velY: " << velY << endl;

	// Add change in velocity
	pvt.v.addX(velX);
	pvt.v.addY(velY);

	// double dx = computeVelocity(speed, ddx, timeInterval);
	// pvt.v.addX(ddx, timeInterval);
	// double dy = computeVelocity(speed, ddy, timeInterval);
	// pvt.v.addY(ddy, timeInterval);

	// Update position
	pvt.pt.setMetersX(computeNewPosition(pvt.pt.getMetersX(), pvt.v.getDX(), ddx, timeInterval));
	pvt.pt.setMetersY(computeNewPosition(pvt.pt.getMetersY(), pvt.v.getDY(), ddy, timeInterval));


	// Add to flight path
	flightPath.push_back(pvt);

	cout << "PVT after: p: " << pvt.pt << ", v: " << pvt.v.getDX() << "x " << pvt.v.getDY() << "y, t: " << pvt.t << endl;
	cout << "advanced\n" << endl;
}

//TODO FIX BULLET FLIGHT PATH GRAPHICS
/***************************************
 * DRAW
 ***************************************/
void Projectile::draw(ogstream& gout)
{
	int count = 0;
	//decleration of vector iterator
	vector<PositionVelocityTime>::iterator iter = flightPath.begin();

	for (iter; iter < flightPath.end(); iter++)
	{
		PositionVelocityTime bullet = *iter;
		gout.drawProjectile(bullet.pt);
		count++;
	}
}

/***************************************
 * FLYING
 * Is the projectile flying? 
 ***************************************/
bool Projectile::flying()
{
	if (pvt.pt.getMetersY() > 0)
		return true;
	else
		return false;
}

void Projectile::display()
{
	vector<PositionVelocityTime>::iterator iter = flightPath.begin();
	PositionVelocityTime pvt;

	for (iter; iter < flightPath.end(); iter++)
	{
		pvt = *iter;
	}

	cout << "Distance: "  << pvt.pt.getMetersX() << " meters" << endl;
	cout << "Altitude: "  << pvt.pt.getMetersY() << " meters" << endl;
	cout << "Hang Time: " << pvt.t << " seconds" << endl;
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
