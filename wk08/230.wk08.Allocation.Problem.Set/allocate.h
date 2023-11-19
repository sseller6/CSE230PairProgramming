/************************************************************************
 * 1. Name:
 *      Jarom Anderson & Steven Sellers
 * 2. Assignment Name:
 *      Practice 08: Allocation
 * 3. Assignment Description:
 *      Allocate an array and then use it
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 ***********************************************************************/

 /***********************************************************************
  * ALLOCATE ONE FLOAT
  * This function takes a float as a parameter which will be
  * placed in a newly allocated slot.
  * This function will return a pointer 
  * to the newly allocated float.
  **********************************************************************/
 inline float* allocateOneFloat(float num)
{
	 // Create a newly allocated slot for the num to be placed into.
	 float* newAllocatedSlot;
	 // Allocate the new slot.
	 newAllocatedSlot = new float;
	 // Place the num in the new slot.
	 *newAllocatedSlot = num;
	 // Return a pointer to the newly allocated float.
	 return newAllocatedSlot;
}

/************************************************************************
 * ALLOCATE ARRAY of DOUBLEs
 * This function will take an integer as a parameter which 
 * determine how many slots will be in the newly allocated array. 
 * If the number is zero or negative, it will return the nullptr. 
 * Otherwise, it will return a pointer to the newly allocated array.
 *******************************************************************/
 inline double* allocateArrayDouble(int size)
 {
	 // If the size is zero or negative, it will return nullptr. 
	 if (size <= 0)
	 {
		 return nullptr;
	 }
	 // Otherwise, it will return a pointer to the newly allocated array.
	 else
	 {
		 // First step is to allocate the memory.
		 double* newAllocatedArray = new double[size];
		 return newAllocatedArray;
	 }
 }

/************************************************************************
 * DELETE ONE FLOAT
 * This function will take a float pointer as a parameter. 
 * It will delete the pointer (if the pointer is not the nullptr) 
 * and set the pointer to nullptr. 
 * This means the pointer parameter must be a float pointer 
 * by-reference. 
 * This function has a void return value.
 ***********************************************************************/
 inline void deleteOneFloat(float* &p)
 {
	 // If the pointer is not null, delete the pointer & set to null.
	 if (p != nullptr)
	 {
		 delete p;
		 p = nullptr;
	 }
 }

/************************************************************************
 * DELETE ARRAY of DOUBLEs
 * This function will work much like deleteOneFloat().
 ***********************************************************************/
 inline void deleteArrayDouble(double* &p)
 {
	 if (p != nullptr)
	 {
		 delete[] p;
		 p = nullptr;
	 }
 }