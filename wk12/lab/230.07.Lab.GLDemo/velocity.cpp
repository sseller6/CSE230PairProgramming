#include "velocity.h"
#include <iostream>
using namespace std;


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
void Velocity::addX(double dx)
{
    this->dx += dx;
    cout << "added dx" << dx << endl;
}

/***************************************
* ADD DY
****************************************/
void Velocity::addY(double dy)
{
    this-> dy += dy;
    cout << "added dy" << dy << endl;
}