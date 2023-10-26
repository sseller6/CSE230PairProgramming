#include "projectile.h"

#include <cmath>


/*****************************************************************
* Constructors
*****************************************************************/
Projectile::Projectile(double aDegrees, double initialVelocity, double objectMass)
    : 
    x(0),
    y(0),
    accX(0),
    accY(0),
    mass(objectMass)
{
    angle.setDegrees(aDegrees);
    velocityX = computeHorizontalComponent(initialVelocity);
    cout << velocityX << endl;
    velocityY = computeVerticalComponent(initialVelocity);
    cout << velocityY << endl;
}


/*****************************************************************
* PROJECTILE GETX
*****************************************************************/
double Projectile::getX()
{
    return x;
}

/*****************************************************************
* PROJECTILE GETY
*****************************************************************/
double Projectile::getY()
{
    return y;
}

/*****************************************************************
* PROJECTILE GET VELOCITYX
*****************************************************************/
double Projectile::getVelocityX()
{
    return velocityX;
}

/*****************************************************************
* PROJECTILE GET VELOCITYY
*****************************************************************/
double Projectile::getVelocityY()
{
    return velocityY;
}

/*****************************************************************
* PROJECTILE GET ACCX
*****************************************************************/
double Projectile::getAccX()
{
    return accX;
}

/*****************************************************************
* PROJECTILE GET ACCY
*****************************************************************/
double Projectile::getAccY()
{
    return accY;
}

/*****************************************************************
* PROJECTILE GET MASS
*****************************************************************/
double Projectile::getMass()
{
    return mass;
}

/*****************************************************************
* PROJECTILE SET VELOCITY X
*****************************************************************/
void Projectile::setVelocityX(double velocity)
{
    velocityX = velocity;
}

/*****************************************************************
* PROJECTILE SET VELOCITY Y
*****************************************************************/
void Projectile::setVelocityY(double velocity)
{
    velocityY = velocity;
}

/*****************************************************************
* PROJECTILE SET X
*****************************************************************/
void Projectile::setX(double x)
{
    x = x;
}

/*****************************************************************
* PROJECTILE SET Y
*****************************************************************/
void Projectile::setY(double y)
{
    y = y;
}

/*****************************************************************
* PROJECTILE SET ACCX
*****************************************************************/
void Projectile::setAccX(double AccX)
{
    AccX = AccX;
}

/*****************************************************************
* PROJECTILE SET ACCY
*****************************************************************/
void Projectile::setAccY(double AccY)
{
    AccY = AccY;
}

/*****************************************************************
* PROJECTILE SET MASS
*****************************************************************/
void Projectile::setMass(double mass)
{
    this->mass = mass;
}

/*****************************************************************
* PROJECTILE MOVE
* Moves the projectile by calculating new x and y
*****************************************************************/
void Projectile::move(double timeInterval)
{
    // Compute change in X
    double newX = computeNewX(timeInterval);
    cout << "Move - newX: " << newX << endl;

    // Compute change in Y
    double newY = computeNewY(timeInterval);
    cout << "Move - newY: " << newY << endl;

    // Set new x and y
    x = newX;
    y = newY;
}
/*****************************************************************
* PROJECTILE COMPUTE NEW X
* Calculates the new x value based on physics.
*****************************************************************/
double Projectile::computeNewX(double timeInterval)
{
    double newPosition = x + velocityX * timeInterval + (accX * (timeInterval * timeInterval) / 2);
    return newPosition;
}
/*****************************************************************
* PROJECTILE COMPUTE NEW Y
* Calculates the new y value based on physics.
*****************************************************************/
double Projectile::computeNewY(double timeInterval)
{
    double newPosition = y + velocityY * timeInterval + (accY * (timeInterval * timeInterval) / 2);
    return newPosition;
}

//////////////////////////// FUNCTIONS FROM LUNAR MODULE STUFF ////////////////////////////


/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     y : the vertical component of the total
 ***********************************************/
double Projectile::computeVerticalComponent(double total)
{
    // Find vertical component of a velocity or accelration.
    double y;
    y = cos(angle.getRadians()) * total;
    return y;
}

/***********************************************
 * COMPUTE HORIZONTAL COMPONENT
 * Find the horizontal component of a velocity or acceleration.
 * The equation is:
 *     sin(a) = x / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     aRadians : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     x : the vertical component of the total
 ***********************************************/
double Projectile::computeHorizontalComponent(double total)
{
    double x;
    x = sin(angle.getRadians()) * total;
    return x;
}

/************************************************
 * COMPUTE TOTAL COMPONENT
 * Given the horizontal and vertical components of
 * something (velocity or acceleration), determine
 * the total component. To do this, use the Pythagorean Theorem:
 *    x^2 + y^2 = t^2
 * where:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    | /
 *    |/
 * INPUT
 *    x : horizontal component
 *    y : vertical component
 * OUTPUT
 *    total : total component
 ***********************************************/
double Projectile::computeTotalComponent(double x, double y)
{
    double total;
    total = sqrt((x * x) + (y * y));
    return total;
}