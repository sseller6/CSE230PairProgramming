#include "position.h"

#include <iostream>

using namespace std;

// Constructor
Position::Position()
    : position(0)
{}

// Gets Row as an integer
int Position::getRow()
{
    return  position / 8;
}

// Gets Column as an integer
int Position::getColumn()
{
    int column = position % 8;
    // Column 8 will always be column = 0
    if (column == 0) 
    {
        return 8;
    }
    return column;
}

// Set position.
void Position::set(int row, int column)
{
    // Handle Invalid Inputs

    // Invalid Row: 1 <= Row >= 8
    if (row < 1) // Default low is 1
    {
        row = 1;
    }
    if (row > 8) // Default high is 8
    {
        row = 8;
    }

    // Invalid Col 1 <= Col >= 8
    if (column < 1)
    {
        column = 1;
    }
    if (column > 8)
    {
        column = 8;
    }

    position = row * 8 + column;
}

// Display position.
void Position::display()
{
    cout << "Row: " << getRow() << " " << "Col: " << getColumn() << endl;
}