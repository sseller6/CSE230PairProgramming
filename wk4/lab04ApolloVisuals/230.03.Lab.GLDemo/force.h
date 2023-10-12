/***********************************************************************
 * Header File:
 *     Force : Indicates rotation and moving up
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
    Force(double newtons);
    int getForce();
    void setForce();
 
private:
    double force;
};