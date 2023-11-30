/***********************************************************************
 * Source File:
 *    Howitzer : The representation of the Howitzer on the screen.
 * Author:
 *    Jarom & Steven
 * Summary:
 *    Everything we need to know about the howitzer.
 ************************************************************************/

#pragma once

#include <iostream>
#include "howitzer.h"
#include "velocity.h"
#include "uiInteract.h"

using namespace std;

// Constructors

/***************************************
 * Default Constructor
 ***************************************/
Howitzer::Howitzer()
{
}

/***************************************
 * NON-Default Constructor
 ***************************************/
Howitzer::Howitzer() // I'm not sure what to do for the non-default constructor
{
}

/***************************************
 * DRAW
 ***************************************/
void Howitzer::draw(ogstream& gout, double flightTime)
{

}

/***************************************
 * Generate Position
 ***************************************/
void Howitzer::generatePosition(double size)
{

}

/***************************************
 * ROTATE
 * Moves the Howitzer by a large amount.
 ***************************************/
void Howitzer::rotate(double radians)
{

}

/***************************************
 * RAISE 
 * Moves the Howitzer by a little.
 ***************************************/
void Howitzer::raise(double radians)
{
	// move by a little
	if (pUI->isUp())
		pDemo->angle += (pDemo->angle >= 0 ? -0.003 : 0.003);
	if (pUI->isDown())
		pDemo->angle += (pDemo->angle >= 0 ? 0.003 : -0.003);

}

// Getters

/***************************************
 * GET POSITION
 ***************************************/
double Howitzer::getPosition()
{

}

/***************************************
 * GET MUZZLE VELOCITY
 ***************************************/
Velocity Howitzer::getMuzzleVelocity()
{

}