#pragma once

#include "force.h"

class Acceleration
{
private:
	double ddx;
	double ddy;

public:
	Acceleration();

	// Methods
	void updateAcceleration(Force& force, double mass);
	double computeAcceleration(double force, double mass);

	// Getters
	double getDDX();
	double getDDY();

	// Setters
	void setDDX();
	void setDDY();
};

