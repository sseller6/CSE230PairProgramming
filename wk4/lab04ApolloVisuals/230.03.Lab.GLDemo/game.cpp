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
Game::Game(Point ptUpperRight, Game* pGame, Interface* pUI) :
    lander(ptUpperRight),    // Set lander position
    sky(ptUpperRight),       // generate sky
    ground(ptUpperRight),    // generate ground
{}

/*****************************************
* RESET
*****************************************/
void reset()
{
    // Stub for reset
}

/*****************************************
* GAMEPLAY
*****************************************/
void gamePlay(double thrust)
{
    // Stub for Play
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
bool Game::input(Interface* pUI)
{
    return false;
}
