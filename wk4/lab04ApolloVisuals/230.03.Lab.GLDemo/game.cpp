/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "game.h"

/******************************************
 * GAME : CONSTRUCTOR
 * Initialize the point to the passed position
 *****************************************/
Game::Game(double ptUpperRight)
    lander(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),    // Set lander position
    sky(ptUpperRight.getX(), ptUpperRigth.getY()),       // generate sky
    ground(),      // generate ground
{}

string input(string ui);// I'm not sure about this. I put string to catch your attention.


void reset()
{
}

void gamePlay(double thrust)
{
}

void display(double thrust)
{
}
