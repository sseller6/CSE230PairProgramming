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
    double convertDegreesToRadians(double degrees);
    double convertRadiansToDegrees(double radians);
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
    double getDegrees() ;

    // Operators
    Direction& operator=(const Direction& rhs);
    Direction& operator-();
    Direction& operator++();
    Direction  operator++(int postfix);
    Direction& operator--();
    Direction  operator--(int postfix);
    Direction& operator+=(const double value);
    Direction& operator-=(const double value);


private:
    // Attributes
    double radians;
};