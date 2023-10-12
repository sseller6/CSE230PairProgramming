/******************************************************************
 * Source File:
 *    Status : Contains the status of the LM.
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of Status which contains the state of the LM.
 *****************************************************************/

#include "status.h"

/******************************************************************
 * STATUS : CONSTRUCTOR
 * Default constructor.
 *****************************************************************/
Status :: Status()
{
}

/******************************************************************
 * IS DEAD
 * Returns if the status of the LM is dead.
 *****************************************************************/
// 
bool Status :: isDead()
{
	return true;
}

/******************************************************************
 * IS LANDED
 * Returns if the status of the LM is landed.
 *****************************************************************/
bool Status :: isLanded()
{
	return true;
}
/******************************************************************
 * IS FLYING
 * Returns if the status of the LM is flying.
 *****************************************************************/
// Is the status of the LM flying.
bool Status :: isFlying()
{
	return true;
}

/******************************************************************
 * IS COASTING
 * Returns if the status of the LM is coasting.
 *****************************************************************/
bool Status :: isCoasting()
{
	return true;
}
/******************************************************************
 * CHECK STATUS
 * Returns the status of the lander.
 *****************************************************************/
int Status::checkStatus() const
{
	return 0;
}
