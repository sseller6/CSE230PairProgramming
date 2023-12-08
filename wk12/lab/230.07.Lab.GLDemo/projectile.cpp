/***********************************************************************
 * Source File:
 *    Projectile : The representation of the projectile on screen.
 * Author:
 *    Jarom & Steven
 * Summary:
 *    Everything we need to know about the projectile.
 ************************************************************************/

#pragma once

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
}

/***************************************
 * ADVANCE
 * Advance the projectile farther along.
 ***************************************/
void Projectile::advance(double time)
{
}

/***************************************
 * DRAW
 ***************************************/
void Projectile::draw(ogstream& gout)
{
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
void Projectile::setMass()
{
}

/***************************************
 * SET RADIUS
 ***************************************/
void Projectile::setRadius()
{
}
