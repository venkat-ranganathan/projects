

#include "oop.h"

//-----------------------------------------------------------------------------
// Function Name: objectType::objectType
// Description:
//   Constructor - this will initialize the array counter to 0
//
//-----------------------------------------------------------------------------
objectType::objectType(void)
{
	// Initialize constructor to 0
	arrayCounter = 0;
}


//-----------------------------------------------------------------------------
// Function Name: objectType::~objectType
// Description:
//   Destructor - this will print a message to the screen
//
//-----------------------------------------------------------------------------
objectType::~objectType(void)
{
	// Print message to the screen
	printf("\nYour object has been destroyed\n");
}


//-----------------------------------------------------------------------------
// Function Name: objectType::PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void objectType::PrintHeader(FILE* pOutput)
{
	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

	// Call functions to print three strings to center to the screen
	CenterString(pOutput, SCHOOL, SCREEN_WIDTH);
	CenterString(pOutput, PROGRAMMER, SCREEN_WIDTH);
	CenterString(pOutput, LAB, SCREEN_WIDTH);

	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

}


//-----------------------------------------------------------------------------
// Function Name: objectType::PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void objectType::PrintDivider(FILE* pOutput, char symbol, int numberOf)
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

}


//-----------------------------------------------------------------------------
// Function Name: objectType::CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void objectType::CenterString(FILE* pOutput, const char string[], int lengthToCenterAcross)
{
	// Capture how long the string is
	// Cast to an integer because strlen technically returns size_t
	int stringLength = (int)strlen(string);

	// Calculate the width to print the string in
	int width = (lengthToCenterAcross + stringLength) / 2;

	// Calculate how many blank spaces are needed before printing the string
	int numberOfBlankSpaces = width - stringLength;

	for (int counter = 0; counter < numberOfBlankSpaces; counter++)
	{
		// Print one space
		fprintf(pOutput, " ");
	}

	// Print the string
	fprintf(pOutput, "%s\n", string);
}


//-----------------------------------------------------------------------------
// Function Name: objectType::ReadDataFromFile
// Description:
//   Integers will be read in and stored in the array
//
//-----------------------------------------------------------------------------
void objectType::ReadDataFromFile(FILE * pFin)
{
	int value;
	
	// Check to see if we have a valid file pointer
	if (pFin != NULL)
	{
		while (fscanf(pFin, "%d" , &value) == 1 && arrayCounter < ARRAY_SIZE)
		{
			// Assign value to the array
			intArray[arrayCounter] = value;
			
			// Increase the counter of elements by 1
			arrayCounter++;
		}
	}
			
}


//-----------------------------------------------------------------------------
// Function Name: objectType::PrintArray
// Description:
//   This method will be the driver for printing the array 
//
//-----------------------------------------------------------------------------
void objectType::PrintArray(FILE * pOutput)
{
	//  Call private methods
	PrintArrayHeader(pOutput);
	PrintData(pOutput);
}


//-----------------------------------------------------------------------------
// Function Name: objectType::PrintArrayHeader
// Description:
//   The method will print the header for the array output
//
//-----------------------------------------------------------------------------
void objectType::PrintArrayHeader(FILE * pOutput)
{
	PrintDivider(pOutput, DASH, TABLE_WIDTH); 
	
	CenterString(pOutput, TABLE_TITLE, TABLE_WIDTH);
	
	PrintDivider(pOutput, DASH, TABLE_WIDTH);
	
}


//-----------------------------------------------------------------------------
// Function Name: objectType::PrintData
// Description:
//   This method will print the array
//
//-----------------------------------------------------------------------------
void objectType::PrintData(FILE * pOutput)
{
	
	for (int index = 0; index < arrayCounter; index++)
	{
		// Print element of the array to the output source
		fprintf(pOutput, "%5d", intArray[index]);
		
		// Check to see if we need an enter key
		if ((index + 1) % NUMBER_PER_LINE == 0)
		{
			// Print the enter key
			fprintf(pOutput, "\n");
		}
	}
	
	// Print the enter key
	fprintf(pOutput, "\n");
}

