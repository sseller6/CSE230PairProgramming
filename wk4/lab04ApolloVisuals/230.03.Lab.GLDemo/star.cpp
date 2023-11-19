/*******************************************************************
 * Source File:
 *     Star
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of the star class.
 ******************************************************************/

#include "star.h"

 /******************************************************************
  * STAR : CONSTRUCTOR
  * Default constructor.
  *****************************************************************/
Star :: Star() : phase(0)
{
}

/******************************************************************
 * SET POSITION
 * Sets the position of a star.
 *****************************************************************/
void Star::setPosition(double x, double y)
{
	position.setX(x);
	position.setY(y);
}
/******************************************************************
 * SET PHASE
 * Sets the phase of a star.
 *****************************************************************/
void Star::setPhase(unsigned char number)
{
	phase = number;
}
/******************************************************************
 * GET POSITION
 * Gets the position of a star.
 *****************************************************************/
Point Star::getPositon()
{
	return position;
}
/******************************************************************
 * GET PHASE
 * Gets the phase of a star.
 *****************************************************************/
int Star::getPhase()
{
	return phase;
}

/******************************************************************
 * INCREMENT PHASE
 * Changes phase value by 1.
 *****************************************************************/
void Star::incrementPhase()
{
	phase++;
}



