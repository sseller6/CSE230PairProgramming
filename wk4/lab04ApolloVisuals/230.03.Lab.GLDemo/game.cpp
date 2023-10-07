/***********************************************************************
 * Source File:
 *    Game: The state of the game
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Contains the game state
 ************************************************************************/

#include "game.h"

/******************************************
 * GAME : CONSTRUCTOR
 * Initialize the point to the passed position
 *****************************************/
Game::Game(Point ptUpperRight) :
    sky(ptUpperRight),       // generate sky
    ground(ptUpperRight),    // generate ground
    lander(ptUpperRight),    // Set lander position
    time(0.1)                // set time interval to 0.1 seconds
{}

/*****************************************
* RESET
*****************************************/
void reset()
{
    lander.reset();
    sky.reset();
    ground.reset()
}

/*****************************************
* UPDATE GAME
*****************************************/
void updateGame(const Interface* pUI)
{    
    // Move Lunar Module
    lander.move();
    // Update HUD
    hud.updateHUD();
    // Check for collisions with the LM
    bool collision = checkCollision(pUI);
}

/****************************************
* CHECK COLLISOIN
*****************************************/
bool checkCollision() 
{
    // Check the status of the LM

}

/*****************************************
* DISPLAY
*****************************************/
void display(double thrust)
{
    // Stub for display
}

/*****************************************
* INPUT
*****************************************/
bool Game::input(const Interface* pUI)
{
    return false;
}
