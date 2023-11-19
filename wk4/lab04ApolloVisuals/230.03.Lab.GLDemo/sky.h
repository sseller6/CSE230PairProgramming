/***********************************************************************
 * Header File:
 *     Sky : Contains all the stars in the sky
 * Author:
 *    Jarom Anderson & Steven Sellers
 * Summary:
 *    Where the sky is located as well as all the stars
 ************************************************************************/

#pragma once

#include "star.h"    // for stars
#include "uiDraw.h"  // for ogstream

using namespace std;

 /***********************************************************
  * SKY
  * The Sky class
  ***********************************************************/
class Sky
{
public:
	Sky(const Point& ptUpperRight);
	void draw(ogstream &gout);
	void reset();
private:
	Star stars[50];


};