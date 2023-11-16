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
        int pos1   = (int)coordinate[0];
        int pos2   = (int)coordinate[1];
        int column = -1;
        int row    = -1;

        // find position of the letter

        // (col, row) lowercase (valid)
        if (97 <= pos1 && pos1 <= 104)
        {
            column = pos1 - 97;
            row    = pos2 - 49;
        }
        // (row, col) lowercase
        else if (97 <= pos2 && pos2 <= 104)
        {
            row    = pos2 - 49;
            column = pos1 - 97;
        }
        // (col, row) uppercase
        else if (65 <= pos1 && pos1 <= 72)
        {   
            column = pos1 - 65;
            row    = pos2 - 49;
        }

        // (row, col) uppercase
        else if (65 <= pos1 && pos1 <= 72)
        {
            row    = pos2 - 49;
            column = pos1 - 65;
        }
        else
        {
            cout << "Error: Invalid String";
            position = -1; // Invalid position
            return;
        }

        // set position
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
        test_setPosition_A1();
        test_setPosition_C1();
        test_setPosition_1a();
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

    void test_setPosition_A1()
    {
		// setup
		class ChessPiece piece;
		piece.position = 45;
		// exercise
		piece.setPosition("A1");
		// verify
		assert(piece.position == 0);
		// teardown
    }

    void test_setPosition_C1()
    {
		// setup
		class ChessPiece piece;
		piece.position = 45;
		// exercise
		piece.setPosition("C1");
		// verify
		assert(piece.position == 2);
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
		assert(piece.position == -1);
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
		assert(piece.position == -1);
		// teardown
    }

    void test_setPosition_1a()
    {
        // setup
        class ChessPiece piece;
        piece.position = 10;
        piece.setPosition("1a");
        // verify
        assert(piece.position == 0);
        // teardown
    }
};

int main()
{
    TestChessPiece().run();

    return 0;
}
