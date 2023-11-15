/*****************************************************************************
 * Week 10 Problem Set Test Driven Development
 *****************************************************************************/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class TestChessPiece; // forward delcaration

class ChessPiece
{
    friend TestChessPiece;
public:
    // Methods
    ChessPiece() : position(0) {};

    // Sets a position given a clumn and a row (ex: "a1" = position 0)
    void setPosition(const char * coordinate) 
    {
        int column = (int)coordinate[0] - 97;
        int row    = (int)coordinate[1] - 49;

        // get column (letter) 
        // If column is under bounds
        if (column < 0)
            column = 0;
        // If column is over bounds
        else if (8 <= column)
            column = 7;
       
        // get row (number)
        // If row is under bounds
        if (row < 0)
            row = 0;
        // If row is over bounds
        else if (8 <= row)
            row = 7;

        // convert to a position
        position = (row * 8) + column;
    };

private:
    // Attributes
    int position;
};

class TestChessPiece
{
public:
    void run() 
    {
        test_setPosition_a1();
        test_setPosition_c1();
        test_setPosition_i1(); // Column out of bounds
        test_setPosition_a9(); // Row out of bounds

    };
    
private:
    void test_setPosition_a1()
    {
        // setup
        class ChessPiece piece;
        piece.position = 45;
        // exercise
        piece.setPosition("a1");
        // verify
        assert(piece.position == 0);
        // teardown
    }

    void test_setPosition_c1()
    {
        // setup
        class ChessPiece piece;
        piece.position = 10;
        // exercise
        piece.setPosition("c1");
        // verify
        assert(piece.position == 2);
        // teardown
    }

    void test_setPosition_i1()
    {
		// setup
		class ChessPiece piece;
		piece.position = 10;
		// exercise
		piece.setPosition("i1");
		// verify
		assert(piece.position == 7);
		// teardown
    }

    void test_setPosition_a9()
    {
		// setup
		class ChessPiece piece;
		piece.position = 10;
		// exercise
		piece.setPosition("a9");
		// verify
		assert(piece.position == 56);
		// teardown
    }
};

int main()
{
    TestChessPiece().run();

    return 0;
}
