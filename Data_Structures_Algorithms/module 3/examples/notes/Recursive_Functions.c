/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Prof. Foos
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Recursive Functions
| Date:             January 2, 2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   
|
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   All input will be assigned in the program. 
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   
|
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   All output fill be displayed on the screen
|
|--------------------------------------------------------------------------------------------------
*/

// Define if working in Visual Studio
#define _CRT_SECURE_NO_WARNINGS

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Macros
#define DASH '-'
#define STAR '*'
#define SCREEN_WIDTH 80

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Prof. Foos"
#define LAB "Recursive Example"

// Prototypes 
void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);

// Prototypes for recursive functions 
void StarPattern(FILE* pFout, int number);
void PositiveNumberCount(int myArray[], int arrayCount, int initialArrayPosition, int* pPosCount);
int MathFunction(int number);

int main(void)
{
	PrintHeader(stdout);

	PrintDivider(stdout, DASH, 80);
	CenterString(stdout, "Star Pattern", 80);
	PrintDivider(stdout, DASH, 80);

	StarPattern(stdout, 5);

	//-------------------------------------------------------------------------
	// Recursive Function: StarPatern
	//-------------------------------------------------------------------------

	// Output to the screen

	PrintDivider(stdout, DASH, 80);
	CenterString(stdout, "1st Recursive Function: Star Pattern - Printed to the screen", 80);
	PrintDivider(stdout, DASH, 80);

	StarPattern(stdout, 15);

	PrintDivider(stdout, DASH, 80);

	//-------------------------------------------------------------------------
	// Recursive Function: Array function 
	//-------------------------------------------------------------------------

	int myArray[] = { 2, 0, 1, -5 };
	
	int numberOfPositiveNumbers = 0;

	PrintDivider(stdout, DASH, 80);
	CenterString(stdout, "2nd Recursive Function: Array function - Printed to the screen", 80);
	PrintDivider(stdout, DASH, 80);

	PositiveNumberCount(myArray, 4, 0, &numberOfPositiveNumbers);

	fprintf(stdout, "Number of positive integers in the array: %d\n", numberOfPositiveNumbers);


	//-------------------------------------------------------------------------
	// Recursive Function: Math Function
	//-------------------------------------------------------------------------

	int answer;

	PrintDivider(stdout, DASH, 80);
	CenterString(stdout, "3rd Recursive Function: Math Function", 80);
	PrintDivider(stdout, DASH, 80);

	// Print math function to the screen
	fprintf(stdout, "Math Function\n");
	fprintf(stdout, "If x <= 3, then f(x) = x * x - 2\n");
	fprintf(stdout, " if x > 3, then f(x) = x + f ( x-3 )\n");

	// Evaluate f(8)
	answer = MathFunction(8);

	fprintf(stdout, "\n f(5) = %d\n\n", answer);

	PrintDivider(stdout, DASH, 80);

	return 0;
}


//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE* pOutput)
{
	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

	// Call functions to print three strings to center to the screen
	CenterString(pOutput, SCHOOL, SCREEN_WIDTH);
	CenterString(pOutput, PROGRAMMER, SCREEN_WIDTH);
	CenterString(pOutput, LAB, SCREEN_WIDTH);

	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

} // End PrintHeader


//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void PrintDivider(FILE* pOutput, char symbol, int numberOf)
{
	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print a bunch of symbols across the screen
	while (counter < numberOf)
	{
		// Print one character to the screen
		fprintf(pOutput, "%c", symbol);

		// Increment counter
		counter++;
	}

	// Move the cursor down to the next line
	fprintf(pOutput, "\n");

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
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross)
{
	// Capture how long the string is
	// Cast to an integer because strlen technically returns size_t
	int stringLength = (int)strlen(string);

	// Calculate the width to print the string in
	int width = (lengthToCenterAcross + stringLength) / 2;

	// Calculate how many blank spaces are needed before printing the string
	int numberOfBlankSpaces = width - stringLength;

	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print the spaces needed to center the string
	while (counter < numberOfBlankSpaces)
	{
		// Print one space
		fprintf(pOutput, " ");

		// Increment counter
		counter++;
	}

	// Print the string
	fprintf(pOutput, "%s\n", string);

}


//-----------------------------------------------------------------------------
// Function Name: OpenFile
// Description:
//  This function will prompt the user for a file and open the file
//
//  Because FILE is a pointer and we want to change the value of the address
//  we will need to use a double pointer. 
// 
//  The double pointer uses ** in the parameters. 
//-----------------------------------------------------------------------------
void OpenFile(FILE** filePointer, char message[], char type[])
{
	char fileName[30];

	printf("%s", message);

	// Check to see if one string was read in
	if (scanf("%s", fileName) == 1)
	{
		// Because fileName is a double pointer, we must dereference it 
		*filePointer = fopen(fileName, type);
	}

}

//-----------------------------------------------------------------------------
// Task 1: starPattern - creates a pattern of stars based on number given
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Function Name: StarPattern
// Description:
//   This function will print a pattern of stars to the screen or an output 
//  file.
//
//-----------------------------------------------------------------------------
void StarPattern(FILE * pFout, int number) 
{ 
	PrintDivider(pFout, STAR, number);
	 
	// Will keep looping until parameter number is equal to 1
	if (number > 1) 
	{ 
		StarPattern(pFout, number - 1); 
	} 
	 
	PrintDivider(pFout, STAR, number); 
}
 
//-----------------------------------------------------------------------------
// Task 2: Array Function
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Function Name: PositiveNumberCount
// Description:
//   This function will use recursive calls to count the number of positive 
//  numbers. Positive numbers will be defined as any number greater than 0.
// 
//-----------------------------------------------------------------------------
void PositiveNumberCount(int myArray[], int arrayCount, int initialArrayPosition, int * pPosCount)
{
	// Loop until array position reaches size of the array - 1
	// arrayCount - 1 is used because arrayCount would require a 4 to fail the if-statement. 
	// The next if-statement would then check myArray[4] which is outside the bounds of the array

	if (initialArrayPosition < arrayCount - 1)
	{
		PositiveNumberCount(myArray, arrayCount, initialArrayPosition + 1, pPosCount);
	}

	if (myArray[initialArrayPosition] > 0)
	{
		// Increment positive number count
		(*pPosCount)++;
	}
}

//---------------------------------------------------------------------------------------------------------------------
// Task 3: Math Function
//---------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Function Name: MathFunction
// Description:
//   For Numbers <= 3: f(x) = (x * x) - 2 
//   For all other numbers: f(x) = x + f( x - 3 )
//
//-----------------------------------------------------------------------------
int MathFunction(int number)
{
	if (number <= 3)
	{
		// Return the base case
		return number * number - 2;

	}
	else
	{
		// Call the function again
		return (number + MathFunction(number - 3));
	}
}