#include "velocity.h"


/***************************************
 * GET DX
 ***************************************/
double Velocity::getDX()
{
    return dx;
}

/***************************************
 * GET DY
 ***************************************/
double Velocity::getDY()
{
    return dy;
}

/***************************************
* SET DX
****************************************/
void Velocity::setDX(double dx)
{
    this->dx = dx;
}

/***************************************
* SET DY
****************************************/
void Velocity::setDY(double dy)
{
    this->dy = dy;
}

/***************************************
 * SET DXDY
 ***************************************/
void Velocity::setDxDy(double dx, double dy)
{
    this->dx = dx;
    this->dy = dy;
}

/***************************************
* ADD DX
****************************************/
void Velocity::addDX(double dx)
{
    this->dx += dx;
}

/***************************************
* ADD DY
****************************************/
void Velocity::addDY(double dy)
{
    this->dy += dy;
}