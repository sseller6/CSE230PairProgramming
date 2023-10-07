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
    void reset(double width, double height);
    string draw(string gout); // I'm really not sure what types to put here, so I put string to grab atteniton.
private:
    // Attributes
    Point pt;


    // This is gonna take a bit of refactoring.
};