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
#include <cassert>

 /************************************
  * TEST DIRECTION
  ************************************/
class TestDirection : public UnitTest
{
public:
	void run()
	{
		// direction.convertDegreesToRadians()
		reset();
		test_convertDegreesToRadians_from_0();
		test_convertDegreesToRadians_from_90();
        test_convertDegreesToRadians_from_359();
		report("convertDegreesToRadians");
		// direction.assign()
		reset();

		report("directionAssign()");

		// direction.setRadians()
		reset();
		test_setRadians_correct();
		report("directionSetRadians()");

		// direction.setDegrees()
		reset();
		test_setDegrees_correct();
		report("directionSetDegrees()");

		// direction.setDxDy()
		reset();
		test_setDxDy_correct();
		report("directionSetDxDy()");

		// direction.setDown()
        reset();
		test_setDown_correct();
		report("directionSetDown()");

		// direction.setUp()
        reset();
		test_setUp_correct();
		report("directionSetUp()");

		// direction.setRight()
        reset();
		test_setRight_correct();
		report("directionSetRight()");

		// direction.setLeft()
        reset();
		test_setLeft_correct();
		report("directionSetLeft()");

		// direction.reverse()
		reset();
        test_reverse_from_0_degrees();
		test_reverse_from_90_degrees();
		test_reverse_from_359_degrees();
		report("directionReverse()");

		// direction.getRadians()
		reset();
		test_getRadians_correct();
		report("getRadians()");

		// direction.getDegrees()
		reset();
		test_getDegrees_correct();
		report("directionGetDegrees()");

		// direction.getDx()
		reset();
		test_getDx_correct();
		report("getDx()");

		// direction.getDy()
		reset();
		test_getDy_correct();
		report("getDy()");
	}

private:
	/***************************************
	 * ASSIGN
	 ***************************************/
	 // The structure chart didn't show anything about the assign() method.
	 // and the UML class diagram for Direction confused us about assign().

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
		assert(result = 0);
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
	 * SET DX DY
	 ***************************************/
	void test_setDxDy_correct()
	{
		// Setup
		Direction direction;
		// Exercise
		direction.setDxDy(50, 100);
		double dxResult = direction.getDx();
		double dyResult = direction.getDy();
		// Verify
		assert(dxResult == 50);
		assert(dyResult == 100);
		// Teardown
	}

	/***************************************
	 * SET DOWN
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
	 * SET UP
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
     * SET RIGHT
     ***************************************/
	void test_setRight_correct()
	{
		// Setup
		Direction direction;
		// Exercise
		direction.setRight();
		// Verify
		assert(direction.radians == 1.57); // 1.57 = pointing to the right.
		// Teardown
	}
	/***************************************
	 * SET LEFT
	 ***************************************/
	void test_setLeft_correct()
	{
		// Setup
		Direction direction;
		// Exercise
		direction.setLeft();
		// Verify
		assert(direction.radians == 4.71); // 4.71 = pointing to the left.
		// Teardown
	}
	/***************************************
	 * REVERSE
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
		assert(direction.radians == 3.14);
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
		assert(direction.radians == 4.71);
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
		assert(direction.radians == 6.26);
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
		assert(result == 1.57);
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
	/***************************************
	 * GET DX
	 ***************************************/
	void test_getDx_correct()
	{
		// Setup
		Direction direction;
		direction.setDxDy(50, 100);
		// Exercise
		double result = direction.getDx();
		// Verify
		assert(result == 50);
		// Teardown
	}
	/***************************************
	 * GET DY
	 ***************************************/
	void test_getDy_correct()
	{
		// Setup
		Direction direction;
		direction.setDxDy(50, 100);
		// Exercise
		double result = direction.getDy();
		// Verify
		assert(result == 100);
		// Teardown
	}
};