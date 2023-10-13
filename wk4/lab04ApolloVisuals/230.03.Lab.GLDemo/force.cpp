/*************************************************************************
 * Source File:
 *     Force : Indicates rotation and moving up
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of Force that indicates rotation and direction of the LM.
 ************************************************************************/

#include "force.h"

 /************************************************************************
 * Default Constructor
 ************************************************************************/
Force::Force() : force(0)
{
}

/************************************************************************
* NON DEFAULT CONSTRUCTOR
************************************************************************/
Force::Force(double newtons) : force(newtons)
{
}

/*************************************************************************
* GET FORCE
* Takes no parameters and get force.
*************************************************************************/
int Force::getForce()
{
	return force;
}
/*************************************************************************
* SET FORCE
* Takes no parameters and set force.
*************************************************************************/
void Force::setForce()
{
}
