/***********************************************************************
 * Header File:
 *     Thrust : Indicates rotation and moving up
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Indicates rotation and direction
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
    void rotation();
    void mainEngineThrust();
    bool isMain();
    bool isClock();
    bool isCounter;
    void set(UI);
private:
    bool mainEngine;
    bool clockwise;
    bool counterClockwise;
}
