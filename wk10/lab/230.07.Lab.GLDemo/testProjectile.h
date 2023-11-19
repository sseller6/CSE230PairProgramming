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
		reset();
		test_default_constructor();
		report("projectileDefaultConstructor()");

		// projectile.reset()
		reset();
		test_reset_empty();
		test_reset_full();
		report("projectileReset()");

		// projectile.fire()
		reset();
		test_fire_right();
		test_fire_left();
		test_fire_up();
		report("projectileFire()");

		// projectile.advance()
		reset();
        advance_nothing();
		advance_fall();
		advance_up();
		advance_diagonal();
		report("projectileAdvance()");

	}
private:

	double metersFromPixels = -1.0;

	bool closeEnough(double value, double test, double tolerance) const
	{
		double difference = value - test;
		return (difference >= -tolerance) && (difference <= tolerance);
	}

	void test_defaultConstructor()
	{
		// Setup

		// Exercise
		Projectile p;
		// Verify
		assert(p.mass == 46.7);
	    assert(p.radius == 0.077545);
		assert(p.flightPath.empty() == true);
		// Teardown
	}

    // Test Reset
	void test_reset_empty()
	{
		// Setup
        
		// Exercise

		// Verify

		// Teardown
	}

	void test_reset_full();
	// Test Fire

	// Test advance

};