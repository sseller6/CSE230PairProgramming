// Verifys the input and output of the position class.

#pragma once

#include "position.h"

#include <iostream>
#include <string>

using namespace std;

class  WhiteBoxTestPosition
{
public:
	void run()
	{
		testStoredAsChar();
		testRowValue();
		testColumnValue();
	}
private:
	// Problem 24.4: Resilient asks for only 3 test functions.
	// Test Stored As Char, Test Row Value, and Test Column Value
	// will be the three functions.
	void testStoredAsChar()
	{
		// Create a piece.
		Position piece;
		// Set position of piece.
		piece.set(0, 1);
		// Display char value to verify that value has been stored as char.
		cout << "Char value: " << position << endl;
	}
	void testRowValue()
	{
		// Create a piece.
		Position piece;
		// Set position of piece.
		piece.set(0, 5);
		// Display row value to verify that it's not less than 1 nor greater than 8.
		cout << "Row value: " << piece.getRow() << endl;
	}
	void testColumnValue()
	{
		// Create a piece.
		Position piece;
		// Set position of piece.
		piece.set(5, 5);
		// Display column value to ensure it's not less than 0 nor greater than 7.
		cout << "Row value: " << piece.getColumn() << endl;
	}
};