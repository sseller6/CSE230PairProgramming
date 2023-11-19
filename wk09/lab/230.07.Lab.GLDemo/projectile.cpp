#include "projectile.h"

Projectile::Projectile()
	: mass(0.00),
	  radius(0.00),
      flightPath()
{
}

Projectile::Projectile(double mass, double radius)
	: mass(mass),
	  radius(radius),
	  flightPath()
{
}

// Resets all attributes
void Projectile::reset()
{
}

// Used for initial variables for pvt
void Projectile::fire(Position position, double time,
	                  double angle, double velocity)
{
}

void Projectile::advance(double time)
{
}

void Projectile::draw()
{
}

bool Projectile::flying()
{
	return false;
}

double Projectile::getAltitude()
{
	return 0.0;
}

Position Projectile::getPosition()
{
	return Position();
}

double Projectile::getFlightTime()
{
	return 0.0;
}

double Projectile::getFlightDistance()
{
	return 0.0;
}

double Projectile::getSpeed()
{
	return 0.0;
}

double Projectile::getCurrentTime()
{
	return 0.0;
}

void Projectile::setMass()
{
}

void Projectile::setRadius()
{
}
