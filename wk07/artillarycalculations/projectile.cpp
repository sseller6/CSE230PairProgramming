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
}


/*****************************************************************
* PROJECTILE GET MASS
*****************************************************************/
double Projectile::getMass()
{
    return mass;
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
    // COMPUTE FORCES
    gravity.updateForce(mass, position.getMetersY());
    drag.updateForce(surfaceArea, velocity);
    // SUM THE FORCES
    netForce.setForceX(drag.getForceX()); // Gravity has no x component
    netForce.setForceY(drag.getForceY() + gravity.getForceY());
    // CHANGE IN ACCELERATION
    acceleration.updateAcceleration(netForce, mass);
    // CHANGE IN VELOCITY
    velocity.updateVelocity(acceleration, timeInterval);
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

double Projectile::computeSurfaceArea(double diameter)
{
    double radius = diameter / 2;
    return numbers::pi * (radius * radius);
}

// Get distance from origin
double Projectile::getDistance()
{
    return position.getMetersX();
}

double Projectile::getAltitude()
{
    return position.getMetersY();
}

