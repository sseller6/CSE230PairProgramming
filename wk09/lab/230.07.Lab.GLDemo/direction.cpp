#include "direction.h"

// Constructors

/***************************************
 * Default Constructor
 ***************************************/
Direction::Direction()
: radians(0.00)
{
}

/***************************************
 * Non-Default Constructor
 ***************************************/
Direction::Direction(double radians)
    : radians(radians)
{
}

// Methods

/***************************************
 * ASSIGN
 ***************************************/
void Direction::assign(Direction rhs)
{

}

/***************************************
 * REVERSE
 ***************************************/
void Direction::reverse()
{

}

// Setters

/***************************************
 * SET RADIANS
 ***************************************/
void Direction::setRadians(double rhs)
{
    radians = rhs;
}

/***************************************
 * SET DEGREES
 ***************************************/
void Direction::setDegrees(double rhs)
{

}

/***************************************
 * SET DXDY
 ***************************************/
void Direction::setDxDy(double dx, double dy)
{

}

/***************************************
 * SET DOWN
 ***************************************/
void Direction::setDown()
{

}

/***************************************
 * SET UP
 ***************************************/
void Direction::setUp()
{

}

/***************************************
 * SET RIGHT
 ***************************************/
void Direction::setRight()
{

}

/***************************************
 * SET LEFT
 ***************************************/
void Direction::setLeft()
{

}

// Getters

/***************************************
 * GET RADIANS
 ***************************************/
double Direction::getRadians()
{
    return 0.00;
}

/***************************************
 * GET DEGREES
 ***************************************/
double Direction::getDegrees()
{
    return 0.00;
}

/***************************************
 * GET DX
 ***************************************/
double Direction::getDx()
{
    return 0.00;
}

/***************************************
 * GET DY
 ***************************************/
double Direction::getDy()
{
    return 0.00;
}

/*************************************************
 * RADIANS FROM DEGEES
 * Convert degrees to radians:
 *     radians / 2pi = degrees / 360
 * INPUT
 *     d : degrees from 0 to 360
 * OUTPUT
 *     r : radians from 0 to 2pi
 **************************************************/
double convertDegreesToRadians(double d)
{
    double pi = 3.14159265359;
    double r;
    r = (d / 360) * (2 * pi);
    return r;
}