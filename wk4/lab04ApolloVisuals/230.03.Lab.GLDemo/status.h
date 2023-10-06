/***********************************************************************
 * Header File:
 *    Status : Contains the status of the LM.
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object named Status which contains the state of the LM.
 ************************************************************************/

#pragma once
 
#include "lander.h"


 /***********************************************************
  * Status
  * The Status class
  ***********************************************************/

class Status
{
public:
	Status();
	bool isDead();
	bool isLanded();
	bool isFlying();
	bool isCoasting();
	void setStatus() const;
	int getStatus();

private:
	int status;

};