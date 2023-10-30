/***********************************************************************
 * Header File:
 *     Acceleration
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object containing the physics for acceleration of the M777 Howitzer.
 ************************************************************************/

#pragma once
#include "force.h"

 /************************************
  * ACCELERATION class
  ************************************/
class Acceleration
{
private:
	double ddx;
	double ddy;

public:
	Acceleration();

	// Methods
	void   updateAcceleration(Force& force, double mass);
	double computeAcceleration(double force, double mass);

	// Getters
	double getDDX();
	double getDDY();

	// Setters
	void setDDX();
	void setDDY();
};

