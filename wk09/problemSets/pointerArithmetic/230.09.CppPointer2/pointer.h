/*************************************************************
 * 1. Name:
 *      Jarom Anderson & Steven Sellers
 * 2. Assignment Name:
 *      Practice 09: Pointer Arithmetic
 * 3. Assignment Description:
 *      Traverse a string using pointer notation
 * 4. What was the hardest part? Be as specific as possible.
 *      It was hard to figure out how to pass in the address of the array.
 *      We ended up sovling it when we looked at the parameters for strlen()
 * 5. How long did it take for you to complete the assignment?
 *      It took us about 46 minutes to complete the assignment.
**************************************************************/


/**************************************
 * COUNT - ARRAY
 **************************************/
int countArray(const char *text, char letter)
 {
	 int count = 0;
	 int textLength = strlen(text);
	 for (int i = 0; i < textLength; i++)
	 {
		 if (text[i] == letter)
		     count++;
	 }

	 return count;
 }

/**************************************
 * COUNT - POINTER
 * Loop through an array using pointer
 * notation, then return the count as
 * an int.
 **************************************/
 int countPointer(char *text, char letter)
 {
	 int count = 0;
	 int textLength = strlen(text);
	 // "char* p = &text" means to start at the beginnning of the c-string.
	 // "*p" means to end when p is no longer true.
	 // "p++" typical increment by 1.

	 for (char* p = text; *p; p++)
	 {
		 if (*p == letter)
		 {
			 count += 1;
		 }
	 }
	 return count;
 }
