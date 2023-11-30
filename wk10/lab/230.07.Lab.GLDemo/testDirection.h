/*************************************************************
 * Module
 *      TEST DIRECTION
 * Description:
 *      Unit tests for the Direction class
 * Author:
 *      Jarom Anderson & Steven Sellers.
 **************************************************************/

#pragma once

#include "direction.h"
#include "unitTest.h"
#include <iostream>
#include <cassert>


 /************************************
  * TEST DIRECTION
  ************************************/
class TestDirection : public UnitTest
{
public:
	void run()
	{
		/***************************************
		* Brother Helfrich's code to add.
		****************************************/
		test_defaultConstructor();
		test_convertDegreesToRadians_from_0();
		test_convertDegreesToRadians_from_90();
        test_convertDegreesToRadians_from_359();
		test_setRadians_correct();
		test_setDegrees_correct();
		test_setDown_correct();
		test_setUp_correct();
		test_setRight_correct();
		test_setLeft_correct();
        test_reverse_from_0_degrees();
		test_reverse_from_90_degrees();
		test_reverse_from_359_degrees();
		test_getRadians_correct();
		test_getDegrees_correct();
	}

private:
	/***************************************
	* Brother Helfrich's code to add.
	* The code added between lines 112 and
	* 126 were added, because 
	* testDirection.h needed them.
	****************************************/
	bool closeEnough(double value, double test, double tolerance) const
	{
		double difference = value - test;
		return (difference >= -tolerance) && (difference <= tolerance);
	}

	void test_defaultConstructor() const
	{
		// setup
		// exercise
		Direction d;
		// verify
		assert(d.radians == 0.00);
		// teardown
	}

	/***************************************
	 * CONVERT DEGREES TO RADIANS
	 ***************************************/
	void test_convertDegreesToRadians_from_0()
	{
		// Setup
		Direction direction;
		double degrees = 0;
		// Exercise
		double result = direction.convertDegreesToRadians(degrees);
		// Verify
		assert(result == 0.0);
		// Teardown
	}

	void test_convertDegreesToRadians_from_90()
	{
        // Setup
        Direction direction;
        double degrees = 90;
        // Exercise
        double result = direction.convertDegreesToRadians(degrees);
        // Verify
        assert(result = 1.57);
        // Teardown
	}

	void test_convertDegreesToRadians_from_359()
	{
        // Setup
        Direction direction;
        double degrees = 359;
        // Exercise
        double result = direction.convertDegreesToRadians(degrees);
        // Verify
        assert(result = 6.26);
        // Teardown
	}
	/***************************************
	 * SET RADIANS
	 ***************************************/
	void test_setRadians_correct()
	{
		// Setup
		Direction direction;
		// Exercise
		direction.setRadians(3.14);
		double result = direction.getRadians();
		// Verify
		assert(result = 3.14);
		// Teardown
	}

	/***************************************
	 * SET DEGREES
	 ***************************************/
	void test_setDegrees_correct()
	{
		// Setup
		Direction direction;
		// Exercise 
		direction.setDegrees(90);
		double result = direction.getDegrees();
		// Verify
		assert(result == 90);
		// Teardown
	}

	/***************************************
	 * SET DOWN --------------- FINISHED
	 ***************************************/
	void test_setDown_correct()
	{
		// Setup
		Direction direction;
		// Exercise
		direction.setDown();
		// Verify
		assert(direction.radians == 3.14); // 3.14 = pointing straight down.
		// Teardown
	}
	/***************************************
	 * SET UP ----------------- FINISHED
	 ***************************************/
	void test_setUp_correct()
	{
		// Setup
		Direction direction;
		// Exercise
		direction.setUp();
		// Verify
		assert(direction.radians == 0.00); // 0.00 = pointing straight up.
		// Teardown
	}
	/***************************************
     * SET RIGHT--------------- FINISHED
     ***************************************/
	void test_setRight_correct()
	{
		// Setup
		Direction direction;
		// Exercise
		direction.setRight();
		// Verify
		assert(closeEnough(direction.radians, 1.5708, 0.001)); // 1.57 = pointing to the right.
		// Teardown
	}
	/***************************************
	 * SET LEFT --------------- FINISHED
	 ***************************************/
	void test_setLeft_correct()
	{
		// Setup
		Direction direction;
		// Exercise
		direction.setLeft();
		// Verify
		assert(direction.radians == 4.71239); // 4.71 = pointing to the left.
		// Teardown
	}
	/***************************************
	 * REVERSE ---------------- FINISHED
	 ***************************************/
	void test_reverse_from_0_degrees()
	{
        // This test verifies if an angle that starts at 0 degrees
        // will successfully be changed to 180 degrees. 
		// Setup
		Direction direction;
		direction.setDegrees(0.00);
		// Exercise
		direction.reverse();
		// Verify
		assert(closeEnough(direction.radians, 3.14159, 0.01));
		// Teardown
	}

	void test_reverse_from_90_degrees()
	{
		// This test verifies if an angle that starts at 90 degrees
		// will successfully be changed to 270 degrees. 
		// Setup
		Direction direction;
		direction.setDegrees(90);
		// Exercise
		direction.reverse();
		// Verify
		assert(closeEnough(direction.radians, 4.71239, 0.00001));
		// Teardown
	}

	void test_reverse_from_359_degrees()
	{
		// This test verifies if an angle that starts off at 359 
		// degrees will successfully be changed to 179 degrees.
		// Setup
		Direction direction;
		direction.setDegrees(359);
		// Exercise
		direction.reverse();
		// Verify
		assert(closeEnough(direction.radians, 3.12414, 0.001));
		// Teardown
	}
    /***************************************
	 * GET RADIANS
	 ***************************************/
	void test_getRadians_correct()
	{
		// Setup
		Direction direction;
		direction.setDegrees(90);
		// Exercise
		double result = direction.getRadians();
		// Verify
		assert(closeEnough(result, 1.5708, 0.001));
	}
	/***************************************
	 * GET DEGREES
	 ***************************************/
	void test_getDegrees_correct()
	{
		// Setup
		Direction direction;
		direction.setDegrees(90);
		// Exercise
		double result = direction.getDegrees();
		// Verify
		assert(result == 90.0);
	}

};