/***********************************************************************
 * Header File:
 *     Game 
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object containing the game state.
 ************************************************************************/

#pragma once

#include <math.h>    // for math
#include <iostream>  // for cout
#include "lander.h"  // for lander
#include "point.h"   // for point
#include "ground.h"  // for ground
#include "star.h"    // for star
#include "sky.h"     // for sky

using namespace std;

class Game

{
    // Methods
public:
    Game(double ptUpperRight);
    void reset();
    string input(string ui);// I'm not sure about this. I put string to catch your attention.
    void gamePlay(double thrust);
    void display(double thrust);
private:
    // Attributes
    Lander lander;
    Point ptUpperRight;
    Ground ground;
    Star stars;
    Sky sky; // We added this. It is not in Bro. Helfrich's original design.
};