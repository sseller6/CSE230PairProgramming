#include <iostream>

using namespace std;


/****************************************************************
* POSITION 
****************************************************************/
class Position 
{
private:
    char position;
public:
    Position();
    int getRow();
    int getColumn();
    void set(int row, int column);
    void display();

};

/****************************************************************
* TEST POSITION
****************************************************************/
class TestPosition
{
    // Test getters and setters
    Position piece;
    piece.set(2, 4);
    // Getters and setters are called in display function
    piece.display();

    // Test getters and setters
    Position piece;
    piece.set(2, 4);
    // Getters and setters are called in display function
    piece.display();


};

int main()
{
    // Test getters and setters
    Position piece;
    piece.set(2, 4);
    // Getters and setters are called in display function
    piece.display();

    return 0;
}

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

