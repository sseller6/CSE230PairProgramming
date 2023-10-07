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
    for (Star star : stars)
    { 
        int x = random(0, int(ptUpperRight.getX() - 20));
        int y = random(0, int(ptUpperRight.getY() - 20));
        // Set random position
        star.setPosition(x, y);

        // Set random phase
        star.setPhase(random(0, 255));
    }
}

// Draw the sky

void Sky :: draw(ogstream & gout)
{
    for (Star star : stars)
    {
        gout.drawStar(star.getPositon(), star.getPhase());
    }
}

void Sky::reset()
{
}
