#include "hud.h"

// Default constructor
HUD::HUD() : fuel(0), altitude(0), speed(0), angle(0)
{

}

// Non Default Constructor
HUD::HUD(const Point& ptUpperRight) : fuel(0), altitude(0), speed(0), angle(0)
{
    position.setX(20);
    position.setY((int) ptUpperRight.getY() - 20);
}

void HUD::updateHUD(const Lander &lander)
{

    this->altitude = lander.getPosition().getY();
    this->angle = lander.getAngle().getDegrees();
    this->fuel = lander.getFuel();
    this->speed = lander.getSpeed().getVelocity();
}

void HUD::draw(ogstream& gout, const Lander& lander)
{
    // put some text on the screen
    gout.setPosition(position);
    gout << "Altitude: " << altitude << "m\n"
         << "Fuel: "     << fuel     << "lbs\n"
         << "Speed: "    << speed    << "m/s\n"
         << "Angle: "    << angle    << " degrees\n";
}
