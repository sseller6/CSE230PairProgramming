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
private:
	// Attributes
	int status;

	// Methods
public:
	Status();
	bool isDead();
	bool isLanded();
	bool isFlying();
	bool isCoasting();
	void setStatus(int status);
	int getStatus() const;
	int checkStatus() const;


}