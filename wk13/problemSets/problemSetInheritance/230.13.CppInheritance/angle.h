/*************************************************************
 * 1. Name:
 *      Jarom & Steven
 * 2. Module
 *      ANGLE
 * 3. Assignment Description:
 *      A class to represent an angle
 **************************************************************/

#pragma once

#include <iostream>
#include <cassert>
#include <math.h>

using namespace std;

#define PI           3.141592653589793238462643383279502
#define TWO_PI       6.28318530718
#define ONE_DEGREE   (PI / 180)

class TestAngle;

/************************************
 * ANGLE
 ************************************/
class Angle
{
	friend TestAngle;

protected:
	/**************************************************************************
	 * NORMALIZE
	 * Takes a radian as a parameter and reduce it to between 0
	 * and 2π. For example, 3π will become π, 362° will become 2°, -5° will
	 * become 355°, and -7π will become π.
	 **************************************************************************/
	double normalize(double angle) const
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
	/**************************************************************************
	 * CONVERT TO DEGREES
	 * Takes a radians as a parameter and returns degrees.
	 * Does not utilize the class's attribute. Note that the results must be
	 * normalized.
	 **************************************************************************/
	double convertToDegrees(double angle) const
	{
		return normalize(angle) / TWO_PI * 360;
	}
	/**************************************************************************
	 * CONVERT TO RADIANS
	 * Takes a degrees as a parameter and returns radians.
	 * Does not utilize the class's attribute. Note that the results must be
	 * normalized.
	 **************************************************************************/
	double convertToRadians(double degrees) const
	{
		double angle = degrees * (TWO_PI / 360); // convert to radians
		angle = normalize(angle);
		return angle;
	}
public:
	// Attributes
	double radians;

	/********************************
	 * DEFAULT CONSTRUCTOR
	 ********************************/
	Angle()
	{
		radians = 0.0;
	}

	/********************************
	 * NON-DEFAULT CONSTRUCTOR
	 * (input: degrees)
	 ********************************/
	Angle(double degrees)
	{
		radians = convertToRadians(degrees);
	}

	/********************************
	 * COPY CONSTRUCTOR
	 ********************************/
	Angle(const Angle& other)
	{
		radians = other.radians;
	}

	/**************************************************************************
	 * GET DEGREES
	 * Takes no parameters and return the angle in degrees.
	 **************************************************************************/
	double getDegrees() const
	{
		return convertToDegrees(radians);
	}
	/**************************************************************************
	 * GET RADIANS
	 * Takes no parameters and return the angle in radians.
	 **************************************************************************/
	double getRadians() const
	{
		return radians; // Angle is already in radians
	}

	/**************************************************************************
	 * SET DEGREES
	 * Takes a degrees as a parameter and updates the attribute
	 * with the passed parameter. If the parameter is above 360 or below zero,
	 * then it will "unwrap" so the radians is between 0 and 2π.
	 **************************************************************************/
	void setDegrees(double degrees)
	{
		this->radians = convertToRadians(degrees);
	}
	/**************************************************************************
	 * SET RADIANS
	 * Takes a radian as a parameter and updates the attribute
	 * with the passed parameter. If the parameter is above 2π or below zero,
	 * then it will "unwrap."
	 **************************************************************************/
	void setRadians(double angle)
	{
		this->radians = normalize(angle);
	}

	/**************************************************************************
	 * DISPLAY
	 * Takes a ostream & out as a parameter display the value, in
	 * degrees, to 1 decimal place of accuracy. This out parameter can be
	 * treated exactly the same as cout. You can use it with a.display(cout)
	 * if a is the name of your object.
	 **************************************************************************/
	virtual void display(ostream& out) const
	{
		out.setf(ios::fixed);     // "fixed" means don't use scientific notation
		out.setf(ios::showpoint); // "showpoint" means always show the decimal point
		out.precision(1);         // Set the precision to 1 decimal place of accuracy.

		out << convertToDegrees(radians);
	}

	/********************************
	* NEGATIVE OPERATOR
	* Negates the value of the angle
	********************************/
	Angle& operator-()
	{
		Angle negated;
		negated.radians = normalize(radians - PI);
		return negated;
	}

