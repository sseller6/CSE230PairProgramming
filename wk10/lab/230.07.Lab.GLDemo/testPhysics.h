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

    void test_computeMach()
    {
        assert(0.0 == computeMach(0.0, 0.0));
        assert(0.0 == computeMach(1.0, 0.0));

        assert(0.0 == computeMach(0.0, 0.1));
        
        // Way below
        assert(closeEnough(0.0294, computeMach(10, 340), 0.001));
        // Just below
        assert(closeEnough(0.5882, computeMach(200, 340), 0.0001));
        // Right on
        assert(1.0 == computeMach(340, 340));
        // Just above
        assert(closeEnough(1.0147, computeMach(345, 340), 0.0001));
        // Way above
        assert(closeEnough(2.0, computeMach(680, 340), 0.1));
        // Different speed of sound
        assert(closeEnough(1.0, computeMach(295, 295), 0.1));
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
        // Below the table
        assert(0.1629 == dragFromMach(0.0));
        // Bottom of the table
        assert(0.1629 == dragFromMach(0.3));
        // Middle of the table
        assert(0.4258 == dragFromMach(1.0));
        // With interpolation
        assert(closeEnough(0.4157, dragFromMach(1.200), 0.0001));
        // Top of the table
        assert(0.2656 == dragFromMach(5.0));
        // Above the table
        assert(0.2656 == dragFromMach(7.2));
    }

    // Speed of Sound from Altitude
    void test_speedOfSoundFromAltitude() const
    {
        // Below the table
        assert(340 == speedOfSoundFromAltitude(-10));
        // Bottom of the table
    	assert(340 == speedOfSoundFromAltitude(0));
    	// On the table
    	assert(320 == speedOfSoundFromAltitude(5000));
    	// Interpolation
    	assert(closeEnough(314, speedOfSoundFromAltitude(6500), 0.1));
    	// Top of the table
    	assert(324 == speedOfSoundFromAltitude(40000));
    	// Above the table
    	assert(324 == speedOfSoundFromAltitude(50000));
    }
};
