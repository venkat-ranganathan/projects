#include "Inputs.h"
#include "Simulation.h"

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

	// Move cursor down one line
	printf("\n");

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

	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print the spaces needed to center the string
	while (counter < numberOfBlankSpaces)
	{
		// Print one space
		printf(" ");

		// Increment counter
		counter++;
	}

	// Print the string
	printf("%s\n", string);

} // END CenterString


//-----------------------------------------------------------------------------
// Function Name: OpenDataFile
// Description:
//    Open both files
//
//-----------------------------------------------------------------------------
void OpenDataFile(FILE** pOutputLog, FILE** pDebugLog)
{
	// Open Output File 
	*pOutputLog = fopen("SimulationOutput.txt", "w");
	*pDebugLog = fopen("DebuggingData.txt", "w");
}


//-----------------------------------------------------------------------------
// Function Name: CloseFiles
// Description:
//    Close both files 
//
//-----------------------------------------------------------------------------
void CloseFiles(FILE** pDebug, FILE** pLog)
{
	// Close both output files 
	fclose(*pDebug);
	fclose(*pLog);
}
