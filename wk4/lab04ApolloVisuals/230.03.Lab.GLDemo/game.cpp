/******************************************************************
 * Source File:
 *    Game: The state of the game
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Contains the game state
 *****************************************************************/

#include "game.h"

/******************************************************************
 * GAME : CONSTRUCTOR
 * Initialize the point to the passed position
 *****************************************************************/
Game::Game(Point ptUpperRight) :
    sky(ptUpperRight),       // generate sky
    ground(ptUpperRight),    // generate ground
    lander(ptUpperRight),    // Set lander position
    hud(ptUpperRight),       // Set HUD position
    time(0.1)                // set time interval to 0.1 seconds
{}

/******************************************************************
* RESET
* Reset the lander, the sky, and the ground.
******************************************************************/
void Game::reset()
{
    lander.reset();
    sky.reset();
    ground.reset();
}

/******************************************************************
* GET INPUT
* Gets user input
******************************************************************/
void Game::getInput(const Interface* pUI)
{
	// Handle user input

	// Check fuel
	if (lander.getFuel() >= 0.1) // Has enough fuel to change angle
	{
		if (pUI->isRight())
		{
            lander.rotateLeft(0.1);
		}
		if (pUI->isLeft())
		{
            lander.rotateRight();

			angle.addRadians(-0.1);
			position.addX(-1.0); // Temporary movement
			useFuel(0.1);
		}

		// Has enough fuel to engage main engine
		if (getFuel() > 10)
		{
			(pUI->isDown()) ? lander.setStatus(1) : lander.setStatus(0); // If down is pressed, 
                                               // then engage thruster (fly).
                                               // Otherwise, just coast.
		}
	}
}

/******************************************************************
* UPDATE GAME
* Update Game State.
******************************************************************/
void Game::updateGame()
{
    // 1 - Check Collisions. (This is basically checking if continue)
	// Check for collisions with the LM
	// bool collision = checkCollision();

	// 2 - Get input
	//     * change  angle()
	//     * engage thrust()
	//     * set    status()
	// 


	// 4 - Then move lander according to status.
	switch (lander.getStatus())
	{
	case 1: // Crash
		lander.crash();
		break;
	case 2: // Landed
		lander.land();
		break;
	case 3: // Fly
		lander.fly();
		break;
	default: // Coasting
		lander.coast();
		break;
	}

    // 5 - Update HUD
    hud.updateHUD(lander);

    
    // TODO:
    // Implement end of game at collision
}

/******************************************************************
* CHECK COLLISION
* Check to see if lander has hit the ground.
******************************************************************/
bool Game::checkCollision()
{
    if (ground.hitGround(lander.getPosition(), 20))
    {
        return true; // Lander hit the ground
    }
        return false; // Lander hasn't hit ground
}
/******************************************************************
* DISPLAY
* Draw the sky, ground, lander, and HUD.
******************************************************************/
void Game::display(ogstream& gout, const Interface* pUI)
{
    sky.draw(gout);
    ground.draw(gout);
    lander.draw(gout, pUI);
    hud.draw(gout, lander);
}


