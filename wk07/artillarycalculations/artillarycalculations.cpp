#include <iostream>
#include "projectile.h"


using namespace std;


// Initial variables
double PI = 3.141592653589793;      // Yumm
double dragCoefficient;             // Create maps of datatables for linear interpolation
double airDensity;                  // See above
double INITIAL_VELOCITY = 827.0;    // Velocity when fired
double MASS = 46.7;                 // Mass of bullet in kg
double ACCELERATION_GRAVITY = -9.8; // meters/second^2
double DIAMETER = 0.15489;          // in meters
double TIME_INTERVAL = 0.1;         // Time in seconds

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
    Projectile bullet(75.00, INITIAL_VELOCITY, MASS, DIAMETER);


    int i = 1; // Initialize loop time tracker.
    // Move the projectile 20 for 20 seconds
    while (bullet.checkCollision() == false)
    {
        
        bullet.move(TIME_INTERVAL);
        
        // Display Distance & Altitutde
        cout << "Round: " << i << "." << endl;
        bullet.display();
        cout << endl;

        i++; // Track how many times loop is run
    }

    // Display Distance & Altitutde
    cout << "Distance: " << bullet.getDistance() << "\n";
    cout << "Altitude: " << bullet.getAltitude() << "\n";


}


