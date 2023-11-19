/*************************************************************
 * 1. Name:
 *      Jarom Anderson & Steven Sellers
 * 2. Assignment Name:
 *      Practice 03: Angle Class
 * 3. Assignment Description:
 *      A class to represent an angle
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/

#pragma once

#define TWO_PI 6.28318530718

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
using namespace std;

class TestAngle;

 /************************************
  * ANGLE
  ************************************/
class Angle
{
	friend TestAngle;

private:

	// Attributes
	double radians;

	//Implement Private Methods:
	// normalize(): Takes a radian as a parameter and reduce it to between 0
	// and 2π. For example, 3π will become π, 362° will become 2°, -5° will
	// become 355°, and -7π will become π.
	double normalize(double angle)
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

	// convertToDegrees(): Takes a radians as a parameter and returns degrees.
	// Does not utilize the class's attribute. Note that the results must be
	// normalized.
	double convertToDegrees(double angle)
	{
		angle = normalize(angle);
		double degrees = angle * (360 / TWO_PI);
		return degrees;
	}

	// convertToRadians(): Takes a degrees as a parameter and returns radians.
	// Does not utilize the class's attribute. Note that the results must be
	// normalized. 
	double convertToRadians(double degrees)
	{
		double angle = degrees * (TWO_PI / 360); // convert to radians
		angle = normalize(angle);
		return angle;
	}

	// Implement Public Methods:
public:
	double getDegrees() // Takes no parameters and return the angle in degrees. 
	{
		double degrees = convertToDegrees(radians);
		return degrees;
	}

	double getRadians() // Takes no parameters and return the angle in radians. 
	{
		return radians; // Angle is already in radians
	}

	// Takes a degrees as a parameter and updates the attribute
	// with the passed parameter. If the parameter is above 360 or below zero,
	// then it will "unwrap" so the radians is between 0 and 2π.
	void setDegrees(double degrees)
	{
		radians = convertToRadians(degrees);
	}
 
	// Takes a radian as a parameter and updates the attribute
	// with the passed parameter. If the parameter is above 2π or below zero,
	// then it will "unwrap." 
	void setRadians(double angle) 
	{
		radians = normalize(angle);
	}

	// Takes a ostream & out as a parameter display the value, in
	// degrees, to 1 decimal place of accuracy. This out parameter can be
	// treated exactly the same as cout. You can use it with a.display(cout)
	// if a is the name of your object.
	void display(ostream &out)
	{
		out.setf(ios::fixed);     // "fixed" means don't use scientific notation
		out.setf(ios::showpoint); // "showpoint" means always show the decimal point
		out.precision(1);         // Set the precision to 1 decimal place of accuracy.
	    
		out << convertToDegrees(radians) << "degrees";

	}
};


