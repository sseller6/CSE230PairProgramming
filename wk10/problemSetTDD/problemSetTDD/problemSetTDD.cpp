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
        int pos1   = tolower((int)coordinate[0]);
        int pos2   = tolower((int)coordinate[1]);

        // Make sure both columns are valid

        int column = -1;
        int row    = -1;

        // find position of the letter

        // (col, row) 
        if (isValidColumn(pos1) && isValidRow(pos2))
        {
            column = pos1 - 97;
            row    = pos2 - 49;
        }
        // (row, col) 
        else if (isValidRow(pos1) && isValidColumn(pos2))
        {
            column = pos2 - 97;
            row    = pos1 - 49;
        }
        else
        {
            position = -1;
            return;
        }
        

        // set position
        position = (row * 8) + column;

    };

private:
    // Validate Input
    bool isValidColumn(int column) 
    {
        // Valid range
        if (97 <= column && column <= 104)
            return true;
        else
            return false;
    }
    bool isValidRow(int row) 
    {
        // Valid range
        if (49 <= row && row <= 56)
            return true;
        else
            return false;
    }
    // Attributes
    int position;
};

class TestChessPiece
{
public:
    void run() 
    {
        test_setPosition_a1(); // Valid On board
        test_setPosition_c1(); // Valid on board
        test_setPosition_i1(); // Column out of bounds
        test_setPosition_a9(); // Row out of bounds
        test_setPosition_A1(); // Uppercase Column
        test_setPosition_C1(); // Uppercase Column
        test_setPosition_1a(); // Reverse Order

        test_isValidRow_17(); // Way below bounds
        test_isValidRow_48(); // Just below
        test_isValidRow_49(); // Lower Valid
        test_isValidRow_56(); // Upper Valid
        test_isValidRow_57(); // Just Above
        test_isValidRow_63(); // Way Above

        test_isValidColumn_63(); // Way Below
        test_isValidColumn_96(); // Just below
        test_isValidColumn_97(); // Lower Valid
        test_isValidColumn_104(); // Upper Valid
        test_isValidColumn_105(); // Just Above
        test_isValidColumn_127(); // Way Above
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

    void test_isValidRow_17()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidRow(17);
        // Verify
        assert(result == false);
        //teardown
    }

    void test_isValidRow_48()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidRow(48);
        // Verify
        assert(result == false);
        //teardown
    }

    void test_isValidRow_49()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidRow(49);
        // Verify
        assert(result == true);
        //teardown
    }

    void test_isValidRow_56()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidRow(56);
        // Verify
        assert(result == true);
        //teardown
    }

    void test_isValidRow_57()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidRow(57);
        // Verify
        assert(result == false);
        //teardown
    }

    void test_isValidRow_63()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidRow(63);
        // Verify
        assert(result == false);
        //teardown
    }

    void test_isValidColumn_63()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidColumn(63);
        // Verify
        assert(result == false);
        //teardown
    }

    void test_isValidColumn_96()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidColumn(96);
        // Verify
        assert(result == false);
        //teardown
    }

    void test_isValidColumn_97()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidColumn(97);
        // Verify
        assert(result == true);
        //teardown
    }

    void test_isValidColumn_104()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidColumn(104);
        // Verify
        assert(result == true);
        //teardown
    }

    void test_isValidColumn_105()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidColumn(105);
        // Verify
        assert(result == false);
        //teardown
    }

    void test_isValidColumn_127()
    {
        // Setup
        ChessPiece piece;
        // Exercise
        bool result = piece.isValidColumn(127);
        // Verify
        assert(result == false);
        //teardown
    }
};

int main()
{
    TestChessPiece().run();

    return 0;
}
