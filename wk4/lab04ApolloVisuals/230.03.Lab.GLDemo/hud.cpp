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
HUD::HUD() : fuel(0), altitude(0), speed(0), angle(0), message("")
{

}

/******************************************************************
 * HUD : CONSTRUCTOR
 * Non Default Constructor
 *****************************************************************/
HUD::HUD(const Point& ptUpperRight) : fuel(0), altitude(0), speed(0), angle(0), message("")
{
    // Attribute
    position.setX(20);
    position.setY((int) ptUpperRight.getY() - 20);
}

/******************************************************************
 * GET MESSAGE
 * returns HUD message
 *****************************************************************/
string HUD::getMessage() const
{
    return message;
}

/******************************************************************
 * SET MESSAGE
 * sets HUD message
 *****************************************************************/
void HUD::setMessage(string text)
{
    message = text;
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
    gout.setf(ios::fixed);     // "fixed" means don't use scientific notation
    gout.setf(ios::showpoint); // "showpoint" means always show the decimal point
    gout.precision(2);         // Set the precision to 1 decimal place of accuracy.
    
    // put some text on the screen
    gout.setPosition(position);
    gout << "Altitude: " << altitude << "m\n"
         << "Fuel: "     << fuel     << "lbs\n"
         << "Speed: "    << speed    << "m/s\n"
         << "Angle: "    << angle    << " degrees\n"
         << "Message: "  << message  << endl;
}
