#include "projectile.h"

Projectile::Projectile()
{
}

Projectile::Projectile(double mass, double radius)
{
}

// Resets all attributes
void Projectile::reset()
{
}

//
void Projectile::fire()
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
