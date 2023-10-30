/****************************************************************************
 * Header File:
 *     Angle : Represents the angle that the lunar module is pointing.
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object contianing information of where the M777 Howitzer is pointing.
 ***************************************************************************/

#pragma once

#include <iostream>  // for cout

using namespace std;

 /************************************
  * ANGLE class
  ************************************/
class Angle
{

public:
	Angle();
	Angle(double aRadians);
    // Methods
	double getDegrees();
	double getRadians() const;
	void   addRadians(double radians);
	void   setDegrees(double degrees);
	void   setRadians(double angle);
	void   display(ostream& out);

private:
    // Attributes
	double radians;
	// Methods
	double normalize(double angle);
	double convertToDegrees(double angle);
	double convertToRadians(double degrees);
};
