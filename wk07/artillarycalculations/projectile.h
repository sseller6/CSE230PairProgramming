#pragma once

#include "acceleration.h"
#include "angle.h"
#include "force.h"
#include "position.h"
#include "velocity.h"
#include "xyComponents.h"

#include <numbers>


class Projectile
{
private:
    bool hitGround;             // Has the projectile hit the ground.
    double mass;                // In kg
    double surfaceArea;         // in meters
    Position position;          // Position x and y coordinates.
    Angle  angle;               // In radians
    Velocity velocity;          // The velocity of the object
    Acceleration acceleration;  // The total acceleration of the object.
    Force netForce;             // Total forces acting on the object
    Gravity gravity;            // Gravity force in Newtons
    DragForce drag;             // Drag force in Newtons

public:
    // Constructors
    Projectile();
    Projectile(double aRadians, double initialVelocity, double objectMass, double objectDiameter);
    // Methods
    void display();
    void move(double timeInterval);
    double computeNewX(double timeInterval);
    double computeNewY(double timeInterval);
    double computeSurfaceArea(double diameter);
    bool checkCollision();

    // Getters
    double getMass();
    double getDistance();
    double getAltitude();

    // Setters
    void setMass(double mass);
};

