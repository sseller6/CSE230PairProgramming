/***************************************************************************
 * Source File:
 *     Projectile
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Implementation of the physics for the projectile of the M777 Howitzer.
 **************************************************************************/

#include "projectile.h"
#include <numbers>

/*****************************************************************
* Constructors
*****************************************************************/
Projectile::Projectile(double aDegrees, double initialVelocity,
                       double objectMass, double objectDiameter)
    : mass(objectMass) 
{
    // Initial Angle
    angle.setDegrees(aDegrees);

    // Set initial velocity
    velocity.setDX(computeHorizontalComponent(angle.getRadians(), initialVelocity));
    cout << "Initial X Velocity: " << velocity.getDX() << endl;

    velocity.setDY(computeVerticalComponent(angle.getRadians(), initialVelocity));
    cout << "Initial Y Velocity: " << velocity.getDY() << endl;

    // Set surface area
    surfaceArea = computeSurfaceArea(objectDiameter);

    // Set drag coefficitnt
    
}


/*****************************************************************
* PROJECTILE GET MASS
* Get the mass of the projectile.
*****************************************************************/
double Projectile::getMass()
{
    return mass;
}

/*****************************************************************
* PROJECTILE SET MASS
* Sete the mass of the projectile.
*****************************************************************/
void Projectile::setMass(double mass)
{
    this->mass = mass;
}

/*****************************************************************
* PROJECTILE DISPLAY
* Displays Attributes of the projectile.
* *Joke Comment* Displays everything so that Jaren can see 
* what in the heck is going on.
*****************************************************************/
void Projectile::display()
{
    cout << "Mass: " << mass << "\n"
        << "Surface Area: " << surfaceArea << "\n"
        << "Position - X: " << position.getMetersX() << " Y: " << position.getMetersY() << "\n"
        << "Angle: " << angle.getDegrees() << " degrees\n"
        << "Velocity: X: " << velocity.getDX() << " Y: " << velocity.getDY() << "m/s\n"
        << "Acceleration: X: " << acceleration.getDDX() << " Y: " << acceleration.getDDY() << "m/s^2\n"
        << "Net Force: X: " << netForce.getForce() << " Y: " << netForce.getForceY() << "Newtons\n"
        << "Gravity: X: " << gravity.getForce() << " Y: " << gravity.getForceY() << "Newtons\n"
        << "Gravity Acceleration: " << gravity.getAcceleration(position.getMetersY()) << "m/s\n"
        << "Drag Force: X: " << drag.getForce() << " Y: " << drag.getForceY() << "Newtons\n"
        << "Drag Coefficient: [ADD LATER]" << endl;
}

/*****************************************************************
* PROJECTILE MOVE
* Moves the projectile by calculating new x and y
*****************************************************************/
void Projectile::move(double timeInterval)
{
    // COMPUTE FORCES
    gravity.updateForce(mass, position.getMetersY());
    drag.updateForce(surfaceArea, velocity, getAltitude());
    // SUM THE FORCES
    netForce.setForceX(drag.getForceX()); // Gravity has no x component
    netForce.setForceY(drag.getForceY() + gravity.getForceY());
    // CHANGE IN ACCELERATION
    acceleration.updateAcceleration(netForce, mass);
    // CHANGE IN VELOCITY
    velocity.updateVelocity(acceleration, timeInterval, getAltitude());
    // CHANGE IN POSITION
    position.setMeters(computeNewX(timeInterval), computeNewY(timeInterval));
}

/*****************************************************************
* PROJECTILE COMPUTE NEW X
* Calculates the new x value based on physics.
*****************************************************************/
double Projectile::computeNewX(double timeInterval)
{
    return position.getMetersX() + velocity.getDX() * timeInterval + (acceleration.getDDX() * (timeInterval * timeInterval) / 2);
}
/*****************************************************************
* PROJECTILE COMPUTE NEW Y
* Calculates the new y value based on physics.
*****************************************************************/
double Projectile::computeNewY(double timeInterval)
{
    return position.getMetersY() + velocity.getDY() * timeInterval + (acceleration.getDDY() * (timeInterval * timeInterval) / 2);
}

/*****************************************************************
* PROJECTILE COMPUTE SURFACE AREA
* Computes the surface area of the projectile.
*****************************************************************/
double Projectile::computeSurfaceArea(double diameter)
{
    double radius = diameter / 2;
    return numbers::pi * (radius * radius);
}

/*****************************************************************
* PROJECTILE CHECK COLLISION
* Returns true if altitude is < 0.
*****************************************************************/
bool Projectile::checkCollision()
{
    return (getAltitude() >= 0) ? false : true;
}


/*****************************************************************
* PROJECTILE GET DISTANCE
* Get distance from origin.
*****************************************************************/
double Projectile::getDistance()
{
    return position.getMetersX();
}

/*****************************************************************
* PROJECTILE GET ALTITUDE
* Get altitude of the projectile.
*****************************************************************/
double Projectile::getAltitude()
{
    return position.getMetersY();
}

