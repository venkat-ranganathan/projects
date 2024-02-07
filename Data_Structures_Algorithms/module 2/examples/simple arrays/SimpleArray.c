/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Prof. Foos
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Simple Array Program
| Date:             12/16/2022
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   This program will populate an array of 100 integers with random numbers.
|   The numbers will be doubled using bit manipulation.
|   The array will be printed before and after the doubling the values in rows of 10.
|
|   NOTE: There are no data files involved in this sample program.
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   All numbers in the array will be randomly assigned
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   All values in the array will be doubled with bit manipulation.
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The array will be printed to the screen before and after the doubling of the values.
|
|--------------------------------------------------------------------------------------------------
*/

#include "SimpleArray.h"

int main(void)
{
	// Declare an array of 100 integers
	int intArray[MAX];

	//
	// NOTE
	// To create a random number, you will need to start with two things:
	//
	// 1. Create an instance of time_t (This is a structure)
	// 2. Call srand with the return value of time (casted to an unsigned int) to 
	//    seed the random number generator to the clock.
	//
	
	// Create an instance of time_t (Notice this is NOT a pointer)
	time_t myTime;

	// Initializes random number generator to the clock
	srand((unsigned int)time(&myTime));
	
	PrintHeader();

	InitializeArray(intArray);

	PrintArray(intArray);

	DoubleArray(intArray);

	PrintArray(intArray);

	// Move the cursor down one line
	printf("\n");

	return 0;
}

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(void)
{
	// Call function to print a divider to the screen
	PrintDivider(STAR, SCREEN_WIDTH);

	// Call functions to print three strings to center to the screen
	CenterString(SCHOOL, SCREEN_WIDTH);
	CenterString(PROGRAMMER, SCREEN_WIDTH);
	CenterString(LAB, SCREEN_WIDTH);

	// Call function to print a divider to the screen
	PrintDivider(STAR, SCREEN_WIDTH);

} // End PrintHeader


//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void PrintDivider(char symbol, int numberOf)
{
	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print a bunch of symbols across the screen
	while (counter < numberOf)
	{
		// Print one character to the screen
		printf("%c", symbol);

		// Increment counter
		counter++;
	}

	// Move the cursor down to the next line
	printf("\n");

} // END PrintDivider


//-----------------------------------------------------------------------------
// Function Name: CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void CenterString(char string[], int lengthToCenterAcross)
{
	// Capture how long the string is
	// Cast to an integer because strlen technically returns size_t
	int stringLength = (int)strlen(string);

	// Calculate the width to print the string in
	int width = (lengthToCenterAcross + stringLength) / 2;

	// Calculate how many blank spaces are needed before printing the string
	int numberOfBlankSpaces = width - stringLength;

	// Print the spaces needed to center the string
	for (int counter = 0; counter < numberOfBlankSpaces; counter++)
	{
		// Print one space
		printf(" ");

	}

	// Print the string
	printf("%s\n", string);

} // END CenterString


//-----------------------------------------------------------------------------
// Function Name: InitializeArray
// Description:
//   Every element of the array will be assigned a value between 0 and 99.
//
//-----------------------------------------------------------------------------
void InitializeArray(int intArray[])
{
	for (int index = 0; index < MAX; index++)
	{
		//
		// NOTE
		//
		// The rand function will return a random number of type unsigned int.
		// 
		// We will then use the modulus operator to take the 
		//  remainder after dividing by 100.
		//
		// So our random number will be between 0 and 99
		//
		
		// Set each element of the array to a number between 0 and 99
		intArray[index] = rand() % 100;
	}
}


//-----------------------------------------------------------------------------
// Function Name: DoubleArray
// Description:
//   Every element of the array will be doubled.
//
//-----------------------------------------------------------------------------
void DoubleArray(int intArray[])
{
	for (int index = 0; index < MAX; index++)
	{
		// Use shift left to double a value of the array
		intArray[index] = intArray[index] << 1;
	}

}


//-----------------------------------------------------------------------------
// Function Name: PrintArray
// Description:
//   Print array in rows of 10 integers per line.
//
//-----------------------------------------------------------------------------
void PrintArray(const int intArray[])
{
	PrintDivider(DASH, TABLE_WIDTH);
	
	CenterString("Table of Integers", TABLE_WIDTH);

	PrintDivider(DASH, TABLE_WIDTH);

	for (int index = 0; index < MAX; index++)
	{
		// Print one element of the array 
		// The integer will be left justified in a width of 5 spaces
		printf("%-5d", intArray[index]);

		// Check to see a enter key should be printed
		if (((index + 1) % 10) == 0)
		{
			// Move the cursor down to the next line
			printf("\n");
		}
	}

	// Move the cursor down to the next line
	printf("\n");

}

