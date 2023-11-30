/*************************************************************
 * Module
 *      TEST VELOCITY
 * Description:
 *      Unit tests for the Velocity class
 * Author:
 *      Jarom Anderson & Steven Sellers.
 **************************************************************/

#pragma once

#include "velocity.h"
#include "unitTest.h"
#include <cassert>

 /************************************
  * TEST VELOCITY
  ************************************/
class TestVelocity : public UnitTest
{
public:
    void run()
    {
        // velocity.setDxDy()
        reset();
        test_setDxDy_correct();
        report("velocitySetDxDy()");

        // velocity.getDx()
        reset();
        test_getDx_correct();
        report("velocityGetDx()");

        // velocity.getDy()
        reset();
        test_getDy_correct();
        report("velocityGetDy()");
    }

private:
    /***************************************
     * GET DX
     ***************************************/


    /***************************************
     * GET DY
     ***************************************/


    /***************************************
     * GET SPEED
     ***************************************/


    /***************************************
     * GET DIRECTION
     ***************************************/


    /***************************************
     * SET DX
     ***************************************/

    /***************************************
     * SET DY
     ***************************************/

    /***************************************
     * SET DX DY
     ***************************************/
    void test_setDxDy_correct()
    {
        // Setup
        Velocity velocity;
        // Exercise
        velocity.setDxDy(50, 100);
        double dxResult = velocity.getDx();
        double dyResult = velocity.getDy();
        // Verify
        assert(dxResult == 50);
        assert(dyResult == 100);
        // Teardown
    }

    /***************************************
     * GET DX
     ***************************************/
    void test_getDx_correct()
    {
        // Setup
        Velocity velocity;
        velocity.setDxDy(50, 100);
        // Exercise
        double result = velocity.getDx();
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
        Velocity velocity;
        velocity.setDxDy(50, 100);
        // Exercise
        double result = velocity.getDy();
        // Verify
        assert(result == 100);
        // Teardown
    }
    /***************************************
     * SET DIRECTION
     ***************************************/

    /***************************************
     * SET SPEED
     ***************************************/

    /***************************************
     * ADD DX
     ***************************************/

    /***************************************
     * ADD DY
     ***************************************/

    /***************************************
     * ADD V
     ***************************************/

    /***************************************
     * REVERSE
     ***************************************/
};