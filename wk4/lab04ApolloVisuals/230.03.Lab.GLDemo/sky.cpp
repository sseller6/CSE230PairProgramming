/***********************************************************************
 * Header File:
 *     Sky : Contains all the stars in the sky
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of the sky.
 ************************************************************************/

#include "sky.h"

#include <cstdlib>

// Default Constructor

Sky :: Sky(const Point& ptUpperRight)
{
    // Give every star a random position and 
    for (int index = 0; index <= 49; index++)
    { 
        int x = random(0, int(ptUpperRight.getX() - 20));
        int y = random(0, int(ptUpperRight.getY() - 20));
        // Set random position
        stars[index].setPosition(x, y);

        // Set random phase
        stars[index].setPhase(random(0, 255));
    }
}

// Draw the sky

void Sky :: draw(ogstream & gout)
{
    for (int index = 0; index <= 49; index++)
    {
        gout.drawStar(stars[index].getPositon(), stars[index].getPhase());
    }
}

void Sky::reset()
{
}
