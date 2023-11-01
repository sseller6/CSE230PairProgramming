#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

// Area from radius
double areaFromRadius(double radius)
{
	return	M_PI * (radius * radius);
}