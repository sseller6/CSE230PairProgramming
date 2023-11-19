#pragma once

using namespace std;
// forward declaration for the Velocity unit tests

class TestVelocity;

class Velocity
{
private:

public:
	// Setters
	void setDxDy(double dx, double dy);
	// Getters
	double getDx();
	double getDy();
};