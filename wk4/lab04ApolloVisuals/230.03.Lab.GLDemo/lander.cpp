/***********************************************************************
 * Source File:
 *    Lander.
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    The source file for lander.
 ************************************************************************/

#include "lander.h"

 // Default constructor
Lander::Lander(Point ptUpperRight) 
    // By default, set the lander at the center of the screen
	: position(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0)
{}

// Resets the lander attributes to original values
void Lander::reset()
{
}

// Returns the lander's positoin
Point Lander::getPosition() const
{
	return position;
}

int Lander::getFuel() const
{
	return 0;
}

bool Lander::getStatus() const
{
	return this->status;
}

// Sets the lander's status
// 0 for engine disengaged
// 1 for engine engaged
void Lander::setStatus(bool status)
{
	this->status = status;
}

void Lander::draw(Thrust &thrust, ogstream &gout) const
{
}

// Moves lander based on status
void Lander::move(const Interface* pUI)
{
	// Handle user input
    if (pUI->isRight())
        angle.add(0.1);
    if (pUI->isLeft())
        angle.add(0.1);
    if (pUI->isUp())
        position.addY(-1.0);
    if (pUI->isDown())
        position.addY(1.0);

}

void Lander::coast()
{
}

void Lander::land()
{
}

void Lander::crash()
{
}

