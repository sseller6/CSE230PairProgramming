#pragma once

using namespace std;

// forward declaration for the Ground unit tests
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
    void setDxDy(double dx, double dy);
    void setDown();
    void setUp();
    void setRight();
    void setLeft();

    // Getters
    double getRadians();
    double getDegrees();
    double getDx();
    double getDy();


private:
    // Attributes
    double radians;
};