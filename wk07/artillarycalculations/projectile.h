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
    void move(double timeInterval);
    double computeNewX(double timeInterval);
    double computeNewY(double timeInterval);
    double computeSurfaceArea(double diameter);
    double getDistance();
    double getAltitude();

    // Getters
    double getMass();

    // Setters
    void setMass(double mass);
};

