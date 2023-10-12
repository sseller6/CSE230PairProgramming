/******************************************************************
* Source File:
*     HUD : Heads Up Display
* Author:
*    Jarom Anderson & Steven Sellers
* Summary:
*     Implementation of a heads up display 
*     to display important info to the player.
******************************************************************/

#include "hud.h"

/******************************************************************
 * HUD : CONSTRUCTOR
 * Default constructor
 *****************************************************************/
HUD::HUD() : fuel(0), altitude(0), speed(0), angle(0)
{

}

/******************************************************************
 * HUD : CONSTRUCTOR
 * Non Default Constructor
 *****************************************************************/
HUD::HUD(const Point& ptUpperRight) : fuel(0), altitude(0), speed(0), angle(0)
{
    // Attribute
    position.setX(20);
    position.setY((int) ptUpperRight.getY() - 20);
}
/******************************************************************
 * UPDATE HUD
 * Takes information form lander to update HUD.
 *****************************************************************/
void HUD::updateHUD(const Lander &lander)
{

    this->altitude = lander.getPosition().getY();
    this->angle = lander.getAngle().getDegrees();
    this->fuel = lander.getFuel();
    this->speed = lander.getSpeed().getVelocity();
}

/******************************************************************
 * DRAW 
 * Draws the information to the top left of the screen. 
 *****************************************************************/
void HUD::draw(ogstream& gout, const Lander& lander)
{
    // put some text on the screen
    gout.setPosition(position);
    gout << "Altitude: " << altitude << "m\n"
         << "Fuel: "     << fuel     << "lbs\n"
         << "Speed: "    << speed    << "m/s\n"
         << "Angle: "    << angle    << " degrees\n";
}
