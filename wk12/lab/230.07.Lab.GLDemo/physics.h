#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

using namespace std;


#ifndef  M_PI
#define  M_PI  3.1415926535897932384626433
#endif

double gravityFromAltitude(double altitude);
double densityFromAltitude(double altitude);
double dragFromMach(double mach);
double speedOfSoundFromAltitude(double altitude);

inline double computeMach(double speed, double speedOfSound)
{
	if (speedOfSound == 0.0)
		return 0.0;
	// mach = speed / speed of sound
	return speed / speedOfSound;
}

inline double areaFromRadius(double radius) 
{
	// area = pi * r^2
	return M_PI * radius * radius;
}

inline double forceFromDrag(double density, double drag,
	                        double radius, double velocity)
{
	// compute area
	double area = areaFromRadius(radius);

	// compute drag
	return 0.5 * density * drag * area * velocity * velocity;
}

inline double accelerationFromForce(double force, double mass)
{
	// acceleration = force / mass
	return force / mass;
}

inline double velocityFromAcceleration(double acceleration, double time)
{
	// velocity = acceleration * time
	return acceleration * time;
}

struct Mapping
{
	double domain;
	double range;
};

inline double linearInterpolation(double d0, double r0,
	                              double d1, double r1,
	                              double d)
{
	double range;
    // r = r0 + (r1 - r0) (d - d0) / (d1 - d0)
	
	if ((d1 - d0) != 0.0)
		 range = r0 + (r1 - r0) * (d - d0) / (d1 - d0);
	else
		 range = 0.0;

	return range;
}

inline double linearInterpolation(const Mapping& zero,
	                              const Mapping& one,
	                              double d)
{
	return linearInterpolation(zero.domain, zero.range,
		                       one.domain, one.range,
		                       d);
}

/***********************************************
 * COMPUTE HORIZONTAL COMPONENT
 * Find the horizontal component of a velocity or acceleration.
 * The equation is:
 *     sin(a) = x / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     aRadians : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     x : the vertical component of the total
 ***********************************************/
inline double computeHorizontalComponent(double aRadians, double total)
{
	double x;
	x = sin(aRadians) * total;
	return x;
}

/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     aRadians : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     y : the vertical component of the total
 ***********************************************/
inline double computeVerticalComponent(double aRadians, double total)
{
	// Find vertical component of a velocity or accelration.
	double y;
	y = cos(aRadians) * total;
	return y;
}

/************************************************
 * COMPUTE TOTAL COMPONENT
 * Given the horizontal and vertical components of
 * something (velocity or acceleration), determine
 * the total component. To do this, use the Pythagorean Theorem:
 *    x^2 + y^2 = t^2
 * where:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    | /
 *    |/
 * INPUT
 *    x : horizontal component
 *    y : vertical component
 * OUTPUT
 *    total : total component
 ***********************************************/
inline double computeTotalComponent(double x, double y)
{
	double total;
	total = sqrt((x * x) + (y * y));
	return total;
}

/***********************************************
 * COMPUTE ACCELERATION
 ***********************************************/
inline double computeAcceleration(double force, double mass)
{
	return force / mass;
}

/***********************************************
 * COMPUTE VELOCITY
 ***********************************************/
inline double computeVelocity(double velocity, double acceleration, double timeInterval)
{
	// Find the new velocity.
	return velocity + (acceleration * timeInterval);
}

/*****************************************************************
* COMPUTE NEW POSITION
* Calculates the new x or y value based on physics.
*****************************************************************/
inline double computeNewPosition(double position, double velocity, double acceleration, double time)
{
	return position + (velocity * time) + ((acceleration * (time * time) / 2));
}

/*****************************************************************
* ANGLE FROM COMPONENTS
* Compute angle from velocity components
*****************************************************************/
inline double angleFromComponents(double dx, double dy)
{
	return atan2(dx, dy);
}