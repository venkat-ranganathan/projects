/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Prof. Foos
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Files and Arrays
| Date:             January 30, 2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   This program will demonstrate the following:
|     1. Using input and output files 
|     2. Using a function to open and close the input and output files 
|        (you will use double pointers)
|     3. The arrays will be printed in rows of 10. One function will print to both the output file
|        and the screen
|     4. Pointer arithmetic will be used to add three to each element
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   All data for the array will come from an input file.
|  
|--------------------------------------------------------------------------------------------------
| Processing:
|  This program will print the array in table format.
|  Then three will be added to every element of the array (using pointer arithmetic.
|  The array will be printed a second time
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The array will be printed to both the output file and the screen.
|
|--------------------------------------------------------------------------------------------------
*/

#include "File_And_Arrays.h"

int main(void)
{
	// Declare a file pointer
	FILE* pFin;
	FILE* pFout;

	int intArray[MAX];
	int arrayCounter = 0;

	//
	// NOTES:
	// Notes that we are passing in the address of a pointer to OpenFile
	// In the OpenFile header you will notice that the first parameter is a double pointer
	//
	// This technique must be used when passing a file stream to open the file.
	//

	OpenFile(&pFin, "Enter name of the input file to open: ", "r");

	OpenFile(&pFout, "Enter name of the output file to open: ", "w");

	//
	// NOTES:
	// Passing in stdout will print to the screen
	// Passing in pFout will print to the output file
	//
	
	PrintHeader(stdout);
	PrintHeader(pFout);

	FillArray(pFin, intArray, &arrayCounter);

	// Check to see if the file was empty (no data was read in)
	if (arrayCounter == 0)
	{
		// Print message to the screen and output file
		// The first function call could have been printf without stdout
		fprintf(stdout, "\nNo integers were stored in the array\n\n");
		fprintf(pFout, "\nNo integers were stored in the array\n\n");
	}
	else
	{
		//
		// We can assume that some data was read in from the input file
		//

		PrintArray(stdout, intArray, arrayCounter);
		PrintArray(pFout, intArray, arrayCounter);

		AddThreeWithPointerArithmatic(intArray, arrayCounter);

		PrintArray(stdout, intArray, arrayCounter);
		PrintArray(pFout, intArray, arrayCounter);
	}

	// Close the data file - ALWAYS REMEMBER TO CLOSE YOUR FILES
	CloseFiles(&pFin, &pFout);

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
// Function Name:CloseFiles
// Description:
//  This function will close both files
//
//  Because FILE is a pointer and we want to change the value of the address
//  we will need to use a double pointer. 
// 
//  The double pointer uses ** in the parameters.
//-----------------------------------------------------------------------------
void CloseFiles(FILE** file1, FILE** file2)
{
	// Check to see if file1 is valid
	if (*file1 != NULL)
	{
		// Close file1
		fclose(*file1);
	}

	// Check to see if file2 is valid
	if (*file2 != NULL)
	{
		// Close file2
		fclose(*file2);
	}
}


//-----------------------------------------------------------------------------
// Function Name:FillArray
// Description:
//  This function will fill the array with integers read in from the input 
//  file. 
//
//-----------------------------------------------------------------------------
void FillArray(FILE* pFin, int intArray[], int* arrayCounter)
{
	int value;
	int dataReadIn;

	if (pFin == NULL)
	{
		// Print message to the screen
		printf("\nFile does not exist\n");
	}
	else
	{

		// Primer - attempt to read in a value
		dataReadIn = fscanf(pFin, "%d", &value);
		
		// Check to see if the file is empty
		if (dataReadIn == -1)
		{
			// Print message to the screen
			printf("File exist, but it is empty\n\n");
		}

		while (dataReadIn == 1 && *arrayCounter < MAX)
		{
			// Assign the value to an element of the array
			intArray[*arrayCounter] = value;

			// Increase the number of elements by one
			(*arrayCounter)++;

			// Changer - attempt to read in another value
			dataReadIn = fscanf(pFin, "%d", &value);
		}

	}
}


//-----------------------------------------------------------------------------
// Function Name:PrintArray
// Description:
//  This function will print the contents of the integer array in rows of 10
// 
//  Because FILE is a pointer and we want to change the value of the address
//  we will need to use a double pointer. 
// 
//  The double pointer uses ** in the parameters.
//-----------------------------------------------------------------------------
void PrintArray(FILE * pFout, const int intArray[], int arrayCounter)
{
	
	PrintDivider(pFout, DASH, TABLE_WIDTH);
	
	CenterString(pFout, "Array Contents", TABLE_WIDTH);
	
	PrintDivider(pFout, DASH, TABLE_WIDTH);

	for (int index = 0; index < arrayCounter; index++)
	{
		// Print one integer to the screen in a width of 5 and right justified
		fprintf(pFout, "%5d", intArray[index]);

		// Check to see if 10 integers have been printed
		if ((index + 1) % 10 == 0)
		{
			// Move the cursor down to the next line
			fprintf(pFout, "\n");
		}
	}

	// Move the cursor down two lines
	fprintf(pFout, "\n\n");
}


//-----------------------------------------------------------------------------
// Function Name:AddThreeWithPointerArithmatic
// Description:
//  This function will use pointer arithmetic to increase the value of each
//  element by 3.
//
//-----------------------------------------------------------------------------
void AddThreeWithPointerArithmatic(int intArray[], int arrayCounter)
{
	int* pStart;
	int* pEnd;

	for (pStart = intArray, pEnd = &intArray[arrayCounter]; pStart < pEnd; pStart++)
	{
		// Add three the element pointed to by pStart
		*pStart += 3;
	}
}
