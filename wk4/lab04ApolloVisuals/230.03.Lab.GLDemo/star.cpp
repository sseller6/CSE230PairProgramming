/***********************************************************************
 * Header File:
 *     Star
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of all information for the stars.
 ************************************************************************/

#include "star.h"

// Default Constructor
Star :: Star() : phase(0)
{
}

void Star::setPosition(double x, double y)
{
	position.setX(x);
	position.setY(y);
}

void Star::setPhase(unsigned char number)
{
	phase = number;
}

Point Star::getPositon()
{
	return position;
}

int Star::getPhase()
{
	return phase;
}



