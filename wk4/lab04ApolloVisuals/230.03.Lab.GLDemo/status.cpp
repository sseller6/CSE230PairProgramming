/***********************************************************************
 * Header File:
 *    Status : Contains the status of the LM.
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of Status which contains the state of the LM.
 ************************************************************************/

#include "status.h"

// Defualt Constructor
Status :: Status()
{
}

// Is the status of the LM dead.
bool Status :: isDead()
{
	return false;
}

// Is the status of the LM landed.
bool Status :: isLanded()
{
	return false;
}

// Is the status of the LM flying.
bool Status :: isFlying()
{
	return false;
}

// Is the status of the LM coasting.
bool Status :: isCoasting()
{
	return false;
}

int Status::checkStatus() const
{
	switch (status)
		case 0 // isDead
	return 0;
}
