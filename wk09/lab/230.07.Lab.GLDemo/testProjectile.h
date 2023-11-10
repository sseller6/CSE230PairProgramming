#pragma once

#include "projectile.h"
#include "unitTest.h"

/****************************
* TEST PROJECTILE
*****************************/

class TestProjectile : public UnitTest
{
public:
	void run()
	{

		// projectile.fire()
		reset();

		report("projectileFire()");

		// projectile.advance()
		reset();

		report("projectileAdvance()");

	}
private:

	/****************************
	* TEST RESET
	* Make sure reset method sets attributes
	* to their default values.
	*****************************/


	/****************************
	* TEST FIRE
	*****************************/


	/****************************
	* TEST ADVANCE
	*****************************/

		


};