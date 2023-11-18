#pragma once

using namespace std;

// forward declaration for the Direction unit tests
class TestDirection;

class Direction
{
public:
    // unit test access
    friend TestDirection;

    // Default Constructor
    Direction();

    // Non-default Constructor
    Direction(double radians);

    // Methods
    void assign(Direction rhs);
    double convertDegreesToRadians(double d);

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
    double getRadians();
    double getDegrees();

private:
    // Attributes
    double radians;
    double degrees;
};