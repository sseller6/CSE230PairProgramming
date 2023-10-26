#include <iostream>
#include "projectile.h"

using namespace std;


// Initial variables
double pi = 3.14159265359;
double dragCoefficient; // Create maps of datatables for linear interpolation
double airDensity;      // See above
double INITIAL_VELOCITY = 827.0; // Velocity when fired
double MASS = 46.7; // Mass of bullet in kg

// Position
// double x0 = 0.00;
// double y0 = 0.00;
// Time in seconds
// double t = 1.00;
// Angle 30 degrees in radians
// double angle = 0.5255;
// Initial Velocity (m/s)
// double v0 = 8.27; 
// Initial mass (kg)
// double mass = 46.7;
// Diameter in meters
// double diameter = 0.15489;
// radius
// double radius = diameter / 2;
// area pi*r^2
// double area = pi * (radius * radius);
// speed of sound (m/s) (dependent on altitude)
// double vs = 340.00;
// Mach speed
// double mach = v0 / vs;

// drag force 
// double dragForce = (dragCoefficient / 2) * airDensity* (mach * mach) * area;





int main()
{
    // Create a projectile
    Projectile bullet(75, INITIAL_VELOCITY, MASS);

    // Move the projectile 20 for 20 seconds
    for (int i = 1; i < 21; i++)
    {
        bullet.move(1);
    }

    // Display Distance & Altitutde
    cout << "Distance: " << bullet.getX() << "\n";
    cout << "Altitude: " << bullet.getY() << "\n";


}


