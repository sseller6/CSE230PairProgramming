/****************************************************************************
 * Source File:
 *     Angle : Represents the angle that the lunar module is pointing.
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of where the M777 Howitzer is pointing.
 ***************************************************************************/

#define TWO_PI 6.28318530718

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
#include "angle.h"   
using namespace std;

/*************************************************************************
 * NORMALIZE 
 * Takes a radian as a parameter and reduce it to between 0 and 2π.
 ************************************************************************/
double Angle::normalize(double angle)
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

/*************************************************************************
 * CONVERT TO DEGREES
 * Takes a radians as a parameter and returns degrees.
 ************************************************************************/
double Angle::convertToDegrees(double angle)
{
	angle = normalize(angle);
	double degrees = angle * (360 / TWO_PI);
	return degrees;
}

/*************************************************************************
 * CONVERT TO RADIANS
 * Takes a degrees as a parameter and returns radians.
 ************************************************************************/
double Angle::convertToRadians(double degrees)
{
	double angle = degrees * (TWO_PI / 360); // convert to radians
	angle = normalize(angle);
	return angle;
}

/*************************************************************************
 * 
 * Default Constructor
 ************************************************************************/
Angle::Angle() : radians(0)
{}

/*************************************************************************
 * Non-Default Constructor
 ************************************************************************/
Angle::Angle(double aRadians) : radians(aRadians)
{}

/*************************************************************************
 * GET DEGREES
 * Takes no parameters and return the angle in degrees.
 ************************************************************************/
double Angle::getDegrees() 
{
    double degrees = convertToDegrees(radians);
	return degrees;
}

/*************************************************************************
 * GET RADIANS
 * Takes no parameters and return the angle in radians.
 ************************************************************************/
double Angle::getRadians() const
{
	return radians; // Angle is already in radians
}

/*************************************************************************
 * ADD RADIANS
 * Adds radians to the angle of the LM.
 ************************************************************************/
void Angle::addRadians(double radians)
{
	this->radians += radians;
}

/*************************************************************************
 * SET DEGREES
 * Takes a degrees as a parameter and updates the attribute
 * with the passed parameter. If the parameter is above 360 or below zero,
 * then it will "unwrap" so the radians is between 0 and 2π.
 ************************************************************************/
void Angle::setDegrees(double degrees)
{
	radians = convertToRadians(degrees);
}

/*************************************************************************
 * SET RADIANS
 * Takes a radian as a parameter and updates the attribute
 * with the passed parameter. If the parameter is above 2π or below zero,
 * then it will "unwrap." 
 ************************************************************************/

void Angle::setRadians(double angle)
{
	radians = normalize(angle);
}

/*************************************************************************
 * DISPLAY 
 * Takes a ostream & out as a parameter display the value, in
 * degrees, to 1 decimal place of accuracy. This out parameter can be
 * treated exactly the same as cout.
 ************************************************************************/

void Angle::display(ostream& out)
{
    out.setf(ios::fixed);     // "fixed" means don't use scientific notation
	out.setf(ios::showpoint); // "showpoint" means always show the decimal point
	out.precision(1);         // Set the precision to 1 decimal place of accuracy.
	
	out << convertToDegrees(radians) << "degrees";

}


