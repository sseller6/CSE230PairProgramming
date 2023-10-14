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
	: position(ptUpperRight.getX() / 2.0, ptUpperRight.getY()),
      width(1),
      fuel(5000),
      isFlying(false),
      angle(0),
      velocity(0, 0),
      thrust(45000.00),
      gravity(-1.625),
      mass(15103.00),
      time(0.1) // HARD CODED VALUE
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
 * GET WIDTH
 * Returns the lander's width.
 *****************************************************************/
int Lander::getWidth() const
{
    return this->width;
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
 * setIsFlying
 * Sets isFlying to true
 *****************************************************************/
void Lander::setIsFlying(bool value) 
{
    isFlying = value;
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
 * DRAW
 * Draws the lander on the screen.
 *****************************************************************/
void Lander::draw(ogstream &gout, const Interface* pUI) const
{
    double LMangle = angle.getRadians();
    // Taken from demo draw LM
    gout.drawLander(position, LMangle);
    // Current implementation only draws flames when thruster engaged
    if (isFlying == true)
    {
        gout.drawLanderFlames(position, LMangle, /*angle*/
            pUI->isDown(), pUI->isLeft(), pUI->isRight());
    }
}

/******************************************************************
 * MOVE 
 * Moves the lander based on status.
 *****************************************************************/
void Lander::move()
{
    if (isFlying == true)
    {
        useFuel(10);
        // Caclculate total acceleration includeing thrust
        double accelerationThrust = thrust.getForce() / mass;
        acceleration.setDDX(computeHorizontalComponent(accelerationThrust));
        acceleration.setDDY(computeVerticalComponent(accelerationThrust) + gravity);

    }
    else
    {
        // Caclulate total acceleration without thrust
        acceleration.setDDX(0.00);
        acceleration.setDDY(gravity);
    }

   // Calculate change in velocity
    velocity.addX(acceleration.getDDX(), time);
    velocity.addY(acceleration.getDDY(), time);

   // Calculate new position
    position.setX(computeNewPosition(position.getX(), velocity.getDX(),
        acceleration.getDDX(), time));
    position.setY(computeNewPosition(position.getY(), velocity.getDY(),
        acceleration.getDDY(), time));
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

void Lander::stop()
{
    // Stub Method may be irrelevant
}

/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(angle) = y / total
 ***********************************************/
double Lander::computeVerticalComponent(double total)
{
    // Find vertical component of a velocity or accelration.
    double y;
    y = cos(angle.getRadians()) * total;
    return y;
}

/***********************************************
 * COMPUTE HORIZONTAL COMPONENT
 * Find the horizontal component of a velocity or acceleration.
 * The equation is:
 *     sin(angle) = x / total
 ***********************************************/
double Lander::computeHorizontalComponent(double total)
{
    double x;
    x = -sin(angle.getRadians()) * total;
    return x;
}

double Lander::computeNewPosition(double position0, double v, double a, double t)
{
	double position1 = position0 + v * t + (a * (t * t) / 2);
	return position1;
}