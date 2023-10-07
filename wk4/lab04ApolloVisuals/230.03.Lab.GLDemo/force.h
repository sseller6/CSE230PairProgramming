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
  * Force
  * The force class
  ***********************************************************/
class Force
{
public:
    Force();
    int getForce();
    void setForce();
 
private:
    int force;
};