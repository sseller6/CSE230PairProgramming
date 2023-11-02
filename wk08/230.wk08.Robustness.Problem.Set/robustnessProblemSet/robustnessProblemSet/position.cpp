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
    return position % 8;
}

// Set position.
void Position::set(int row, int column)
{
    position = row * 8 + column;
}

// Display position.
void Position::display()
{
    cout << "Row: " << getRow() << " " << "Col: " << getColumn() << endl;
}