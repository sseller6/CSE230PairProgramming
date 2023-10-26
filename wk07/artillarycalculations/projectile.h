#pragma once

#include "angle.h"

class Projectile
{
private:
    double x;         // X coordinate.
    double y;         // Y coordinate.
    Angle  angle;     // In radians
    double velocityX; // Velocity of X coordinate
    double velocityY; // Velocity of Y coordinate
    double accX;      // Acceleration of X coordinate
    double accY;      // Aceleration of Y coordinate
    double mass;      // In kg

public:
    // Constructors
    Projectile();
    Projectile(double aRadians, double initialVelocity, double objectMass);
    // Methods
    void move(double timeInterval);
    double computeNewX(double timeInterval);
    double computeNewY(double timeInterval);

    // Getters
    double getX();
    double getY();
    double getVelocityX();
    double getVelocityY();
    double getAccX();
    double getAccY();
    double getMass();

    // Setters
    void setX(double x);
    void setY(double y);
    void setVelocityX(double velocity);
    void setVelocityY(double velocity);
    void setAccX(double AccX);
    void setAccY(double AccY);
    void setMass(double mass);

    // FUNCITION FROM LUNAR MODULE
    double computeVerticalComponent(double total);
    double computeHorizontalComponent(double total);
    double computeTotalComponent(double x, double y);
};

