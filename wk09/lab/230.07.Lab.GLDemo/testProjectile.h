/*************************************************************
 * Module
 *      TEST Projectile
 * Description:
 *      Unit tests for the Projectile class
 * Author:
 *      Jarom Anderson & Steven Sellers.
 **************************************************************/

#pragma once

#include "projectile.h"
#include "unitTest.h"
#include <cassert>



/****************************
* TEST PROJECTILE
*****************************/

class TestProjectile : public UnitTest
{
public:
	void run()
	{
		// projectile.reset()
		reset();
		test_reset_Default();
		test_reset_nonDefault();
		test_reset_alteredMass();
		test_reset_alteredRadius();
		report("projectileReset()");

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
	// Test default constructor - Black Box
	void test_reset_Default()
	{
		// Setup
		Projectile projectile;
		// Exersize
		projectile.reset();
		// Verify
		assert(projectile.mass == 0.00);
		assert(projectile.radius == 0.00);
		assert(projectile.flightPath.empty());
		// Teardown
	}

	// Test non-default constructor - Black Box
	void test_reset_nonDefault()
	{
		// Setup
		Projectile projectile(5.00, 3.00);
		// Exersize
		projectile.reset();
		// Verify
		assert(projectile.mass == 5.00);
		assert(projectile.radius == 3.00);
		assert(projectile.flightPath.empty());
		// Teardown
	}
	
	// Test altered states - White Box
	
	// Change mass
	void test_reset_alteredMass()
	{
		// Setup
		Projectile projectile;
		projectile.mass = 7.00;
		// Exersize
		projectile.reset();
		// Verify
		assert(projectile.mass == 0.00);
		assert(projectile.radius == 0.00);
		assert(projectile.flightPath.empty());
		// Teardown
	}

	// Test altered Radius
	void test_reset_alteredRadius()
	{
		// Setup
		Projectile projectile;
		projectile.radius = 5.00;
		// Exersize
		projectile.reset();
		// Verify
		assert(projectile.mass == 0.00);
		assert(projectile.radius == 0.00);
		assert(projectile.flightPath.empty());
		// Teardown
	}


	/****************************
	* TEST FIRE
	*****************************/


	/****************************
	* TEST ADVANCE
	*****************************/

		


};