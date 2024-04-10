#include "RanganathanV_Lab6.h"

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
// Function Name: InitializeStack
// Description:
//   Set the top pointer to equal NULL
//
//-----------------------------------------------------------------------------
void InitializeStack(stackType* pTop)
{
	// Set pointer to NULL
	pTop->pTop = NULL;
}


//-----------------------------------------------------------------------------
// Function Name: StackIsEmpty
// Description:
//   Returns true or false based on if the pointer to top is NULL
//
//-----------------------------------------------------------------------------
int StackIsEmpty(stackType stack)
{
	// check to see if the stack is empty
	return stack.pTop == NULL;
}


//-----------------------------------------------------------------------------
// Function Name: Push
// Description:
//   Add one node to the stack.
//   Thus function assumes that the new node has already been 
//  declared and initialized. 
//
//-----------------------------------------------------------------------------
void Push(stackType* pTop, nodeType* newElement)
{
	//Defensive coding
	if (newElement == NULL)
	{
		printf("ERROR - There is no new data\n");
	}
	else
	{
		// Set the next pointer of the new node to equal top
		newElement->pNext = pTop->pTop;

		// Move the top pointer
		pTop->pTop = newElement;
	}
}


//-----------------------------------------------------------------------------
// Function Name: Pop
// Description:
//   Remove one node from the stack
//
//   Depending on the needs of your program, you may want to pass in a 
//  nodeType pointer so you can return the data from the node. 
//
//-----------------------------------------------------------------------------

void Pop(stackType* pTop)
{
	nodeType* pTemp;

	// See if the stack is empty
	if (!StackIsEmpty(*pTop))
	{
		// Assign pTemp to the top of the stack
		pTemp = pTop->pTop;

		// Move the top pointer down one node
		pTop->pTop = pTop->pTop->pNext;

		// Free the memory pointed to by temp
		free(pTemp);

	}

}

//-----------------------------------------------------------------------------
// Function Name: ReturnPriority
// Description:
//    Function will:
//    return 0 for character '('
//    return 1 for the '+' or the '-' characters
//    return 2 for the '*' or the '/' characters
//
//-----------------------------------------------------------------------------
int ReturnPriority(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
        break;
    
    case '+':
        return 1;
        break;
    
     case '-':
        return 1;
        break;   

    case '*':
        return 2;
        break;

    case '/':
        return 2;
        break;
    
    default:
        break;
    }
}

//-----------------------------------------------------------------------------
// Function Name: OpenDataFile
// Description:
//    Open both files
//
//-----------------------------------------------------------------------------
void OpenDataFile(FILE** pOutputLog, FILE** pDebugLog)
{
	// Open Output File 
	*pOutputLog = fopen("Lab6_Output.txt", "w+");

#ifdef DEBUG
	*pDebugLog = fopen("DebuggingData.txt", "w");
#endif
}


//-----------------------------------------------------------------------------
// Function Name: CloseFiles
// Description:
//    Close data file
//
//-----------------------------------------------------------------------------
void CloseFile(FILE ** pFile)
{
	if (pFile != NULL)
	{
		// Close file 
		fclose(*pFile);
	}
}