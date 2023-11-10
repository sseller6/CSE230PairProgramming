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
		// direction.assign()
		reset();

		report("directionAssign()");

		// direction.setRadians()
		reset();

		report("directionSetRadians()");

		// direction.setDegrees()
		reset();

		report("directionSetDegrees()");

		// direction.setDxDy()
		reset();

		report("directionSetDxDy()");

		// direction.setDown()
        reset();

		report("directionSetDown()");
		// direction.setUp()
        reset();

		report("directionSetUp()");
		// direction.setRight()
        reset();

		report("directionSetRight()");
		// direction.setLeft()
        reset();

		report("directionSetLeft()");
		// direction.reverse()
		reset();

		report("directionReverse()");

		// We only need to test one getter.
		// direction.getDegrees()
		reset();

		report("directionGetDegrees()");
	}

private:
	/***************************************
	 * ASSIGN
	 ***************************************/
	 

	/***************************************
	 * SET RADIANS
	 ***************************************/


	/***************************************
	 * SET DEGREES
	 ***************************************/


	/***************************************
	 * SET DX DY
	 ***************************************/


	/***************************************
	 * SET DOWN
	 ***************************************/

	/***************************************
	 * SET UP
	 ***************************************/

	/***************************************
     * SET RIGHT
     ***************************************/

	/***************************************
	 * SET LEFT
	 ***************************************/

	/***************************************
	 * REVERSE
	 ***************************************/

    /***************************************
	 * GET RADIANS
	 ***************************************/

	/***************************************
	 * GET DEGREES
	 ***************************************/

	/***************************************
	 * GET DX
	 ***************************************/

	/***************************************
	 * GET DY
	 ***************************************/
};