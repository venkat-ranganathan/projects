/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Prof. Foos
| Course:           CS-212: Data Structures for Engineers
| Program Name:     Simple File Processing
| Date:             12/18/2022
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   This program will use the following functions for processing input and output data files:
|    > fopen   - This function open a file for either input or output
|    > fgetc   - This function will read one character from the input file
|    > ungetc  - This function will put a character back into the input file.
|    > fgets   - This function will read a string from an input file
|    > fscanf  - This function read data from an input file, much like scanf
|    > fprintf - This function print data to an output file, much like printf
|    > fclose  - This function will close a data file
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   All input will be read in from an input file named input.txt
|
|--------------------------------------------------------------------------------------------------
| Processing:
|  There will be no calculations done in this program
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|  All output will be written to an output file named output.txt
|
|--------------------------------------------------------------------------------------------------
*/

// Define this macro if you are going to run in Microsoft Visual Studio
#define _CRT_SECURE_NO_WARNINGS

// Include for scanf and printf
#include <stdio.h>

// Include for strlen
#include <string.h>

#define MAX 80

#define SCREEN_WIDTH 80
#define STAR '*'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Prof. Foos"
#define LAB "Simple File Handling"

// Prototypes
void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);

int main(void)
{
	// Declare a file pointer
	FILE* pFin;
	FILE* pFout;

	// variables for storing the data that is read from the input file
	char myString[MAX];
	int intValueA;
	int intValueB;

	// Variables for testing our input file
	int integersReadIn;
	char dataInFile;

	// Pass in stdout, which is defined in the header file stdio.h, 
	// so the output goes to the screen
	PrintHeader(stdout);

	// Print message to the screen
	printf("\nAll other output is located in output.txt\n\n");

	//
	// NOTES: - fopen - 
	// The third parameters determines what kind of file we are opening
	// 	r - read or input file
	//	w - write or output file
	//
	// There are others, but these will be the only two we use this semester
	//

	// Open file as an input file
	pFin = fopen("input.txt", "r");

	// Open file as an output file 
	pFout = fopen("output.txt", "w");

	// Pass in pFout so the header gets printed to the output file
	PrintHeader(pFout);


	// Check to see if the opened
	if (pFin == NULL)
	{
		// Print message to the screen and the output file
		printf("\nFile did not open");
		fprintf(pFout, "\nFile did not open");
		
	}
	else
	{
		//
		// We can now assume that input file is open
		//

		//
		// NOTES: - fgetc -
		// This function will read in one character from the data file
		//

		// Check to see if there is data in the file
		dataInFile = fgetc(pFin);

		// Check to see if the file is empty
		if (dataInFile == EOF)
		{
			// Print message to the screen and the output file
			printf("File was empty\n\n");
			fprintf(pFout, "File was empty\n\n");
		}
		else
		{
			// 
			// We can assume that there is data in the file
			//

			//
			// NOTES: - ungetc -
			// This function will put the character read in from fgetc back into the file
			//

			// First, put the character back
			ungetc(dataInFile, pFin);

			//
			// NOTES: - fgets - 
			// When reading a string, remember that the last character will be NULL or '\0'
			// Also remember that the character before that will probably be an end line or '\n'
			//

			// Read a line, up to 80 characters from our input file
			// This function will include spaces
			fgets(myString, MAX, pFin);

			//
			// NOTES: - fprintf - 
			// Notice that the first parameter is our file stream
			// The next two parameters are the same as using printf
			//

			// Print a string to our output file 
			fprintf(pFout, "Line 1: %s", myString);

			//
			// NOTES - fscanf - 
			// Notice the first parameter is our file stream
			// The next two parameters are the same as using scanf
			//

			// Read two numbers in from our input file
			integersReadIn = fscanf(pFin, "%d %d", &intValueA, &intValueB);

			//
			// NOTE - integersReadIn -
			// The above line of code attempts to read in two integers 
			// 
			// If two integers are read in, integersReadIn will equal 2.
			// If one integer is read in, integersReadIn will equal 1.
			// If no integers are read in, integersReadIn will equal -1.
			//
			
			// Check to see if any data was read in
			if (integersReadIn == -1)
			{
				// Print error message to the screen
				printf("\nERROR: No integers were read in\n\n");
			}

			// Check to see if only one integer was read in
			else if (integersReadIn == 1)
			{
				// Print error message to the screen
				printf("\nERROR: Only one integer was read in\n\n");

				// Print the one number to the output file
				fprintf(pFout, "Number 1: %d\n", intValueA);
			}

			// Assume that two integers were read in
			else
			{
				// Print the two numbers to the output file
				fprintf(pFout, "Number 1: %d\n", intValueA);
				fprintf(pFout, "Number 2: %d\n", intValueB);
			}
		}

		//
		// Close files - ALWAYS REMEMBER TO CLOSE YOUR FILES
		//
		
		// Check to see if an input file exist 
		if (pFin != NULL)
		{
			// close the input file 
		   fclose(pFin);
		}
		
		// Check to see if an output file exist
		if (pFout != NULL)
		{
			// Close the output file
		   fclose(pFout);
		}
	}

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

} // END CenterString
