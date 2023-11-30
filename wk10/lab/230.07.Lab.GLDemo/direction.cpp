
#include "direction.h"
#include <cmath>            // for normalize()


#ifndef TWO_PI
#define TWO_PI 6.28318530717958647693 
#endif

#ifndef  M_PI
#define  M_PI  3.1415926535897932384626433
#endif

// Constructors

/***************************************
 * Default Constructor
 ***************************************/
Direction::Direction()
: radians(0.00)
{
}

/***************************************
 * Non-Default Constructor
 ***************************************/
Direction::Direction(double radians)
    : radians(radians)
{
}

// Methods

/***************************************
 * ASSIGN
 ***************************************/
void Direction::assign(Direction rhs)
{
	// I can't remember why, but we decided to not implement this for now.
}

/***************************************
 * REVERSE
 ***************************************/
void Direction::reverse()
{
	// Set radians to the opposite side of where it's pointing.
	radians += M_PI;
	// Then normalize it.
	radians = normalize(radians);

	// For example. If radians is already 3.14, then it's techincally
	// pointing to 180 degrees. Line 40 would add 3.14 radians or 180 degrees
	// in order to reverse the direction.
	// Then line 42 normalizes the radians.
}

// Setters

/***************************************
 * SET RADIANS
 ***************************************/
void Direction::setRadians(double radians)
{
    this->radians = normalize(radians);
}

/***************************************
 * SET DEGREES
 ***************************************/
void Direction::setDegrees(double degrees)
{
	radians = convertDegreesToRadians(degrees);
}

/***************************************
 * SET DOWN
 ***************************************/
void Direction::setDown()
{
	radians = 3.14;
}

/***************************************
 * SET UP
 ***************************************/
void Direction::setUp()
{
	radians = 0.00;
}

/***************************************
 * SET RIGHT
 ***************************************/
void Direction::setRight()
{
	radians = 1.5708;
}

/***************************************
 * SET LEFT
 ***************************************/
void Direction::setLeft()
{
	radians = 4.71239;
}

// Getters

/***************************************
 * GET RADIANS
 ***************************************/
double Direction::getRadians() const
{
	return radians;
}

/***************************************
 * GET DEGREES
 ***************************************/
double Direction::getDegrees() 
{
	return convertRadiansToDegrees(radians);
}

/*************************************************
 * RADIANS FROM DEGEES
 * Convert degrees to radians:
 *  radians = (degrees * PI) / 180
 * INPUT
 *     d : degrees from 0 to 360
 * OUTPUT
 *     r : radians from 0 to 2pi
 **************************************************/
double Direction::convertDegreesToRadians(double degrees)
{
    return normalize((degrees * M_PI) / 180);
}

/***************************************************
* RADIANS TO DEGREES
***************************************************/
double Direction::convertRadiansToDegrees(double radians)
{
	return (normalize(radians) * 180) / M_PI;
}

double Direction::normalize(double angle)
{
	// For anything greater than 2π
	while (angle > TWO_PI)
	{
		angle -= TWO_PI;
	}

	// For anything less than 0.
	while (angle < 0)
	{
		angle += TWO_PI;
	}

	return angle;
}