#include "velocity.h"


/***************************************
 * GET DX
 ***************************************/
double Velocity::getDx()
{
    return dx;
}

/***************************************
 * GET DY
 ***************************************/
double Velocity::getDy()
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