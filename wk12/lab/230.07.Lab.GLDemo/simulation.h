#pragma once

#include "direct.h"
#include "ground.h"  
#include "howitzer.h" 
#include "physics.h"
#include "position.h"
#include "projectile.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "velocity.h"


class Simulation
{
public:
    Simulation(Position ptUpperRight);                     // Constructor
    void run(const Interface* pUI);
    void reset();                                          // Resets entire simulation
    void fire();                                           // Starts the simulation
    void display(ogstream& gout, const Interface* pUI);    // Displays the objects
    void getInput(const Interface* pUI);                   // Gets the keyboard input
private:
    bool   hitTarget();                                    // Tests if projectile hits the target
    double getHeightMeters();                              // Retruns the heght in meters

    // Attributes
    Position   ptUpperRight;       // size of the screen
    Ground     ground;             // the ground
    Howitzer   howitzer;           // the howitzer
    Projectile projectile;         // the howitzer bullet
    double     time;               // time since last fire
    bool       isFired;            // true if the howitzer has been fired    


    // Position  projectilePath[20];  // path of the projectile
};

