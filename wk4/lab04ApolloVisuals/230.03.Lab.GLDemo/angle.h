/***********************************************************************
 * Header File:
 *     Angle : Represents the angle that the lunar module is pointing.
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object contianing information of where the lunar module is pointing.
 ************************************************************************/

#pragma once

#include <iostream>  // for cout

using namespace std;

 /************************************
  * ANGLE class
  ************************************/
class Angle
{

public:
    // Methods
	double getDegrees();
	double getRadians() const;
	double addRadians(double radians);
	void setDegrees(double degrees);
	void setRadians(double angle);
	void display(ostream& out);

private:
    // Attributes
	double radians;
	// Methods
	double normalize(double angle);
	double convertToDegrees(double angle);
	double convertToRadians(double degrees);
};
