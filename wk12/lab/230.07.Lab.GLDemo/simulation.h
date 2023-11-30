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
    void reset();                                          // Resets entire simulation
    void fire();                                           // Starts the simulation
    void display(ogstream& gout, const Interface* pUI);    // Displays the objects
    void update(const Interface* pUI);                     // Updates the simulation by one frame
    void getInput(const Interface* pUI);                   // Gets the keyboard input
private:
    bool   hitTarget();                                    // Tests if projectile hits the target
    double getHeightMeters();                              // Retruns the heght in meters

    // Attributes
    Position  ptUpperRight;        // size of the screen
    Ground ground;                 // the ground
    Howitzer howitzer;             // the howitzer
    Projectile projectile;         // the howitzer bullet
    double time;                   // time since last fire


    // Position  projectilePath[20];  // path of the projectile
};

