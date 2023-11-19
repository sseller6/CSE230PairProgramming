/***********************************************************************
 * Source File:
 *     Artillary Calculations
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    This file serves as the main file for the program.
 ************************************************************************/

#include <iostream>
#include "projectile.h"

using namespace std;

// Initial variables
#define PI 3.141592653589793         // Yumm
#define INITIAL_VELOCITY 827.0       // Velocity when fired
#define MASS 46.7                    // Mass of bullet in kg
#define ACCELERATION_GRAVITY -9.8    // meters/second^2
#define DIAMETER 0.15489             // in meters
#define TIME_INTERVAL 0.01           // Time in seconds
#define ANGLE 75.00                  // Angle in degrees

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
    Projectile bullet(ANGLE, INITIAL_VELOCITY, MASS, DIAMETER);

    int i = 0; // Initialize loop time tracker.
    while (bullet.checkCollision() == false)
    {
        i++; // Track how many times loop is run (this is our time in seconds
        // Move the bullet        
        bullet.move(TIME_INTERVAL);

    }
    // bullet.display();
    // Display Distance & Altitutde
    cout << "Distance: "  << bullet.getDistance()  << " meters"  << endl;
    cout << "Altitude: "  << bullet.getAltitude()  << " meters"  << endl;
    cout << "Hang Time: " << i / 100               << " seconds" << endl;


}


