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
		test_defaultConstructor();
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
        test_advance_nothing();
		test_advance_fall();
		test_advance_up();
		test_advance_diagonal();
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
		Projectile p;
		// Exercise
		p.reset();
		// Verify
		assert(p.mass == 46.7);
		assert(p.radius == 0.077545);
		assert(p.flightPath.empty() == true);
		// Teardown
	}

	void test_reset_full()
	{
		// Setup
		Projectile p;
		Projectile::PositionVelocityTime pvt;
		p.flightPath.push_back(pvt);
		p.flightPath.push_back(pvt);
		p.flightPath.push_back(pvt);
		assert(p.flightPath.size() == 3);
		// exercise
		p.reset();
		// Verify
		assert(p.mass == 46.7);
		assert(p.radius == 0.077545);
		assert(p.flightPath.empty() == true);
		// teardown
	}
	// Test Fire
	void test_fire_right()
	{
		// setup
		setupStandardFixture();
		Projectile p;
		Position pos;
		pos.x = 111.0;
		pos.y = 222.0;
		double simulationTime(1.0);
		Direction d;
		d.radians = M_PI / 2.0; // 90 degrees to the right
		double muzzleVelocity(100.0);
		// exercise
		p.fire(pos, simulationTime, d, muzzleVelocity);
		// verify
		assert(p.mass == 46.7);
		assert(p.radius == 0.077545);
		assert(p.flightPath.size() == 1);
		assert(p.flightPath.front().pt.x == 111.0);
		assert(p.flightPath.front().pt.y == 222.0);
		assert(closeEnough(100.0, p.flightPath.front().v.dx, 0.01));
		assert(closeEnough(  0.0, p.flightPath.front().v.dy, 0.01));
		assert(p.flightPath.front().t == 1.0);
		// teardown
		teardwonStandardFixture();
	}

	void test_fire_left()
	{
		// setup
		setupStandardFixture();
		Projectile p;
		Position pos;
		pos.x = 111.0;
		pos.y = 222.0;
		double simulationTime(1.0);
		Direction d;
		d.radians = -M_PI / 2.0; // 270 degrees to the right
		double muzzleVelocity(100.0);
		// exercise
		p.fire(pos, simulationTime, d, muzzleVelocity);
		// verify
		assert(p.mass == 46.7);
		assert(p.radius == 0.077545);
		assert(p.flightPath.size() == 1);
		assert(p.flightPath.front().pt.x == 111.0);
		assert(p.flightPath.front().pt.y == 222.0);
		assert(closeEnough(-100.0, p.flightPath.front().v.dx, 0.01));
		assert(closeEnough(   0.0, p.flightPath.front().v.dy, 0.01));
		assert(p.flightPath.front().t == 1.0);
		// teardown
		teardwonStandardFixture();
	}

	void test_fire_up()
	{
		// setup
		setupStandardFixture();
		Projectile p;
		Position pos;
		pos.x = 111.0;
		pos.y = 222.0;
		double simulationTime(1.0);
		Direction d;
		d.radians = 0.0; // 90 degrees to the right
		double muzzleVelocity(100.0);
		// exercise
		p.fire(pos, simulationTime, d, muzzleVelocity);
		// verify
		assert(p.mass == 46.7);
		assert(p.radius == 0.077545);
		assert(p.flightPath.size() == 1);
		assert(p.flightPath.front().pt.x == 111.0);
		assert(p.flightPath.front().pt.y == 222.0);
		assert(closeEnough( 0.0, p.flightPath.front().v.dx, 0.01));
		assert(closeEnough(100.0, p.flightPath.front().v.dy, 0.01));
		assert(p.flightPath.front().t == 1.0);
		// teardown
		teardwonStandardFixture();
	}

	// Test advance
	test_advance_nothing()
	{
		// Setup
		setupStandardFixture();
		Projectile p;
		// exercise
		p.advance(1.0);
		// verify
		assert(p.mass == 46.7);
		assert(p.radius == 0.077545);
		assert(p.flightPath.empty() == true);
		// Teardown
		teardownStandardFixture();
	}

	test_advance_fall()
	{
		// Setup
		setupStandardFixture();
		Projectile p;
		Projectile::PositionVelocityTime pvt;
		pvt.pt.x = 100.0;
		pvt.pt.y = 200.0;
		pvt.v.setDX(0.0);
		pvt.v.setDY(0.0);
		pvt.t = 100.0;
		p.flightPath.push_back(pvt);
		// exercise
		p.advance(101.0);
		// verify
		assert(p.mass == 46.7);
		assert(p.radius == 0.077545);
		assert(p.flightPath.size() == 2);
		assert(closeEnough(100.0, p.flightPath.back().pt.x, 0.01));
		assert(closeEnough(190.19, p.flightPath.back().pt.y, 0.01));
		assert(closeEnough(0.0, p.flightPath.back().v.dx, 0.01));
		assert(closeEnough(-9.806, p.flightPath.back().v.dy, 0.01));
		assert(p.flightPath.back().t == 101.0);
		// Teardown
		teardownStandardFixture();
	}

	test_advance_up()
	{
		// Setup
		setupStandardFixture();
		Projectile p;
		Projectile::PositionVelocityTime pvt;
		pvt.pt.x = 100.0;
		pvt.pt.y = 200.0;
		pvt.v.setDX(0.0);
		pvt.v.setDY(100.0);
		pvt.t = 100.0;
		p.flightPath.push_back(pvt);
		// exercise
		p.advance(101.0);
		// verify
		assert(p.mass == 46.7);
		assert(p.radius == 0.077545);
		assert(p.flightPath.size() == 2);
		assert(closeEnough(100.0, p.flightPath.back().pt.x, 0.01));
		assert(closeEnough(289.80, p.flightPath.back().pt.y, 0.01));
		assert(closeEnough(0.0, p.flightPath.back().v.dx, 0.01));
		assert(closeEnough(89.80, p.flightPath.back().v.dy, 0.01));
		assert(p.flightPath.back().t == 101.0);
		// Teardown
		teardownStandardFixture();
	}

	test_advance_diagonal()
	{
		// Setup
		setupStandardFixture();
		Projectile p;
		Projectile::PositionVelocityTime pvt;
		pvt.pt.x = 100.0;
		pvt.pt.y = 200.0;
		pvt.v.setDX(50.0);
		pvt.v.setDY(40.0);
		pvt.t = 100.0;
		p.flightPath.push_back(pvt);
		// exercise
		p.advance(101.0);
		// verify
		assert(p.mass == 46.7);
		assert(p.radius == 0.077545);
		assert(p.flightPath.size() == 2);
		assert(closeEnough(150.0, p.flightPath.back().pt.x, 0.01));
		assert(closeEnough(230.1, p.flightPath.back().pt.y, 0.01));
		assert(closeEnough(50.0, p.flightPath.back().v.dx, 0.01));
		assert(closeEnough(30.1, p.flightPath.back().v.dy, 0.01));
		assert(p.flightPath.back().t == 101.0);
		// Teardown
		teardownStandardFixture();
	}

	// setup standard fixture - set the zoom to 1100m per pixel
	void setupStandardFixture()
	{
		Position p;
		metersFromPixels = p.metersFromPixels;
		p.metersFromPixels = 1.0;
	}
};