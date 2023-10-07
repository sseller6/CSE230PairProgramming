#include "hud.h"

// Default constructor
HUD::HUD() : fuel(0), altitude(0), speed(0), angle(0)
{

}

void HUD::updateHUD(const Lander &lander)
{

    this->altitude = lander.getPosition().getY();
    this->angle = lander.getAngle().getDegrees();
    this->fuel = lander.getFuel();
    this->speed = lander.getSpeed().getVelocity();
}
