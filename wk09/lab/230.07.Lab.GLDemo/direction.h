#pragma once

using namespace std;

// forward declaration for the Ground unit tests
class TestDirection;

class Direction
{
public:
    // unit test access
    friend TestDirection;

    // Methods
    Direction();
    void assign(Direction rhs);

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