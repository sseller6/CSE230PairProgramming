#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "physics.h"
#include "physics.cpp"
#include <cassert>

using namespace std;

/************************************
* TEST PHYSICS
* A class containing automation for all the physics functions
**************************************/

class TestPhysics
{
public:
    void run()
    {
        test_computeMach();
        test_areaFromRadius();
        test_forceFromDrag();
        test_accelerationFromForce();
        test_velocityFromAcceleration();
        test_linearInterpolation();
        test_gravityFromAltitude();
        test_densityFromAltitude();
        test_dragFromMach();
        test_speedOfSoundFromAltitude();
    }

private:
    bool closeEnough(double value, double test, double tolerance) const
    {
        double difference = value - test;
        return (difference >= -tolerance) && (difference <= tolerance);
    }

    void test_areaFromRadius() const
    {
        assert(0.00 == areaFromRadius(0.0));
        assert(M_PI == areaFromRadius(1.0));
        assert(M_PI * 4.0 == areaFromRadius(2.0));
    }

    // Force From Drag
    void test_forceFromDrag() const
    {
        assert(0.0 == forceFromDrag(1.0, 1.0, 1.0, 0.0));
        assert(0.0 == forceFromDrag(1.0, 1.0, 0.0, 1.0));
        assert(0.0 == forceFromDrag(1.0, 0.0, 1.0, 1.0));
        assert(0.0 == forceFromDrag(0.0, 1.0, 1.0, 1.0));

        assert(0.5 * M_PI == forceFromDrag(1.0, 1.0, 1.0, 1.0));

        assert(1.0 * M_PI == forceFromDrag(2.0, 1.0, 1.0, 1.0));
        assert(1.0 * M_PI == forceFromDrag(1.0, 2.0, 1.0, 1.0));
        assert(2.0 * M_PI == forceFromDrag(1.0, 1.0, 2.0, 1.0));
        assert(2.0 * M_PI == forceFromDrag(1.0, 1.0, 1.0, 2.0));
    }

    // Accelertation From Force
    void test_accelerationFromForce()
    {
        assert(0.0 == accelerationFromForce(0.0, 1.0));

        assert(1.0 == accelerationFromForce(1.0, 1.0));

        assert(2.0 == accelerationFromForce(2.0, 1.0));
        assert(0.5 == accelerationFromForce(1.0, 2.0));
    }

    // Velocity From Acceleration
    void test_velocityFromAcceleration()
    {
        assert(0.0 == velocityFromAcceleration(0.0, 1.0));
        assert(0.0 == velocityFromAcceleration(1.0, 0.0));

        assert(1.0 == velocityFromAcceleration(1.0, 1.0));

        assert(2.0 == velocityFromAcceleration(2.0, 1.0));
        assert(2.0 == velocityFromAcceleration(1.0, 2.0));
    }

    // Linear Interpolation
    void test_linearInterpolation() const
    {
        assert(0.0 == linearInterpolation(0.0, 0.0, 0.0, 0.0, 0.0));
        assert(0.0 == linearInterpolation({ 0.0, 0.0 }, { 0.0, 0.0 }, 0.0));

        assert(0.0 == linearInterpolation(0.0, 0.0, 2.0, 0.0, 1.0));
        assert(1.0 == linearInterpolation(0.0, 0.0, 2.0, 2.0, 1.0));
        assert(0.0 == linearInterpolation({ 0.0, 0.0 }, { 2.0, 0.0 }, 1.0));
        assert(1.0 == linearInterpolation({ 0.0, 0.0 }, { 2.0, 2.0 }, 1.0));

        assert(2.25 == linearInterpolation(1.0, 2.0, 2.0, 3.0, 1.25));
        assert(2.75 == linearInterpolation(1.0, 2.0, 2.0, 3.0, 1.75));
        assert(2.25 == linearInterpolation({ 1.0, 2.0 }, { 2.0, 3.0 }, 1.25));
        assert(2.75 == linearInterpolation({ 1.0, 2.0 }, { 2.0, 3.0 }, 1.75));

        assert(2.50 == linearInterpolation(2.0, 2.0, 2.0, 3.0, 1.50));
        assert(2.25 == linearInterpolation(2.0, 2.0, 2.0, 3.0, 1.75));
        assert(2.50 == linearInterpolation({ 2.0, 2.0 }, { 2.0, 3.0 }, 1.50));
        assert(2.25 == linearInterpolation({ 2.0, 2.0 }, { 2.0, 3.0 }, 1.75));
    }

    // Gravity From Altitude
    void test_gravityFromAltitude()
    {
        assert(9.087 == gravityFromAltitude(0.0));
        assert(closeEnough(9.805, gravityFromAltitude(666.6), 0.01));
        assert(closeEnough(9.972, gravityFromAltitude(4666.6), 0.01));
        assert(closeEnough(9.781, gravityFromAltitude(8333.3), 0.01));
        assert(closeEnough(9.565, gravityFromAltitude(79666.6), 0.01));
    }

    // Density from altittude
    void test_densityFromAltitude() const
    {
        assert(1.2250000 == densityFromAltitude(0.0));

        assert(closeEnough(1.0600, densityFromAltitude(1500.0), 0.01));
        assert(closeEnough(0.8111, densityFromAltitude(4100.0), 0.001));
        assert(closeEnough(0.0000185, densityFromAltitude(80000.0), 0.0000001));
    }

    // Drag from Mach
    void test_dragFromMach() const
    {
        assert(0.0 == machFromSpeed(000.0, 0.0));
        assert(1.0 == machFromSpeed(340.0, 0.0));

        assert(closeEnough(1.00, machFromSpeed(326.0, 3500.0), 0.001));
        assert(closeEnough(0.50, machFromSpeed(163.0, 3500.0), 0.001));

        assert(closeEnough(2.00, machFromSpeed(295.0, 21657.0), 0.001));
    }

    // Speed of Sound from Altitude
    void test_speedOfSoundFromAltitude() const
    {
    	assert(0.0 == speedFromAltitude(0.0));
    
    	// Mach 
    	assert(closeEnough(0.4258, dragFromSpeed(326.0, 3500.0), 0.0001));
    
    	// Mach 0.5
    	assert(closeEnough(0.1659, dragFromSpeed(163.0, 3500.0), 0.0001));
    
    	// Mach 0.2
    	assert(closeEnough(0.1086, dragFromSpeed(59.0, 21657.0), 0.0001));
    
    	// Mach 0.32
    	assert(closeEnough(0.1632, dragFromSpeed(96.0, 27500.0), 0.0001));
    }
};
