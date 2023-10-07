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
void Game::reset()
{
    lander.reset();
    sky.reset();
    ground.reset();
}

// Update Game State
void Game::updateGame(const Interface* pUI)
{
    // Move Lunar Module
    lander.move(pUI, time);
    // Update HUD
    hud.updateHUD(lander);
    // Check for collisions with the LM
    bool collision = checkCollision();
    
    // TODO:
    // Implement end of game at collision
}

bool Game::checkCollision()
{
    // Check to see if lander has hit the ground
    if (ground.hitGround(lander.getPosition(), 20))
    {
        return true; // Lander hit the ground
    }
        return false; // Lander hasn't hit ground
}

void Game::display(ogstream& gout, const Interface* pUI)
{
    // Draw Sky
    sky.draw(gout);
    // Draw Ground
    ground.draw(gout);
    // Draw lander
    lander.draw(gout, pUI);
}


