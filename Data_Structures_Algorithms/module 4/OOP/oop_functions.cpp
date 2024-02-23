
#include "oop.h"

//-----------------------------------------------------------------------------
// Function Name: OpenFiles
// Description:
//   Open both the input and the output file
//
//-----------------------------------------------------------------------------
void OpenFiles(FILE ** pFin, FILE ** pFout)
{
	// Open files
	*pFin = fopen("OOP_Numbers.txt", "r");
	*pFout = fopen("Output.txt", "w");
}


//-----------------------------------------------------------------------------
// Function Name: CloseFiles
// Description:
//   Close both the input and the output file
//
//-----------------------------------------------------------------------------
void CloseFiles(FILE ** pFin, FILE ** pFout)
{
	// Check to see if the input file pointer is valid
	if (*pFin != NULL)
	{
		// Close the input file
		fclose(*pFin);
	}
	
	// Check to see if the output file pointer is valid
	if (*pFout != NULL)
	{
		// Close the output file
		fclose(*pFout);
	}
}