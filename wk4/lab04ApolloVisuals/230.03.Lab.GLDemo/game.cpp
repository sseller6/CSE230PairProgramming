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
    hud(ptUpperRight)       // Set HUD position
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
			lander.rotateRight(0.1);
		}
	}
	// Has enough fuel to engage main engine
	if (lander.getFuel() >= 10)
	{
		//(pUI->isDown()) ? lander.fly() : lander.coast(); // If down is pressed, 
											   // then engage thruster (fly).
											   // Otherwise, just coast.
		if (pUI->isDown())
		{
			lander.setIsFlying(true);
		}
		else
		{
			lander.setIsFlying(false);
		}
	}
	else
	{
		lander.setIsFlying(false);
	}

}

/******************************************************************
* RUN
* Runs one round of the simulator
******************************************************************/
void Game::run(const Interface* pUI)
{   // Check collisoin
	if (ground.hitGround(lander.getPosition(), lander.getWidth()) == false)
	{
        // Get input
		getInput(pUI);
		// Move lander
		lander.move();
	}
	

	// Check to see if lander is on the pad
	else if (ground.onPlatform(lander.getPosition(), lander.getWidth()) == true)
	{
		// Make sure they didn't land too fast (< -4.0 m/s)
		if (lander.getSpeed().getVelocity() < -4.0)
		{
			lose();
		}
		else
		{
			win();
		}
	}
	else
	{
		lose();
	}

	// Update HUD
	hud.updateHUD(lander);
}

/******************************************************************
* WIN
* 
******************************************************************/
void Game::win()
{
	// Stop lander
	// lander.stop();
	// Set winning message
	hud.setMessage("The Eagle has landed!");
}

/******************************************************************
* LOSE
*
******************************************************************/
void Game::lose()
{
	// Stop lander
	// lander.stop();
	// Set winning message
	hud.setMessage("Houston, we have a problem!");
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


