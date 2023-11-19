// Tests the I/O interfaces of the position class with boundary and invalid cases.

#pragma once

#include "position.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BlackBoxTestPosition
{
public:
    void run()
    {
        testExtremeLowRow();
        testExtremeLowCol();
        testJustLowRow();
        testJustLowCol();
        testEdgeLowRow();
        testEdgeLowCol();
        testValidInput();
        testEdgeUpperRow();
        testEdgeUpperCol();
        testJustUpperRow();
        testJustUpperCol();
        testExtremeUpperRow();
        testExtremeUpperCol();

        display();
    }

private:
    vector <string> failedMethods;
	// Test Boundaries: 8x8 Grid, Input Type – INT, Output Type – INT, Valid Inputs (1-8) 

    // LOWER BOUNDS

    // Extreme Lower (lowRow, validCol), (validRow, lowCol)
    void testExtremeLowRow()
    {
        Position piece;
        piece.set(-1000, 5); 
        if (piece.getRow() != 1)
        {
            failedMethods.push_back("testExtremeLowRow");
        }
    }

    void testExtremeLowCol()
    {
        Position piece;
        piece.set(5, -1000);
        if (piece.getColumn() != 1)
        {
            failedMethods.push_back("testExtremeLowCol");
        }
    }

    // Just below    (lowRow, validCol), (validRow, lowCol) 
    void testJustLowRow()
    {
        Position piece;
        piece.set(0, 5);
        if (piece.getRow() != 1)
        {
            failedMethods.push_back("testJustLowRow");
        }
    }

    void testJustLowCol()
    {
        Position piece;
        piece.set(5, 0);
        if (piece.getColumn() != 1)
        {
            failedMethods.push_back("testJustLowCol");
        }
    }
    // Edge Lower    (lowRow, validCol), (validRow, lowCol) 
    void testEdgeLowRow()
    {
        Position piece;
        piece.set(1, 5);
        if (piece.getRow() != 1)
        {
            failedMethods.push_back("testEdgeLowRow");
        }
    }

    void testEdgeLowCol()
    {
        Position piece;
        piece.set(5, 1);
        if (piece.getColumn() != 1)
        {
            failedMethods.push_back("testEdgeLowCol");
        }
    }

    // Valid Input      (validX, validY) 
    void testValidInput()
    {
        Position piece;
        piece.set(5, 5);
        if (piece.getRow() != 5 || piece.getColumn() != 5)
        {
            failedMethods.push_back("testValidInput");
        }
    }



    // UPPER BOUNDS 

    // Edge Upper    (highRow, validCol), (validRow, highCol) 
    void testEdgeUpperRow()
    {
        Position piece;
        piece.set(8, 5);
        if (piece.getRow() != 8)
        {
            failedMethods.push_back("testEdgeUpperRow");
        }
    }

    void testEdgeUpperCol()
    {
        Position piece;
        piece.set(5, 8);
        if (piece.getColumn() != 8)
        {
            failedMethods.push_back("testEdgeUpperColumn");
        }
    }

    // Just Above    (highRow, validCol), (validRow, highCol) 
    void testJustUpperRow()
    {
        Position piece;
        piece.set(9, 5);
        if (piece.getRow() != 8)
        {
            failedMethods.push_back("testJustUpperRow");
        }
    }

    void testJustUpperCol()
    {
        Position piece;
        piece.set(5, 9);
        if (piece.getColumn() != 8)
        {
            failedMethods.push_back("testJustUpperCol");
        }
    }

    // Way Above     (highRow, validCol), (validRow, highCol) 
    void testExtremeUpperRow()
    {
        Position piece;
        piece.set(10000, 5);
        if (piece.getRow() != 8)
        {
            failedMethods.push_back("testExtremeUpperRow");
        }
    }

    void testExtremeUpperCol()
    {
        Position piece;
        piece.set(5, 10000);
        if (piece.getColumn() != 8)
        {
            failedMethods.push_back("testExtremeUpperCol");
        }
    }

    void display()
    {
        cout << "Failed Methods:" << endl;

        for (auto& element : failedMethods)
        {
            cout << element << endl;
        }
    }
};

