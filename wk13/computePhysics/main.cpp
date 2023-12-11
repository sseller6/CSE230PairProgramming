/*************************************************************
 * 1. Name:
 *      The Key
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "direction.h"
#include "howitzer.h"   // for HOWITZER
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include "simulation.h"
#include "test.h"
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*

// Constants
// Initial variables
#define PI 3.141592653589793         // Yumm
#define INITIAL_VELOCITY 827.0       // Velocity when fired
#define MASS 46.7                    // Mass of bullet in kg
#define ACCELERATION_GRAVITY -9.8    // meters/second^2
#define DIAMETER 0.15489             // in meters
#define TIME_INTERVAL 0.5           // Time in seconds

using namespace std;

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
int main()
{
    while (true) 
    {
        double degrees;
        Direction angle;

        cout << "What is the initial angle in degrees: ";
        cin >> degrees;
        cout << endl;

        angle.setDegrees(degrees);

        // Create a projectile
        Projectile bullet(MASS, DIAMETER / 2);

		bullet.fire(Position(0.0, 0.0), 0.0,
            angle.getRadians(), INITIAL_VELOCITY);

        int i = 0; // Initialize loop time tracker.
        do
        {
            i++; // Track how many times loop is run (this is our time in seconds
            // Move the bullet        
            bullet.advance(TIME_INTERVAL);
        }
        while(bullet.flying());

        // Display Distance & Altitutde
        bullet.display();
        
    }
    return 0;
}