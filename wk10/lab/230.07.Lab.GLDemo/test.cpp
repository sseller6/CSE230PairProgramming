/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testPhysics.h"
#include "testVelocity.h"
#include "testDirection.h"
#include "testGround.h"
#include "testHowitzer.h"
// #include "testProjectile.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestPosition().run();
   TestPhysics().run();
   TestVelocity().run();
   TestDirection().run();
   TestGround().run();
   //TestHowitzer().run();
   // TestProjectile().run();
}
