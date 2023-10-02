/*************************************************************
 * 1. Name:
 *    - Steven Sellers and Jarom 
 * 2. Assignment Name:
 *      Practice 04: Contaiers
 * 3. Assignment Description:
 *      Work with a list and a vector
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/


#include "testContainers.h"
#include <string>
#include <list>
using namespace std;

/*****************************************************************************
* ARRAY TO LIST
* INPUT:
*     a[]           : Array.
*     num           : Number of elements in array.
* OUTPUT:
*     listOfStrings : List of strings taken from an array.
*****************************************************************************/
list<string> arrayToList(string a[], int num)
{
    list<string> listOfStrings;
    for (int index = 0; index < num; index++) {
        listOfStrings.push_back(a[index]);
    }
    return listOfStrings;
}

/*****************************************************************************
* ARRYAY TO LIST BACKWARDS
* INPUT:
*     a[]           :  An array of strings.
*     num           :  Number of elements in the array.
* OUTPUT:
*     backwardsList :  List of strings in reverse order from the array.
*****************************************************************************/
list<string> arrayToListBackwards(string a[], int num)
{
    // Initialize
    list<string> backwardsList;

    for(int index = num - 1; index >= 0; index--)
    {
        backwardsList.push_back(a[index]);
    }
    return backwardsList;
}

/*****************************************************************************
* COPY A LIST TO A VECTOR
* INPUT:
*     l               : A list of strings.
* OUTPUT:
*     vectorOfStrings : Vector of Strings taken from a list.
*****************************************************************************/

vector<string> listToVector(const list<string>& l)
{
    vector<string> vectorOfStrings;
    //our function will itrate through the list and push each element onto the back of the vector.
    for (auto iterator = l.begin(); iterator != l.end(); ++iterator)
    {
        vectorOfStrings.push_back(*iterator);
    }
    return vectorOfStrings;
}

/*****************************************************************************
* LIST TO VECTOR BACKWARDS
* INPUT:
*     l             :  A list of strings.
* OUTPUT:
*     backwardsVec :  A vector of strings in reverse order from the list.
*****************************************************************************/
vector<string> listToVectorBackwards(const list<string>& l)
{
    vector<string> backwardsVec;

    for (auto rit = l.rbegin(); rit != l.rend(); rit++)
    {
        backwardsVec.push_back(*rit);
    }
    return backwardsVec;
}

/*****************************
 * FIND ELEMENT IN VECTOR
 *****************************/
bool findElementInVector(const vector<string>& v, const string& element)
{
    for (auto it = v.begin(); it != v.end(); it++) // Iterate through a vector of elements
    {
        if (*it == element)
        {
            return true; // Element is found
        }
    }
    return false; // Element not found
}

/*****************************
 * MAIN
 *****************************/
int main()
{
   TestCollection().run();
   return 0;
}
