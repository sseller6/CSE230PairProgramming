/*************************************************************
 * 1. Name:
 *      -your name-
 * 2. Assignment Name:
 *      Lab 02: Apollo 11
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, and writing code-
 *****************************************************************/

#include <iostream>  // for CIN and COUT
#include <numbers>  // for pi
using namespace std;

#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
double computeDistance(double s, double v, double a, double t)
{
    // find new distance using the provided equation
    double distance;
    distance = s + (v * t) + ((a * (t * t) / 2));
    return distance;
}

/**************************************************
 * COMPUTE ACCELERATION
 * Find the acceleration given a thrust and mass.
 * This will be done using Newton's second law of motion:
 *     f = m * a
 * INPUT
 *     f : force, in Newtons (kg * m / s^2)
 *     m : mass, in kilograms
 * OUTPUT
 *     a : acceleration, in meters/second^2
 ***************************************************/
double computeAcceleration(double f, double m) 
{
    // find a by dividing f my m.
    double a;
    a = f / m;
    return a;
}

/***********************************************
 * COMPUTE VELOCITY
 * Starting with a given velocity, find the new
 * velocity once acceleration is applied. This is
 * called the Kinematics equation. The
 * equation is:
 *     v = v + a t
 * INPUT
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     v : new velocity, in meters/second
 ***********************************************/
double computeVelocity(double v, double a, double t) 
{
    // Find the new velocity.
    double newV;
    newV = v + (a * t);
    return newV;
}

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
double computeVerticalComponent(double a, double total)
{
    // Find vertical component of a velocity or accelration.
    double y;
    y = cos(a) * total;
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
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     x : the vertical component of the total
 ***********************************************/
double computeHorizontalComponent(double a, double total)
{
    double x;
    x = sin(a) * total;
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
double computeTotalComponent(double x, double y) 
{
    double total;
    total = sqrt((x * x) + (y * y));
    return total;
}


/*************************************************
 * RADIANS FROM DEGEES
 * Convert degrees to radians:
 *     radians / 2pi = degrees / 360
 * INPUT
 *     d : degrees from 0 to 360
 * OUTPUT
 *     r : radians from 0 to 2pi
 **************************************************/
double convertDegreesToRadians(double d) 
{
    double pi = numbers::pi_v<double>;
    double r;
    r = (d / 360) * (2 * pi);
    return r;
}

/**************************************************
 * PROMPT
 * A generic function to prompt the user for a double
 * INPUT
 *      message : the message to display to the user
 * OUTPUT
 *      response : the user's response
 ***************************************************/
double prompt(string message) 
{
    double response;
    cout << message;
    cin >> response;
    return response;
}

/****************************************************************************
 * COMPUTE NEW POSITION
 * Given the formula:
 * s = s_0 + v * t + (a * (t * t) / 2)
 * INPUT
 *     s_0 : Initial Position
 *     v   : Velocity
 *     a   : Acceleration
 *     t   : Time
 * OUTPUT:
 *     s   : The new position
 ****************************************************************************/
 double computeNewPosition(double s_0, double v, double a, double t)
 {
    double s = s_0 + v * t + (a * (t * t) / 2);
    return s;
 }

 /****************************************************************************
 * DISPLAY MOTION
 * Displays the motion of the LM at the instance it is called 
 * INPUT
 *     x        : Position
 *     y        : Altitude
 *     dx       : Horizontal Velocity
 *     dy       : Vertical Velocity
 *     v        : Total Velocity
 *     adegrees : angle of LM in degrees where 0 is up
 *     t        : Time interval
 * OUTPUT
 *     1s - x,y:(7.37, 86.76)m  dx,dy:(8.42, -13.48)m/s  speed:15.89m/s  angle:-45.00deg
 ****************************************************************************/
 int displayMotion(double x, double y, double dx, double dy, double v, double t, double aDegrees)
 {
     cout.setf(ios::fixed | ios::showpoint);
     cout.precision(2);
     cout << t << "s - x,y:(" << x << ", " << y << ")m dx, dy:(" << dx << ", " << dy << ")m/s speed:" << v << "m/s angle:"
         << aDegrees << "deg" << endl;
     /*cout << "\tNew position:   (" << x << ", " << y << ")m\n";
     cout << "\tNew velocity:   (" << dx << ", " << dy << ")m/s\n";
     cout << "\tTotal velocity:  " << v << "m/s\n\n";*/
     return 0;
 }

/****************************************************************
 * MAIN
 * Prompt for input, compute new position, and display output
 ****************************************************************/
int main()
{
    // Prompt for input and variables to be computed
    double dx = prompt("What is your horizontal velocity (m/s)? ");
    double dy = prompt("What is your vertical velocity (m/s)? ");
    double y = prompt("What is your altitude (m)? ");
    double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
    double x = 0;               // Starting position is 
    double t = 1;               // Time interval in seconds
    double aRadians;            // Angle in radians
    double accelerationThrust;  // Acceleration due to thrust 
    double ddxThrust;           // Horizontal acceleration due to thrust
    double ddyThrust;           // Vertical acceleration due to thrust
    double ddx;                 // Total horizontal acceleration
    double ddy;                 // Total vertical acceleration
    double v;                   // Total velocity

    // Go through the simulator five times
    
    aRadians = convertDegreesToRadians(aDegrees);
    accelerationThrust = computeAcceleration(THRUST, WEIGHT);
    ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust); 
    ddyThrust = computeVerticalComponent(aRadians, accelerationThrust);
    
    
    while (y > 0) 
    {
        // Loop 5 times
        for (int i = 1; i < 6; i++)
        {
            // Calculate
            ddx = ddxThrust;
            ddy = ddyThrust + GRAVITY;
            dx = dx + (ddx * t);
            dy = dy + (ddy * t);
            v = computeTotalComponent(dx, dy);
            x = computeNewPosition(x, dx, ddx, t);
            y = computeNewPosition(y, dy, ddy, t);

            // Output
            displayMotion(x, y, dx, dy, v, i, aDegrees);
            
        }

        // Ask user for new angle
        aDegrees = prompt("What is the new angle of the LM where 0 is up (degrees)? ");
        aRadians = convertDegreesToRadians(aDegrees);
    }
    

    


    return 0;
}