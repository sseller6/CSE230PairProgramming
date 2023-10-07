#include "hud.h"

// Default constructor
HUD::HUD()
{

}

void HUD::updateHUD()
{
    this->altitude = lander.position.getY();
    this->angle = lander.angle.getDegrees();
    this->fuel = lander.getfuel();
    this->speed = lander.v.getVelocity();
}
