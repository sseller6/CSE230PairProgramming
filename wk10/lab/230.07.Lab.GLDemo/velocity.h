#pragma once

using namespace std;
// forward declaration for the Velocity unit tests

class TestVelocity;
class TestProjectile;

class Velocity
{
	friend TestVelocity;
	friend TestProjectile;
private:
	double dx;
	double dy;
	
public:
	// Setters
	void setDX(double dx);
	void setDY(double dy);
	void setDxDy(double dx, double dy);
	// Getters
	double getDx();
	double getDy();
};