/***********************************************************************
 * Header File:
 *     Star
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object containing all information for the stars.
 ************************************************************************/

#pragma once

#include <math.h>    // for math
#include <iostream>  // for cout
#include "point.h"   // for point
#include "uiDraw.h"  // for draw


using namespace std;

class Star

{
    // Methods
public:
    Star();
    void setPosition(double x, double y);
    void setPhase(unsigned char number);
    Point getPositon();
    int getPhase();
private:
    // Attributes
    Point position;
    unsigned char phase;
};