#include "RanganathanV_Lab5.h"

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE* pOutput)
{
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣀⣀\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⠿⠿⠟\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣤⣴⣶⣶⣶⣤⣿⡿⠁⠀⠀⠀\n");
	fprintf(pOutput, "⣀⠤⠴⠒⠒⠛⠛⠛⠛⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⣿⣿⣿⡟⠻⢿⡀⠀⠀⠀⠀⠀\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⢿⣿⠟⠀⠸⣊⡽⠀⠀⠀⠀⠀\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⣿⡁⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀\n");
	fprintf(pOutput, "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");

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
//   Symbols will be printed to the output file. 
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
	// filePointer is a double pointer, so need to dereference to access file
	*filePointer = fopen(message, type);

} // END OpenFile

//-----------------------------------------------------------------------------
// Function Name: CloseFile (single file)
// Description:
//  This function will close a single file
//
//  Because FILE is a pointer and we want to change the value of the address
//  we will need to use a double pointer. 
// 
//  The double pointer uses ** in the parameters.
//-----------------------------------------------------------------------------
void CloseFile(FILE** file)
{
	// Check to see if file is valid
	if (*file != NULL)
	{
		// Close file
		fclose(*file);
	}
} // END CloseFile

//-----------------------------------------------------------------------------
// Function Name: CloseFiles
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
} // End CloseFiles

//-----------------------------------------------------------------------------
// Function Name: ReadDataFromFile
// Description:
//  This function will fill the array with integers read in from the input 
//  file. 
//
//-----------------------------------------------------------------------------
void ReadDataFromFile(FILE* pFin, int intArray[], int* arrayCounter)
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
} // END ReadDataFromFile

//-----------------------------------------------------------------------------
// Function Name:CreateNode
// Description:
//   Both members of the new node will be initialized. 
//
//-----------------------------------------------------------------------------
void CreateNode(nodeType* pNewNode, int input)
{
	// Assign members of the new node
	pNewNode->oneBook.author = input;
	pNewNode->pNext = NULL;
}

//-----------------------------------------------------------------------------
// Function Name:PrintList
// Description:
//  This function will take the pointer to our link list. 
//  Since the address will not be changing there is no reason for a double 
//  pointer. 
//
//  Every item of the link list will be printed to the screen
//
//-----------------------------------------------------------------------------
void PrintList(nodeType* pList, orderType order)
{
	if (!IsEmpty(pList) && order == LEAST_TO_GREATEST)
	{
		// Print the number of the current number
		printf("%5d", pList->record.number);
	}

	// Check to see if the list is empty
	if (!IsEmpty(pList))
	{
		// Print message to the screen
		PrintList(pList->pNext, order);
	}

	if (!IsEmpty(pList) && order == GREATEST_TO_LEAST)
	{
		// Print the number of the current number
		printf("%5d", pList->record.number);
	}
}