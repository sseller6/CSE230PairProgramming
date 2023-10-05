/************************************************
VELOCITY
************************************************/

#pragma once

#include <math.h>    // for math
#include <iostream>  // for cout

using namespace std;

class Velocity

{
	// Methods
public:
	Velocity();
	Velocity(double dx, double dy);
	double getDX() const;
	double getDY() const;
	double getSpeed() const;
	void setDX(double dx);
	void setDY(double dy);
	void add(double accel, double time);
private:
    // Attributes
	double dx;
	double dy;
};