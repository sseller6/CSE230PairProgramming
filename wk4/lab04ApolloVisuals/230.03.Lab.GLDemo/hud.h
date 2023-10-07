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
	double fuel;
	double altitude;
	double speed;
	double angle;

public:
	// Methods
	void updateHUD();

};