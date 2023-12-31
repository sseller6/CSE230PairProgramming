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
#include "ground.h"     // for ground
#include "sky.h"        // for sky
#include "uiInteract.h" // For gettng input


class Game

{
    // Methods
public:
    Game(Point ptUpperRight);
    void reset();
    void run(const Interface* pUI);
    void win();
    void lose();
    void getInput(const Interface* pUI);
    void display(ogstream &gout, const Interface* pUI);
private:
    // Attributes
    HUD hud;
    Lander lander;
    Ground ground;
    Sky sky; 
};