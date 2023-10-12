/*******************************************************************
 * Source File:
 *    Lander.
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of the lander object.
 ******************************************************************/

#include "lander.h"

 /******************************************************************
  * LANDER : CONSTRUCTOR
  * Default constructor.
  *****************************************************************/
Lander::Lander(Point ptUpperRight) 
    // By default, set the lander at the center of the screen
	: position(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),
      fuel(5000),
      status(false),
      angle(0),
      velocity(0, 0),
      thrust(45000.00)
{}

/******************************************************************
 * RESET
 * Resets the lander attributes to original values.
 *****************************************************************/
void Lander::reset()
{
}

/******************************************************************
 * GET POSITION
 * Returns the lander's current position.
 *****************************************************************/
Point Lander::getPosition() const
{
	return this->position;
}

/******************************************************************
 * GET ANGLE
 * Returns the current angle of the lander.
 *****************************************************************/
Angle Lander::getAngle() const
{
    return angle;
}

/******************************************************************
 * GET SPEED
 * Returns the current speed of the lander.
 *****************************************************************/
Velocity Lander::getSpeed() const
{
    return velocity;
}

/******************************************************************
 * GET FUEL
 * Returns the current fuel of the lander.
 *****************************************************************/
double Lander::getFuel() const
{
	return this->fuel;
}

/******************************************************************
 * USE FUEL
 * Subtracts ammount of fuel spent.
 *****************************************************************/
void Lander::useFuel(double ammount)
{
    this->fuel -= ammount;
}
/******************************************************************
 * GET STATUS
 * Subtracts ammount of fuel spent.
 *****************************************************************/
int Lander::getStatus() const
{
	return this->status;
}

/******************************************************************
 * SET STATUS
 * Sets the lander's status
 * 0 for coast
 * 1 for flying
 * 2 land
 * 3 for crash
 *****************************************************************/
void Lander::setStatus(int status)
{
	this->status = status;
}
/******************************************************************
 * DRAW
 * Draws the lander on the screen.
 *****************************************************************/
void Lander::draw(ogstream &gout, const Interface* pUI) const
{
    double LMangle = angle.getRadians();
    // Taken from demo draw LM
    gout.drawLander(position, LMangle);
    gout.drawLanderFlames(position, LMangle, /*angle*/
        pUI->isDown(), pUI->isLeft(), pUI->isRight());
}

/******************************************************************
 * MOVE 
 * Moves the lander based on status.
 *****************************************************************/
void Lander::move()
{
    
}

/******************************************************************
 * ROTATE LEFT
 * Rotates lander left by specified radians
 *****************************************************************/
void Lander::rotateLeft(double radians)
{
    angle.addRadians(radians);
    useFuel(0.1);
}

/******************************************************************
 * ROTATE RIGHT
 * Rotates lander right by specified radians
 *****************************************************************/
void Lander::rotateRight(double radians)
{
	angle.addRadians(-radians);
	useFuel(0.1);
}

/******************************************************************
 * COAST
 * The lander is 
 *****************************************************************/
void Lander::coast()
{
    
}

void Lander::fly()
{
    // Caclculate change in acceleration due to thrust

    // Caclulate total acceleration

    // Calculate change in velocity

    // Calculate new position
    useFuel(10);
    position.setX(computeNewPosition(position.getX(), velocity.getDX(),
                                     acceleration.getDDX(), game.getTime()));
    position.setY(computeNewPosition(position.getY(), velocity.getDY(),
                                     acceleration.getDDY(), game.getTime()));
}

void Lander::land()
{
    // Stub
}

void Lander::crash()
{
    // Stub
}

double computeNewPosition(double position0, double v, double a, double t)
{
	double position1 = position0 + v * t + (a * (t * t) / 2);
	return position1;
}