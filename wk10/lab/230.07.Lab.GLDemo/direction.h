#pragma once

using namespace std;

// forward declaration for the Direction unit tests
class TestDirection;
class TestProjectile;

class Direction
{
    friend TestDirection;
    friend TestProjectile;
public:

    // Default Constructor
    Direction();

    // Non-default Constructor
    Direction(double radians);

    // Methods
    void assign(Direction rhs);
    double convertDegreesToRadians(double d);
    double normalize(double radians);

    // Reverse
    void reverse();
    // Setters
    void setRadians(double rhs);
    void setDegrees(double rhs);
    void setDown();
    void setUp();
    void setRight();
    void setLeft();

    // Getters
    double getRadians() const;
    double getDegrees() const;

private:
    // Attributes
    double radians;
    double degrees;
};