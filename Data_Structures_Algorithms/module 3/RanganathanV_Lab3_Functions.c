#include "RanganathanV_Lab3.h"

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE* pOutput, int option)
{
	switch (option)
	{
		case 0:
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
			CenterString(pOutput, SCHOOL, SCREEN_WIDTH, option);
			CenterString(pOutput, PROGRAMMER, SCREEN_WIDTH, option);
			CenterString(pOutput, LAB, SCREEN_WIDTH, option);

			// Call function to print a divider to the screen
			PrintDivider(pOutput, STAR, SCREEN_WIDTH);

			break;

		case 1:
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣀⣀\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⠿⠿⠟\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣤⣴⣶⣶⣶⣤⣿⡿⠁⠀⠀⠀\n");
			printf("⣀⠤⠴⠒⠒⠛⠛⠛⠛⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⣿⣿⣿⡟⠻⢿⡀⠀⠀⠀⠀⠀\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⢿⣿⠟⠀⠸⣊⡽⠀⠀⠀⠀⠀\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⣿⡁⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀\n");
			printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");

			// Call function to print a divider to the screen
			PrintDividerScreen(STAR, SCREEN_WIDTH);

			// Call functions to print three strings to center to the screen
			CenterString(pOutput, SCHOOL, SCREEN_WIDTH, option);
			CenterString(pOutput, PROGRAMMER, SCREEN_WIDTH, option);
			CenterString(pOutput, LAB, SCREEN_WIDTH, option);

			// Call function to print a divider to the screen
			PrintDividerScreen(STAR, SCREEN_WIDTH);
			break;
	}


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
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void PrintDividerScreen(char symbol, int numberOf)
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
} // END PrintDividerScreen


//-----------------------------------------------------------------------------
// Function Name: CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross, int option)
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

	switch (option)
	{
		case 0:
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

			break;
		case 1:
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

			break;
	}



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
// Function Name: StarPatternFile
// Description:
//   This function will print a pattern of stars to an output 
//  file and will recursively print the pattern from 1 until the set number is reached
//
//-----------------------------------------------------------------------------
void StarPattern(FILE * pFout, int number, int counter, int option) 
{ 
	switch (option)
	{
	case 0:
		if (number == 0)
		return;

		PrintDivider(pFout, STAR, counter);

		if (number > 1)
		{
			StarPattern(pFout, number - 1, counter + 1, option);
		}
		break;

	case 1:
		if (number == 0)
			return;

		PrintDividerScreen(STAR, counter);

		if (number > 1)
		{
			StarPattern(pFout, number - 1, counter + 1, option);
		}
		break;
	}


} // END StarPatternFile

//-----------------------------------------------------------------------------
// Function Name: StarPattern2
// Description:
//   This function will print a pattern of stars to the screen and will recursively print the pattern from 1 until the set number is reached
//
//-----------------------------------------------------------------------------
void StarPatternScreen(int number, int counter) 
{ 
	if (number == 0)
		return;

	PrintDividerScreen(STAR, counter);

	if (number > 1)
	{
		StarPatternScreen(number - 1, counter + 1);
	}

} // END StarPatternScreen

//-----------------------------------------------------------------------------
// Function Name: FillArrayWithRandomNumbers
// Description:
//   Every element of the array will be assigned a value between 0 and 99.
//
//-----------------------------------------------------------------------------
void FillArrayWithRandomNumbers(int intArray[])
{
	for (int index = 0; index < MAX; index++)
	{		
		// Set each element of the array to a number between 0 and 99
		intArray[index] = rand() % 99 + 1;
	}
} // END FillArrayWithRandomNumbers

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
void PrintArray(FILE * pFout, const int intArray[], int arrayCounter, int option)
{
	int counter = 1;

	switch (option)
	{
		case 0:
			PrintDivider(pFout, DASH, TABLE_WIDTH+2);
			
			CenterString(pFout, "2nd Recursive Function: Sum the Array", TABLE_WIDTH+2, 0);
			
			PrintDivider(pFout, DASH, TABLE_WIDTH+2);
			
			// primer for row
			fprintf(pFout, "\n");

			for (int index = 0; index < arrayCounter; index++)
			{
				// Print one integer to the screen in a width of 5 and right justified
				fprintf(pFout, "%5d", intArray[index]);

				// Check to see if 2 integers have been printed
				if ((index + 1) % 2 == 0)
				{
					// Move the cursor down to the next line and print row number
					fprintf(pFout, "\n");
				}
			}

			// Move the cursor down two lines
			fprintf(pFout, "\n");
			break;

		case 1:
	
		PrintDividerScreen(DASH, TABLE_WIDTH+2);
		
		CenterString(pFout, "2nd Recursive Function: Sum the Array", TABLE_WIDTH+2, 1);
		
		PrintDividerScreen(DASH, TABLE_WIDTH+2);
		
		// primer for row
		printf("\n");

		for (int index = 0; index < arrayCounter; index++)
		{
			// Print one integer to the screen in a width of 5 and right justified
			printf("%5d", intArray[index]);

			// Check to see if 2 integers have been printed
			if ((index + 1) % 2 == 0)
			{
				// Move the cursor down to the next line and print row number
				printf("\n");
			}
		}

		// Move the cursor down two lines
		printf("\n");
			break;
	}

} // END PrintArray

int SumArray(int intArray[], int counter, int size)
{
	if (size <= 0)
	{
		return 0;
	}
		
	return (SumArray(intArray, counter, size - 1) + intArray[size - 1]);
}

void PrintDigits(FILE* pFout, int number, int option)
{
	switch (option)
	{
		case 0:
			if (number <= 0)
			{
				return;
			}

			PrintDigits(pFout, number / 10, option);

			fprintf(pFout, "%d", number % 10);
			break;
		case 1:	
			if (number <= 0)
			{
				return;
			}

			PrintDigits(pFout, number / 10, option);

			printf("%d", number % 10);
			break;
	}

}

