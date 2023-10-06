/***********************************************************************
 * Header File:
 *     Thrust : Indicates rotation and moving up
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object that indicates rotation and direction of the LM.
 ************************************************************************/

#pragma once

#include "point.h"   // for Point


 /***********************************************************
  * THRUST
  * The thrust class
  ***********************************************************/
class Thrust
{
public:
    Thrust();
    void rotate();
    void mainEngineThrust();
    bool isMain();                // is the main engine on
    bool isClock();
    bool isCounter();
    void set(UI);                 // UI is undefined. Uh oh.
private:
    bool mainEngine;
    bool clockwise;
    bool counterClockwise;
}
