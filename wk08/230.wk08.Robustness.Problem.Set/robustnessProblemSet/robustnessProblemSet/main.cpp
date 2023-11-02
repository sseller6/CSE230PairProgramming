#include "position.h"
#include "blackBOxTestPosition.h"
#include <iostream>

using namespace std;

void adHocTestPosition();

int main()
{
    cout << "Ad Hoc Test: " << endl;
    adHocTestPosition();

    cout << "\nBlack Box Test: " << endl;
    BlackBoxTestPosition blackBox;
    blackBox.run();

    cout << "\nWhite Box Test: " << endl;
    cout << "Not Implemented Yet" << endl;


    return 0;
}

void adHocTestPosition()
{
    // Test getters and setters
    Position piece;
    piece.set(2, 4);
    // Getters and setters are called in display function
    piece.display(); 
    
    cout << "Expected: Row 2, Col 4" << endl;
}
