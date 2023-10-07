/********************************************************************
* Header File:
*     HUD : Heads Up Display
* Author:
*    Jarom Anderson & Steven Sellers
* Summary:
*     A heads up display to display important info to the player
*******************************************************************/

#pragma once
#include "lander.h"

class HUD
{
private:
	// Attributes
	Point position;
	double fuel;
	double altitude;
	double speed;
	double angle;

public:
	// Methods
	HUD();
	HUD(const Point& ptUpperRight);
	void updateHUD(const Lander &lander);
	void draw(ogstream& gout, const Lander& lander);

};