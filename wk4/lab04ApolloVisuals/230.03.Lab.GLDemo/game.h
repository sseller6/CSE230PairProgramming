/***********************************************************************
 * Header File:
 *     Game 
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Object containing the game state.
 ************************************************************************/

#pragma once

#include "hud.h"        // for Heads Up Display
#include "lander.h"     // for lander
#include "point.h"      // for point
#include "ground.h"     // for ground
#include "star.h"       // for star
#include "sky.h"        // for sky
#include "uiInteract.h" // For gettng input

using namespace std;

class Game

{
    // Methods
public:
    Game(Point ptUpperRight);
    void reset();
    void updateGame(const Interface* pUI);
    bool checkCollision();
    void display();
private:
    // Attributes
    HUD hud;
    Lander lander;
    Ground ground;
    Sky sky; // We added this. It is not in Bro. Helfrich's original design.
    double time; // time interval in seconds
};