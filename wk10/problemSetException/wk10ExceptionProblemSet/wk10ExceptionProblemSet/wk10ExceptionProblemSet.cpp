/*************************************************************
 * 1. Name:
 *      Jarom Anderson & Steven Sellers
 * 2. Assignment Name:
 *      Practice 10: Exceptions
 * 3. Assignment Description:
 *      Throwing and catching exceptions
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part was figuring out why the program
 *      would not continue after the first assert.
 * 5. How long did it take for you to complete the assignment?
 *      About 1 hour and 15 minutes.
 **************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/**************************************************************
* Exception class declerations.
***************************************************************/
class ErrorNullPosition {};

class ErrorMultipleColumn {};

class ErrorCapitalColumn {};

class ErrorOutsideColumnRange {};

class ErrorMultipleRow {};

class ErrorOutsideRowRange {};

class ErrorUnknownLetter {};

class ErrorMissingRow {};

class ErrorMissingColumn {};

/**************************************
 * GET POSITION
 * Turn a chess position like "d4" into a number
 **************************************/
int getPosition(const char* position)
{
    int row = -1;
    int col = -1;

    // Start of "try-catch" block.
    try
    {
        if (nullptr == position)
        {
            throw ErrorNullPosition();
        }

        for (const char* p = position; *p; p++)
        {
            if (isalpha(*p))
            {
                if (col != -1)
                {
                    throw ErrorMultipleColumn();
                }
                else if (isupper(*p))
                {
                    throw ErrorCapitalColumn();
                }
                else if ('a' <= *p && *p <= 'h')
                    col = *p - 'a';
                else
                {
                    throw ErrorOutsideColumnRange();
                }
            }
            else if (isdigit(*p))
            {
                if (row != -1)
                {
                    throw ErrorMultipleRow();
                }
                else if ('1' <= *p && *p <= '8')
                    row = *p - '1';
                else
                {
                    throw ErrorOutsideRowRange();
                }
            }
            else
            {
                throw ErrorUnknownLetter();
            }
        }

        if (row == -1)
        {
            throw ErrorMissingRow();
        }
        else if (col == -1)
        {
            throw ErrorMissingColumn();
        }

        return row * 8 + col;
    }
    catch (ErrorNullPosition e)       
    { 
        cout << "\tERROR: Please provide a valid string\n";
		return -1;
    }
    catch (ErrorMultipleColumn e)     
    { 
        cout << "\tERROR: More than one column specifier\n";
		return -1;
    }
    catch (ErrorCapitalColumn e)      
    { 
        cout << "\tERROR: Columns must be lowercase\n";
		return -1;
	}
    catch (ErrorOutsideColumnRange e) 
    { 
        cout << "\tERROR: Columns must be between a and h\n";
		return -1;
	}
    catch (ErrorMultipleRow e)        
    { 
        cout << "\tERROR: More than one row specifier\n";
		return -1;
	}
    catch (ErrorOutsideRowRange e)    
    { 
        cout << "\tERROR: Rows must be between 1 and 8\n";
		return -1;
	}
    catch (ErrorUnknownLetter e)      
    { 
        cout << "\tERROR: Unknown letter\n"; 
        return -1;
    }
    catch (ErrorMissingRow e)         
    { 
        cout << "\tERROR: You must specify a row\n";
		return -1;
	}
    catch (ErrorMissingColumn e)      
    { 
        cout << "\tERROR: You must specify a column\n";     
        return -1;
    }
}


/**************************************
 * TEST GET POSITION
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void test_getPosition()
{
    assert(27 == getPosition("d4"));
    assert(27 == getPosition("4d"));
    assert(0  == getPosition("a1"));
    assert(63 == getPosition("h8"));
    assert(7  == getPosition("h1"));
    assert(56 == getPosition("a8"));
    assert(-1 == getPosition(nullptr));
    assert(-1 == getPosition("D4"));
    assert(-1 == getPosition("dd4"));
    assert(-1 == getPosition("d44"));
    assert(-1 == getPosition("d"));
    assert(-1 == getPosition("4"));
    assert(-1 == getPosition("i8"));
    assert(-1 == getPosition("h9"));
    assert(-1 == getPosition("d4^"));
}

/**************************************
 * MAIN
 **************************************/
int main()
{
    test_getPosition();
    cout << "Tests pass\n";

    return 0;
}