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

// More Needed later