	/********************************
	 * INCREMENT OPERATOR
	 * Increments data.
	 ********************************/
	 // Prefix increment ++x
	virtual Angle& operator++()
	{
		radians = normalize(radians += ONE_DEGREE);
		return *this;
	}
	// Postfix increment x++
	virtual Angle operator++(int postfix)
	{
		Angle numReturn(*this);
		radians = normalize(radians += ONE_DEGREE);
		return numReturn;
	}

	/********************************
	 * DECREMENT OPERATOR
	 * Decrements data.
	 ********************************/
	 // Prefix decrement --x
	virtual Angle& operator--()
	{
		radians = normalize(radians -= ONE_DEGREE);
		return *this;
	}
	// Postfix decrement x--
	virtual Angle operator--(int postfix)
	{
		Angle numReturn(*this);
		radians = normalize(radians -= ONE_DEGREE);
		return numReturn;
	}
};

/********************************
* EQUALS OPERATOR
* Returns true if member
* variables are equal
********************************/
inline bool operator==(const Angle& lhs, const Angle& rhs)
{
	return lhs.radians == rhs.radians;
}

/********************************
* NOT EQUALS OPERATOR
* Returns false if member
* variables are equal
********************************/
inline bool operator!=(const Angle& lhs, const Angle& rhs)
{
	return lhs.radians != rhs.radians;
}

/********************************
 * INSERTION OPERATOR
 * Inserts output to the screen.
 ********************************/
inline ostream& operator<<(ostream& out,
	const Angle& rhs)
{
	out.setf(ios::fixed);     // "fixed" means don't use scientific notation
	out.setf(ios::showpoint); // "showpoint" means always show the decimal point
	out.precision(1);         // Set the precision to 1 decimal place of accuracy.

	out << rhs.getDegrees();
	return out;
}

/********************************
 * EXRRACTION OPERATOR
 * Receives input from user.
 ********************************/
inline istream& operator>>(istream& in,
	Angle& rhs)
{
	double degrees;
	in >> degrees;
	if (not in.fail())
		rhs.setDegrees(degrees);
	return in;
}

/******************************************************************************
 * ANGLE RADIANS
 * It inherits from angle. It implements virtual functions and changes stuff.
 ******************************************************************************/
class AngleRadians : public Angle 
{
public:
	// Constructors

	/**************************************************************************
	 * DEFAULT CONSTRUCTOR
	 **************************************************************************/
	AngleRadians()
	{
		radians = 0.0;
	}
	/**************************************************************************
	 * NON-DEFAULT CONSTRUCTOR
	 **************************************************************************/
	AngleRadians(double radians) 
	{
		radians = radians;
	}

	/*
	* NON DEFAULT CONSTRUCTOR
	*/
	AngleRadians(Angle angle)
	{
		this->radians = angle.radians;
	}

	/********************************
	 * COPY CONSTRUCTOR
	 ********************************/
	AngleRadians(const AngleRadians& other)
	{
		radians = other.radians;
	}
	// Methods

	/**************************************************************************
	 * DISPLAY
	 * Displays Radians at 2 decimal places of accuracy.
	 **************************************************************************/
	void display(ostream& out) const
	{
		out.setf(ios::fixed);     // "fixed" means don't use scientific notation
		out.setf(ios::showpoint); // "showpoint" means always show the decimal point
		out.precision(2);         // Set the precision to 2 decimal place of accuracy.

		out << radians << "radians";
	}

	/********************************
	 * ASSIGNMENT OPERATOR
	 ********************************/

	/********************************
	 * INCREMENT OPERATOR
	 * Increments data.
	 ********************************/
	 // Prefix increment ++x
	Angle& operator++()
	{
		radians = normalize(radians += PI / 8);
		return *this;
	}
	// Overloaded postfix increment operator (++)
	Angle operator++(int) {
		// Increment the radians value
		radians += PI /8;

		// Normalize the radians if necessary
		radians = normalize(radians);

		// Return a copy of the modified AngleRadians object cast as Angle
		return Angle(*this);
	}

	/********************************
	 * DECREMENT OPERATOR
	 * Decrements data.
	 ********************************/
	 // Prefix decrement --x
	 Angle& operator--()
	{
		radians = normalize(radians -= PI / 8);
		return *this;
	}
	// Postfix decrement x--
    virtual Angle operator--(int postfix)
	{
		Angle numReturn(*this);
		radians = normalize(radians -= PI / 8);
		return numReturn;
    }
};