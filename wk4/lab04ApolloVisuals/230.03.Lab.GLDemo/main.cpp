/*************************************************************
 * 1. Name:
 *      Jarom Anderson & Steven Sellers
 * 2. Assignment Name:
 *      Lab 04: Apollo 11 Visuals
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      Fixing syntax errors. We had a couple if statements without brackets
 *      that were just running and making us think the controls weren't working.
 *      When we got the HUD working, we noticed we were running out of fuel
 *      almost immediately. So we went to that area in the code and found the
 *      syntax errors.
 * 5. How long did it take for you to complete the assignment?
 *      9 hours
 *****************************************************************/

/**********************************************************************
 * Main
 * Opens an OpenGL window, draws to the window, and takes user input
 **********************************************************************/

#include "game.h"
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "lander.h"
using namespace std;


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    // Initialize graphics out.
    ogstream gout;

    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL.   
    Game* pGame = (Game*)p;

    // Call Update
    pGame->updateGame(pUI);

    // Draw Window
    pGame->display(gout, pUI);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pCmdLine,
    _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
    // Initialize OpenGL
    Point ptUpperRight(400.0, 400.0);
    Interface ui(0, NULL,
        "Lander Simulator",
        ptUpperRight);

    // Initialize the game class
    Game game(ptUpperRight);

    // set everything into action
    ui.run(callBack, &game);

    return 0;
}
