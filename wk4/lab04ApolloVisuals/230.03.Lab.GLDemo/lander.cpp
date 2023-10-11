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
	: position(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),
      fuel(5000),
      status(false),
      angle(0),
      velocity(0, 0)
{}

// Resets the lander attributes to original values
void Lander::reset()
{
}

// Returns the lander's positoin
Point Lander::getPosition() const
{
	return this->position;
}

Angle Lander::getAngle() const
{
    return angle;
}

Velocity Lander::getSpeed() const
{
    return velocity;
}

double Lander::getFuel() const
{
	return this->fuel;
}

// Subtracts ammount of fuel spent
void Lander::useFuel(double ammount)
{
    this->fuel -= ammount;
}

int Lander::getStatus() const
{
	return this->status;
}

// Sets the lander's status
// 0 for coast
// 1 for flying
// 2 land
// 3 for crash
void Lander::setStatus(int status)
{
	this->status = status;
}

void Lander::draw(ogstream &gout, const Interface* pUI) const
{
    double LMangle = angle.getRadians();

    // Taken from demo draw LM
    gout.drawLander(position, LMangle);
    gout.drawLanderFlames(position, LMangle, /*angle*/
        pUI->isDown(), pUI->isLeft(), pUI->isRight());
}

// Moves lander based on status
void Lander::move(const Interface* pUI, double time)
{
	// Handle user input
    
    // Check fuel
    if (getFuel() > 0) // Has enough fuel to change angle
    {
        if (pUI->isRight())
        {
            angle.addRadians(0.1);
            position.addX(1.0); // Temporary movement
            useFuel(0.1);
        }
        if (pUI->isLeft())
        {
            angle.addRadians(-0.1);
            position.addX(-1.0); // Temporary movement
            useFuel(0.1);
        }
        
        // Has enough fuel to engage main engine
        if (getFuel() > 10)
        {
            (pUI->isDown()) ? fly() : coast(); // if down is pressed, engage thruster (fly). Otherwise just coast
        }
    }

    // Handle Physics
    //TODO
    

}

void Lander::coast()
{
}

void Lander::fly()
{
    position.addY(1.0);
    useFuel(10);
}

void Lander::land()
{
}

void Lander::crash()
{
}

